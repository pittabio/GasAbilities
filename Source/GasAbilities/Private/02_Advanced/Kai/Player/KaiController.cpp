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
	
	UE_LOG(LogTemp, Warning, TEXT("OnPossess - Controller: %s, Pawn: %s, IsLocalController: %s"), 
		  *GetName(),
		  InPawn ? *InPawn->GetName() : TEXT("NULL"),
		  IsLocalController() ? TEXT("TRUE") : TEXT("FALSE"));
	
    
	if (IsLocalController())
	{
		GasCharacterBase = Cast<AKaiCharacterBase>(InPawn);
		
		UE_LOG(LogTemp, Warning, TEXT("OnPossess: Local Controller %s possessed %s"), 
			  *GetName(), 
			  InPawn ? *InPawn->GetName() : TEXT("NULL"));

		if (MainMappingContext)
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = 
				ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
			{
				if (!Subsystem->HasMappingContext(MainMappingContext.Get()))
				{
					Subsystem->AddMappingContext(MainMappingContext.Get(), 0);
					UE_LOG(LogTemp, Warning, TEXT("Mapping Context added"));
				}
			}
		}
	}
}

void AKaiController::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsLocalController())
	{
		GasCharacterBase = Cast<AKaiCharacterBase>(GetPawn());
		
		UE_LOG(LogTemp, Warning, TEXT("BeginPlay - Controller: %s, Pawn: %s, IsLocalController: TRUE"), 
			  *GetName(), 
			  GasCharacterBase ? *GasCharacterBase->GetName() : TEXT("NULL"));
		
		if (MainMappingContext)
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = 
				ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(MainMappingContext.Get(), 0);
				UE_LOG(LogTemp, Warning, TEXT("Mapping Context added for local controller"));
			}
		}
	}
}

/// Input action handlers implementation

// Handle look input
void AKaiController::Look(const FInputActionValue& Value)
{
	if (!GasCharacterBase)
	{
		UE_LOG(LogTemp, Warning, TEXT("Look called but Character is null!"));
		return;
	}
	
	// Get the look axis vector from the input value and pass it to the current character
	const FVector2d LookAxisVector = Value.Get<FVector2d>();
	GasCharacterBase->Look(LookAxisVector);
}

// Handle move input
void AKaiController::Move(const FInputActionValue& Value)
{
	if (!GasCharacterBase)
	{
		UE_LOG(LogTemp, Warning, TEXT("Look called but GasCharacterBase is null!"));
		return;
	}
	
	// Get the movement vector from the input value and pass it to the current character
	const FVector2d MovementVector = Value.Get<FVector2d>();
	this->GasCharacterBase->Move(MovementVector);
}

// Handle jump input start
void AKaiController::JumpStart()
{
	if (!GasCharacterBase)
	{
		UE_LOG(LogTemp, Warning, TEXT("Look called but GasCharacterBase is null!"));
		return;
	}
	
	this->GasCharacterBase->Jump();
}

// Handle jump input stop
void AKaiController::JumpStop()
{
	if (!GasCharacterBase)
	{
		UE_LOG(LogTemp, Warning, TEXT("Look called but GasCharacterBase is null!"));
		return;
	}
	
	this->GasCharacterBase->StopJumping();
}