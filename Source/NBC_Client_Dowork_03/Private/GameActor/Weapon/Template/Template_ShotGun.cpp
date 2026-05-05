#include "GameActor/Weapon/Template/Template_ShotGun.h"

#include "DataTable/DT_Weapon.h"


ATemplate_ShotGun::ATemplate_ShotGun()
	: ShotGunStat()
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
		ShotGunStat.CurrentAmmo = WeaponStats->AmmoInClip;
		ShotGunStat.MaxAmmo = WeaponStats->MaxAmmo;
		ShotGunStat.FireRate = WeaponStats->FireRate;
		ShotGunStat.MaxDistance = WeaponStats->MaxDistance;
		ShotGunStat.Damage = WeaponStats->AttackDamage;
		ShotGunStat.PalletCount = WeaponStats->PalletCount;
		ShotGunStat.SpreadAngle = WeaponStats->SpreadAngle;
		ShotGunStat.RemainCoilPitch = WeaponStats->RemainRecoilPitch;
		ShotGunStat.RecoilSpeed = WeaponStats->RecoilSpeed;
	}
}

void ATemplate_ShotGun::Fire(APlayerCameraManager* CameraManager)
{
	FVector Start = SkeletalMeshComp->GetSocketLocation(TEXT("Muzzle"));
	FVector LaunchDir;
	if (CameraManager)
	{
		LaunchDir = CameraManager->GetCameraRotation().Vector();
	}
	
	
	for (int32 i = 0; i < ShotGunStat.PalletCount; i++)
	{
		FVector RandomDir = FMath::VRandCone(LaunchDir,FMath::DegreesToRadians(ShotGunStat.SpreadAngle));
		FVector EndPos = Start + (RandomDir * ShotGunStat.MaxDistance);
		
		TArray<FHitResult> HitResulits;
		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);
		
		bool bHit = GetWorld()->LineTraceMultiByChannel(HitResulits,Start,EndPos,ECC_Visibility);
		
		DrawDebugLine(GetWorld(),Start,EndPos,FColor::Red,false, 1.f,0,1.f);
		
		if (bHit)
		{
			for (const auto& Hit : HitResulits)
			{
				UE_LOG(LogTemp,Warning,TEXT("Hit Actor : %s"),*Hit.GetActor()->GetName());
			}
		}
	}
	
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


