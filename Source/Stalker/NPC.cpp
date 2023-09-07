#include "NPC.h"

// ANPC
//------------------------------------------------------------------------------------------------------------
ANPC::ANPC()
{
	PrimaryActorTick.bCanEverTick = true;  // Включает тик персонажа на каждый кадр
}
//------------------------------------------------------------------------------------------------------------
void ANPC::BeginPlay()
{
	Super::BeginPlay();
}
//------------------------------------------------------------------------------------------------------------
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
//------------------------------------------------------------------------------------------------------------




// ANPC_Human
//------------------------------------------------------------------------------------------------------------
void ANPC_Human::Attach_Weapon(USkeletalMeshComponent *character_mesh, FName arm_socket_name, AWeapon *weapon)
{
	if (weapon == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%S] >>>>>> weapon = 0"), __FUNCTION__);
		return;
	}

	if (Current_Weapon != 0)
		Current_Weapon->Detach();

	Current_Weapon = weapon;
	Current_Weapon->Attach_To_Socket(character_mesh, arm_socket_name);
}
//------------------------------------------------------------------------------------------------------------
