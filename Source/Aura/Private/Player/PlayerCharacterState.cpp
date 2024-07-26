// Copyright Pedro Nortes


#include "Player/PlayerCharacterState.h"
#include "AbilitySystem/MasterAbilitySystemComponent.h"
#include "AbilitySystem/MasterAttributeSet.h"

APlayerCharacterState::APlayerCharacterState( ) {
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>( "AbilitySystemComponent" );
	AbilitySystemComponent->SetIsReplicated( true );
	AbilitySystemComponent->SetReplicationMode( EGameplayEffectReplicationMode::Mixed );

	AttributeSet = CreateDefaultSubobject<UAttributeSet>( "AttributeSet" );

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* APlayerCharacterState::GetAbilitySystemComponent( ) const {
	return AbilitySystemComponent;
}