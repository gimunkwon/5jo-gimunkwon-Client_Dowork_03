#include "GameActor/Weapon/BaseTemplateWeapon.h"



ABaseTemplateWeapon::ABaseTemplateWeapon()
{
	
	PrimaryActorTick.bCanEverTick = true;
}


void ABaseTemplateWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}


void ABaseTemplateWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

