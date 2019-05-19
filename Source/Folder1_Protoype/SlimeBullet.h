// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SlimeBullet.generated.h"

UCLASS()
class FOLDER1_PROTOYPE_API ASlimeBullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASlimeBullet();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
    
    /**Speed of bullet*/
    UPROPERTY(EditAnywhere)
    float Speed = 500.f;

    //set randomizer speed for player
    UPROPERTY(EditAnywhere)
    float MinReducedPlayerSpeed = 100.f;

    float MaxReducedPlayerSpeed = 200.f;
    
    float PlayerMaxSpeed = 300.f;

    UPROPERTY(EditAnywhere)
    float TimeBeforeDestroyed = 5.f;
    
    float TimeLeft{0};

    //does the bullet hit the player
    UPROPERTY(EditAnywhere)
    bool HitPlayer = false;
    
    /**The collision shape of the bullet*/
    UPROPERTY(VisibleAnywhere)
    UShapeComponent* RootSphere = nullptr;

	UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
                   UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
                   bool bFromSweep, const FHitResult &SweepResult);
};
