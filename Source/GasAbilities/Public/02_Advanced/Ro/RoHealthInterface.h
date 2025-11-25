// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RoHealthInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class URoHealthInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GASABILITIES_API IRoHealthInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateHealthDisplay(float CurrentHealth, float MaxHealth);
};
