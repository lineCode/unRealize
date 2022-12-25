#pragma once

#include "SampleModel.generated.h"


USTRUCT()
struct FSampleEntityWithAllTypes
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (PrimaryKey))
	FString Id;

	UPROPERTY()
	bool SampleBoolean;

	UPROPERTY()
	int16 SampleSmallInt;

	UPROPERTY()
	int32 SampleInteger;

	UPROPERTY()
	int64 SampleLong;

	UPROPERTY()
	float SampleFloat;

	UPROPERTY()
	double SampleDouble;
};


USTRUCT(meta = (PersistAs = "SampleEntityWithAllTypes"))
struct FSampleEntityWithAllTypesPersistAs
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (PrimaryKey))
	FString Id;

	UPROPERTY()
	bool SampleBoolean;

	UPROPERTY()
	int16 SampleSmallInt;

	UPROPERTY()
	int32 SampleInteger;

	UPROPERTY()
	int64 SampleLong;

	UPROPERTY()
	float SampleFloat;

	UPROPERTY()
	double SampleDouble;
};