// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VoiceComponentUI.generated.h"

/**
 * 
 */
UCLASS()
class MOJPROJEKT3_API UVoiceComponentUI : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly,meta = (BindWidget))
	class UButton* PlayButton;
	UPROPERTY(BlueprintReadOnly,meta = (BindWidget))
	class USlider* PitchSlider;
	UPROPERTY(BlueprintReadOnly,meta = (BindWidget))
	 USlider* VolumeSlider;
	
};
