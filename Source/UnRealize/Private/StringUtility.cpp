#include "StringUtility.h"


std::string FStringUtility::ToStd(const FString& String)
{
	return std::string(TCHAR_TO_UTF8(*String));
}


FString FStringUtility::FromStd(const std::string& String)
{
	return FString(String.c_str());
}