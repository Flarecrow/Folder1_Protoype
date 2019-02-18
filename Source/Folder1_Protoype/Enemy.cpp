// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "MyPawn.h"

#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    ///A standard box collider with Overlap Events:
    RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("MyEnemy"));
    RootComponent = RootBox;
    RootBox->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
    MoveDirection.Normalize();
    SetActorRotation(MoveDirection.Rotation());
}

// Called every frame
void AEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
    
    MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
    MoveDirection.Normalize();
    SetActorRotation(MoveDirection.Rotation());
    FVector NewLocation = GetActorLocation();
    NewLocation += (MoveDirection * Speed * DeltaTime);
    SetActorLocation(NewLocation);
}

void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

