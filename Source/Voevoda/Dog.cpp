// Fill out your copyright notice in the Description page of Project Settings.


#include "Dog.h"
#include <Components/WidgetComponent.h>
// Sets default values
ADog::ADog(const FObjectInitializer& ObjectInitializer)
{
 	PrimaryActorTick.bCanEverTick = true;
	if (RootComponent == nullptr)
	{
		RootComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));
	}
	HealthWidgetComp = ObjectInitializer.CreateDefaultSubobject<UWidgetComponent>(this, TEXT("HealthBar"));
	HealthWidgetComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ADog::BeginPlay()
{
	Super::BeginPlay();
	Health = FMath::RandRange(0.0f, MaxHealth);
}

// Called every frame
void ADog::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

