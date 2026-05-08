// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractionSystem/InteractableActor.h"

void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Execute_Interact(this);
}

void AInteractableActor::Interact_Implementation()
{
	IInteractable::Interact_Implementation();
	UE_LOG(LogTemp, Warning, TEXT("Interact!"));
	GEngine->AddOnScreenDebugMessage(12134, 2.0f, FColor::Orange, TEXT("INTERACT!"));
}

