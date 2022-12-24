#include "InsertStatement.h"

#include "../Public/SqlProperty.h"


FInsertStatement::FInsertStatement(const FString& TableName)
{
	this->TableName = TableName;
}


FString FInsertStatement::Formulate() const
{
	FString KeyStatement = TEXT("INSERT INTO ");
	KeyStatement.Appendf(TEXT("\"%s\" ("), *TableName);
	FString ValueStatement = TEXT("VALUES (");
	for(uint8 i = 0; i < Values.Num(); ++i)
	{
		const FString Separator = i == Values.Num() - 1 ? TEXT(")") : TEXT(", ");
		KeyStatement.Appendf(TEXT("\"%s\"%s"), *Values[i].Key, *Separator);
		ValueStatement.Appendf(TEXT("%s%s"), *Values[i].Value.GetSqlLiteral(), *Separator);
	}

	return KeyStatement.Appendf(TEXT(" %s"), *ValueStatement);
}


void FInsertStatement::AddValue(const FString& Name, const FSqlProperty& Value)
{
	Values.Add(TTuple<FString, FSqlProperty>(Name, Value));
}