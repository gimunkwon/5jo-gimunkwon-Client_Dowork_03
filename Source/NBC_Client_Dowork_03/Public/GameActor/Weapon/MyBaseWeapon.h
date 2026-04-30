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

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;
};
