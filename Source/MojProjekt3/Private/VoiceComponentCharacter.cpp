// Fill out your copyright notice in the Description page of Project Settings.


#include "VoiceComponentCharacter.h"
#include "VoiceTestHUD.h"
#include "VoiceCaptureComponent.h"
#include "VoiceComponentUI.h"
#include "Components/Button.h"
#include "Components/Slider.h"

// Sets default values
AVoiceComponentCharacter::AVoiceComponentCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVoiceComponentCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AVoiceComponentCharacter::TryGetWidget()
{
	APlayerController* MyPlayerController = Cast<APlayerController>(GetController());
	if (MyPlayerController)
	{
		AVoiceTestHUD* VoiceTestHUD = Cast<AVoiceTestHUD>(MyPlayerController->GetHUD());
		if (VoiceTestHUD)
			VoiceWidget = VoiceTestHUD->GetVoiceWidget();
	}
}


