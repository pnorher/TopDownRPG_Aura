// Copyright Pedro Nortes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class AURA_API AEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEffectActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION( BlueprintCallable )
	void ApplyEffectToTarget( AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass );

	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "Applied Effects" )
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
};
