#pragma once


struct UNREALIZE_API FPropertyUtility
{
	static FProperty* FindPropertyByMetaData(const UStruct* Struct, const FString& MetaDataSpecifier);	
	
	static FProperty* FindPropertyByMetaData(const UStruct* Struct, const FString& MetaDataSpecifier, const FString& MetaDataSpecifierValue);

	static FProperty* FindPrimaryKeyProperty(const UStruct* Struct);

	static FProperty* FindPropertyByPersistedName(const UStruct* Struct, const FString& PersistedAs);

	static FString GetPersistedName(const FProperty* Property);
};