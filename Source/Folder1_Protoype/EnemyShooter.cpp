// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyShooter.h"


// Sets default values
AEnemyShooter::AEnemyShooter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyShooter::BeginPlay()
{
	Super::BeginPlay();
	MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
    MoveDirection.Normalize();
    SetActorRotation(MoveDirection.Rotation());
	
}

// Called every frame
void AEnemyShooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
    MoveDirection.Normalize();
    SetActorRotation(MoveDirection.Rotation());
    FVector NewLocation = GetActorLocation();
    NewLocation += (MoveDirection * Speed * DeltaTime);
    SetActorLocation(NewLocation);

    if (Ammo > 0)
    {
    UWorld* world = GetWorld();	//Henter peker til spillverdenen
        if (world)			//checking if the world exists
        {
            FVector Location = GetActorLocation();   //getting the player pawn location
            world->SpawnActor<ASlimeBullet>(ShotBlueprint, Location + FVector(255.f, 0.f, 0.f), GetActorRotation());
        }
	}
}

// Called to bind functionality to input
void AEnemyShooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

