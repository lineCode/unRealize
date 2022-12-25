#include "StructUtility.h"

#include "PropertyUtility.h"


TMap<UStruct*, TMap<FString, FProperty*>> FStructUtility::PersistedNameCache = TMap<UStruct*, TMap<FString, FProperty*>>();


FString FStructUtility::GetPersistedName(const UStruct* Struct)
{
	if(Struct->HasMetaData(TEXT("PersistAs")))
	{
		return Struct->GetMetaData(TEXT("PersistAs"));
	}
	return Struct->GetName();
}


bool FStructUtility::Check(UStruct* Struct, const TArray<FString>& CheckValues)
{
	CacheStruct(Struct);
	for(const FString& Value : CheckValues)
	{
		if(PersistedNameCache.Find(Struct)->Find(Value) == nullptr)
		{
			return false;
		}
	}
	return true;
}


void FStructUtility::CacheStruct(UStruct* Struct)
{
	if(PersistedNameCache.Contains(Struct))
	{
		return;
	}
	TMap<FString, FProperty*> PropertyMap;
	for(TFieldIterator<FProperty> PropertyIterator(Struct); PropertyIterator; ++PropertyIterator)
	{
		FProperty* Property = *PropertyIterator;
		PropertyMap.Add(FPropertyUtility::GetPersistedName(Property), Property);
	}
	PersistedNameCache.Add(Struct, PropertyMap);
}