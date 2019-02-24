// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorShroud.h"
#include "Folder1_Protoype.h"
#include "Components/InputComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AActorShroud::AActorShroud()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Collision object and RootObject
    UShapeComponent* RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("My Enemy"));
    RootComponent = RootBox;

}

// Called when the game starts or when spawned
void AActorShroud::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorShroud::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//setting location
	FVector NewLocation = GetActorLocation();
    NewLocation += (MoveDirection * Speed * DeltaTime);
    SetActorLocation(NewLocation);

}

