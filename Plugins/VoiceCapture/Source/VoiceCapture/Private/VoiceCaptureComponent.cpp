// Created by Marcin Piotrkowicz


#include "VoiceCaptureComponent.h"
#include "Sound/SoundWaveProcedural.h"
#include "VoiceModule.h"
#include "Serialization/BulkData.h"



UVoiceCaptureComponent::UVoiceCaptureComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	bIsCapturing = false;
	CapturedSoundWave = nullptr;
	VoiceCapture = FVoiceModule::Get().CreateVoiceCapture("", SamplingRate, NumChannels);
}

void UVoiceCaptureComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!VoiceCapture.IsValid())
	{
		return;
	}
	if (!bIsCapturing) {
		return;
	}
	uint32 VoiceCaptureBytesAvailable = 0;
	IncomingVoiceData.Reset();

	if (VoiceCapture->GetCaptureState(VoiceCaptureBytesAvailable) == EVoiceCaptureState::Ok && VoiceCaptureBytesAvailable > 0)
	{
		//int16_t VoiceCaptureSample;
		uint32 VoiceCaptureReadBytes;
		//float VoiceCaptureTotalSquared = 0;

		IncomingVoiceData.SetNumUninitialized(VoiceCaptureBytesAvailable);

		VoiceCapture->GetVoiceData(IncomingVoiceData.GetData(), VoiceCaptureBytesAvailable, VoiceCaptureReadBytes);

		/*for (uint32 i = 0; i < (VoiceCaptureReadBytes / 2); i++)
		{
			VoiceCaptureSample = (IncomingVoiceData[i * 2 + 1] << 8) | IncomingVoiceData[i * 2];
			VoiceCaptureTotalSquared += ((float)VoiceCaptureSample * (float)VoiceCaptureSample);
		}

		float VoiceCaptureMeanSquare = (2 * (VoiceCaptureTotalSquared / IncomingVoiceData.Num()));
		float VoiceCaptureRms = FMath::Sqrt(VoiceCaptureMeanSquare);
		float VoiceCaptureFinalVolume = ((VoiceCaptureRms / 32768.0) * 200.f);

		VoiceCaptureVolume = VoiceCaptureFinalVolume;*/
		CapturedSoundWave->QueueAudio(IncomingVoiceData.GetData(), VoiceCaptureReadBytes);
	}



}

bool UVoiceCaptureComponent::StartCapture()
{
	
	if (bIsCapturing)
	{
		return false;
	}
	if (VoiceCapture.IsValid())
	{
		bIsCapturing = VoiceCapture->Start();
	}
	CapturedSoundWave = NewObject<USoundWaveProcedural>(USoundWaveProcedural::StaticClass());
	CapturedSoundWave->SetSampleRate(SamplingRate);
	CapturedSoundWave->NumChannels = NumChannels;
	CapturedSoundWave->Duration = INDEFINITELY_LOOPING_DURATION;
	CapturedSoundWave->SoundGroup = SOUNDGROUP_Voice;
	CapturedSoundWave->bLooping = false;
	CapturedSoundWave->bProcedural = true;
	CapturedSoundWave->Pitch = Pitch;
	CapturedSoundWave->Volume = Volume;
	return bIsCapturing;
}

void UVoiceCaptureComponent::StopCapture()
{
	if (!bIsCapturing) return;

	if (VoiceCapture.IsValid())
	{
		VoiceCapture->Stop();
	}
	bIsCapturing = false;
	OnCaptureFinished.Broadcast(CapturedSoundWave);

}



void UVoiceCaptureComponent::BeginPlay()
{
	Super::BeginPlay();


}




void UVoiceCaptureComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (bIsCapturing)
	{
		StopCapture();
	}

	Super::EndPlay(EndPlayReason);
}

