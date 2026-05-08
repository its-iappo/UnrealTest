// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Damageable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UDamageable : public UInterface
{
	GENERATED_BODY()
};

class UNREALTEST_API IDamageable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category = Damageable)
	class UHealthComponent* GetHealthComponent() const;
	
	UFUNCTION(BlueprintNativeEvent, Category = Damageable)
	void ApplyDamage(const float DamageAmount);
	
	UFUNCTION(BlueprintNativeEvent, Category = Damageable)
	void Heal(const float HealAmount);
	
};
