#include "UnRealizeModule.h"

#include "UnRealize.h"


#define LOCTEXT_NAMESPACE "FUnRealizeModule"


DEFINE_LOG_CATEGORY(LogUnRealize);


void FUnRealizeModule::StartupModule()
{
	FUnRealize::Initialize();
}


void FUnRealizeModule::ShutdownModule()
{
}


#undef LOCTEXT_NAMESPACE


IMPLEMENT_MODULE(FUnRealizeModule, UnRealize)