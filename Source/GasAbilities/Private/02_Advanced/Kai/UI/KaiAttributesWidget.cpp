// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Kai/UI/KaiAttributesWidget.h"
#include "02_Advanced/Kai/AbilitySystem/KaiAttributeSet.h"
#include "02_Advanced/Kai/Player/KaiPlayerState.h"

void UKaiAttributesWidget::BindToAttributes()
{
	const AKaiPlayerState* PlayerState = Cast<AKaiPlayerState>(GetOwningPlayerState());
	if (!PlayerState) return;
	
	UAbilitySystemComponent* KaiAsc = PlayerState->GetAbilitySystemComponent();
	const UKaiAttributeSet* KaiAs = PlayerState->GetAttributeSet();
	
	// Initial Attributes
	HealthPercent = NUMERIC_VALUE(KaiAs, Health) / NUMERIC_VALUE(KaiAs, MaxHealth);
	StaminaPercent = NUMERIC_VALUE(KaiAs, Stamina) / NUMERIC_VALUE(KaiAs, MaxStamina);
	
	// Attribute changes
	
	// Health
	KaiAsc->GetGameplayAttributeValueChangeDelegate(KaiAs->GetHealthAttribute()).AddLambda(
		[this, KaiAs](const FOnAttributeChangeData& Data)
		{
			HealthPercent = Data.NewValue / NUMERIC_VALUE(KaiAs, MaxHealth);
		});
	
	// Stamina
	KaiAsc->GetGameplayAttributeValueChangeDelegate(KaiAs->GetStaminaAttribute()).AddLambda(
		[this, KaiAs](const FOnAttributeChangeData& Data)
		{
			StaminaPercent = Data.NewValue / NUMERIC_VALUE(KaiAs, MaxStamina);
		});
}
