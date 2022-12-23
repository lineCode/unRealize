#include "Selector.h"


template <typename SelectedType>
TSelector<SelectedType>::TSelector()
{
}


template <typename SelectedType>
TSelector<SelectedType> TSelector<SelectedType>::Where(TArray<TTuple<FString, FString>> Conditions)
{
	return this;
}