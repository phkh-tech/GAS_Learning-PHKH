// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayFramework/PlayerControllerBase.h"
#include "UI/CombatUserWidget.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"


void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerControllerBase::CreateCombatWidget()
{
	if (IsLocalController() && CombatWidgetClass)
	{
		CacheWidget = CreateWidget<UCombatUserWidget>(this, CombatWidgetClass);
		if (CacheWidget)
		{
			CacheWidget->AddToViewport();
			CacheWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void APlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (ShowWidgetInputAction)
		{
			EnhancedInput->BindAction(ShowWidgetInputAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::OpenCombatMenu);
			
		}
	}
}

void APlayerControllerBase::OpenCombatMenu(const FInputActionValue& Value)
{
	if (!CacheWidget)
	{
		CreateCombatWidget();
	}
	
	if (!CacheWidget) return;
	
	if (CacheWidget->IsVisible())
	{
		CacheWidget->SetVisibility(ESlateVisibility::Hidden);
		
		FInputModeGameOnly GameMode;
		SetInputMode(GameMode);
		bShowMouseCursor = false;
	}
	else
	{
		CacheWidget->SetVisibility(ESlateVisibility::Visible);
		
		//Pause the game when the widget is open
		SetPause(true);
		
		// Explicitly tell tell the input system to focus on the widget when it's opened
		FInputModeUIOnly UIMode;
		UIMode.SetWidgetToFocus(CacheWidget->GetCachedWidget());
		UIMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		
		SetInputMode(UIMode);
		bShowMouseCursor = true;
	}
}
