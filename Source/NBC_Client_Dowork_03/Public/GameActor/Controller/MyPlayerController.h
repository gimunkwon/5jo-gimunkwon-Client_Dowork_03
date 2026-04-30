#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class NBC_CLIENT_DOWORK_03_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AMyPlayerController();
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input")
	TObjectPtr<UInputMappingContext> IMC_Default;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input")
	TObjectPtr<UInputAction> IA_Move;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input")
	TObjectPtr<UInputAction> IA_Rotate;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input")
	TObjectPtr<UInputAction> IA_Attack;
};
