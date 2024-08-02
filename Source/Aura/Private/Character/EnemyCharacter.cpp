// Copyright Pedro Nortes


#include "Character/EnemyCharacter.h"
#include "AbilitySystem/MasterAbilitySystemComponent.h"
#include "AbilitySystem/MasterAttributeSet.h"
#include "Aura/Aura.h"

AEnemyCharacter::AEnemyCharacter( ) {
	GetMesh( )->SetCollisionResponseToChannel( ECollisionChannel::ECC_Visibility, ECR_Block );

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>( "AbilitySystemComponent" );
	AbilitySystemComponent->SetIsReplicated( true );
	AbilitySystemComponent->SetReplicationMode( EGameplayEffectReplicationMode::Minimal );

	AttributeSet = CreateDefaultSubobject<UMasterAttributeSet>( "AttributeSet" );
}

void AEnemyCharacter::HighlightActor( ) {
	GetMesh( )->SetRenderCustomDepth( true );
	GetMesh( )->SetCustomDepthStencilValue( CUSTOM_DEPTH_RED );
	SK_Weapon->SetRenderCustomDepth( true );
	SK_Weapon->SetCustomDepthStencilValue( CUSTOM_DEPTH_RED );
}

void AEnemyCharacter::UnHighlightActor( ) {
	GetMesh( )->SetRenderCustomDepth( false );
	SK_Weapon->SetRenderCustomDepth( false );
}

void AEnemyCharacter::BeginPlay( ) {
	Super::BeginPlay( );

	check( AbilitySystemComponent );
	AbilitySystemComponent->InitAbilityActorInfo( this, this );
}