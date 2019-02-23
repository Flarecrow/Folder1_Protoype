// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlimeBall.h"
#include "GameFramework/Pawn.h"
#include "EnemyShooter.generated.h"

class ASlimeBall;

UCLASS()
class FOLDER1_PROTOYPE_API AEnemyShooter : public APawn
{
	GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    AEnemyShooter();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    FVector MoveDirection = FVector(1.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, Category = "Spawning")
    TSubclassOf<class ASlimeBall> ShotBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn Setup")
    int Ammo = 1;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:

    UPROPERTY(EditAnywhere)
        float Speed = 0.f;

    UPROPERTY(EditAnywhere)
        UShapeComponent* RootBox = nullptr;
};
