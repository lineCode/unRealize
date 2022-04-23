#pragma once

#include "CoreMinimal.h"


class FUnRealizeModule final : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};