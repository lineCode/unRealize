#pragma once

#include "CoreMinimal.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "LogMacros/LogMacros.h"


DECLARE_LOG_CATEGORY_EXTERN(LogUnRealize, Log, Verbose);


class FUnRealizeModule final : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};