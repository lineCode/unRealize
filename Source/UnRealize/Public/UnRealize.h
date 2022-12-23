#pragma once

#include "CoreMinimal.h"
#include "UObject/Class.h"
#include "UnRealize/Private/DatabaseAdapter.h"


class FUnRealize
{
public:
	static void Initialize();

	static TSharedPtr<FUnRealize> Get();

	void Persist(const UStruct* StructType, const void* Struct) const;

	template<typename SelectedType>
	TArray<SelectedType> FindMany(const UStruct* StructType) const;
	
	/* void Delete(const UStruct* StructType, const void* Struct) const;

	template<typename SelectedType>
	void Delete(const UStruct* StructType, TSelector<SelectedType> Selector) const; */

	void RegisterTypes(const TArray<UStruct*> Types);

protected:
	bool LoadConfiguration();
	
private:
	static TSharedPtr<FUnRealize> UnRealize;

	TSharedPtr<FDatabaseAdapter> Adapter;
};