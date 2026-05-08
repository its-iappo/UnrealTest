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


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HealthSystem/Damageable.h"
#include "Logging/LogMacros.h"
#include "UnrealTestCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All)

/**
 *  A simple player-controllable third person character
 *  Implements a controllable orbiting camera
 */
UCLASS(abstract)
class AUnrealTestCharacter : public ACharacter, public IDamageable
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UHealthComponent> HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interactions", meta = (AllowPrivateAccess = "true"))
	float InteractionRadius = 0.0f;

public:
	AUnrealTestCharacter();
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);

	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoLook(float Yaw, float Pitch);

	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void Interact();
	UFUNCTION(BlueprintCallable, Category="Input")
	

	virtual UHealthComponent* GetHealthComponent_Implementation() const override { return HealthComponent; }

	virtual void ApplyDamage_Implementation(const float DamageAmount) override;
	virtual void Heal_Implementation(const float HealAmount) override;
};
