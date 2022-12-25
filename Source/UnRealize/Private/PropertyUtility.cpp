#include "PropertyUtility.h"


FProperty* FPropertyUtility::FindPropertyByMetaData(const UStruct* Struct, const FString& MetaDataSpecifier)
{
	for(TFieldIterator<FProperty> PropertyIterator(Struct); PropertyIterator; ++PropertyIterator)
	{
		FProperty* Property = *PropertyIterator;
		if(Property->HasMetaData(*MetaDataSpecifier))
		{
			return Property;
		}
	}
	return nullptr;
}


FProperty* FPropertyUtility::FindPropertyByMetaData(const UStruct* Struct, const FString& MetaDataSpecifier, const FString& MetaDataSpecifierValue)
{
	for(TFieldIterator<FProperty> PropertyIterator(Struct); PropertyIterator; ++PropertyIterator)
	{
		FProperty* Property = *PropertyIterator;
		if(Property->GetMetaData(*MetaDataSpecifier) == MetaDataSpecifierValue)
		{
			return Property;
		}
	}
	return nullptr;
}


FProperty* FPropertyUtility::FindPrimaryKeyProperty(const UStruct* Struct)
{
	return FindPropertyByMetaData(Struct, TEXT("PrimaryKey"));
}


FProperty* FPropertyUtility::FindPropertyByPersistedName(const UStruct* Struct, const FString& PersistedAs)
{
	for(TFieldIterator<FProperty> PropertyIterator(Struct); PropertyIterator; ++PropertyIterator)
	{
		FProperty* Property = *PropertyIterator;
		if(GetPersistedName(Property) == PersistedAs)
		{
			return Property;
		}
	}
	return nullptr;
}


FString FPropertyUtility::GetPersistedName(const FProperty* Property)
{
	if(Property->HasMetaData(TEXT("PersistAs")))
	{
		return Property->GetMetaData(TEXT("PersistAs"));
	}
	return Property->GetName();
}
