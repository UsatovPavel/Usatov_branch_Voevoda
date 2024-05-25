// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/IntPoint.h"

/**
 * 
 */
class VOEVODA_API Location:public FIntPoint
{
public:
	Location(): FIntPoint(0, 0){}
	Location(const int32 x_, const int32 y_):FIntPoint(x_, y_){}
	FVector UE_coordinates() {
		return FVector(64.f * X+32, -64.f * Y-32, 1.f);
	}
	int32 Manh_dist(Location second) {
		return (*this - second).X + (*this - second).Y;
	}
};