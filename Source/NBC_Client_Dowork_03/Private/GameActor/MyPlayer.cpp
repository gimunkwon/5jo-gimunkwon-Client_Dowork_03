#include "NBC_Client_Dowork_03/Public/GameActor/MyPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "NBC_Client_Dowork_03/Public/GameActor/Weapon/MyBaseWeapon.h"


AMyPlayer::AMyPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(RootComponent);
	CameraComp->bUsePawnControlRotation = true;
}


void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	EquipWeapon();
}


void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMyPlayer::EquipWeapon()
{
	if (WeaponClass)
	{
		if (AMyBaseWeapon* Weapon = GetWorld()->SpawnActor<AMyBaseWeapon>(WeaponClass,GetActorLocation(),FRotator::ZeroRotator))
		{
			UE_LOG(LogTemp,Warning,TEXT("무기 초기화중..."));
			FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget,true);
			Weapon->GetWeaponMesh()->AttachToComponent(GetMesh(),AttachmentRules,TEXT("GunSocket"));
		}
	}
}