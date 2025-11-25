// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "RoHealthInterface.h"
#include "GameFramework/PlayerController.h"
#include "RoController.generated.h"

/**
 * 
 */
UCLASS()
class GASABILITIES_API ARoController : public APlayerController, public IRoHealthInterface
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> UISubClass;
	
	UPROPERTY()
	class URoUI* UIClass;
	
	virtual void BeginPlay() override;
	
	virtual void UpdateHealthDisplay_Implementation(float CurrentHealth, float MaxHealth) override;
};
