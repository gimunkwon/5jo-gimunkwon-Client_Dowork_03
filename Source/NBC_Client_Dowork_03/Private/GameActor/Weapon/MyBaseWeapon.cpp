#include "NBC_Client_Dowork_03/Public/GameActor/Weapon/MyBaseWeapon.h"



AMyBaseWeapon::AMyBaseWeapon()
{
	
	PrimaryActorTick.bCanEverTick = true;
}


void AMyBaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMyBaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

