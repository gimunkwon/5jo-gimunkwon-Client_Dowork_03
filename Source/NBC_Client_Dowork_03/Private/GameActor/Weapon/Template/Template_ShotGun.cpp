#include "GameActor/Weapon/Template/Template_ShotGun.h"



ATemplate_ShotGun::ATemplate_ShotGun()
{
	PrimaryActorTick.bCanEverTick = true;
}


void ATemplate_ShotGun::BeginPlay()
{
	Super::BeginPlay();
}


void ATemplate_ShotGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

