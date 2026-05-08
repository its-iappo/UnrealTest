// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthSystem/Damageable.h"
#include "DamageableActor.generated.h"

UCLASS()
class UNREALTEST_API ADamageableActor : public AActor, public IDamageable
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UHealthComponent> HealthComponent;

public:
	// Sets default values for this actor's properties
	ADamageableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual UHealthComponent* GetHealthComponent_Implementation() const override { return HealthComponent; }

	virtual void ApplyDamage_Implementation(const float DamageAmount) override;
	virtual void Heal_Implementation(const float HealAmount) override;
	
};
