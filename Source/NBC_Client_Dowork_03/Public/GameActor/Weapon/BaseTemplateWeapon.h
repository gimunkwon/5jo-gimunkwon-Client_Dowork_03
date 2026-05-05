#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTemplateWeapon.generated.h"

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
public:
	virtual void Tick(float DeltaTime) override;
};
