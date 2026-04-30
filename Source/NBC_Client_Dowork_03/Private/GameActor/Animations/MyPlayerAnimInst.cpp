#include "NBC_Client_Dowork_03/Public/GameActor/Animations/MyPlayerAnimInst.h"

#include "NBC_Client_Dowork_03/Public/GameActor/MyPlayer.h"

void UMyPlayerAnimInst::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	MyOwnerInst = Cast<AMyPlayer>(TryGetPawnOwner());
}

void UMyPlayerAnimInst::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if (MyOwnerInst)
	{
		FVector Velocity = MyOwnerInst->GetVelocity();
		GroundSpeed = Velocity.Size2D();
	}
}
