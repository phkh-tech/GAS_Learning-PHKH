// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CombatUserWidget.h"

#include "Components/Button.h"

void UCombatUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (CloseUIButton)
	{
		CloseUIButton->OnClicked.AddDynamic(this, &UCombatUserWidget::TurnOffWidget);
	}
}

void UCombatUserWidget::TurnOffWidget()
{
	SetVisibility(ESlateVisibility::Hidden);
}
