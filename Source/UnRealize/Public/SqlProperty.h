#pragma once

enum ESqlPropertyType
{
	Varchar,
	Bool,
	Numeric,
};


struct UNREALIZE_API FSqlProperty
{
public:
	FSqlProperty(const FProperty* Property, const void* Struct);

	FString GetSqlLiteral() const;

private:
	ESqlPropertyType PropertyType;
	
	FString SqlLiteral;
};