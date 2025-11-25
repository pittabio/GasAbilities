// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Ro/Widget/RoHealthWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void URoHealthWidget::UpdateHealthBar(const float HealthPercent, const FText& HealthText) const
{
	HealthProgressBar->SetPercent(HealthPercent);
	HealthTextBlock->SetText(HealthText);
}
