#pragma once

#include "CoreMinimal.h"
#include "GameActor/Weapon/BaseTemplateWeapon.h"
#include "Template_ShotGun.generated.h"

UCLASS()
class NBC_CLIENT_DOWORK_03_API ATemplate_ShotGun : public ABaseTemplateWeapon
{
	GENERATED_BODY()

public:
	ATemplate_ShotGun();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
};
