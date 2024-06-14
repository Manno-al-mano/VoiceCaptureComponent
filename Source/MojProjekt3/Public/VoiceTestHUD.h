// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "VoiceTestHUD.generated.h"

/**
 * 
 */
UCLASS()
class MOJPROJEKT3_API AVoiceTestHUD : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
private:

	class UVoiceComponentUI* VoiceWidget;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UVoiceComponentUI> VoiceWidgetClass;
public:
	FORCEINLINE UVoiceComponentUI* GetVoiceWidget() { return VoiceWidget; }
};
