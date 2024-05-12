// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/UnrealString.h"
#include "Containers/Array.h"
#include "TerrainType.h"
#include "General.h"
#include "Scout.h"
#include "PlayerGameSessionStatistic.h"
#include "BaseStrategist.h"
#include "Strategist.generated.h"

UCLASS()
class VOEVODA_API AStrategist : public AActor, public BaseStrategist
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	TSubclassOf<AActor> ActorToSpawn;
public:
	AStrategist();
	AStrategist(Location init_loc);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
