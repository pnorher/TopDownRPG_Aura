// Copyright Pedro Nortes

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "MasterCharacter.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(ABSTRACT)
class AURA_API AMasterCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMasterCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent( ) const override;
	UAttributeSet* GetAttributeSet( ) const { return AttributeSet; };
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY( EditAnywhere, Category = "Combat" );
	TObjectPtr<USkeletalMeshComponent> SK_Weapon;

	UPROPERTY( )
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY( )
	TObjectPtr<UAttributeSet> AttributeSet;
};
