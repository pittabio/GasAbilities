// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "02_Advanced/Kai/Characters/KaiCharacterBase.h"
#include "KaiPlayerCharacter.generated.h"

UCLASS()
class GASABILITIES_API AKaiPlayerCharacter : public AKaiCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AKaiPlayerCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
private:
	void InitAbilitySystemComponent();
	void InitHUD();
};
