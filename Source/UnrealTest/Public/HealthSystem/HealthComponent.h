// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthValueChangedSignature, float, OldValue, float, NewValue);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UNREALTEST_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	float CurrentHealth = 0.0f;
	
	bool bCanBeDamaged = true;

public:
	UPROPERTY(BlueprintAssignable)
	FOnHealthValueChangedSignature OnHealthValueChangedDelegate;
	
	UHealthComponent();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (UIMin = 0.0f, ClampMin = 0.0f))
	float MaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bStartWithMaxHealth = true;
	
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void ApplyDamage(const float DamageAmount);	
	
	UFUNCTION(BlueprintCallable)
	void Heal(const float HealAmount);
};
