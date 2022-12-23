#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

struct UNREALIZE_API FReadStatement
{
public:
	explicit FReadStatement(const FString& TableName);

	FString Formulate() const;

private:
	FString TableName;
};