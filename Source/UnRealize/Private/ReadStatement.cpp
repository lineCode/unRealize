#include "ReadStatement.h"


FReadStatement::FReadStatement(const FString& TableName)
{
	this->TableName = TableName;
}


FString FReadStatement::Formulate() const
{
	FString SelectStatement = TEXT("SELECT * FROM ");
	SelectStatement.Appendf(TEXT("\"%s\";"), *TableName);
	return SelectStatement;
}