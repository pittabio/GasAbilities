// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "Abilities/MyJumpAbility.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"

void UMyJumpAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	// Check if the actor has a valid Character reference
	if (ACharacter* MyCharacter = Cast<ACharacter>(ActorInfo->AvatarActor.Get()))
		MyCharacter->Jump();

	// End the ability immediately after performing the jump
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
