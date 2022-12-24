#pragma once

#include "CoreMinimal.h"
#include "FQueryField.h"
#include "FQueryRow.h"
#include "QueryResult.h"
#include "ReadStatement.h"
#include "Selector.h"
#include "UObject/Class.h"
#include "UnRealize/Private/DatabaseAdapter.h"


class UNREALIZE_API FUnRealize
{
public:
	static void Initialize();

	static TSharedPtr<FUnRealize> Get();

	void Persist(const UStruct* StructType, const void* Struct) const;

	template<typename SelectedType>
	TArray<SelectedType> FindMany(const UStruct* StructType) const
	{
		FString PersistedAs = StructType->GetMetaData(TEXT("PersistAs"));
		if(PersistedAs == TEXT(""))
		{
			PersistedAs = StructType->GetName();
		}
		const FReadStatement Statement(PersistedAs);

		const FQueryResult Result = Adapter->Query(Statement.Formulate());
		TArray<SelectedType> QueryResult;
		for(const FQueryRow& Row : Result.Rows)
		{
			SelectedType Object;
			for(const FQueryField& Field : Row.Fields)
			{
				const FProperty* Property = StructType->FindPropertyByName(*Field.ColumnName);
				if(Property != nullptr)
				{
					const FString Value = Field.StringValue;
					Property->SetValue_InContainer(&Object, &Value);
				}
			}
		
			QueryResult.Add(Object);
		}
		
		return QueryResult;
	}
	
	/* void Delete(const UStruct* StructType, const void* Struct) const; */

	template<typename SelectedType>
	FORCEINLINE void Delete(const UStruct* StructType, TSelector<SelectedType> Selector) const
	{
		const FReadStatement Statement(TEXT("SOMETHING"));
		UE_LOG(LogTemp, Log, TEXT("Delete"));
	}

	void RegisterTypes(const TArray<UStruct*> Types);

protected:
	bool LoadConfiguration();
	
private:
	static TSharedPtr<FUnRealize> UnRealize;

	TSharedPtr<FDatabaseAdapter> Adapter;
};