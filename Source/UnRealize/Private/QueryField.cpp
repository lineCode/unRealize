#include "QueryField.h"

#include "StringUtility.h"
#include "pqxx/field.hxx"


FQueryField FQueryField::FromPqxxField(const pqxx::field& Field)
{
	FQueryField QueryField;
	QueryField.TableName =  FStringUtility::FromStd(std::to_string(Field.table()));
	QueryField.ColumnName = FString(Field.name());
	if(Field.type() == 16)
	{
		QueryField.Value = MakeShareable(new bool(Field.as<bool>()));
	}
	else if(Field.type() == 21)
	{
		QueryField.Value = MakeShareable(new int16(Field.as<int16>()));
	}
	else if(Field.type() == 23)
	{
		QueryField.Value = MakeShareable(new int32(Field.as<int32>()));
	}
	else if(Field.type() == 20)
	{
		QueryField.Value = MakeShareable(new int64(Field.as<int64>()));
	}
	else if(Field.type() == 700)
	{
		QueryField.Value = MakeShareable(new float(Field.as<float>()));
	}
	else if(Field.type() == 701)
	{
		QueryField.Value = MakeShareable(new double(Field.as<double>()));
	}
	else if(Field.type() == 1043)
	{
		QueryField.Value = MakeShareable(new FString(FStringUtility::FromStd(Field.as<std::string>())));
	}
	else
	{
		QueryField.Value = MakeShareable(new FString(Field.c_str()));
	}
	return QueryField;
}
