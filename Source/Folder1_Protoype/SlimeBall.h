// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SlimeBall.generated.h"

class UShapeComponent;

UCLASS()
class FOLDER1_PROTOYPE_API ASlimeBall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASlimeBall();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
    /**Speed of bullet*/
    UPROPERTY(EditAnywhere)
    float Speed = 10.f;
    
    /**Time before bullet selfdestruct*/
    UPROPERTY(EditAnywhere)
    float TimeBeforeDestroy = 5.f;
    
    float TimeLived{0};
    
    /**The collision shape of the bullet*/
    UPROPERTY(EditAnywhere)
    UShapeComponent* RootSphere = nullptr;

	UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
                   UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
                   bool bFromSweep, const FHitResult &SweepResult);

};
