#include "SampleModel.h"
#include "UnRealize.h"
#include "Interfaces/IPluginManager.h"


BEGIN_DEFINE_SPEC(FUnRealizeTests, "UnRealize Tests", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
	void ExecuteStatementFromFile(const FString& FileName) const;
	void InitializeSampleModel() const;
	void CleanUpSampleModel() const;
END_DEFINE_SPEC(FUnRealizeTests)


void FUnRealizeTests::ExecuteStatementFromFile(const FString& FileName) const
{
	const FString Path = FPaths::Combine(IPluginManager::Get().FindPlugin("unRealize")->GetBaseDir(), TEXT("Source"),
	                                     TEXT("UnRealize"), TEXT("Test"), FileName);
	FString Statement;
	FFileHelper::LoadFileToString(Statement, *Path);

	// ReSharper disable once CppExpressionWithoutSideEffects
	FUnRealize::Get()->Query(Statement);
}


void FUnRealizeTests::InitializeSampleModel() const
{
	ExecuteStatementFromFile(TEXT("InitializeSampleModel.sql"));
}


void FUnRealizeTests::CleanUpSampleModel() const
{
	ExecuteStatementFromFile(TEXT("CleanUpSampleModel.sql"));
}


void FUnRealizeTests::Define()
{
	BeforeEach([this]()
	{
		InitializeSampleModel();
	});

	Describe("Simple operations without joins", [this]()
	{
		It("Saving and reading an entity, should remain equal", [this]()
		{
			FSampleEntityWithAllTypes Entity;
			Entity.Id = TEXT("b12a30da-2f05-40d6-a8a2-d62f23121b81");
			Entity.SampleBoolean = true;
			Entity.SampleSmallInt = 1024;
			Entity.SampleInteger = -8071;
			Entity.SampleLong = 12523532451;
			Entity.SampleFloat = 0.1243252;
			Entity.SampleDouble = -12353.69284;

			FUnRealize::Get()->Persist(FSampleEntityWithAllTypes::StaticStruct(), &Entity);

			const FSampleEntityWithAllTypes ReadEntity = FUnRealize::Get()->FindUnique<FSampleEntityWithAllTypes>(
				FSampleEntityWithAllTypes::StaticStruct(),
				FSelector().Where(FSqlCondition::Equals("Id", FSqlProperty(Entity.Id)))).GetValue();

			TestEqual(TEXT("String is unequal"), Entity.Id, ReadEntity.Id);
			TestEqual(TEXT("Boolean is unequal"), Entity.SampleBoolean, ReadEntity.SampleBoolean);
			TestEqual(TEXT("Int16 is unequal"), Entity.SampleSmallInt, ReadEntity.SampleSmallInt);
			TestEqual(TEXT("Int32 is unequal"), Entity.SampleInteger, ReadEntity.SampleInteger);
			TestEqual(TEXT("Int64 is unequal"), Entity.SampleLong, ReadEntity.SampleLong);
			TestEqual(TEXT("Float is unequal"), Entity.SampleFloat, ReadEntity.SampleFloat);
			TestEqual(TEXT("Double is unequal"), Entity.SampleDouble, ReadEntity.SampleDouble);
		});
	});

	AfterEach([this]()
	{
		CleanUpSampleModel();
	});
}
