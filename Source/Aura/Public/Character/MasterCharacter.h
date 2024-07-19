// Copyright Pedro Nortes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MasterCharacter.generated.h"

UCLASS(ABSTRACT)
class AURA_API AMasterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMasterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
