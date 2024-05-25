// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dog.generated.h"

UCLASS()
class VOEVODA_API ADog : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADog(const FObjectInitializer& ObjectInitializer);
	virtual void Tick(float DeltaTime) override;
	float GetHealth() const { return Health; }
	void SetHealth(float val) { Health = val; }
	float GetMaxHealth() const { return MaxHealth; }
	void SetMaxHealth(float val) { MaxHealth = val; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
		class UWidgetComponent* HealthWidgetComp;
	FVector MovementVelocity;
	float Health;
	float MaxHealth = 120;
	float HealthTweenDirection;

};
