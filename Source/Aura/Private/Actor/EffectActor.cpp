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
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec( GameplayEffectClass, 1.f, EffectContextHandle );
	TargetASC->ApplyGameplayEffectSpecToSelf( *EffectSpecHandle.Data.Get( ) );
}