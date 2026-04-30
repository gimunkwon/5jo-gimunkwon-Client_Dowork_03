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
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Mesh")
	TObjectPtr<USceneComponent> SceneComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Mesh")
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
public:
	virtual void Tick(float DeltaTime) override;
};
