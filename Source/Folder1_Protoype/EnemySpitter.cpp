// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpitter.h"

// Sets default values
AEnemySpitter::AEnemySpitter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpitter::BeginPlay()
{
	Super::BeginPlay();
	/*MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
    MoveDirection.Normalize();
    SetActorRotation(MoveDirection.Rotation());*/
	
}

// Called every frame
void AEnemySpitter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
    MoveDirection.Normalize();
    SetActorRotation(MoveDirection.Rotation());
    FVector NewLocation = GetActorLocation();
    NewLocation += (MoveDirection * Speed * DeltaTime);
    SetActorLocation(NewLocation);


    CurrentShootDelay -= DeltaTime;

    if (CurrentShootDelay < 0.f)
    {
        if (Ammo > 0)
            {
            UWorld* world = GetWorld();	//Henter peker til spillverdenen
                if (world)			//checking if the world exists
                {
                    FVector Location = GetActorLocation();   //getting the player pawn location
                    world->SpawnActor<ASlimeBullet>(ShotBlueprint, Location + FVector(0.f, 0.f, 0.f), GetActorRotation());
                }
            }
        
        CurrentShootDelay = FMath::FRandRange(ShootDelayMin, ShootDelayMax);
    }*/
}

void AEnemySpitter::Spitting()
{
    UWorld* world = GetWorld();	//Henter peker til spillverdenen
    if (world)			//checking if the world exists
    {
        FVector Location = GetActorLocation();   //getting the player pawn location
        world->SpawnActor<ASlimeBullet>(ShotBlueprint, Location + FVector(0.f, 0.f, 0.f), GetActorRotation());
    }
     CurrentShootDelay = FMath::FRandRange(ShootDelayMin, ShootDelayMax);
    
}

void AEnemySpitter::Turning()
{
    MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
    MoveDirection.Normalize();
    SetActorRotation(MoveDirection.Rotation());
}

// Called to bind functionality to input
void AEnemySpitter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

