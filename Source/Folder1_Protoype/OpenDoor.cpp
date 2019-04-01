// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Math/Rotator.h"
#include "Math/Vector.h"
#include "Components/SceneComponent.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	/*Check if the pressure plate has correct overlapping actor
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))*/ 		//Use for Doors that need specific openers.

	/*TArray <AActor*> result;

	 PressurePlate->GetOverlappingActors(result);					//Use for doors that need any openers.
	 if (result.Num() > 0)*/


	

	 TArray <AActor*> result;

	 PressurePlate->GetOverlappingActors(result);
	 if (result.Num() > 0)
	{
	AActor* Owner = GetOwner();
	/*sets rotation
	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f);*/
	FVector ActorLocation = GetActorLocation();

	FVector NewLocation = ActorLocation + FVector(0.f, 10.f, 0.f); 
	Owner->ActorLocation(NewLocation);
	}

	
	PressurePlate->GetOverlappingActors(result);
	 if (result.Num() == 0)
	{
	AActor* Owner = GetOwner();
	FVector ActorLocation = GetActorLocation();

	FVector NewLocation = ActorLocation - FVector(0.f, -10.f, 0.f); 
	Owner->ActorLocation(NewLocation);
	}
}

