#include "SqlProperty.h"


FSqlProperty::FSqlProperty(const FProperty* Property, const void* Struct)
{
	if (Property->GetClass()->IsChildOf(FStrProperty::StaticClass()))
	{
		PropertyType = Varchar;
		SqlLiteral = FString::Printf(TEXT("'%s'"), **Property->ContainerPtrToValuePtr<FString>(Struct));
	}
	else if (Property->GetClass()->IsChildOf(FBoolProperty::StaticClass()))
	{
		PropertyType = Bool;
		SqlLiteral = *Property->ContainerPtrToValuePtr<bool>(Struct) ? TEXT("TRUE") : TEXT("FALSE");
	}
	else if (Property->GetClass()->IsChildOf(FNumericProperty::StaticClass()))
	{
		PropertyType = Numeric;
		if(Property->GetClass()->IsChildOf(FIntProperty::StaticClass()))
		{
			SqlLiteral = FString::Printf(TEXT("%d"), *Property->ContainerPtrToValuePtr<int32>(Struct));
		}
	}
	else if (Property->GetClass()->IsChildOf(FStructProperty::StaticClass()))
	{
		const UScriptStruct* InnerStructType = CastField<FStructProperty>(Property)->Struct;
		for(TFieldIterator<FProperty> PropertyIterator(InnerStructType); PropertyIterator; ++PropertyIterator)
		{
			const FProperty* InnerProperty = *PropertyIterator;
			if(InnerProperty->HasMetaData(TEXT("PersistAsPrimaryKey")))
			{
				// TODO
			}
		}
	}
}


FString FSqlProperty::GetSqlLiteral() const
{
	return SqlLiteral;
}