// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "02_Advanced/Kai/Characters/KayCharacterBase.h"
#include "KaiEnemyCharacter.generated.h"

UCLASS()
class GASABILITIES_API AKaiEnemyCharacter : public AKayCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKaiEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
