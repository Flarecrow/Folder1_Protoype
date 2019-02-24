// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class ABullet;
class UShapeComponent;
class USceneComponent;

UCLASS()
class FOLDER1_PROTOYPE_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//setting the void functions
	void Move_XAxis(float AxisValue);
    void Move_YAxis(float AxisValue);
	void Shoot();
	void Restart();

	//creating Pawn Setup
	UPROPERTY(EditAnywhere, Category = "Pawn Setup")
	USceneComponent* OurVisibleComponent;
	//set speed
	UPROPERTY(EditAnywhere, Category = "Pawn Setup")
    int Speed = 20;

	//The bullet the pawn shoots
    UPROPERTY(EditAnywhere, Category = "Pawn Setup")
    TSubclassOf<class ABullet> BulletBlueprint;

	//one of these works the other don't, im to scare to remove one.
	UPROPERTY(EditAnywhere, Category = "Spawning")
    TSubclassOf<ABullet> ShotBlueprint;

	//set velocity
	FVector CurrentVelocity;

	//set time before speed returns after colliding with enemy
	UPROPERTY(EditAnywhere)
    float TimeBeforeSpeedReturn = 5.f;
    
    float TimeMotionless{0};

	//Holds whether the pawn is dead or not
    bool Died = false;

	UShapeComponent* CollisionBox = nullptr;

	//How much ammo does the pawn have now
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn Setup")
    int Ammo = 1;

	//set overlap
	 UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, 
					UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, 
							bool bFromSweep, const FHitResult &SweepResult);
 
	
};
