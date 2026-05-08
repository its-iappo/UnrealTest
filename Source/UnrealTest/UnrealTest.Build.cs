// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealTest : ModuleRules
{
	public UnrealTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"UnrealTest",
			"UnrealTest/Variant_Platforming",
			"UnrealTest/Variant_Platforming/Animation",
			"UnrealTest/Variant_Combat",
			"UnrealTest/Variant_Combat/AI",
			"UnrealTest/Variant_Combat/Animation",
			"UnrealTest/Variant_Combat/Gameplay",
			"UnrealTest/Variant_Combat/Interfaces",
			"UnrealTest/Variant_Combat/UI",
			"UnrealTest/Variant_SideScrolling",
			"UnrealTest/Variant_SideScrolling/AI",
			"UnrealTest/Variant_SideScrolling/Gameplay",
			"UnrealTest/Variant_SideScrolling/Interfaces",
			"UnrealTest/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
