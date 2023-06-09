// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VRHelper : ModuleRules
{
	public VRHelper(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				"Components/VRHSelect.h",
                "Components/VRHGrab.h",
                "Components/VRHBaseComponent.h",
                "Components/VRHCharacterMovementComponent.h",
				"Character/VRHDesktopCharacter.h",
                "Character/VRHBaseCharacter.h",
                "Components/VRHWeaponComponent.h",
				"Animation/VRHAnimNotify.h",
				"TimerManager.h",
            }
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "EnhancedInput",
				"UMG",
				"VR",
				"Engine"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
