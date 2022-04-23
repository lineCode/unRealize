#include "UnRealizeModule.h"

#include "UnRealize.h"
#include "Misc/MessageDialog.h"


#define LOCTEXT_NAMESPACE "FUnRealizeModule"


void FUnRealizeModule::StartupModule()
{
	FUnRealize::Initialize();
}


void FUnRealizeModule::ShutdownModule()
{
}


#undef LOCTEXT_NAMESPACE


IMPLEMENT_MODULE(FUnRealizeModule, UnRealize)