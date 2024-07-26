// Copyright Pedro Nortes

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "PlayerCharacterState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class AURA_API APlayerCharacterState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	APlayerCharacterState( );
	virtual UAbilitySystemComponent* GetAbilitySystemComponent( ) const override;
	UAttributeSet* GetAttributeSet( ) const { return AttributeSet; };
protected:
	UPROPERTY( )
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY( )
	TObjectPtr<UAttributeSet> AttributeSet;
};
