#include "UnRealize.h"

#include "PostgresAdapter.h"
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


void FUnRealize::Persist(const UStruct* StructType, const void* Struct)
{
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
