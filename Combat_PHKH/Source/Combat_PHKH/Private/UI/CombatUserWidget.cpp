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
	SetIsFocusable(true);
}

FReply UCombatUserWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	TurnOffWidget();
	return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
}

FReply UCombatUserWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	TurnOffWidget();
	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

void UCombatUserWidget::TurnOffWidget()
{
	SetVisibility(ESlateVisibility::Hidden);

	if (APlayerController* PC = GetOwningPlayer())
	{
		//Unpause the game when the widget is closed
		PC->SetPause(false);
		
		FInputModeGameOnly GameMode;
		PC->SetInputMode(GameMode);
		PC->bShowMouseCursor = false;
	}
}
