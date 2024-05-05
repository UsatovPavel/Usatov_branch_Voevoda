#include "GameWorld.h"
#include "CoreMinimal.h"
#include "EngineUtils.h"
#include "GameFramework/Actor.h"
#include "Templates/SharedPointer.h"
#include "BattleResponseModel.h"

AGameWorld::AGameWorld() {

    PrimaryActorTick.bCanEverTick = true;

}

void AGameWorld::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    TOptional<Location> battle_location;
    for (int i = 1; i<strategists.Num(); i++) {
        if (strategists[i]->general.position - strategists[0]->general.position == 1) {
            battle_location = strategists[i]->general.position;
        }
    }
    if (battle_location.IsSet()) {
        BattleResponseModel(strategists, battle_location.GetValue(), *map_ptr);
    }
}

void AGameWorld::BeginPlay() {
    Super::BeginPlay();

    for (TActorIterator<AMapPainter> ActorItr(GetWorld()); ActorItr;
        ++ActorItr) {

        painter_ptr = Cast<AMapPainter>(*ActorItr);
        map_ptr = &(painter_ptr->map);
    }

    if (painter_ptr) {
        //AStrategist* Spawned_strateg =
        //GetWorld()->SpawnActor<AStrategist>(AStrategist::StaticClass(), FVector(100.f, 100.f, 0.f), FRotator::ZeroRotator);
        //TWeakObjectPtr<AStrategist>(Spawned_strateg));
        for (auto& general_pos : map_ptr->GeneralsInitPos) {
            AActor* Spawned_strateg =
            GetWorld()->SpawnActor<AActor>(BP_Strategist, general_pos.UE_coordinates(), FRotator::ZeroRotator);
            strategists.Add(Cast<AStrategist>(Spawned_strateg));
            //TSharedPtr<General> Strategist_ptr(new General());//work
            //TSharedPtr<AStrategist> (MakeShareable(AStrategist(general_pos)));//not work
            //strategists.Add(&new_strat1egist);
        }
        for (auto& castle_pos : map_ptr->CastlesInitPos) {
            //AStructure new_castle(castle_pos);
            //structures.Add(&new_castle);
        }
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("painter_ptr is nullptr."));
    }
}