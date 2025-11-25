// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Ro/Widget/RoHealthSkill.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

void URoHealthSkill::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	if (IsValid(AbilityClass))
	{
		SkillButton->SetVisibility(ESlateVisibility::Visible);
		SkillIcon->SetVisibility(ESlateVisibility::Visible);

		// Get Class Default
		if (const UObject* AbilityClassObj = AbilityClass->GetDefaultObject())
		{
			if (FProperty* IconProperty = AbilityClass->FindPropertyByName(FName("Icon")))
			{
				// Check if it's an object property (UTexture2D is a UObject)
				if (const FObjectProperty* ObjectProperty = CastField<FObjectProperty>(IconProperty))
				{
					// Get the value of the property from the CDO
					UObject* IconObject = ObjectProperty->GetObjectPropertyValue_InContainer(AbilityClassObj);
						
					// Cast to UTexture2D
					if (UTexture2D* Icon = Cast<UTexture2D>(IconObject)) SkillIcon->SetBrushFromTexture(Icon);
					else UE_LOG(LogTemp, Warning, TEXT(
						"Icon property found but is not a UTexture2D in %s"), 
						*AbilityClass->GetName());
				}
				else UE_LOG(LogTemp, Warning, TEXT("Icon property found but is not an object property in %s"), *AbilityClass->GetName());
			}
			else UE_LOG(LogTemp, Warning, TEXT("No 'AbilityIcon' or 'Icon' property found in %s"), *AbilityClass->GetName());
		}
	}
	else
	{
		SkillButton->SetVisibility(ESlateVisibility::Hidden);
		SkillIcon->SetVisibility(ESlateVisibility::Hidden);
	}
}

void URoHealthSkill::NativeConstruct()
{
	Super::NativeConstruct();
	
	SkillButton->OnClicked.AddDynamic(this, &URoHealthSkill::OnSkillButtonClicked);
}

void URoHealthSkill::OnSkillButtonClicked()
{
	if (UAbilitySystemComponent* Asc = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(
		GetOwningPlayerPawn()))
	{
		Asc->TryActivateAbilitiesByTag(AbilityTag);
	}
}
