// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlimeBullet.h"
#include "GameFramework/Character.h"
#include "EnemySpitter.generated.h"

UCLASS()
class FOLDER1_PROTOYPE_API AEnemySpitter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemySpitter();

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

    //These functions determins if the enemy should be turning and spitting
    UFUNCTION(BlueprintCallable, Category = "Spitting")
    void Spitting();

    UFUNCTION(BlueprintCallable, Category = "Turning")
    void Turning();

private:

    //the enemies move speed, its at 0 because the enmey isn't suppose to move.
    UPROPERTY(EditAnywhere)
    float Speed = 0.f;

    //collision box
    UPROPERTY(EditAnywhere)
    UShapeComponent* RootBox = nullptr;

    //Delay for shooting
    UPROPERTY(EditAnywhere)
    float ShootDelayMax = 5.f;

    UPROPERTY(EditAnywhere)
    float ShootDelayMin = 3.f;

    float CurrentShootDelay;
};
