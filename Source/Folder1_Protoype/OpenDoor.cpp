// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Math/Rotator.h"
#include "Math/Vector.h"
#include "Components/SceneComponent.h"
#include "Math/UnrealMath.h"

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
//void UOpenDoor::Close
// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{	
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	/*Check if the pressure plate has correct overlapping actor
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))*/ 		//Use for Doors that need specific triggers

	/*TArray <AActor*> result;
	 PressurePlate->GetOverlappingActors(result);					
	 if (result.Num() > 0)*/										//Use for doors that dont need specific triggers

	/*sets rotation
	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f);*/

	FVector PlateLocation = PhysicalPlate->GetActorLocation();
	FVector ActorLocation = GetOwner()->GetActorLocation();
	TArray <AActor*> result;

	PressurePlate->GetOverlappingActors(result);
	if ((result.Num() == 0) && (Counter == false))
	{
		
		FVector PlateLocation = PhysicalPlate->GetActorLocation();
		FVector ActorLocation = GetOwner()->GetActorLocation(); //FMath::VInterp(GetOwner()->GetActorLocation(), WantedPosition, DeltaTime, 10.0f);
		Counter = true;
		UE_LOG(LogTemp, Warning, TEXT("Close"))
		AActor* Owner = GetOwner();

		 ActorLocation.Z += 400.0f;
		 PlateLocation.Z += 20.0f;
	

		GetOwner()->SetActorLocation(ActorLocation); 
		PhysicalPlate->SetActorLocation(PlateLocation);
		
	}
	else if ((result.Num() > 0) && (Counter == true))
	{

		FVector PlateLocation = PhysicalPlate->GetActorLocation();
		FVector ActorLocation = GetOwner()->GetActorLocation();
		
		Counter = false;
		UE_LOG(LogTemp, Warning, TEXT("Open"))
		AActor* Owner = GetOwner();

		ActorLocation.Z -= 400.0f;
		PlateLocation.Z -= 20.0f;


		GetOwner()->SetActorLocation(ActorLocation);
		PhysicalPlate->SetActorLocation(PlateLocation);

	}
	
}

