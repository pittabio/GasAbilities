// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "RoHealthSkill.h"
#include "RoHealthWidget.h"
#include "Blueprint/UserWidget.h"
#include "RoUI.generated.h"

/**
 * 
 */
UCLASS()
class GASABILITIES_API URoUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta=(BindWidget))
	URoHealthWidget* HealthWidget;
	
	UPROPERTY(meta=(BindWidget))
	URoHealthSkill* HealthSkill;
};
