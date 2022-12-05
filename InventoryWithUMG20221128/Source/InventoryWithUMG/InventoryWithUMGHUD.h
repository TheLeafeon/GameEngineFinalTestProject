// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InventoryWithUMGHUD.generated.h"

UCLASS()
class AInventoryWithUMGHUD : public AHUD
{
	GENERATED_BODY()

public:
	AInventoryWithUMGHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	UPROPERTY(BlueprintReadWrite)
		bool ShowCrosshairs;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;


	

};

