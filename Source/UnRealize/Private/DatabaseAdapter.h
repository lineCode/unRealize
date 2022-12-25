#pragma once

#include "CoreMinimal.h"


class UNREALIZE_API FDatabaseAdapter
{
public:
	virtual ~FDatabaseAdapter() = default;

	virtual void ExecuteStatement(const FString& Statement) = 0;

	virtual const struct FQueryResult Query(const FString& Statement) = 0;
};
