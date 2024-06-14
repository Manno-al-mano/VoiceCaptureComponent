// Created by Marcin Piotrkowicz

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/VoiceCapture.h"
#include "Components/ActorComponent.h"
#include "VoiceCaptureComponent.generated.h"

class USoundWaveProcedural;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOICECAPTURE_API UVoiceCaptureComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVoiceCaptureComponent();
    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction);
    UFUNCTION(BlueprintCallable, Category = "AudioCapture")
    bool StartCapture();

    UFUNCTION(BlueprintCallable, Category = "AudioCapture")
    void StopCapture();

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCaptureFinishedSignature, USoundWaveProcedural*, CapturedSoundWave);

    UPROPERTY(BlueprintAssignable, Category = "AudioCapture")
    FOnCaptureFinishedSignature OnCaptureFinished;


    
   

protected:
    TArray<uint8> IncomingVoiceData;
    //TArray<uint8> VoiceData;
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    
    UPROPERTY(BlueprintReadOnly)
    bool bIsCapturing=false;
    UPROPERTY();
    USoundWaveProcedural* CapturedSoundWave;
    TSharedPtr<IVoiceCapture> VoiceCapture;
    float VoiceCaptureVolume = 0.f;
    float VoiceCaptureVolumeMult = 1.f;
    UPROPERTY(EditAnywhere);
    int32 NumChannels = 1;
    UPROPERTY(EditAnywhere);
    int32 SamplingRate = 16000;
    UPROPERTY(BlueprintReadWrite)
    float Volume = 1.f;
    UPROPERTY(BlueprintReadWrite)
    float Pitch = 1.f;
};