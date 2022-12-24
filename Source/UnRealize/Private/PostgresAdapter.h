#pragma once

#include "CoreMinimal.h"
#include "DatabaseAdapter.h"
#include <pqxx/pqxx>


class UNREALIZE_API FPostgresAdapter final : public FDatabaseAdapter
{
public:
	virtual ~FPostgresAdapter() override;
	
	static TSharedPtr<FPostgresAdapter> Get();

	virtual void ExecuteStatement(const FString& Statement) override;

	virtual const struct FQueryResult Query(const FString& Statement) override;

protected:
	bool Connect();
	
private:
	static TSharedPtr<FPostgresAdapter> SingletonAdapter;

	pqxx::connection* Connection = nullptr;
};
