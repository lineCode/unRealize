#pragma once

#include "CoreMinimal.h"
#include "UnRealize/Private/DatabaseAdapter.h"
#include "UObject/Class.h"


class UNREALIZE_API FUnRealize
{
public:
	static void Initialize();

	static TSharedPtr<FUnRealize> Get();

	template <typename T>
	void Persist(const T& Entity)
	{
		const UStruct* Struct = T::StaticStruct();
		const FString Statement = FString::Printf(TEXT("CREATE TABLE %s();"), *Struct->GetName());
		Adapter->ExecuteStatement(Statement);
	}

	void Persist(const UStruct* StructType, const void* Struct);

protected:
	bool LoadConfiguration();
	
private:
	static TSharedPtr<FUnRealize> UnRealize;

	TSharedPtr<FDatabaseAdapter> Adapter;
};
