// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CombatUserWidget.h"

#include "Components/Button.h"

void UCombatUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	UE_LOG(LogTemp, Warning, TEXT("CombatUserWidget dang duoc dung"));
	
	if (CloseUIButton)
	{
		CloseUIButton->OnClicked.AddDynamic(this, &UCombatUserWidget::TurnOfWidget);
	}
}

void UCombatUserWidget::TurnOfWidget()
{
	SetVisibility(ESlateVisibility::Hidden);
}
