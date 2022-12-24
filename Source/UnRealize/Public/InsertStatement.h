#pragma once


struct UNREALIZE_API FInsertStatement
{
public:
	explicit FInsertStatement(const FString& TableName);
	
	FString Formulate() const;

	void AddValue(const FString& Name, const struct FSqlProperty& Value);

private:
	FString TableName;
	
	TArray<TTuple<FString, FSqlProperty>> Values;
};
