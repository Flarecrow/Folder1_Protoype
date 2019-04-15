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
}

// Called every frame
void AEnemySpitter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemySpitter::Spitting() //this is the enemy's shooting function
{
    UWorld* world = GetWorld();	//Gets pointer to the gameworld
    if (world)			//checking if the world exists
    {
        UE_LOG(LogTemp, Warning, TEXT("Shoot fired"))
        FVector Location = GetActorLocation();   //getting the player pawn location
        world->SpawnActor<ASlimeBullet>(ShotBlueprint, Location + FVector(0.f, 0.f, 0.f), GetActorRotation());
    }
     CurrentShootDelay = FMath::FRandRange(ShootDelayMin, ShootDelayMax);
    
}

void AEnemySpitter::Turning() //this is the moving function
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

