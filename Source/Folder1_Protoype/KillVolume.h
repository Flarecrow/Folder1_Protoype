// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "KillVolume.generated.h"

UCLASS()
class FOLDER1_PROTOYPE_API AKillVolume : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AKillVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, 
					UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, 
							bool bFromSweep, const FHitResult &SweepResult);

};
