// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoorTwoPlates.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FOLDER1_PROTOYPE_API UOpenDoorTwoPlates : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoorTwoPlates();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:

//Set box for the pressure plate triggering
UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

UPROPERTY(EditAnywhere)
	ATriggerVolume* OtherPressurePlate;

UPROPERTY(EditAnywhere)
	AActor* PhysicalPlate;

UPROPERTY(EditAnywhere)
	AActor* OtherPhysicalPlate;

	bool Counter = false;
	bool PlateOneCounter = false;
	bool PlateTwoCounter = false;
	//	int Counter = 1;
//Select acto to trigger collision box
/*UPROPERTY(EditAnywhere)
AActor* ActorThatOpens;*/		
};
