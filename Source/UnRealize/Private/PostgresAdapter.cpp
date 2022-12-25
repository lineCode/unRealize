#include "PostgresAdapter.h"


#if PLATFORM_WINDOWS
// Winsock Includes
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define SECURITY_WIN32

#include "Windows/AllowWindowsPlatformTypes.h"
#include <windows.h>
#include <sspi.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#include "Windows/HideWindowsPlatformTypes.h"

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Secur32.lib")
#endif
/** END OF WINDOWS-SPECIFIC INCLUDES/CODE */

/** START OF LINUX-SPECIFIC INCLUDES/CODE */
#if PLATFORM_LINUX
// Nothing here yet! But the placeholder is here for future releases.
#endif
/** END OF LINUX-SPECIFIC INCLUDES/CODE */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <time.h>

#include <pqxx/pqxx>

#include "QueryField.h"
#include "QueryRow.h"
#include "QueryResult.h"
#include "StringUtility.h"
#include "UnRealizeModule.h"
#include "Interfaces/IPluginManager.h"
#include "LogMacros/LogMacros.h"


TSharedPtr<FPostgresAdapter> FPostgresAdapter::SingletonAdapter = nullptr;


FPostgresAdapter::~FPostgresAdapter()
{
	delete Connection;
}


TSharedPtr<FPostgresAdapter> FPostgresAdapter::Get()
{
	if(SingletonAdapter == nullptr)
	{
		SingletonAdapter = MakeShareable(new FPostgresAdapter);
		SingletonAdapter->Connect();
	}
	return SingletonAdapter;
}


bool FPostgresAdapter::Connect()
{
	try
	{
		const FString BaseDirectory = IPluginManager::Get().FindPlugin(TEXT("unRealize"))->GetBaseDir();
		const FString ConfigPath = FPaths::Combine(*BaseDirectory, TEXT("Config"), TEXT("UnRealizeConfig.ini"));
		const FString DatabaseName = GConfig->GetStr(TEXT("Connection"), TEXT("DatabaseName"), ConfigPath);
		const FString User  = GConfig->GetStr(TEXT("Connection"), TEXT("User"), ConfigPath);
		const FString Password = GConfig->GetStr(TEXT("Connection"), TEXT("Password"), ConfigPath);
		const FString Host = GConfig->GetStr(TEXT("Connection"), TEXT("Host"), ConfigPath);
		int32 Port;
		GConfig->GetInt(TEXT("Connection"), TEXT("Port"), Port, ConfigPath);

		const FString ConnectionString = FString::Printf(TEXT("dbname = %s user = %s password = %s host = %s port = %i"),
			*DatabaseName, *User, *Password, *Host, Port);

		Connection = new pqxx::connection(FStringUtility::ToStd(ConnectionString));

		if (Connection->is_open())
		{
			return true;
		}
	}
	catch (const std::exception& e)
	{
		const FString Exception = FString(e.what());
		UE_LOG(LogTemp, Error, TEXT("Exception: %s"), *Exception);
	}
	return false;
}


void FPostgresAdapter::ExecuteStatement(const FString& Statement)
{
	try
	{
		LOG_PRINTF(LogUnRealize, "Execute SQL statement: %s", *Statement);
		pqxx::work Work(*Connection);
		Work.exec(FStringUtility::ToStd(Statement));
		Work.commit();
	}
	catch (const std::exception& e)
	{
		const FString Exception = FString(e.what());
		UE_LOG(LogTemp, Log, TEXT("Exception: %s"), *Exception);
	}
}

const FQueryResult FPostgresAdapter::Query(const FString& Statement)
{
	try
	{
		LOG_PRINTF(LogUnRealize, "Execute SQL statement: %s", *Statement);
		pqxx::work Work(*Connection);
		const pqxx::result Result = Work.exec(FStringUtility::ToStd(Statement));
		Work.commit();
		FQueryResult QueryResult;
		for(const pqxx::row& Row : Result)
		{
			FQueryRow QueryRow;
			for(const pqxx::field& Field : Row)
			{
				QueryRow.Fields.Add(FQueryField::FromPqxxField(Field));
			}
			QueryResult.Rows.Add(QueryRow);
		}
		return QueryResult;
	}
	catch (const std::exception& e)
	{
		const FString Exception = FString(e.what());
		UE_LOG(LogTemp, Log, TEXT("Exception: %s"), *Exception);
		throw e;
		unimplemented()
	}
}