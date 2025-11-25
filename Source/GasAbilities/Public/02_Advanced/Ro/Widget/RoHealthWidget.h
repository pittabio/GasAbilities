// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RoHealthWidget.generated.h"

/**
 * 
 */
UCLASS()
class GASABILITIES_API URoHealthWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthProgressBar;
	
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HealthTextBlock;
	
public:
	UFUNCTION(BlueprintCallable)
	void UpdateHealthBar(float HealthPercent, const FText& HealthText) const;
};
