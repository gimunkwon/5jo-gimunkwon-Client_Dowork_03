#pragma once

#include "CoreMinimal.h"
#include "GameActor/Weapon/BaseTemplateWeapon.h"
#include "Template_ShotGun.generated.h"

USTRUCT()
struct FTemplate_ShotGunStat : public FBaseTemplateWeaponStat
{
	GENERATED_BODY()
	
	int32 PalletCount;
	float SpreadAngle;
};

UCLASS()
class NBC_CLIENT_DOWORK_03_API ATemplate_ShotGun : public ABaseTemplateWeapon
{
	GENERATED_BODY()

public:
	ATemplate_ShotGun();
protected:
	virtual void BeginPlay() override;
	
	virtual void InitializeWeaponStat() override;
	virtual void Fire(APlayerCameraManager* CameraManager) override;
	virtual void Reload() override;
	virtual void AddGunRecoil() override;
	
	FTemplate_ShotGunStat ShotGunStat;
public:
	virtual void Tick(float DeltaTime) override;
};
