using Internal;
using UnrealBuildTool;


public class Libpqxx : ModuleRules
{
	public Libpqxx(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		Type = ModuleType.External;

		PublicIncludePaths.Add(ModuleDirectory);

		PublicDependencyModuleNames.Add("OpenSSL");
		
		string LibPath = System.IO.Path.Combine(ModuleDirectory, Target.Platform.ToString());

		if (Target.Platform == UnrealTargetPlatform.Linux)
		{
		}
		else if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicAdditionalLibraries.Add(System.IO.Path.Combine(LibPath, "libpgcommon.lib"));
			PublicAdditionalLibraries.Add(System.IO.Path.Combine(LibPath, "libpgport.lib"));
			PublicAdditionalLibraries.Add(System.IO.Path.Combine(LibPath, "libpq.lib"));
			PublicAdditionalLibraries.Add(System.IO.Path.Combine(LibPath, "libpqxx_static.lib"));
		}
	}
}