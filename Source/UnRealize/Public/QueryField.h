#pragma once

namespace pqxx
{
	class field;
}

struct FQueryField
{
	static FQueryField FromPqxxField(const pqxx::field& Field);
	
	FString TableName;

	FString ColumnName;

	TSharedPtr<void> Value;
};
