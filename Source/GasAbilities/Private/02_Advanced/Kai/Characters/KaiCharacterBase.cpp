// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Kai/Characters/KaiCharacterBase.h"
#include "02_Advanced/Kai/AbilitySystem/KaiAbilitySystemComponent.h"

// Sets default values
AKaiCharacterBase::AKaiCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* AKaiCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UKaiAttributeSet* AKaiCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void AKaiCharacterBase::GiveDefaultAbilities()
{
	check(AbilitySystemComponent);
	if (!HasAuthority()) return;
	
	for (const TSubclassOf<UGameplayAbility> AbilityClass : DefaultAbilities)
	{
		const FGameplayAbilitySpec AbilitySpec(AbilityClass, 1);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}

void AKaiCharacterBase::InitDefaultAttributes() const
{
	if (!AbilitySystemComponent || !DefaultAttributeEffect) { return; }
	
	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	
	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(
		DefaultAttributeEffect,
		1.f,
		EffectContext
	);
	
	if (SpecHandle.IsValid())
	{
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

// Simple motion

// Handle look input
void AKaiCharacterBase::Look(const FVector2d LookAxisVector)
{
	// Add yaw and pitch input to the current character's controller
	this->AddControllerYawInput(LookAxisVector.X);
	this->AddControllerPitchInput(LookAxisVector.Y);
}

// Handle move input
void AKaiCharacterBase::Move(const FVector2d MovementVector)
{
	// Get the control rotation and isolate the yaw component
	const FRotator Rotation = this->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// Get the forward and right vectors based on the yaw rotation
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Add movement input in the forward and right directions
	this->AddMovementInput(ForwardDirection, MovementVector.Y);
	this->AddMovementInput(RightDirection, MovementVector.X);
}
