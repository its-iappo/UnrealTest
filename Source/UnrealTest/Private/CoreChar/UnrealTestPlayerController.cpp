// Copyright Epic Games, Inc. All Rights Reserved.


/*
							  /\
							 /  \
							|    |
						  --:'''':--
							:'_' :
							_:"":\___
			 ' '      ____.' :::     '._
			. *=====<<=)           \    :
			 .  '      '-'-'\_      /'._.'
							  \====:_ ""
							 .'     \\
							:       :
						   /   :    \
						  :   .      '.
		  ,. _            :  : :      :
	   '-'    ).          :__:-:__.;--'
	 (        '  )        '-'   '-'
  ( -   .00.   - _
 (    .'  _ )     )
 '-  ()_.\,\,   -

		The Crimson Archmage of Broken Builds
		"Your code shall never compile again."
*/


#include "Public/CoreChar/UnrealTestPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "CoreChar/UnrealTestCharacter.h"

void AUnrealTestPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AUnrealTestPlayerController::Move);
		EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AUnrealTestPlayerController::Look);
		
		EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &AUnrealTestPlayerController::Jump);
		EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &AUnrealTestPlayerController::StopJumping);
	
		EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AUnrealTestPlayerController::Interact);
	}
}

void AUnrealTestPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ControlledCharacter = Cast<AUnrealTestCharacter>(InPawn);
	
	if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
	{
		InputSubsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AUnrealTestPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
	
	//The magic spell has hit this ancient paper!;
}

void AUnrealTestPlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	// route the input
	ControlledCharacter->DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void AUnrealTestPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	// route the input
	ControlledCharacter->DoMove(MovementVector.X, MovementVector.Y);
}

void AUnrealTestPlayerController::Jump(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogTemp, Error, TEXT("Jumping"));
	
	GEngine->AddOnScreenDebugMessage(1234, 2.0f, FColor::Red, TEXT("JUMP ERROR!"));
}

void AUnrealTestPlayerController::StopJumping(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogTemp, Error, TEXT("Stop jumping"));
	GEngine->AddOnScreenDebugMessage(12345, 2.0f, FColor::Red, TEXT("JUMP ERROR!"));
}

void AUnrealTestPlayerController::Interact(const FInputActionValue& InputActionValue)
{
	ControlledCharacter->DoInteract();
}
