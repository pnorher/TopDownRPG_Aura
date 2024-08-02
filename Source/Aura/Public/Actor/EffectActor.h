// Copyright Pedro Nortes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EffectActor.generated.h"

class USphereComponent;

UCLASS()
class AURA_API AEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEffectActor();

	UFUNCTION( )
	virtual void OnOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
							int32 OtherBodyIndex, bool bFromSwepp, const FHitResult& SweepResult );

	UFUNCTION( )
	virtual void EndOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
							 int32 OtherBodyIndex );

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY( VisibleAnywhere )
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY( VisibleAnywhere )
	TObjectPtr<UStaticMeshComponent> Mesh;
};
