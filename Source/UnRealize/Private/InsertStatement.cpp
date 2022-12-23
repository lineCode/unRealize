#include "InsertStatement.h"


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
		ValueStatement.Appendf(TEXT("'%s'%s"), *Values[i].Value, *Separator);
	}

	return KeyStatement.Appendf(TEXT(" %s"), *ValueStatement);
}


void FInsertStatement::AddValue(const FString& Name, const FString& Value)
{
	Values.Add(TTuple<FString, FString>(Name, Value));
}