#pragma once

#include "CoreMinimal.h"


template <typename SelectedType>
class UNREALIZE_API TSelector
{
public:
	TSelector();

	TSelector<SelectedType> Where(TArray<TTuple<FString, FString>> Conditions);
};