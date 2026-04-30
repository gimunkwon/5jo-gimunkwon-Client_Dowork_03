#include "NBC_Client_Dowork_03/Public/GameActor/MyPlayer.h"

#include "Camera/CameraComponent.h"
#include "NBC_Client_Dowork_03/Public/GameActor/Weapon/MyBaseWeapon.h"
#include "EnhancedInputComponent.h"
#include "NBC_Client_Dowork_03/Public/GameActor/Controller/MyPlayerController.h"


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
	if (UEnhancedInputComponent* EnhancedInputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AMyPlayerController* PC = Cast<AMyPlayerController>(GetController()))
		{
			if (PC->IA_Move) EnhancedInputComp->BindAction(PC->IA_Move,ETriggerEvent::Triggered,this,&AMyPlayer::Move);
			if (PC->IA_Rotate) EnhancedInputComp->BindAction(PC->IA_Rotate,ETriggerEvent::Triggered,this,&AMyPlayer::Rotate);
			if (PC->IA_Attack) EnhancedInputComp->BindAction(PC->IA_Attack,ETriggerEvent::Started,this,&AMyPlayer::Attack);
		}
	}
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

void AMyPlayer::Move(const FInputActionValue& Value)
{
	UE_LOG(LogTemp,Warning,TEXT("Move On!!"));
}

void AMyPlayer::Rotate(const FInputActionValue& Value)
{
	UE_LOG(LogTemp,Warning,TEXT("Rotate On!!"));
}

void AMyPlayer::Attack()
{
	UE_LOG(LogTemp,Warning,TEXT("Attack On!!"));
}
