#include "NBC_Client_Dowork_03/Public/GameActor/MyPlayer.h"

#include "Camera/CameraComponent.h"
#include "NBC_Client_Dowork_03/Public/GameActor/Weapon/MyBaseWeapon.h"
#include "EnhancedInputComponent.h"
#include "KismetTraceUtils.h"
#include "Kismet/KismetSystemLibrary.h"
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
		WeaponInst = GetWorld()->SpawnActor<AMyBaseWeapon>(WeaponClass,GetActorLocation(),FRotator::ZeroRotator);
		if (WeaponInst)
		{
			UE_LOG(LogTemp,Warning,TEXT("무기 초기화중..."));
			FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget,true);
			WeaponInst->GetWeaponMesh()->AttachToComponent(SkeletalMeshComp,AttachmentRules,TEXT("GunSocket"));
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
	
	FVector Start = WeaponInst->GetWeaponMesh()->GetSocketLocation(TEXT("Muzzle"));
	FVector LaunchDir;
	if (AMyPlayerController* PC = Cast<AMyPlayerController>(GetController()))
	{
		LaunchDir = PC->PlayerCameraManager->GetCameraRotation().Vector();
	}
	
	//TODO::DT로 분리해서 관리
	int32 PalletCount = 10;
	float MaxDistance = 1500.f;
	float SpreadAngel = 5.f;
	
	for (int32 i = 0; i < PalletCount; i++)
	{
		FVector RandomDir = FMath::VRandCone(LaunchDir,FMath::DegreesToRadians(SpreadAngel));
		FVector EndPos = Start + (RandomDir * MaxDistance);
		
		TArray<FHitResult> HitResulits;
		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);
		
		bool bHit = GetWorld()->LineTraceMultiByChannel(HitResulits,Start,EndPos,ECC_Visibility);
		
		DrawDebugLine(GetWorld(),Start,EndPos,FColor::Red,false, 1.f,0,1.f);
		
		if (bHit)
		{
			for (const auto& Hit : HitResulits)
			{
				UE_LOG(LogTemp,Warning,TEXT("Hit Actor : %s"),*Hit.GetActor()->GetName());
			}
		}
	}
	AddGunRecoil();
}

void AMyPlayer::AddGunRecoil()
{
	UE_LOG(LogTemp,Warning,TEXT("총기 반동 로직!!"));
	
	AddControllerPitchInput(-3.f);
}
