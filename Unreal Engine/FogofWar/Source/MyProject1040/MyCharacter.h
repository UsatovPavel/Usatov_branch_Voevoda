// MyCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MapGenerator.h"
#include "MyCharacter.generated.h"
enum Vision
{
	See     UMETA(DisplayName = "See"),
	Unsee   UMETA(DisplayName = "Unsee"),
};

UCLASS()
class MYPROJECT1040_API AMyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
  
    AMyCharacter();
	TArray<TArray<Vision>> MapVision;
    //TArray<TArray<TerrainType>> MapExplored;
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    
    virtual void BeginPlay() override;

    void MoveRightOrLeft(float Value);
    void MoveForwardOrBack(float Value);
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="MyVars")
	AMapGenerator *Location;
private:
    void InitMap();
};

