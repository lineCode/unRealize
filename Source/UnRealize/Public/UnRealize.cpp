#include "UnRealize.h"

#include "InsertStatement.h"
#include "UnRealize/Private/PostgresAdapter.h"
#include "ReadStatement.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"


TSharedPtr<FUnRealize> FUnRealize::UnRealize = nullptr;


void FUnRealize::Initialize()
{
	if(UnRealize == nullptr)
	{
		UnRealize = MakeShareable(new FUnRealize);
		bool bWasSuccessful = UnRealize->LoadConfiguration();
		if(!bWasSuccessful)
		{
			
		}
	}
}


TSharedPtr<FUnRealize> FUnRealize::Get()
{
	if(UnRealize == nullptr)
	{
		Initialize();
	}
	return UnRealize;
}


void FUnRealize::Persist(const UStruct* StructType, const void* Struct) const
{
	FString PersistAs = StructType->GetMetaData(TEXT("PersistAs"));
	if(PersistAs == TEXT(""))
	{
		PersistAs = StructType->GetName();
	}
	FInsertStatement Statement(PersistAs);
	for(TFieldIterator<FProperty> PropertyIterator(StructType); PropertyIterator; ++PropertyIterator)
	{
		const FProperty* Property = *PropertyIterator;
		if(!Property->HasMetaData(TEXT("IgnorePersist")))
		{
			FString PersistFieldAs = Property->GetMetaData(TEXT("PersistAs"));
			if(PersistFieldAs == TEXT(""))
			{
				PersistFieldAs = Property->GetName();
			}
			Statement.AddValue(PersistFieldAs, *Property->ContainerPtrToValuePtr<FString>(Struct));
		}
	}

	Adapter->ExecuteStatement(Statement.Formulate());
}


template<typename SelectedType>
TArray<SelectedType> FUnRealize::FindMany(const UStruct* StructType) const
{
	FString PersistedAs = StructType->GetMetaData(TEXT("PersistAs"));
	if(PersistedAs == TEXT(""))
	{
		PersistedAs = StructType->GetName();
	}
	const FReadStatement Statement(PersistedAs);

	const pqxx::result Result = Adapter->Query(Statement.Formulate());
	TArray<SelectedType> QueryResult;
	for(const pqxx::row& Row : Result)
	{
		SelectedType Object;
		for(const pqxx::field& Field : Row)
		{
			const FProperty* Property = StructType->FindPropertyByName(Field.name());
			const FString Value = FString(Field.c_str());
			Property->SetValue_InContainer(&Object, &Value);
		}
		
		QueryResult.Add(Object);
	}
		
	return QueryResult;
}


/* void FUnRealize::Delete(const UStruct* StructType, const void* Struct) const
{
	
}


template <typename SelectedType>
void FUnRealize::Delete(const UStruct* StructType, TSelector<SelectedType> Selector) const
{
} */


void FUnRealize::RegisterTypes(const TArray<UStruct*> Types)
{
	if (Adapter == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No Adapter was initialized"));
		return;
	}
	for (const UStruct* Type : Types)
	{
		
		UE_LOG(LogTemp, Log, TEXT("Name: %s"), *(Type->GetMetaData(TEXT("PersistanceName"))));
	}
}


bool FUnRealize::LoadConfiguration()
{
	const FString BaseDirectory = IPluginManager::Get().FindPlugin(TEXT("unRealize"))->GetBaseDir();
	const FString ConfigPath = FPaths::Combine(*BaseDirectory, TEXT("Config"), TEXT("UnRealizeConfig.ini"));
	const FString Dbms = GConfig->GetStr(TEXT("UnRealize"), TEXT("Dbms"), ConfigPath);
	if(Dbms == TEXT("PostgreSQL"))
	{
		Adapter = FPostgresAdapter::Get();
	}
	else
	{
		unimplemented();
	}
	return true;
}
