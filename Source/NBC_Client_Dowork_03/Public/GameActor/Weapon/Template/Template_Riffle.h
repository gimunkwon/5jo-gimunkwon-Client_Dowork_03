#pragma once

#include "CoreMinimal.h"
#include "GameActor/Weapon/BaseTemplateWeapon.h"
#include "Template_Riffle.generated.h"

UCLASS()
class NBC_CLIENT_DOWORK_03_API ATemplate_Riffle : public ABaseTemplateWeapon
{
	GENERATED_BODY()

public:
	ATemplate_Riffle();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
};
