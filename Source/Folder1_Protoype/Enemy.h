// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Enemy.generated.h"

class UShapeComponent;

UCLASS()
class FOLDER1_PROTOYPE_API AEnemy : public APawn
{
	GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    AEnemy();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    //set directional movement
    FVector MoveDirection = FVector(1.f, 0.f, 0.f);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    //set move speed
    UPROPERTY(EditAnywhere)
        float Speed = 100.f;
    //set rootbox
    UPROPERTY(EditAnywhere)
        UShapeComponent* RootBox = nullptr;
    //set overlap event
    UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, 
					UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, 
							bool bFromSweep, const FHitResult &SweepResult);
};

