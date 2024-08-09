// Copyright Pedro Nortes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MasterHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UOverlayWidgetController;
class UMasterUserWidget;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class AURA_API AMasterHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY( )
	TObjectPtr<UMasterUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController( const FWidgetControllerParams& WCParams );

	void InitOverlay( APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS );
private:

	UPROPERTY( EditAnywhere )
	TSubclassOf<UMasterUserWidget> OverlayWidgetClass;

	UPROPERTY( )
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY( EditAnywhere )
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
protected:
};
