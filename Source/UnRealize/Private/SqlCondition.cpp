#include "SqlCondition.h"


FSqlCondition FSqlCondition::Equals(const FString& Name, const FSqlProperty& Property)
{
	return CombineSimpleCondition(Name, Property, TEXT("="));
}


FSqlCondition FSqlCondition::GreaterThan(const FString& Name, const FSqlProperty& Property)
{
	return CombineSimpleCondition(Name, Property, TEXT(">"));
}


FSqlCondition FSqlCondition::LessThan(const FString& Name, const FSqlProperty& Property)
{
	return CombineSimpleCondition(Name, Property, TEXT("<"));
}


FSqlCondition FSqlCondition::GreaterEqualsThan(const FString& Name, const FSqlProperty& Property)
{
	return CombineSimpleCondition(Name, Property, TEXT(">="));
}


FSqlCondition FSqlCondition::LessEqualsThan(const FString& Name, const FSqlProperty& Property)
{
	return CombineSimpleCondition(Name, Property, TEXT("<="));
}


FSqlCondition FSqlCondition::NotEqual(const FString& Name, const FSqlProperty& Property)
{
	return CombineSimpleCondition(Name, Property, TEXT("<>"));
}


FSqlCondition FSqlCondition::Between(const FString& Name, const FSqlProperty& Property1, const FSqlProperty& Property2)
{
	FSqlCondition Condition;
	Condition.ConditionLiteral = FString::Printf(TEXT("\"%s\" BETWEEN %s AND %s"), *Name, *Property1.GetSqlLiteral(), *Property2.GetSqlLiteral());
	return Condition;
}


FSqlCondition FSqlCondition::Like(const FString& Name, const FString& Pattern)
{
	FSqlCondition Condition;
	Condition.ConditionLiteral = FString::Printf(TEXT("\"%s\" LIKE '%s'"), *Name, *Pattern);
	return Condition;
}


FSqlCondition FSqlCondition::In(const FString& Name, const TArray<FSqlProperty>& InArray)
{
	FSqlCondition Condition;
	Condition.ConditionLiteral = FString::Printf(TEXT("\"%s\" IN ("), *Name);
	for(uint64 i = 0; i < InArray.Num(); ++i)
	{
		const FString Separator = i == InArray.Num() - 1 ? TEXT(")") : TEXT(", ") ;
		Condition.ConditionLiteral.Appendf(TEXT("%s%s"), *InArray[i].GetSqlLiteral(), *Separator);
	}
	return Condition;
}


FSqlCondition FSqlCondition::And(const FSqlCondition& Operator1, const FSqlCondition& Operator2)
{
	FSqlCondition Condition;
	Condition.ConditionLiteral = FString::Printf(TEXT("%s AND %s"), *Operator1.ConditionLiteral, *Operator2.ConditionLiteral);
	return Condition;
}


FSqlCondition FSqlCondition::Or(const FSqlCondition& Operator1, const FSqlCondition& Operator2)
{
	FSqlCondition Condition;
	Condition.ConditionLiteral = FString::Printf(TEXT("%s OR %s"), *Operator1.ConditionLiteral, *Operator2.ConditionLiteral);
	return Condition;
}


FSqlCondition FSqlCondition::Not(const FSqlCondition& Operator)
{
	FSqlCondition Condition;
	Condition.ConditionLiteral = FString::Printf(TEXT("NOT %s"), *Operator.ConditionLiteral);
	return Condition;
}


FString FSqlCondition::GetConditionLiteral() const
{
	return ConditionLiteral;
}


FSqlCondition FSqlCondition::CombineSimpleCondition(const FString& Name, const FSqlProperty& Property, const FString& Operator)
{
	FSqlCondition Condition;
	Condition.ConditionLiteral = FString::Printf(TEXT("\"%s\" %s %s"), *Name, *Operator, *Property.GetSqlLiteral());
	return Condition;
}
