// Copyright Pedro Nortes


#include "Character/MasterCharacter.h"

// Sets default values
AMasterCharacter::AMasterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMasterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}