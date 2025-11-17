// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KaiAttributesWidget.generated.h"

/**
 * 
 */
UCLASS()
class GASABILITIES_API UKaiAttributesWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly)
	float HealthPercent;
	
	UPROPERTY(BlueprintReadOnly)
	float StaminaPercent;
	
public:
	void BindToAttributes();
};
