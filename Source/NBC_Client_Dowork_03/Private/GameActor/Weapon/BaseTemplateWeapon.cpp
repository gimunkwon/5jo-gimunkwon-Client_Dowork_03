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
}


void ABaseTemplateWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

