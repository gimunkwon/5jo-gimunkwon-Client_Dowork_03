#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTemplateWeapon.generated.h"

USTRUCT()
struct FBaseTemplateWeaponStat
{
	GENERATED_BODY()
public:
	int32 CurrentAmmo;
	int32 MaxAmmo;
	float MaxDistance;
	float Damage;
	float FireRate;
	float BaseCoilPitch;
	float RemainCoilPitch;
	float RecoilSpeed;
	
	void AddGunRecoil()
	{
		UE_LOG(LogTemp,Warning,TEXT("BaseRecoil : %f"),BaseCoilPitch);
		BaseCoilPitch += RemainCoilPitch;
		UE_LOG(LogTemp,Warning,TEXT("BaseRecoil : %f | RemainColiPitch : %f"),BaseCoilPitch,RemainCoilPitch);
	}
	
	float GetRecoilStep(float DeltaTime)
	{
		float RecoilStep = FMath::FInterpTo(0.f, BaseCoilPitch, DeltaTime, RecoilSpeed);
	
		BaseCoilPitch -= RecoilStep;
	
		if (FMath::IsNearlyZero(BaseCoilPitch)) BaseCoilPitch = 0.f;
	
		return RecoilStep;
	}
};


UCLASS()
class NBC_CLIENT_DOWORK_03_API ABaseTemplateWeapon : public AActor
{
	GENERATED_BODY()

public:
	ABaseTemplateWeapon();
	
	USkeletalMeshComponent* GetWeaponMesh() const {return SkeletalMeshComp;}
	virtual float GetRecoilStep(float DeltaTime);
	virtual void InitializeWeaponStat();
	virtual void Fire(APlayerCameraManager* CameraManager);
	virtual void Reload();
	virtual void AddGunRecoil();
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh")
	TObjectPtr<USceneComponent> SceneComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh")
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DataTable")
	FDataTableRowHandle BaseWeaponStatRowHandle;
	
	FBaseTemplateWeaponStat WeaponStat;
public:
	virtual void Tick(float DeltaTime) override;
};
