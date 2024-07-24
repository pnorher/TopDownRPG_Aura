// Copyright Pedro Nortes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class AURA_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()
	
public:
	APlayerCharacterController( );
private:
	UPROPERTY( EditAnywhere, Category = "Input" );
	TObjectPtr<UInputMappingContext> PlayerContext;

	UPROPERTY( EditAnywhere, Category = "Input" );
	TObjectPtr<UInputAction> MoveAction;

	void Move( const FInputActionValue& InputActionValue );
protected:
	virtual void BeginPlay( ) override;
	virtual void SetupInputComponent( ) override;
};
