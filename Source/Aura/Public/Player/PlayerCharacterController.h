// Copyright Pedro Nortes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interaction/EnemyInterface.h"
#include "PlayerCharacterController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class AURA_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY( )
	
public:
	APlayerCharacterController( );
	virtual void PlayerTick( float DeltaTime ) override;
private:
	UPROPERTY( EditAnywhere, Category = "Input" )
	TObjectPtr<UInputMappingContext> PlayerContext;

	UPROPERTY( EditAnywhere, Category = "Input" )
	TObjectPtr<UInputAction> MoveAction;

	void Move( const FInputActionValue& InputActionValue );

	void CursorTrace( );
	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;
protected:
	virtual void BeginPlay( ) override;
	virtual void SetupInputComponent( ) override;
};
