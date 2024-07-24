// Copyright Pedro Nortes


#include "Character/EnemyCharacter.h"
#include "Aura/Aura.h"

AEnemyCharacter::AEnemyCharacter( ) {
	GetMesh( )->SetCollisionResponseToChannel( ECollisionChannel::ECC_Visibility, ECR_Block );
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