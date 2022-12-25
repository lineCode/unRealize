#include "ReadStatement.h"

#include "Selector.h"


FReadStatement::FReadStatement(const FString& TableName)
{
	this->TableName = TableName;
}


FString FReadStatement::Formulate(const FSelector& Selector) const
{
	FString SelectStatement = FString::Printf(TEXT("SELECT %s FROM \"%s\";"), *Selector.GetSelectClause(), *TableName);
	return SelectStatement;
}