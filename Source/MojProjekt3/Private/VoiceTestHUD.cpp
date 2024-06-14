// Fill out your copyright notice in the Description page of Project Settings.


#include "VoiceTestHUD.h"
#include "Blueprint/UserWidget.h"
#include "VoiceComponentUI.h"

void AVoiceTestHUD::BeginPlay()
{
	Super::BeginPlay();
	UWorld* World = GetWorld();
	if (!World) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!PlayerController) return;
	VoiceWidget = CreateWidget<UVoiceComponentUI>(PlayerController, VoiceWidgetClass);
	if (VoiceWidget) {
		VoiceWidget->AddToViewport();
		VoiceWidget->SetVisibility(ESlateVisibility::Visible);
	}
}
