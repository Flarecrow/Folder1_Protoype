// Fill out your copyright notice in the Description page of Project Settings.

#include "LittleGirl.h"
#include "Bullet.h"
#include "LittleGirlShadowDrop.h"
#include "EnemyGrabber.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/Decalcomponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/UObjectGlobals.h" 

// Sets default values
ALittleGirl::ALittleGirl()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//AutoPossessPlayer = EAutoReceiveInput::Player0;
   
    // Create a dummy root component we can attach things to.
    /*RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    // Create a visible object
    OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
 
    OurVisibleComponent->SetupAttachment(RootComponent);*/
}

// Called when the game starts or when spawned
void ALittleGirl::BeginPlay()
{
	Super::BeginPlay();

	//Set up collision shape
    //Finds the root component, so could be set that way
    /*CollisionBox = this->FindComponentByClass<UBoxComponent>();
    //CollisionBox->bGenerateOverlapEvents = true; //will call my function instead
    
    if (CollisionBox)
    {
        CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ALittleGirl::OnOverlap);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("CollisionBox not found!"));
    }*/
	
}

// Called every frame
void ALittleGirl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*if (!CurrentVelocity.IsZero())
    {
        FVector NewLocation = GetActorLocation() + (Speed * CurrentVelocity * DeltaTime);
        SetActorLocation(NewLocation);
    }

    if (Speed == 0)
    {
        TimeMotionless += DeltaTime;
        if (TimeMotionless > TimeBeforeSpeedReturn)
        {
            Speed = 20;
            TimeMotionless = 0;
        }
    }*/

}

// Called to bind functionality to input
void ALittleGirl::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//check(PlayerInputComponent);

	InputComponent->BindAxis("MoveX", this, &ALittleGirl::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &ALittleGirl::Move_YAxis);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ALittleGirl::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ALittleGirl::StopJumping);

	// Respond when our "Shoot" etc. keys are pressed or released.
    InputComponent->BindAction("Shoot", IE_Pressed, this, &ALittleGirl::Shoot);

}

//Movement functions for x and y
void ALittleGirl::Move_XAxis(float AxisValue)
{
	 if (AxisValue != 0.0f)
	 {
		 AddMovementInput(FVector(1.0f, 0.0f, 0.0f), AxisValue);
	 }
}
void ALittleGirl::Move_YAxis(float AxisValue)
{
	if (AxisValue != 0.0f)
	 {
		 AddMovementInput(FVector(0.0f, 1.0f, 0.0f), AxisValue);
	 }
}

void ALittleGirl::Shoot()
{
    ///Spawn one bullet if we have ammo
    if (Ammo > 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Shoot fired"))
        Ammo--;
        UWorld* world = GetWorld();	//Henter peker til spillverdenen
        if (world)			//checking if the world exists
        {
            FVector Location = GetActorLocation();   //getting the player pawn location
            world->SpawnActor<ALittleGirlShadowDrop>(ShotBlueprint, Location + FVector(-70.f, 0.f, 0.f), GetActorRotation());
            //world->SpawnActor<ALittleGirlShadowDrop>(ShotBlueprint, Location + FVector(-255.f, 0.f, 0.f), GetActorRotation());
        }
    }
}

void ALittleGirl::GainAmmo()
{
    Ammo++;
}

void ALittleGirl::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent,
                        int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    if(OtherActor->IsA(AEnemyGrabber::StaticClass()))
    {
        UE_LOG(LogTemp, Warning, TEXT("Player Hit"))
        //Died = true;
        //Speed = 0;
        //OtherActor->Speed{0};
        //this->SetActorHiddenInGame(true);
        //UGameplayStatics::SetGamePaused(GetWorld(), true);
    }

    if(OtherActor->IsA(ALittleGirlShadowDrop::StaticClass()))
    {
        Ammo = 1;
        UE_LOG(LogTemp, Warning, TEXT("Player Picked Up Clip"))
        OtherActor->Destroy();
    }
}

/*void ALittleGirl::Restart()
{
    if (Died)
    {
        ///Opens level once more
        UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
    }
}*/
