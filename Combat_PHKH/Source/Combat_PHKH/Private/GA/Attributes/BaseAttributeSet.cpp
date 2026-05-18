// Fill out your copyright notice in the Description page of Project Settings.


#include "GA/Attributes/BaseAttributeSet.h"

UBaseAttributeSet::UBaseAttributeSet()
{
	Health = 100.f;
 	MaxHealth = 100.f;
	Stamina = 100.f;
	MaxStamina = 100.f;
}

void UBaseAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}