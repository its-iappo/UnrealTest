// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthSystem/HealthComponent.h"


UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if (bStartWithMaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
}

void UHealthComponent::ApplyDamage(const float DamageAmount)
{
	if (!bCanBeDamaged) return;
	
	const float OldValue = CurrentHealth;
	
	CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.f, MaxHealth);
	
	bCanBeDamaged = CurrentHealth != 0.0f;
	
	OnHealthValueChangedDelegate.Broadcast(OldValue, CurrentHealth);
	
	if (CurrentHealth <= 0.0f) //little debug log for the funsies
	{
		UE_LOG(LogTemp,Warning,TEXT("Dead"));
	}
}

void UHealthComponent::Heal(const float HealAmount)
{
	const float OldValue = CurrentHealth;
	
	CurrentHealth = FMath::Clamp(CurrentHealth + HealAmount, 0.f, MaxHealth);
	
	bCanBeDamaged = CurrentHealth != 0.0f;
	
	OnHealthValueChangedDelegate.Broadcast(OldValue, CurrentHealth);
}
