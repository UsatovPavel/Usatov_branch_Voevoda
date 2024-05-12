// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmyBar.h"
#include <Components/ProgressBar.h>
#include <Components/TextBlock.h>
void UArmyBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (!OwnerDog.IsValid()) {
		return;
	}
	
	InfantryBar->SetPercent(Infantry / MaxInfantry);

	/*FNumberFormattingOptions Opts;
	Opts.SetMaximumFractionalDigits(0);
	CurrentInfantryLabel->SetText(FText::AsNumber(OwnerDog->GetHealth(), &Opts));
	MaxInfantryLabel->SetText(FText::AsNumber(OwnerDog->GetMaxHealth(), &Opts));*/
}