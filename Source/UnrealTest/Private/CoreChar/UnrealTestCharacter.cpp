// Copyright Epic Games, Inc. All Rights Reserved.

#include "Public/CoreChar/UnrealTestCharacter.h"

#include "Engine/LocalPlayer.h"
#include "GameFramework/Controller.h"
#include "Components/CapsuleComponent.h"
#include "Engine/OverlapResult.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "HealthSystem/HealthComponent.h"
#include "InteractionSystem/Interactable.h"

AUnrealTestCharacter::AUnrealTestCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
}

void AUnrealTestCharacter::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void AUnrealTestCharacter::DoLook(float Yaw, float Pitch)
{
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void AUnrealTestCharacter::DoJumpStart()
{
	Jump();
}

void AUnrealTestCharacter::DoJumpEnd()
{
	StopJumping();
}

void AUnrealTestCharacter::Interact()
{
	TArray<FOverlapResult> Overlaps;

	GetWorld()->OverlapMultiByChannel(Overlaps,
	                                  GetActorLocation(), FQuat::Identity,
	                                  ECollisionChannel::ECC_Visibility,
	                                  FCollisionShape::MakeSphere(InteractionRadius)
	);
	
	for (const auto& Overlap : Overlaps)
	{
		if (Overlap.GetActor()->Implements<UInteractable>())
		{
			IInteractable::Execute_Interact(Overlap.GetActor());
		}
	}
}

void AUnrealTestCharacter::ApplyDamage_Implementation(const float DamageAmount)
{
	HealthComponent->Heal(DamageAmount);
}

void AUnrealTestCharacter::Heal_Implementation(const float HealAmount)
{
	HealthComponent->ApplyDamage(HealAmount);
}
