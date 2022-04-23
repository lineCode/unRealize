#pragma once

#include "CoreMinimal.h"


class UNREALIZE_API FDatabaseAdapter
{
public:
	virtual ~FDatabaseAdapter() = default;

	virtual void ExecuteStatement(const FString& Statement);
};