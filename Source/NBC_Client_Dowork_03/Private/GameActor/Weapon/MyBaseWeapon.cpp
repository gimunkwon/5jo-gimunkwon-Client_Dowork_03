#include "NBC_Client_Dowork_03/Public/GameActor/Weapon/MyBaseWeapon.h"

#include "NBC_Client_Dowork_03/Public/DataTable/DT_Weapon.h"


AMyBaseWeapon::AMyBaseWeapon()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComp;
	
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SkeletalMeshComponent->SetupAttachment(SceneComp);
	
	BaseCoilPitch = 0.f;
	RemainCoilPitch = 0.f;
	RecoilSpeed = 0.f;
}

void AMyBaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	InitializeWeaponStat();
}


void AMyBaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyBaseWeapon::InitializeWeaponStat()
{
	const static FString ContextString = "InitializeRemainColiPitch";
	RemainCoilPitch = RowHandle.GetRow<FMyWeapon>(ContextString)->RemainRecoilPitch;
	UE_LOG(LogTemp,Warning,TEXT("RemainColiPitch %f"),RemainCoilPitch);
	RecoilSpeed = RowHandle.GetRow<FMyWeapon>(ContextString)->RecoilSpeed;
}