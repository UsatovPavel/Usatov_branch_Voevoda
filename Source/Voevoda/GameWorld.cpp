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
    for (int i = 0; i<strategists.Num(); i++) {
        if (((strategists[i]->general.position).Manh_dist(player_ptr->general.position) <= 1) && (player_ptr->general.position != Location(0, 0))) {
            battle_location = strategists[i]->general.position;
        }
    }
    if (battle_location.IsSet()) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue,
            FString::Printf(TEXT("battle_location x %lld"), battle_location.GetValue().X));
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue,
            FString::Printf(TEXT("battle_location y %lld"), battle_location.GetValue().Y));
        BattleResponseModel(strategists, battle_location.GetValue(), *map_ptr,player_ptr);
    }
}

void AGameWorld::BeginPlay() {
    Super::BeginPlay();

    for (TActorIterator<AMapPainter> ActorItr(GetWorld()); ActorItr;
        ++ActorItr) {

        painter_ptr = Cast<AMapPainter>(*ActorItr);
        map_ptr = &(painter_ptr->map);
    }
    for (TActorIterator<AMyPlayerCharacter> ActorItr(GetWorld()); ActorItr;
        ++ActorItr) {
        player_ptr = Cast<AMyPlayerCharacter>(*ActorItr);
    }
    if (painter_ptr&&player_ptr) {
        for (auto& general_pos : map_ptr->GeneralsInitPos) {
            AActor* Spawned_strateg =
            GetWorld()->SpawnActor<AActor>(BP_Strategist, general_pos.UE_coordinates(), FRotator::ZeroRotator);
            strategists.Add(Cast<AStrategist>(Spawned_strateg));
            //strategists.Last()->general.army_size.rand(strategists.Num());//this seed rand() in army;
            //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("i seed generator this number %lld"), strategists.Last()->general.army_size.Infantry));
        }
        strategists[0]->general.army_size.Infantry = 1000;//widget берёт данные у первого
        strategists[0]->general.position = { 2005, 78 };
        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("infantry deleted strategist %lld"), strategists[0]->general.army_size.Infantry));
        //strategists[0]->Destroy();

        for (auto& castle_pos : map_ptr->CastlesInitPos) {
            //AStructure new_castle(castle_pos);
            //structures.Add(&new_castle);
        }
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("painter_ptr(MAP) or player_ptr(UserCharacter) is nullptr."));
    }
}
TArray<AStrategist*> AGameWorld::get_alive_strategists() {
    TArray<AStrategist*> alive_strategists;
    for (auto &strateg : strategists) {
        if (!strateg->is_dead()) {
            alive_strategists.Add(strateg);
        }
    }
    return TArray<AStrategist*>();
}