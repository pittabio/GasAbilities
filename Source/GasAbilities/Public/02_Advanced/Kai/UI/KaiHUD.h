// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "KaiHUD.generated.h"

class UKaiAttributesWidget;

/**
 * 
 */
UCLASS()
class GASABILITIES_API AKaiHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UKaiAttributesWidget> AttributeWidgetClass;
	
private:
	UPROPERTY()
	TObjectPtr<UKaiAttributesWidget> AttributeWidget;
	
public:
	void Init();
};
