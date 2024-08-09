// Copyright Pedro Nortes


#include "UI/Widgets/MasterUserWidget.h"

void UMasterUserWidget::SetWidgetController( UObject* InWidgetController ) {
	WidgetController = InWidgetController;
	WidgetControllerSet( );
}