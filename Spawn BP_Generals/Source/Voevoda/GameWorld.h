// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EngineUtils.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Actor.h"
#include "PaperTileLayer.h"
#include "PaperTileMapActor.h"
#include "PaperTileMapComponent.h"
#include "PaperTileSet.h"
#include "Army.h"
#include "TerrainType.h"
#include "GameMap.h"
#include "MapPainter.h"
#include "Strategist.h"
#include "Structure.h"
#include "MyPlayerCharacter.h"
#include "GameWorld.generated.h"

UCLASS()
class VOEVODA_API AGameWorld : public AActor {
    GENERATED_BODY()

public:
    AGameWorld();
    virtual void Tick(float DeltaTime) override;

public:
    virtual void BeginPlay() override;

private:
    // UPROPERTY(EditAnywhere, Category = "TileMap")
    GameMap* map_ptr;
    AMapPainter* painter_ptr;
    //TArray<TWeakObjectPtr<AActor>> strategists; Not work
    TArray<AStrategist*> strategists;
    TArray<AStructure*> structures;
    //AMyPlayerCharacter* player_ptr = UGameplayStatics::GetPlayerCharacter();
public:
    UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = True))
        TSubclassOf<AActor> BP_Strategist;//BP_General - AStrategist с компонентой-полем.
};
