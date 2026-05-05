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

public:
	
	virtual void Tick(float DeltaTime) override;
};
