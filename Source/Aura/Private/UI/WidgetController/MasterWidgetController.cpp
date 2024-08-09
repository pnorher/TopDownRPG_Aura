// Copyright Pedro Nortes


#include "UI/WidgetController/MasterWidgetController.h"

void UMasterWidgetController::SetWidgetControllerParams( const FWidgetControllerParams& WCParams ) {
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UMasterWidgetController::BroadcastInitialValues( ) {

}

void UMasterWidgetController::BindCallbacksToDependencies( ) {

}