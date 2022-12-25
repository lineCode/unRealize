#pragma once

#include "CoreMinimal.h"
#include "DeleteStatement.h"
#include "PropertyUtility.h"
#include "QueryField.h"
#include "QueryRow.h"
#include "QueryResult.h"
#include "ReadStatement.h"
#include "Selector.h"
#include "StructUtility.h"
#include "UnRealizeModule.h"
#include "UpdateStatement.h"
#include "UObject/Class.h"
#include "UnRealize/Private/DatabaseAdapter.h"


class UNREALIZE_API FUnRealize
{
public:
	static void Initialize();

	static TSharedPtr<FUnRealize> Get();

	void Persist(const UStruct* StructType, const void* Struct) const;
	
	template<typename SelectedType>
	FORCEINLINE TArray<SelectedType> FindMany(const UStruct* StructType, const FSelector& Selector = FSelector()) const
	{
		const FString PersistedAs = FStructUtility::GetPersistedName(StructType);
		const FReadStatement Statement(PersistedAs);

		const FQueryResult Result = Adapter->Query(Statement.Formulate(Selector));
		TArray<SelectedType> QueryResult;
		for(const FQueryRow& Row : Result.Rows)
		{
			SelectedType Object;
			for(const FQueryField& Field : Row.Fields)
			{
				const FProperty* Property = FPropertyUtility::FindPropertyByPersistedName(StructType, Field.ColumnName);
				if(Property != nullptr)
				{
					Property->SetValue_InContainer(&Object, Field.Value.Get());
				}
			}
		
			QueryResult.Add(Object);
		}
		
		return QueryResult;
	}

	template<typename SelectedType>
	FORCEINLINE SelectedType FindUnique(const UStruct* StructType, const FSelector& Selector) const
	{
		unimplemented();
		return SelectedType();
	}

	template<typename SelectedType>
	FORCEINLINE SelectedType FindFirst()
	{
		unimplemented();
		return SelectedType();
	}

	template<typename SelectedType>
	FORCEINLINE void Update(const UStruct* StructType, const void* Struct) const
	{
		const FString PersistedAs = FStructUtility::GetPersistedName(StructType);
		const FProperty* PrimaryKey = FPropertyUtility::FindPrimaryKeyProperty(StructType);
		if(PrimaryKey == nullptr)
		{
			LOG_ERROR_PRINTF(LogUnRealize, "No primary key defined for %s. Please add a meta = (PrimaryKey) specifier to one of the struct's properties.", *PersistedAs);
		}
		FUpdateStatement Statement(PersistedAs);
		FSelector Selector;
		Selector.Where(FSqlCondition::Equals(FPropertyUtility::GetPersistedName(PrimaryKey), FSqlProperty::FromProperty(PrimaryKey, Struct)));

		Adapter->ExecuteStatement(Statement.Formulate(Selector));
	}

	template<typename SelectedType>
	FORCEINLINE void Delete(const UStruct* StructType, const SelectedType* Struct) const
	{
		const FProperty* PrimaryKey = FPropertyUtility::FindPrimaryKeyProperty(StructType);
		FSelector Selector;
		Selector.Where(FSqlCondition::Equals(FPropertyUtility::GetPersistedName(PrimaryKey), FSqlProperty::FromProperty(PrimaryKey, Struct)));

		Delete<SelectedType>(StructType, Selector);
	}

	/**
	 * Deletes all database entries of the given type that match the Selector
	 */
	template<typename SelectedType>
	FORCEINLINE void Delete(const UStruct* StructType, const FSelector& Selector) const
	{
		const FString PersistedAs = FStructUtility::GetPersistedName(StructType);
		const FDeleteStatement Statement(PersistedAs);

		Adapter->ExecuteStatement(Statement.Formulate(Selector));
	}

protected:
	bool LoadConfiguration();
	
private:
	static TSharedPtr<FUnRealize> UnRealize;

	TSharedPtr<FDatabaseAdapter> Adapter;
};