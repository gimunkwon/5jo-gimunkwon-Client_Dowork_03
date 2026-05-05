#include "GameActor/Weapon/BaseSandBoxWeapon.h"



ABaseSandBoxWeapon::ABaseSandBoxWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComp;

	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SkeletalMeshComp->SetupAttachment(RootComponent);
}


void ABaseSandBoxWeapon::BeginPlay()
{
	Super::BeginPlay();
}


void ABaseSandBoxWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

