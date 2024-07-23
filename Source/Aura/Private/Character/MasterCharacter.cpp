// Copyright Pedro Nortes


#include "Character/MasterCharacter.h"

// Sets default values
AMasterCharacter::AMasterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SK_Weapon = CreateDefaultSubobject<USkeletalMeshComponent>( "Weapon" );
	SK_Weapon->SetupAttachment( GetMesh( ), FName( "WeaponHandSocket" ) );
	SK_Weapon->SetCollisionEnabled( ECollisionEnabled::NoCollision );
}

// Called when the game starts or when spawned
void AMasterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}