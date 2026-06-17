// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CombatUserWidget.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class COMBAT_PHKH_API UCombatUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
	UPROPERTY(META=(BindWidget))
	TObjectPtr<UButton> CloseUIButton;
	
private:
	UFUNCTION()
	void TurnOffWidget();
	
};
