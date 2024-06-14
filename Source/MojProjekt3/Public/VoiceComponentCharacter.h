// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VoiceComponentCharacter.generated.h"

UCLASS()
class MOJPROJEKT3_API AVoiceComponentCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AVoiceComponentCharacter();

protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void TryGetWidget();
	UPROPERTY(BlueprintReadOnly)
	class UVoiceComponentUI* VoiceWidget;
public:	


};
