// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MojProjekt3 : ModuleRules
{
	public MojProjekt3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput","Voice","VoiceCapture","UMG" });
    }
}
