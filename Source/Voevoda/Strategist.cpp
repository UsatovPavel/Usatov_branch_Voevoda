// Fill out your copyright notice in the Description page of Project Settings.


#include "Strategist.h"
#include "Components/WidgetComponent.h"
#include "Math/Vector.h"
// Sets default values
AStrategist::AStrategist()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//User_near = true;

}
AStrategist::AStrategist(Location init_loc):AStrategist() {
	general.position = init_loc;
}

// Called when the game starts or when spawned
void AStrategist::BeginPlay()
{
	Super::BeginPlay();
	const FVector location = GetActorLocation();
	const FRotator rotation = GetActorRotation();
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, location, rotation);
	//ArmyWidgetComp = ObjectInitializer.CreateDefaultSubobject<UWidgetComponent>(this, TEXT("ArmyBar"));
	//ArmyWidgetComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void AStrategist::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	general.update_pos(this->GetActorLocation());
	FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector Strategist_Location = GetActorLocation();
	if ((Strategist_Location - PlayerLocation).Size() <= 10) {
		User_near = true;
	}
	else {
		User_near = true;
	}
}

