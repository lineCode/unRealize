#pragma once

#include "CoreMinimal.h"
#include "UnRealize.h"


template <typename SelectedType>
class UNREALIZE_API TSelector
{
public:
	TSelector()
	{
	}

	TArray<SelectedType> Get()
	{
		FUnRealize::Get();
		return TArray<SelectedType>();
	}
};