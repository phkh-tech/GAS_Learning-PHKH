// Fill out your copyright notice in the Description page of Project Settings.


#include "GA/Attributes/BaseAttributeSet.h"

UBaseAttributeSet::UBaseAttributeSet()
{
	
}

void UBaseAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}