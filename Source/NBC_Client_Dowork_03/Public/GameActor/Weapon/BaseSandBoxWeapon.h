#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseSandBoxWeapon.generated.h"

UCLASS()
class NBC_CLIENT_DOWORK_03_API ABaseSandBoxWeapon : public AActor
{
	GENERATED_BODY()

public:
	
	ABaseSandBoxWeapon();

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;
};
