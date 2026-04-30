#pragma once

#include "CoreMinimal.h"
#include "DT_Weapon.generated.h"

USTRUCT(BlueprintType)
struct FMyWeapon : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="WeaponStat")
	FName WeaponName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="WeaponStat")
	float MaxDistance;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="WeaponStat")
	int32 PalletCount;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="WeaponStat")
	float SpreadAngle;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="WeaponStat")
	float RemainRecoilPitch;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="WeaponStat")
	float RecoilSpeed;
};
