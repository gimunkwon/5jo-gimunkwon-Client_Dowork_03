#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBaseWeapon.generated.h"

UCLASS()
class NBC_CLIENT_DOWORK_03_API AMyBaseWeapon : public AActor
{
	GENERATED_BODY()

public:
	AMyBaseWeapon();
	
	FORCEINLINE USkeletalMeshComponent* GetWeaponMesh() const {return SkeletalMeshComponent;}
	FORCEINLINE const FDataTableRowHandle& GetWeaponStatRowHandle() const {return RowHandle;}
	
	float BaseCoilPitch;
	float RemainCoilPitch;
	float RecoilSpeed;
	
	void InitializeWeaponStat();
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Mesh")
	TObjectPtr<USceneComponent> SceneComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Mesh")
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DataTable")
	FDataTableRowHandle RowHandle;

public:
	virtual void Tick(float DeltaTime) override;
};
