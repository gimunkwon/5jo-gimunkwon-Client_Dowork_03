#include "NBC_Client_Dowork_03/Public/GameActor/MyPlayer.h"

#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "GameActor/Weapon/BaseTemplateWeapon.h"
#include "NBC_Client_Dowork_03/Public/GameActor/Controller/MyPlayerController.h"


AMyPlayer::AMyPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(RootComponent);
	CameraComp->bUsePawnControlRotation = true;
	
	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SkeletalMeshComp->SetupAttachment(CameraComp);
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	EquipWeapon();
}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	InterpRotationByReCoil(DeltaTime);
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
		WeaponInst = GetWorld()->SpawnActor<ABaseTemplateWeapon>(WeaponClass,GetActorLocation(),FRotator::ZeroRotator);
		if (WeaponInst)
		{
			UE_LOG(LogTemp,Warning,TEXT("무기 초기화중..."));
			FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget,true);
			WeaponInst->GetWeaponMesh()->AttachToComponent(SkeletalMeshComp,AttachmentRules,TEXT("GunSocket"));
			WeaponInst->InitializeWeaponStat();
		}
	}
}

void AMyPlayer::Move(const FInputActionValue& Value)
{
	// UE_LOG(LogTemp,Warning,TEXT("Move On!!"));
	FVector2D Dir = Value.Get<FVector2D>();
	
	if (!FMath::IsNearlyZero(Dir.X))
	{
		AddMovementInput(GetActorForwardVector(),Dir.X);
	}
	if (!FMath::IsNearlyZero(Dir.Y))
	{
		AddMovementInput(GetActorRightVector(),Dir.Y);
	}
	
}

void AMyPlayer::Rotate(const FInputActionValue& Value)
{
	// UE_LOG(LogTemp,Warning,TEXT("Rotate On!!"));
	FVector2D Dir = Value.Get<FVector2D>();
	if (!FMath::IsNearlyZero(Dir.X))
	{
		AddControllerPitchInput(Dir.X);
	}
	if (!FMath::IsNearlyZero(Dir.Y))
	{
		AddControllerYawInput(Dir.Y);
	}
}

void AMyPlayer::Attack()
{
	UE_LOG(LogTemp,Warning,TEXT("Attack On!!"));
	
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (PC->PlayerCameraManager)
		WeaponInst->Fire(PC->PlayerCameraManager);
	}
	
}

void AMyPlayer::InterpRotationByReCoil(float DeltaTime)
{
	AddControllerPitchInput(-WeaponInst->GetRecoilStep(DeltaTime));
}
