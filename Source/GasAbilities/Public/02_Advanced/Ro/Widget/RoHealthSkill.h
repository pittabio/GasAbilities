// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "RoHealthSkill.generated.h"

/**
 * 
 */
UCLASS()
class GASABILITIES_API URoHealthSkill : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer AbilityTag;
	
	UPROPERTY(EditDefaultsOnly)
	UClass* AbilityClass;
	
	UPROPERTY(meta = (BindWidget))
	UButton* SkillButton;
	
	UPROPERTY(meta = (BindWidget))
	UImage* SkillIcon;
	
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;
	
	UFUNCTION()
	void OnSkillButtonClicked();
};
