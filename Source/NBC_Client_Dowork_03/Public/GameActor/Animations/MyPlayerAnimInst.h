#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyPlayerAnimInst.generated.h"

class AMyPlayer;

UCLASS()
class NBC_CLIENT_DOWORK_03_API UMyPlayerAnimInst : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
protected:
	UPROPERTY()
	TObjectPtr<AMyPlayer> MyOwnerInst;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Speed")
	float GroundSpeed;
};
