#pragma once

#include "CoreMinimal.h"
#include "SqlCondition.h"


class UNREALIZE_API FSelector
{
public:
	FSelector();
	
	FSelector& Select(const TArray<FString>& Selection);

	FSelector& Select(const FString& Selection);
	
	FSelector& SelectChecked(UStruct* Struct, const TArray<FString>& Selection);

	FSelector& SelectChecked(UStruct* Struct, const FString& Selection);
	
	FSelector& Where(const FSqlCondition& Condition);

	FSelector& WhereChecked(const UStruct* Struct, const FSqlCondition& Condition);

	FString GetSelectClause() const;
	
	FString GetWhereClause() const;

private:
	static TArray<FString> SplitSelectors(FString Selection);
	
	void AppendSelectors(const TArray<FString>& Selectors);
	
	FString SelectClause;
	
	FString WhereClause;
};