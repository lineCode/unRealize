#include "SqlProperty.h"

#include "PropertyUtility.h"
#include "LogMacros/LogMacros.h"


FSqlProperty FSqlProperty::FromProperty(const FProperty* Property, const void* Struct)
{
	if (Property->GetClass()->IsChildOf(FStrProperty::StaticClass()))
	{
		return FSqlProperty(*Property->ContainerPtrToValuePtr<FString>(Struct));
	}
	if (Property->GetClass()->IsChildOf(FBoolProperty::StaticClass()))
	{
		return FSqlProperty(*Property->ContainerPtrToValuePtr<bool>(Struct));
	}
	if (Property->GetClass()->IsChildOf(FNumericProperty::StaticClass()))
	{
		if(Property->GetClass()->IsChildOf(FInt16Property::StaticClass()))
		{
			return FSqlProperty(*Property->ContainerPtrToValuePtr<int16>(Struct));
		}
		if(Property->GetClass()->IsChildOf(FIntProperty::StaticClass()))
		{
			return FSqlProperty(*Property->ContainerPtrToValuePtr<int32>(Struct));
		}
		if(Property->GetClass()->IsChildOf(FInt64Property::StaticClass()))
		{
			return FSqlProperty(*Property->ContainerPtrToValuePtr<int64>(Struct));
		}
		if(Property->GetClass()->IsChildOf(FFloatProperty::StaticClass()))
		{
			return FSqlProperty(*Property->ContainerPtrToValuePtr<float>(Struct));
		}
		if(Property->GetClass()->IsChildOf(FDoubleProperty::StaticClass()))
		{
			return FSqlProperty(*Property->ContainerPtrToValuePtr<double>(Struct));
		}
		checkf(false, TEXT("%s: Attempting to serialize numeric property that can't be mapped."), __CLASS_FUNCTION__)
	}
	else if (Property->GetClass()->IsChildOf(FStructProperty::StaticClass()))
	{
		const UScriptStruct* InnerStructType = CastField<FStructProperty>(Property)->Struct;
		const FProperty* PrimaryKey = FPropertyUtility::FindPrimaryKeyProperty(InnerStructType);
		return FromProperty(PrimaryKey, Property->ContainerPtrToValuePtr<void>(Struct));
	}
	unimplemented();
	return FSqlProperty();
}


FSqlProperty::FSqlProperty(const bool& BooleanValue)
{
	PropertyType = Bool;
	SqlLiteral = BooleanValue ? TEXT("TRUE") : TEXT("FALSE");
}


FSqlProperty::FSqlProperty(const int16& IntValue)
{
	PropertyType = Numeric;
	SqlLiteral = FString::Printf(TEXT("%d"), IntValue);
}


FSqlProperty::FSqlProperty(const int32& IntValue)
{
	PropertyType = Numeric;
	SqlLiteral = FString::Printf(TEXT("%d"), IntValue);
}


FSqlProperty::FSqlProperty(const int64& IntValue)
{
	PropertyType = Numeric;
	SqlLiteral = FString::Printf(TEXT("%lld"), IntValue);
}


FSqlProperty::FSqlProperty(const float& FloatValue)
{
	PropertyType = Numeric;
	SqlLiteral = FString::Printf(TEXT("%f"), FloatValue);
}


FSqlProperty::FSqlProperty(const double& DoubleValue)
{
	PropertyType = Numeric;
	SqlLiteral = FString::Printf(TEXT("%f"), DoubleValue);
}


FSqlProperty::FSqlProperty(const FString& StringValue)
{
	PropertyType = Varchar;
	SqlLiteral = FString::Printf(TEXT("'%s'"), *StringValue);
}


FString FSqlProperty::GetSqlLiteral() const
{
	return SqlLiteral;
}


FSqlProperty::FSqlProperty()
{
	PropertyType = None;
}