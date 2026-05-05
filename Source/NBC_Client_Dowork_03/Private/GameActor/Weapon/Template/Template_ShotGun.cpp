#include "GameActor/Weapon/Template/Template_ShotGun.h"

#include "DataTable/DT_Weapon.h"


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

void ATemplate_ShotGun::InitializeWeaponStat()
{
	Super::InitializeWeaponStat();
	
	const static FString ContextString = "InitializeWeaponStat";
	if (FMyWeapon* WeaponStats = BaseWeaponStatRowHandle.GetRow<FMyWeapon>(ContextString))
	{
		WeaponStat.CurrentAmmo = WeaponStats->AmmoInClip;
		WeaponStat.MaxAmmo = WeaponStats->MaxAmmo;
		WeaponStat.FireRate = WeaponStats->FireRate;
		WeaponStats->MaxDistance = WeaponStats->MaxDistance;
		WeaponStat.Damage = WeaponStats->AttackDamage;
	}
}

void ATemplate_ShotGun::Fire(APlayerCameraManager* CameraManager)
{
	
	
	Super::Fire(CameraManager);
}

void ATemplate_ShotGun::Reload()
{
	Super::Reload();
}

void ATemplate_ShotGun::AddGunRecoil()
{
	Super::AddGunRecoil();
}


