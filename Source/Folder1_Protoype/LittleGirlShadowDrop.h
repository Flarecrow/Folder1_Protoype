// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LittleGirlShadowDrop.generated.h"

UCLASS()
class FOLDER1_PROTOYPE_API ALittleGirlShadowDrop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALittleGirlShadowDrop();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    FVector MoveDirection = FVector(1.f, 0.f, 0.f);

    void ReturnToPlayer();
    void ReturnShadow();

private:
    /**Speed of bullet*/
    UPROPERTY(EditAnywhere)
    float Speed = 0.f;
    
    UPROPERTY(EditAnywhere)
    bool Return = false;
    
    /**Time before bullet selfdestruct*/
    UPROPERTY(EditAnywhere)
    float TimeBeforeDestroy{7.f};
    
    float TimeLived{0};
    
    /**The collision shape of the bullet*/
    UPROPERTY(EditAnywhere)
    UShapeComponent* RootSphere = nullptr;

	UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
                   UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
                   bool bFromSweep, const FHitResult &SweepResult);

};
