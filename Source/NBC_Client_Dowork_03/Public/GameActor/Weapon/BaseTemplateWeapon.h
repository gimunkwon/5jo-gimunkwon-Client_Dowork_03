#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTemplateWeapon.generated.h"

USTRUCT()
struct FBaseTemplateWeaponStat
{
	GENERATED_BODY()
	
	int32 CurrentAmmo;
	int32 MaxAmmo;
	float MaxDistance;
	float Damage;
	float FireRate;
	float BaseCoilPitch;
	float RemainCoilPitch;
	float RecoilSpeed;
};


UCLASS()
class NBC_CLIENT_DOWORK_03_API ABaseTemplateWeapon : public AActor
{
	GENERATED_BODY()

public:
	ABaseTemplateWeapon();
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh")
	TObjectPtr<USceneComponent> SceneComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh")
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DataTable")
	FDataTableRowHandle BaseWeaponStatRowHandle;
	
	FBaseTemplateWeaponStat WeaponStat;
	
	virtual void InitializeWeaponStat();
	virtual void Fire(APlayerCameraManager* CameraManager);
	virtual void Reload();
	virtual void AddGunRecoil();
public:
	virtual void Tick(float DeltaTime) override;
};
