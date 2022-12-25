#include "UnRealize.h"

#include "InsertStatement.h"
#include "UnRealize/Private/PostgresAdapter.h"
#include "SqlProperty.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"


TSharedPtr<FUnRealize> FUnRealize::UnRealize = nullptr;


void FUnRealize::Initialize()
{
	if(UnRealize == nullptr)
	{
		UnRealize = MakeShareable(new FUnRealize);
		const bool bWasSuccessful = UnRealize->LoadConfiguration();
		if(!bWasSuccessful)
		{
			LOG_ERROR(LogUnRealize, "Either the configuration is incomplete or it uses a unimplemented DBMS.");
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
	const FString PersistAs = FStructUtility::GetPersistedName(StructType);
	FInsertStatement Statement(PersistAs);
	for(TFieldIterator<FProperty> PropertyIterator(StructType); PropertyIterator; ++PropertyIterator)
	{
		const FProperty* Property = *PropertyIterator;
		if(!Property->HasMetaData(TEXT("IgnorePersist")))
		{
			FString PersistFieldAs = FPropertyUtility::GetPersistedName(Property);
			const FSqlProperty SqlProperty = FSqlProperty::FromProperty(Property, Struct);
			Statement.AddValue(PersistFieldAs, SqlProperty);
		}
	}

	Adapter->ExecuteStatement(Statement.Formulate());
}


void FUnRealize::ExecuteStatement(const FString& Statement) const
{
	Adapter->ExecuteStatement(Statement);
}


FQueryResult FUnRealize::Query(const FString& Statement) const
{
	return Adapter->Query(Statement);
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
		return false;
	}
	return true;
}
