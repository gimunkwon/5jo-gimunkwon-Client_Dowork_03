#include "NBC_Client_Dowork_03/Public/GameActor/Enemy/BaseEnemy.h"



ABaseEnemy::ABaseEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
}


void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
}


void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ABaseEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

