#pragma once

struct UNREALIZE_API FUpdateStatement
{
public:
	explicit FUpdateStatement(const FString& TableName);

	FString Formulate(const class FSelector& Selector);
	
private:
	FString TableName;
};