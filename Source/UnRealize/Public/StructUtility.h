#pragma once

struct UNREALIZE_API FStructUtility
{
	static FString GetPersistedName(const UStruct* Struct);

	static bool Check(UStruct* Struct, const TArray<FString>& CheckValues);

private:
	static void CacheStruct(UStruct* Struct);
	
	static TMap<UStruct*, TMap<FString, FProperty*>> PersistedNameCache;
};