#include "UpdateStatement.h"

#include "Selector.h"


FUpdateStatement::FUpdateStatement(const FString& TableName)
{
	this->TableName = TableName;
}


FString FUpdateStatement::Formulate(const FSelector& Selector)
{
	FString UpdateStatement = FString::Printf(TEXT("UPDATE %s"), *TableName);
	UpdateStatement.Appendf(TEXT("WHERE %s"), *Selector.GetWhereClause());
	return UpdateStatement;
}