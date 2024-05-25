// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ArmyBar.generated.h"

/**
 * 
 */
UCLASS( Abstract )
class VOEVODA_API UArmyBar : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* InfantryBar;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CurrentInfantryLabel;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* MaxInfantryLabel;
};
