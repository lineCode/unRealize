#pragma once
#include "Selector.h"


struct UNREALIZE_API FDeleteStatement
{
public:
	explicit FDeleteStatement(const FString& TableName);
	
	FString Formulate(FSelector Selector) const;

private:
	FString TableName;
};
