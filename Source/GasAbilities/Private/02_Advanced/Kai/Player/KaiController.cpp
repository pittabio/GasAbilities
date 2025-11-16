// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Kai/Player/KaiController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Setup input component
void AKaiController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Check if InputComponent is valid
	if (this->InputComponent == nullptr) return;

	// Cast the InputComponent to UEnhancedInputComponent for enhanced input handling
	EnhancedInputComponent = Cast<UEnhancedInputComponent>(this->InputComponent);
	if (EnhancedInputComponent == nullptr) return;

	/// Bind input actions to their respective handlers
	
	// Look - bind to Triggered event
	EnhancedInputComponent->BindAction(LookAction.Get(), ETriggerEvent::Triggered, this, &AKaiController::Look);

	// Move - bind to Triggered event
	EnhancedInputComponent->BindAction(MoveAction.Get(), ETriggerEvent::Triggered, this, &AKaiController::Move);

	// Jump - bind to Started and Completed events
	EnhancedInputComponent->BindAction(JumpAction.Get(), ETriggerEvent::Started, this, &AKaiController::JumpStart);
	EnhancedInputComponent->BindAction(JumpAction.Get(), ETriggerEvent::Completed, this, &AKaiController::JumpStop);
}

// Called when possessing a pawn
void AKaiController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// Cast the possessed pawn to AGasCharacterBase and store the reference
	this->GasCharacterBase = Cast<AKaiCharacterBase>(InPawn);

	// Get the enhanced input local player subsystem
	const TObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputLocalPlayerSubsystem
		= ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer());

	// Add the current input mapping context to the input subsystem
	if (InputLocalPlayerSubsystem && MainMappingContext)
		InputLocalPlayerSubsystem->AddMappingContext(this->MainMappingContext.Get(), 0);
}

/// Input action handlers implementation

// Handle look input
void AKaiController::Look(const FInputActionValue& Value)
{
	// Get the look axis vector from the input value and pass it to the current character
	const FVector2d LookAxisVector = Value.Get<FVector2d>();
	this->GasCharacterBase->Look(LookAxisVector);
}

// Handle move input
void AKaiController::Move(const FInputActionValue& Value)
{
	// Get the movement vector from the input value and pass it to the current character
	const FVector2d MovementVector = Value.Get<FVector2d>();
	this->GasCharacterBase->Move(MovementVector);
}

// Handle jump input start
void AKaiController::JumpStart()
{
	this->GasCharacterBase->Jump();
}

// Handle jump input stop
void AKaiController::JumpStop()
{
	this->GasCharacterBase->StopJumping();
}