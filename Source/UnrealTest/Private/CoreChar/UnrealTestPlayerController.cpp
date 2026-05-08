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
	
		EIC->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AUnrealTestPlayerController::Interact);
		
		EIC->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AUnrealTestPlayerController::Attack);
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
	ControlledCharacter->DoJump();
	
	UE_LOG(LogTemp, Error, TEXT("JUMP ERROR! JUMP SHOULD NOT BE IMPLEMENTED!"));
	UE_LOG(LogTemp, Warning, TEXT("SHUT UP! I'LL DO IT ANYWAY!"));
	
	GEngine->AddOnScreenDebugMessage(1234, 2.0f, FColor::Red, TEXT("JUMP ERROR!"));
	GEngine->AddOnScreenDebugMessage(1234, 2.0f, FColor::Red, TEXT("SHUT UP AND JUMP!"));

}

void AUnrealTestPlayerController::StopJumping(const FInputActionValue& InputActionValue)
{
	ControlledCharacter->DoStopJumping();
	
	UE_LOG(LogTemp, Error, TEXT("STOP JUMPING ERROR! STOP JUMPING SHOULD NOT BE IMPLEMENTED!"));
	UE_LOG(LogTemp, Warning, TEXT("SHUT UP! I'LL DO IT ANYWAY!"));
	
	GEngine->AddOnScreenDebugMessage(12345, 2.0f, FColor::Red, TEXT("JUMP ERROR!"));
	GEngine->AddOnScreenDebugMessage(1234, 2.0f, FColor::Red, TEXT("SHUT UP AND JUMP!"));
}

void AUnrealTestPlayerController::Interact()
{
	ControlledCharacter->DoInteract();
}

void AUnrealTestPlayerController::Attack()
{
	ControlledCharacter->DoAttack();
}
