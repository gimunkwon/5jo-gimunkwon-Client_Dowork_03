#include "GameActor/Weapon/BaseSandBoxWeapon.h"



ABaseSandBoxWeapon::ABaseSandBoxWeapon()
{
	
	PrimaryActorTick.bCanEverTick = true;
}


void ABaseSandBoxWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}


void ABaseSandBoxWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

