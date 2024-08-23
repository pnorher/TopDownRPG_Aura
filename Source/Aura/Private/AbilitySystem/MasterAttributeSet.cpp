// Copyright Pedro Nortes


#include "AbilitySystem/MasterAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UMasterAttributeSet::UMasterAttributeSet( ) {
	InitHealth( 50.f );
	InitMaxHealth( 100.f );
	InitMana( 25.f );
	InitMaxMana( 50.f );
}

void UMasterAttributeSet::GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const {
	Super::GetLifetimeReplicatedProps( OutLifetimeProps );

	DOREPLIFETIME_CONDITION_NOTIFY( UMasterAttributeSet, Health, COND_None, REPNOTIFY_Always );
	DOREPLIFETIME_CONDITION_NOTIFY( UMasterAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always );
	DOREPLIFETIME_CONDITION_NOTIFY( UMasterAttributeSet, Mana, COND_None, REPNOTIFY_Always );
	DOREPLIFETIME_CONDITION_NOTIFY( UMasterAttributeSet, MaxMana, COND_None, REPNOTIFY_Always );
}

void UMasterAttributeSet::PreAttributeChange( const FGameplayAttribute& Attribute, float& NewValue ) {
	Super::PreAttributeChange( Attribute, NewValue );

	if ( Attribute == GetHealthAttribute( ) ) {
		NewValue = FMath::Clamp( NewValue, 0.f, GetMaxHealth( ) );
	}
	if ( Attribute == GetManaAttribute( ) ) {
		NewValue = FMath::Clamp( NewValue, 0.f, GetMaxMana( ) );
	}
}

void UMasterAttributeSet::SetEffectProperties( const FGameplayEffectModCallbackData& Data, FEffectProperties& Props ) const {
	Props.EffectContextHandle = Data.EffectSpec.GetContext( );
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent( );
	if ( IsValid( Props.SourceASC ) && Props.SourceASC->AbilityActorInfo.IsValid( )
		 && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid( ) ) {
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get( );
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get( );

		if ( Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr ) {
			if ( const APawn* Pawn = Cast<APawn>( Props.SourceAvatarActor ) ) {
				Props.SourceController = Pawn->GetController( );
			}
		}
		if ( Props.SourceController ) {
			Props.SourceCharacter = Cast<ACharacter>( Props.SourceController->GetPawn( ) );
		}
	}

	if ( Data.Target.AbilityActorInfo.IsValid( ) && Data.Target.AbilityActorInfo->AvatarActor.IsValid( ) ) {
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get( );
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get( );
		Props.TargetCharacter = Cast<ACharacter>( Props.TargetAvatarActor );
		Props.TargetASC = &Data.Target;
	}
}

void UMasterAttributeSet::PostGameplayEffectExecute( const FGameplayEffectModCallbackData& Data ) {
	Super::PostGameplayEffectExecute( Data );

	FEffectProperties Props;
	SetEffectProperties( Data, Props );
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