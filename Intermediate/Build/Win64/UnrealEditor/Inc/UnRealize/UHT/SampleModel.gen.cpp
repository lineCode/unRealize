// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnRealize/Test/SampleModel.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSampleModel() {}
// Cross Module References
	UNREALIZE_API UScriptStruct* Z_Construct_UScriptStruct_FSampleEntityWithAllTypes();
	UNREALIZE_API UScriptStruct* Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs();
	UPackage* Z_Construct_UPackage__Script_UnRealize();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypes;
class UScriptStruct* FSampleEntityWithAllTypes::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypes.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypes.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes, Z_Construct_UPackage__Script_UnRealize(), TEXT("SampleEntityWithAllTypes"));
	}
	return Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypes.OuterSingleton;
}
template<> UNREALIZE_API UScriptStruct* StaticStruct<FSampleEntityWithAllTypes>()
{
	return FSampleEntityWithAllTypes::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Id;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleBoolean_MetaData[];
#endif
		static void NewProp_SampleBoolean_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_SampleBoolean;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleSmallInt_MetaData[];
#endif
		static const UECodeGen_Private::FInt16PropertyParams NewProp_SampleSmallInt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleInteger_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_SampleInteger;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleLong_MetaData[];
#endif
		static const UECodeGen_Private::FInt64PropertyParams NewProp_SampleLong;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleFloat_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SampleFloat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleDouble_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_SampleDouble;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSampleEntityWithAllTypes>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_Id_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
		{ "PrimaryKey", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSampleEntityWithAllTypes, Id), METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_Id_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_Id_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleBoolean_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleBoolean_SetBit(void* Obj)
	{
		((FSampleEntityWithAllTypes*)Obj)->SampleBoolean = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleBoolean = { "SampleBoolean", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FSampleEntityWithAllTypes), &Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleBoolean_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleBoolean_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleBoolean_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleSmallInt_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	const UECodeGen_Private::FInt16PropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleSmallInt = { "SampleSmallInt", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int16, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSampleEntityWithAllTypes, SampleSmallInt), METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleSmallInt_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleSmallInt_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleInteger_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleInteger = { "SampleInteger", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSampleEntityWithAllTypes, SampleInteger), METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleInteger_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleInteger_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleLong_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleLong = { "SampleLong", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSampleEntityWithAllTypes, SampleLong), METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleLong_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleLong_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleFloat_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleFloat = { "SampleFloat", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSampleEntityWithAllTypes, SampleFloat), METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleFloat_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleFloat_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleDouble_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleDouble = { "SampleDouble", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSampleEntityWithAllTypes, SampleDouble), METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleDouble_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleDouble_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_Id,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleBoolean,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleSmallInt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleInteger,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleLong,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleFloat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewProp_SampleDouble,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_UnRealize,
		nullptr,
		&NewStructOps,
		"SampleEntityWithAllTypes",
		sizeof(FSampleEntityWithAllTypes),
		alignof(FSampleEntityWithAllTypes),
		Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSampleEntityWithAllTypes()
	{
		if (!Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypes.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypes.InnerSingleton, Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypes.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypesPersistAs;
class UScriptStruct* FSampleEntityWithAllTypesPersistAs::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypesPersistAs.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypesPersistAs.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs, Z_Construct_UPackage__Script_UnRealize(), TEXT("SampleEntityWithAllTypesPersistAs"));
	}
	return Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypesPersistAs.OuterSingleton;
}
template<> UNREALIZE_API UScriptStruct* StaticStruct<FSampleEntityWithAllTypesPersistAs>()
{
	return FSampleEntityWithAllTypesPersistAs::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Id;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleBoolean_MetaData[];
#endif
		static void NewProp_SampleBoolean_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_SampleBoolean;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleSmallInt_MetaData[];
#endif
		static const UECodeGen_Private::FInt16PropertyParams NewProp_SampleSmallInt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleInteger_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_SampleInteger;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleLong_MetaData[];
#endif
		static const UECodeGen_Private::FInt64PropertyParams NewProp_SampleLong;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleFloat_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SampleFloat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleDouble_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_SampleDouble;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
		{ "PersistAs", "SampleEntityWithAllTypes" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSampleEntityWithAllTypesPersistAs>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_Id_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
		{ "PrimaryKey", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSampleEntityWithAllTypesPersistAs, Id), METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_Id_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_Id_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleBoolean_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleBoolean_SetBit(void* Obj)
	{
		((FSampleEntityWithAllTypesPersistAs*)Obj)->SampleBoolean = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleBoolean = { "SampleBoolean", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FSampleEntityWithAllTypesPersistAs), &Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleBoolean_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleBoolean_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleBoolean_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleSmallInt_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	const UECodeGen_Private::FInt16PropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleSmallInt = { "SampleSmallInt", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int16, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSampleEntityWithAllTypesPersistAs, SampleSmallInt), METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleSmallInt_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleSmallInt_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleInteger_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleInteger = { "SampleInteger", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSampleEntityWithAllTypesPersistAs, SampleInteger), METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleInteger_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleInteger_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleLong_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleLong = { "SampleLong", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSampleEntityWithAllTypesPersistAs, SampleLong), METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleLong_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleLong_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleFloat_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleFloat = { "SampleFloat", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSampleEntityWithAllTypesPersistAs, SampleFloat), METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleFloat_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleFloat_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleDouble_MetaData[] = {
		{ "ModuleRelativePath", "Test/SampleModel.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleDouble = { "SampleDouble", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSampleEntityWithAllTypesPersistAs, SampleDouble), METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleDouble_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleDouble_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_Id,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleBoolean,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleSmallInt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleInteger,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleLong,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleFloat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewProp_SampleDouble,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_UnRealize,
		nullptr,
		&NewStructOps,
		"SampleEntityWithAllTypesPersistAs",
		sizeof(FSampleEntityWithAllTypesPersistAs),
		alignof(FSampleEntityWithAllTypesPersistAs),
		Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs()
	{
		if (!Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypesPersistAs.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypesPersistAs.InnerSingleton, Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypesPersistAs.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_PandoraAeternitas_Projects_Emilia_Emilia_Plugins_unRealize_Source_UnRealize_Test_SampleModel_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PandoraAeternitas_Projects_Emilia_Emilia_Plugins_unRealize_Source_UnRealize_Test_SampleModel_h_Statics::ScriptStructInfo[] = {
		{ FSampleEntityWithAllTypes::StaticStruct, Z_Construct_UScriptStruct_FSampleEntityWithAllTypes_Statics::NewStructOps, TEXT("SampleEntityWithAllTypes"), &Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypes, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSampleEntityWithAllTypes), 1042251272U) },
		{ FSampleEntityWithAllTypesPersistAs::StaticStruct, Z_Construct_UScriptStruct_FSampleEntityWithAllTypesPersistAs_Statics::NewStructOps, TEXT("SampleEntityWithAllTypesPersistAs"), &Z_Registration_Info_UScriptStruct_SampleEntityWithAllTypesPersistAs, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSampleEntityWithAllTypesPersistAs), 1146864615U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PandoraAeternitas_Projects_Emilia_Emilia_Plugins_unRealize_Source_UnRealize_Test_SampleModel_h_4153583035(TEXT("/Script/UnRealize"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_PandoraAeternitas_Projects_Emilia_Emilia_Plugins_unRealize_Source_UnRealize_Test_SampleModel_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PandoraAeternitas_Projects_Emilia_Emilia_Plugins_unRealize_Source_UnRealize_Test_SampleModel_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
