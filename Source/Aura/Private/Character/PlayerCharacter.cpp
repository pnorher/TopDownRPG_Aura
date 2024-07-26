// Copyright Pedro Nortes


#include "Character/PlayerCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/PlayerCharacterState.h"

APlayerCharacter::APlayerCharacter( ) {
	GetCharacterMovement( )->bOrientRotationToMovement = true;
	GetCharacterMovement( )->RotationRate = FRotator( 0.f, 400.f, 0.f );
	GetCharacterMovement( )->bConstrainToPlane = true;
	GetCharacterMovement( )->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void APlayerCharacter::PossessedBy( AController* NewController ) {
	Super::PossessedBy( NewController );

	// Init Ability Actor Info for the server
	InitAbilityActorInfo( );
}

void APlayerCharacter::OnRep_PlayerState( ) {
	Super::OnRep_PlayerState( );

	// Init Ability Actor Info for the client
	InitAbilityActorInfo( );
}

void APlayerCharacter::InitAbilityActorInfo( ) {
	APlayerCharacterState* PlayerCharacterState = GetPlayerState< APlayerCharacterState>( );
	check( PlayerCharacterState );
	PlayerCharacterState->GetAbilitySystemComponent( )->InitAbilityActorInfo( PlayerCharacterState, this );
	AbilitySystemComponent = PlayerCharacterState->GetAbilitySystemComponent( );
	AttributeSet = PlayerCharacterState->GetAttributeSet( );
}