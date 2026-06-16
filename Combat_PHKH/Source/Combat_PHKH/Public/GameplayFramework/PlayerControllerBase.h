

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "PlayerControllerBase.generated.h"

class UInputAction;
class UCombatUserWidget;
	
/**
 * 
 */
UCLASS()
class COMBAT_PHKH_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	// Assign Input Actions in Blueprint
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> ShowWidgetInputAction;
	
	// Instantiate Widget class
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	TSubclassOf<UCombatUserWidget> CombatWidgetClass;
	
private:
	
	// Cache instance of the widget
	UPROPERTY()
	TObjectPtr<UCombatUserWidget> CacheWidget;
	
	// Function bound to input action
	UFUNCTION()
	void OpenCombatMenu(const FInputActionValue& Value);
	
	void CreateCombatWidget();
};
