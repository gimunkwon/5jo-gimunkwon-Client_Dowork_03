#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

class AMyBaseWeapon;
struct FInputActionValue;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class NBC_CLIENT_DOWORK_03_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AMyPlayer();
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera")
	TObjectPtr<UCameraComponent> CameraComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Mesh")
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Weapon")
	TSubclassOf<AActor> WeaponClass;
	UPROPERTY()
	TObjectPtr<AMyBaseWeapon> WeaponInst;
	
	void EquipWeapon();
	void Move(const FInputActionValue& Value);
	void Rotate(const FInputActionValue& Value);
	void Attack();
	void AddGunRecoil();
private:
	float RemainRecoilPitch;
	float RecoilSpeed;
public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
