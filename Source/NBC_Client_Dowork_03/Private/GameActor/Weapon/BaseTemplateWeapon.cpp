#include "GameActor/Weapon/BaseTemplateWeapon.h"



ABaseTemplateWeapon::ABaseTemplateWeapon()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComp;
	
	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SkeletalMeshComp->SetupAttachment(RootComponent);
}


void ABaseTemplateWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	InitializeWeaponStat();
}

void ABaseTemplateWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseTemplateWeapon::InitializeWeaponStat()
{
	UE_LOG(LogTemp,Warning,TEXT("InitializeWeaponStat"));
}

void ABaseTemplateWeapon::Fire()
{
	UE_LOG(LogTemp,Warning,TEXT("Fire!!"));
}

void ABaseTemplateWeapon::Reload()
{
	UE_LOG(LogTemp,Warning,TEXT("Reload!!"));
}



