// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LittleGirl.generated.h"

class ABullet;
class ALittleGirlShadowDrop;
class UShapeComponent;
class USceneComponent;

UCLASS()
class FOLDER1_PROTOYPE_API ALittleGirl : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALittleGirl();

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
	void GainAmmo();
	void UpdateSpeed();
	//void Restart();

	//creating Character Setup
	/*UPROPERTY(EditAnywhere, Category = "Character Setup")
	USceneComponent* OurVisibleComponent;*/

	//set speed
	/*UPROPERTY(EditAnywhere, Category = "Character Setup")
    int Speed = 20;*/

	//The bullet the Character shoots
    //UPROPERTY(EditAnywhere, Category = "Character Setup")
    //TSubclassOf<class ABullet> BulletBlueprint;

	//one of these works the other don't, im to scare to remove one.
	UPROPERTY(EditAnywhere, Category = "Spawning")
    TSubclassOf<ALittleGirlShadowDrop> ShotBlueprint;

	//set velocity
	//FVector CurrentVelocity;

	//set time before speed returns after colliding with enemy
	/*UPROPERTY(EditAnywhere)
    float TimeBeforeSpeedReturn = 5.f;
    
    float TimeMotionless{0};

	//Holds whether the pawn is dead or not
    bool Died = false;

	UShapeComponent* CollisionBox = nullptr;*/

	//How much ammo does the pawn have now
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Setup")
    int Ammo = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Setup")
    float SpeedFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Setup")
    float BaseSpeed;

	//set overlap
	UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, 
					UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, 
							bool bFromSweep, const FHitResult &SweepResult);
 
};
