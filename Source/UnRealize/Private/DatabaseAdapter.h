#pragma once

#include "CoreMinimal.h"


namespace pqxx
{
	class result;
}


class UNREALIZE_API FDatabaseAdapter
{
public:
	virtual ~FDatabaseAdapter() = default;

	virtual void ExecuteStatement(const FString& Statement) = 0;

	virtual const pqxx::result Query(const FString& Statement) = 0;
};
