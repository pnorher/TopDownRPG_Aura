// Copyright Pedro Nortes

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MasterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS( ClassName, PropertyName ) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class AURA_API UMasterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UMasterAttributeSet( );
	virtual void GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const override;

	UPROPERTY( BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes" )
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS( UMasterAttributeSet, Health );

	UPROPERTY( BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes" )
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS( UMasterAttributeSet, MaxHealth );

	UPROPERTY( BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes" )
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS( UMasterAttributeSet, Mana );

	UPROPERTY( BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes" )
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS( UMasterAttributeSet, MaxMana );

	UFUNCTION(  )
	void OnRep_Health( const FGameplayAttributeData& OldHealth ) const;

	UFUNCTION( )
	void OnRep_MaxHealth( const FGameplayAttributeData& OldMaxHealth ) const;

	UFUNCTION( )
	void OnRep_Mana( const FGameplayAttributeData& OldMana ) const;

	UFUNCTION( )
	void OnRep_MaxMana( const FGameplayAttributeData& OldMaxMana ) const;
};
