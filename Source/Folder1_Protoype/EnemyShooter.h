// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlimeBullet.h"
#include "GameFramework/Pawn.h"
#include "EnemyShooter.generated.h"

class ASlimeBullet;

UCLASS()
class FOLDER1_PROTOYPE_API AEnemyShooter : public APawn
{
	GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    AEnemyShooter();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    //Set move direction
    FVector MoveDirection = FVector(1.f, 0.f, 0.f);

    //acsess slimebullet blueprint
	UPROPERTY(EditAnywhere, Category = "Spawning")
    TSubclassOf<class ASlimeBullet> ShotBlueprint;

    //set ammo if we want to use it
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Setup")
    int Ammo = 1;


private:

    //move speed
    UPROPERTY(EditAnywhere)
        float Speed = 0.f;

    //collision box
    UPROPERTY(EditAnywhere)
        UShapeComponent* RootBox = nullptr;

    UPROPERTY(EditAnywhere)
    float ShootDelayMax = 8.f;

    UPROPERTY(EditAnywhere)
    float ShootDelayMin = 5.f;

    float CurrentShootDelay;
};
