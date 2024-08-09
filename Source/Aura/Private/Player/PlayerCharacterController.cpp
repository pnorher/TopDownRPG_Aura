// Copyright Pedro Nortes


#include "Player/PlayerCharacterController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

APlayerCharacterController::APlayerCharacterController( ) {
	bReplicates = true;
}

void APlayerCharacterController::PlayerTick( float DeltaTime ) {
	Super::PlayerTick( DeltaTime );

	CursorTrace( );
}

void APlayerCharacterController::CursorTrace( ) {
	FHitResult CursorHit;
	GetHitResultUnderCursor( ECollisionChannel::ECC_Visibility, false, CursorHit );
	if ( !CursorHit.bBlockingHit ) {
		return;
	}

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor( );

	if ( ThisActor != LastActor ) {
		if ( LastActor.GetInterface( ) ) {
			LastActor->UnHighlightActor( );
		}

		if ( ThisActor.GetInterface( ) ) {
			ThisActor->HighlightActor( );
		}
	}
}

void APlayerCharacterController::BeginPlay( ) {
	Super::BeginPlay( );

	check( PlayerContext );

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::
		GetSubsystem<UEnhancedInputLocalPlayerSubsystem>( GetLocalPlayer( ) );
	if ( Subsystem ) {
		Subsystem->AddMappingContext( PlayerContext, 0 );
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior( EMouseLockMode::DoNotLock );
	InputModeData.SetHideCursorDuringCapture( false );
	SetInputMode( InputModeData );
}

void APlayerCharacterController::SetupInputComponent( ) {
	Super::SetupInputComponent( );

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>( InputComponent );

	EnhancedInputComponent->BindAction( MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacterController::Move );
}

void APlayerCharacterController::Move( const FInputActionValue& InputActionValue ) {
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>( );
	const FRotator Rotation( 0.f, GetControlRotation( ).Yaw, 0.f );

	const FVector ForwardDirection = FRotationMatrix( Rotation ).GetUnitAxis( EAxis::X );
	const FVector RightDirection = FRotationMatrix( Rotation ).GetUnitAxis( EAxis::Y );

	if ( APawn* ControlledPawn = GetPawn<APawn>( ) ) {
		ControlledPawn->AddMovementInput( ForwardDirection, InputAxisVector.Y );
		ControlledPawn->AddMovementInput( RightDirection, InputAxisVector.X );
	}
}