#pragma once
#include "SqlProperty.h"


enum ESqlConditionOperator
{
	Equal,
	GreaterThan,
	LessThan,
	GreaterEqualsThan,
	LessEqualsThan,
	NotEqual,
	Between,
	Like,
	In,
	And,
	Or,
	Not,
};

struct UNREALIZE_API FSqlCondition
{
public:
	static FSqlCondition Equals(const FString& Name, const FSqlProperty& Property);

	static FSqlCondition GreaterThan(const FString& Name, const FSqlProperty& Property);

	static FSqlCondition LessThan(const FString& Name, const FSqlProperty& Property);

	static FSqlCondition GreaterEqualsThan(const FString& Name, const FSqlProperty& Property);

	static FSqlCondition LessEqualsThan(const FString& Name, const FSqlProperty& Property);

	static FSqlCondition NotEqual(const FString& Name, const FSqlProperty& Property);

	static FSqlCondition Between(const FString& Name, const FSqlProperty& Property1, const FSqlProperty& Property2);

	static FSqlCondition Like(const FString& Name, const FString& Pattern);

	static FSqlCondition In(const FString& Name, const TArray<FSqlProperty>& InArray);
	
	static FSqlCondition And(const FSqlCondition& Operator1, const FSqlCondition& Operator2);

	static FSqlCondition Or(const FSqlCondition& Operator1, const FSqlCondition& Operator2);

	static FSqlCondition Not(const FSqlCondition& Operator);

	FString GetConditionLiteral() const;
	
private:
	static FSqlCondition CombineSimpleCondition(const FString& Name, const FSqlProperty& Property, const FString& Operator);
	
	FString ConditionLiteral;
};