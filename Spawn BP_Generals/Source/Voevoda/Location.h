// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class VOEVODA_API Location
{
public:
	int32 x;
	int32 y;
	Location(): x(0), y(0){ }
	Location(const int32 x_, const int32 y_):x(x_), y(y_) {}
	FVector UE_coordinates() {
		return FVector(64.f * x+32, -64.f * y-32, 1.f);
	}
	int32 operator -(Location other) {
		return x - other.x + y - other.y;
	}
};
