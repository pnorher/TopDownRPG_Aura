// Copyright Pedro Nortes


#include "AbilitySystem/MasterAttributeSet.h"
#include "Net/UnrealNetwork.h"

UMasterAttributeSet::UMasterAttributeSet( ) {
	InitHealth( 50.f );
	InitMaxHealth( 100.f );
	InitMana( 50.f );
	InitMaxMana( 50.f );
}

void UMasterAttributeSet::GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const {
	Super::GetLifetimeReplicatedProps( OutLifetimeProps );

	DOREPLIFETIME_CONDITION_NOTIFY( UMasterAttributeSet, Health, COND_None, REPNOTIFY_Always );
	DOREPLIFETIME_CONDITION_NOTIFY( UMasterAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always );
	DOREPLIFETIME_CONDITION_NOTIFY( UMasterAttributeSet, Mana, COND_None, REPNOTIFY_Always );
	DOREPLIFETIME_CONDITION_NOTIFY( UMasterAttributeSet, MaxMana, COND_None, REPNOTIFY_Always );
}

void UMasterAttributeSet::OnRep_Health( const FGameplayAttributeData& OldHealth ) const {
	GAMEPLAYATTRIBUTE_REPNOTIFY( UMasterAttributeSet, Health, OldHealth );
}

void UMasterAttributeSet::OnRep_MaxHealth( const FGameplayAttributeData& OldMaxHealth ) const {
	GAMEPLAYATTRIBUTE_REPNOTIFY( UMasterAttributeSet, MaxHealth, OldMaxHealth );
}

void UMasterAttributeSet::OnRep_Mana( const FGameplayAttributeData& OldMana ) const {
	GAMEPLAYATTRIBUTE_REPNOTIFY( UMasterAttributeSet, Mana, OldMana );
}

void UMasterAttributeSet::OnRep_MaxMana( const FGameplayAttributeData& OldMaxMana ) const {
	GAMEPLAYATTRIBUTE_REPNOTIFY( UMasterAttributeSet, MaxMana, OldMaxMana );
}