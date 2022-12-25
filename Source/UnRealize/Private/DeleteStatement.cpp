#include "DeleteStatement.h"
#include "Selector.h"


FDeleteStatement::FDeleteStatement(const FString& TableName)
{
	this->TableName = TableName;
}


FString FDeleteStatement::Formulate(FSelector Selector) const
{
	FString DeleteStatement = FString::Printf(TEXT("DELETE FROM \"%s\""), *TableName);
	DeleteStatement.Appendf(TEXT(" WHERE %s"), *Selector.GetWhereClause());
	return DeleteStatement;
}