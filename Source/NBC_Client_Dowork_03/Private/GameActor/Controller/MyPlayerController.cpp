#include "NBC_Client_Dowork_03/Public/GameActor/Controller/MyPlayerController.h"
#include "EnhancedInputSubsystems.h"

AMyPlayerController::AMyPlayerController()
{
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(GetLocalPlayer()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			SubSystem->AddMappingContext(IMC_Default,0);
		}
	}
}
