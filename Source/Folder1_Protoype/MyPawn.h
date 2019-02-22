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

	UPROPERTY(EditAnywhere, Category = "Pawn Setup")
	USceneComponent* OurVisibleComponent;

	UPROPERTY(EditAnywhere, Category = "Pawn Setup")
    int Speed = 15;

	/**The bullet the pawn shoots*/
    UPROPERTY(EditAnywhere, Category = "Pawn Setup")
    TSubclassOf<class ABullet> BulletBlueprint;

	UPROPERTY(EditAnywhere, Category = "Spawning")
    TSubclassOf<ABullet> ShotBlueprint;

	FVector CurrentVelocity;

	/**Holds whether the pawn is dead or not*/
    bool Died = false;

	UShapeComponent* CollisionBox = nullptr;

	/**How much ammo does the pawn have now*/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn Setup")
    int Ammo = 1;

	 UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, 
					UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, 
							bool bFromSweep, const FHitResult &SweepResult);
 
	
};
