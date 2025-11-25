// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Ro/RoController.h"
#include "02_Advanced/Ro/Widget/RoUI.h"
#include "Blueprint/UserWidget.h"

void ARoController::BeginPlay()
{
	Super::BeginPlay();
	
	if (UISubClass)
		if (UUserWidget* UI = CreateWidget(this, UISubClass.Get())) 
			UIClass = Cast<URoUI>(UI);
	
	if (UIClass) UIClass->AddToViewport();
	
	SetShowMouseCursor(true);
}

void ARoController::UpdateHealthDisplay_Implementation(const float CurrentHealth, const float MaxHealth)
{
	IRoHealthInterface::UpdateHealthDisplay_Implementation(CurrentHealth, MaxHealth);
	
	const float HealthPercentage = CurrentHealth / MaxHealth;
	const FText HealthText = FText::FromString(
		"Health: " + 
		FString::Printf(TEXT("%.0f / %.0f"), 
		CurrentHealth, MaxHealth));
	
	if (UIClass) UIClass->HealthWidget->UpdateHealthBar(HealthPercentage, HealthText);
}
