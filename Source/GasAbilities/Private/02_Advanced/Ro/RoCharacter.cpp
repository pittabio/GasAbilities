// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Ro/RoCharacter.h"
#include "02_Advanced/Ro/RoAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ARoCharacter::ARoCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Initialize the custom Ability System Component
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// Initialize the Attribute Set
	AttributeSet = CreateDefaultSubobject<URoAttributeSet>(TEXT("AttributeSet"));
}

// Called when the game starts or when spawned
void ARoCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Initialize attributes when game starts (e.g. health)
	InitializeAttributes();
	
	// Bind the function to handle changes to the delegate in the Ability System Component
	if (IsAbilitySystemValid())
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
			AttributeSet->GetCurrentHealthAttribute()).AddUObject(this, &ARoCharacter::HandleHealthChanged);
}

// Initialize attributes
void ARoCharacter::InitializeAttributes()
{
	if (IsAbilitySystemValid())
	{
		// TODO Update later
	}
}

// Function to handle changes in health attributes
void ARoCharacter::HandleHealthChanged(const FOnAttributeChangeData& Data)
{
	// Extract old and new health values
	const float NewHealth = Data.NewValue; // New health value after change
	const float OldHealth = Data.OldValue; // Old health value before change
	
	// Calculate the difference in health to find out the change amount
	const float DeltaValue = NewHealth - OldHealth;
	
	// Trigger a Blueprint event to update UI or other systems
	OnHealthChanged(DeltaValue, FGameplayTagContainer());
}

// Defines which properties should be replicated for this attribute set
void ARoCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(ARoCharacter, AbilitySystemComponent);
	DOREPLIFETIME(ARoCharacter, AttributeSet);
}
