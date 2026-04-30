#include "NBC_Client_Dowork_03/Public/GameActor/MyPlayer.h"



AMyPlayer::AMyPlayer()
{
	
	PrimaryActorTick.bCanEverTick = true;
}


void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

