// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Kai/UI/KaiHUD.h"
#include "Blueprint/UserWidget.h"
#include "02_Advanced/Kai/UI/KaiAttributesWidget.h"

void AKaiHUD::Init()
{
	AttributeWidget = CreateWidget<UKaiAttributesWidget>(GetOwningPlayerController(), AttributeWidgetClass);
	AttributeWidget->BindToAttributes();
	AttributeWidget->AddToViewport();
}
