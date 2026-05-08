// Fill out your copyright notice in the Description page of Project Settings.


#include "Npc/DamageableActor.h"

#include "HealthSystem/HealthComponent.h"


// Sets default values
ADamageableActor::ADamageableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	HealthComponent=CreateDefaultSubobject<UHealthComponent>(FName("HealthComponent"));
}

// Called when the game starts or when spawned
void ADamageableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamageableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADamageableActor::ApplyDamage_Implementation(const float DamageAmount)
{
	IDamageable::ApplyDamage_Implementation(DamageAmount);
	
	HealthComponent->ApplyDamage(DamageAmount);
}

void ADamageableActor::Heal_Implementation(const float HealAmount)
{
	IDamageable::Heal_Implementation(HealAmount);
	
	HealthComponent->Heal(HealAmount);
}
