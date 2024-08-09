// Copyright Pedro Nortes


#include "UI/HUD/MasterHUD.h"
#include "UI/Widgets/MasterUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AMasterHUD::GetOverlayWidgetController( const FWidgetControllerParams& WCParams ) {
	if ( OverlayWidgetController == nullptr ) {
		OverlayWidgetController = NewObject<UOverlayWidgetController>( this, OverlayWidgetControllerClass );
		OverlayWidgetController->SetWidgetControllerParams( WCParams );
		OverlayWidgetController->BindCallbacksToDependencies( );

		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void AMasterHUD::InitOverlay( APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS ) {
	checkf( OverlayWidgetClass, TEXT( "Overlay Widget Class uninitialized, please fill out BP_MasterHUD" ) );
	checkf( OverlayWidgetControllerClass, TEXT( "Overlay Widget Controller Class uninitialized, please fill out BP_MasterHUD" ) );

	UUserWidget* Widget = CreateWidget<UUserWidget>( GetWorld( ), OverlayWidgetClass );
	OverlayWidget = Cast<UMasterUserWidget>( Widget );

	const FWidgetControllerParams WidgetControllerParams( PC, PS, ASC, AS );
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController( WidgetControllerParams );

	OverlayWidget->SetWidgetController( WidgetController );
	WidgetController->BroadcastInitialValues( );
	Widget->AddToViewport( );
}