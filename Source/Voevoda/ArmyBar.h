// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Dog.h"
#include "ArmyBar.generated.h"

UCLASS(Abstract)
class VOEVODA_API UArmyBar : public UUserWidget
{
	GENERATED_BODY()
public:
	int Infantry;
	int MaxInfantry = 100;
	void SetOwnerDog(ADog* InDog) { OwnerDog = InDog; }
	friend class ADog;
protected:
	TWeakObjectPtr<ADog> OwnerDog;
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* InfantryBar;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CurrentInfantryLabel;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* MaxInfantryLabel;

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

};
