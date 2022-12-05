// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class InventoryWithUMG : ModuleRules
{
	public InventoryWithUMG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
