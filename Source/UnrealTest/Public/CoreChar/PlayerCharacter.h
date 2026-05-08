// Fill out your copyright notice in the Description page of Project Settings.


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
#include "UnrealTestCharacter.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class UNREALTEST_API APlayerCharacter : public AUnrealTestCharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
	
};
