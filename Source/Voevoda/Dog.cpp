// Fill out your copyright notice in the Description page of Project Settings.


#include "Dog.h"
#include "ArmyBar.h"
#include <Components/WidgetComponent.h>
#include "Math/UnrealMathUtility.h"
// Sets default values
ADog::ADog(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (RootComponent == nullptr) {
		RootComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));
	}
	ArmyWidgetComp = ObjectInitializer.CreateDefaultSubobject<UWidgetComponent>(this, TEXT("ArmyBar"));
	ArmyWidgetComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Health = MaxHealth;
}


// Called when the game starts or when spawned
void ADog::BeginPlay()
{
	Super::BeginPlay();
	UArmyBar* ArmyBar = Cast<UArmyBar>(ArmyWidgetComp->GetUserWidgetObject());
	//ArmyBar->Infantry = Health; // CRUSH reading access vioaltion 
	//ArmyBar->OwnerDog=this; //CRUSH reading access vioaltion 
	//ArmyBar->InfantryBar->SetPercent(GetHealth() / GetMaxHealth()); отсюда не можем widget изменять: некомпилится(указатель InfantryBar неполный) 
	//ArmyBar->SetOwnerDog(this);
	//Health = FMath::RandRange(0.0f, MaxHealth);
}

// Called every frame
void ADog::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//SetActorLocation()
}

