// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LittleGirlShadowDrop.h"
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
	void Sprint();
	void GainAmmo();
	void BreakFree();

	//one of these works the other don't, im to scare to remove one.
	UPROPERTY(EditAnywhere, Category = "Spawning")
    TSubclassOf<ALittleGirlShadowDrop> ShotBlueprint;

	//set time before speed returns after colliding with enemy bullets
	UPROPERTY(EditAnywhere)
    float TimeBeforeSpeedReturn = 5.f;
    
    float TimeMotionless{0};

	//set time before you die when grabbed by enemy
	UPROPERTY(EditAnywhere)
    float TimeBeforeDeath = 2.f;
    
    float TimeGrabbed{0};

	//How much ammo does the pawn have now
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Setup")
    int Ammo = 0;

    //These variables are for the break free function
	UPROPERTY(EditAnywhere)
    float MinStruggle = 8.f;
    float MaxStruggle = 24.f;
    float StruggleCounter = 0.f;
    float StruggleReleaseNumber;

	//set overlap and on comp hit, none of them works unfortunatly
	UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, 
					UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, 
							bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, 
					UPrimitiveComponent* OtherComp, FVector NormalImpulse, 
						const FHitResult& Hit);
	

};
