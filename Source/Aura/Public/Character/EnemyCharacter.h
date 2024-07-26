// Copyright Pedro Nortes

#pragma once

#include "CoreMinimal.h"
#include "Character/MasterCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public AMasterCharacter, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AEnemyCharacter( );

	/* Begin Enemy Interface */
	virtual void HighlightActor( ) override;
	virtual void UnHighlightActor( ) override;
	/* End Enemy Interface */
protected:
	virtual void BeginPlay( ) override;
};
