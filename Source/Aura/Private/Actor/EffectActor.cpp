// Copyright Pedro Nortes


#include "Actor/EffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

// Sets default values
AEffectActor::AEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent( CreateDefaultSubobject<USceneComponent>( "SceneRoot" ) );
}

// Called when the game starts or when spawned
void AEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AEffectActor::ApplyEffectToTarget( AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass ) {
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent( TargetActor );
	if ( TargetASC == nullptr ) {
		return;
	}

	check( GameplayEffectClass );
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext( );
	EffectContextHandle.AddSourceObject( this );
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec( 
		GameplayEffectClass, ActorLevel, EffectContextHandle );
	const FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf( 
		*EffectSpecHandle.Data.Get( ) );

	const bool bIsInfinite = EffectSpecHandle.Data.Get( )->Def.Get( )->DurationPolicy == EGameplayEffectDurationType::Infinite;
	if ( bIsInfinite && InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap ) {
		ActiveEffectHandles.Add( ActiveEffectHandle, TargetASC );
	}
}

void AEffectActor::OnOverlap( AActor* TargetActor ) {
	if ( InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap ) {
		ApplyEffectToTarget( TargetActor, InstantGameplayEffectClass );
	}
	if ( DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap ) {
		ApplyEffectToTarget( TargetActor, DurationGameplayEffectClass );
	}
	if ( InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap ) {
		ApplyEffectToTarget( TargetActor, InfiniteGameplayEffectClass );
	}
}

void AEffectActor::OnEndOverlap( AActor* TargetActor ) {
	if ( InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap ) {
		ApplyEffectToTarget( TargetActor, InstantGameplayEffectClass );
	}
	if ( DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap ) {
		ApplyEffectToTarget( TargetActor, DurationGameplayEffectClass );
	}
	if ( InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap ) {
		ApplyEffectToTarget( TargetActor, InfiniteGameplayEffectClass );
	}
	if ( InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap ) {
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent( TargetActor );
		if ( !IsValid( TargetASC ) ) {
			return;
		}

		TArray<FActiveGameplayEffectHandle> HandlesToRemove;
		for ( TTuple<FActiveGameplayEffectHandle, UAbilitySystemComponent*> HandlePair : ActiveEffectHandles ) {
			if ( TargetASC == HandlePair.Value ) {
				TargetASC->RemoveActiveGameplayEffect( HandlePair.Key );
				HandlesToRemove.Add( HandlePair.Key );
			}
		}
		for ( auto& Handle : HandlesToRemove ) {
			ActiveEffectHandles.FindAndRemoveChecked( Handle );
		}
	}
}