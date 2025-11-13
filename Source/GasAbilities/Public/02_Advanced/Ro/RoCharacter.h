// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "RoAttributeSet.h"
#include "RoCharacter.generated.h"

UCLASS()
class GASABILITIES_API ARoCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
	// Ability System Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gas_Attributes, meta = (AllowPrivateAccess = true))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	// Character Attribute Set
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gas_Attributes, meta = (AllowPrivateAccess = true))
	TObjectPtr<URoAttributeSet> AttributeSet;

public:
	// Sets default values for this character's properties
	ARoCharacter();
	
	// Blueprint event to handle health changes and update UI
	UFUNCTION(BlueprintImplementableEvent, Category = "Health")
	void OnHealthChanged(float DeltaValue, const FGameplayTagContainer& EventTags);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Initialize attributes
	void InitializeAttributes();
	
private:
	// Function to handle changes in health attributes
	void HandleHealthChanged(const FOnAttributeChangeData& Data);
	
	// Defines which properties should be replicated for this attribute set
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
public:
	// Getter for the Ability System Component
	FORCEINLINE virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{ return AbilitySystemComponent; }
	
private:
	FORCEINLINE bool IsAbilitySystemValid() const
	{ return AbilitySystemComponent != nullptr && AttributeSet != nullptr; }
};
