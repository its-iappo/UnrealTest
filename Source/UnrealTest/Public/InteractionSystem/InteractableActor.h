// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

UCLASS()
class UNREALTEST_API AInteractableActor : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation() override;
};
