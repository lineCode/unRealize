#pragma once

#include <string>

#include "CoreMinimal.h"


class UNREALIZE_API FStringUtility
{
public:
	static std::string ToStd(const FString& String);

	static FString FromStd(const std::string& String);
};