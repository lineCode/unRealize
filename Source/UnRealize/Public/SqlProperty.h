#pragma once

enum ESqlPropertyType
{
	Varchar,
	Bool,
	Numeric,
	None,
};


struct UNREALIZE_API FSqlProperty
{
public:
	static FSqlProperty FromProperty(const FProperty* Property, const void* Struct);

	explicit FSqlProperty(const FString& StringValue);
	
	explicit FSqlProperty(const bool& BooleanValue);

	explicit FSqlProperty(const int16& IntValue);

	explicit FSqlProperty(const int32& IntValue);

	explicit FSqlProperty(const int64& IntValue);

	explicit FSqlProperty(const float& FloatValue);

	explicit FSqlProperty(const double& DoubleValue);

	FString GetSqlLiteral() const;

private:
	FSqlProperty();
	
	ESqlPropertyType PropertyType;
	
	FString SqlLiteral;
};