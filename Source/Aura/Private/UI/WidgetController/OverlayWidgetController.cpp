// Copyright Pedro Nortes


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/MasterAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues( ) {
	const UMasterAttributeSet* MasterAttributeSet = CastChecked<UMasterAttributeSet>( AttributeSet );

	OnHealthChanged.Broadcast( MasterAttributeSet->GetHealth( ) );
	OnMaxHealthChanged.Broadcast( MasterAttributeSet->GetMaxHealth( ) );
	OnManaChanged.Broadcast( MasterAttributeSet->GetMana( ) );
	OnMaxManaChanged.Broadcast( MasterAttributeSet->GetMaxMana( ) );
}

void UOverlayWidgetController::BindCallbacksToDependencies( ) {
	const UMasterAttributeSet* MasterAttributeSet = CastChecked<UMasterAttributeSet>( AttributeSet );

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate( MasterAttributeSet->GetHealthAttribute( ) )
		.AddUObject( this, &UOverlayWidgetController::HealthChanged );

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate( MasterAttributeSet->GetMaxHealthAttribute( ) )
		.AddUObject( this, &UOverlayWidgetController::MaxHealthChanged );

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate( MasterAttributeSet->GetManaAttribute( ) )
		.AddUObject( this, &UOverlayWidgetController::ManaChanged );

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate( MasterAttributeSet->GetMaxManaAttribute( ) )
		.AddUObject( this, &UOverlayWidgetController::MaxManaChanged );
}

void UOverlayWidgetController::HealthChanged( const FOnAttributeChangeData& Data ) const {
	OnHealthChanged.Broadcast( Data.NewValue );
}

void UOverlayWidgetController::MaxHealthChanged( const FOnAttributeChangeData& Data ) const {
	OnMaxHealthChanged.Broadcast( Data.NewValue );
}

void UOverlayWidgetController::ManaChanged( const FOnAttributeChangeData& Data ) const {
	OnManaChanged.Broadcast( Data.NewValue );
}

void UOverlayWidgetController::MaxManaChanged( const FOnAttributeChangeData& Data ) const {
	OnMaxManaChanged.Broadcast( Data.NewValue );
}