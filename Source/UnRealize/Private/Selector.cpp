#include "Selector.h"

#include "StructUtility.h"
#include "UnRealizeModule.h"
#include "LogMacros/LogMacros.h"


FSelector::FSelector()
{
	SelectClause = TEXT("*");
}


FSelector& FSelector::Select(const TArray<FString>& Selection)
{
	AppendSelectors(Selection);
	return *this;
}


FSelector& FSelector::Select(const FString& Selection)
{
	return Select(SplitSelectors(Selection));
}


FSelector& FSelector::SelectChecked(UStruct* Struct, const TArray<FString>& Selection)
{
	if(!FStructUtility::Check(Struct, Selection))
	{
		LOG_ERROR(LogUnRealize, "Select clause contains properties that don't exist on the selected type.")
	}
	AppendSelectors(Selection);
	return *this;
}


FSelector& FSelector::SelectChecked(UStruct* Struct, const FString& Selection)
{
	return SelectChecked(Struct, SplitSelectors(Selection));
}


FSelector& FSelector::Where(const FSqlCondition& Condition)
{
	WhereClause = Condition.GetConditionLiteral();
	return *this;
}


FSelector& FSelector::WhereChecked(const UStruct* Struct, const FSqlCondition& Condition)
{
	unimplemented();
	return *this;
}


FString FSelector::GetSelectClause() const
{
	return SelectClause;
}


FString FSelector::GetWhereClause() const
{
	return WhereClause;
}


TArray<FString> FSelector::SplitSelectors(FString Selection)
{
	Selection.RemoveSpacesInline();
	TArray<FString> Selectors;
	Selection.ParseIntoArray(Selectors, TEXT(","), true);
	return Selectors;
}


void FSelector::AppendSelectors(const TArray<FString>& Selectors)
{
	SelectClause = TEXT("");
	for(uint8 i = 0; i < Selectors.Num(); ++i)
	{
		const FString Separator = i == Selectors.Num() - 1 ? TEXT("") : TEXT(", ");
		SelectClause.Appendf(TEXT("\"%s\"%s"), *Selectors[i], *Separator);
	}
}