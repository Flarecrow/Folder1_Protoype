// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoorTwoPlates.h"
#include "GameFramework/Actor.h"
#include "Math/Rotator.h"
#include "Math/Vector.h"
#include "Components/SceneComponent.h"

// Sets default values for this component's properties
UOpenDoorTwoPlates::UOpenDoorTwoPlates()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoorTwoPlates::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOpenDoorTwoPlates::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

		/*Check if the pressure plate has correct overlapping actor
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))*/ 		//Use for Doors that need specific triggers

	/*TArray <AActor*> result;
	 PressurePlate->GetOverlappingActors(result);					
	 if (result.Num() > 0)*/										//Use for doors that dont need specific triggers

	/*sets rotation
	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f);*/

	
	FVector ActorLocation = GetOwner()->GetActorLocation();

	TArray <AActor*> PlateOneResult;
	TArray <AActor*> PlateTwoResult;

	OtherPressurePlate->GetOverlappingActors(PlateTwoResult);
	PressurePlate->GetOverlappingActors(PlateOneResult);

	UE_LOG(LogTemp, Warning, TEXT("after overlapped"))
	UE_LOG(LogTemp, Warning, TEXT("%d"), PlateOneResult.Num() )
	UE_LOG(LogTemp, Warning, TEXT("%d"), PlateTwoResult.Num() )
	UE_LOG(LogTemp, Warning, TEXT("%d"), Counter ? 1 : 0)

	if ((PlateOneResult.Num() == 0) && (PlateTwoResult.Num() == 0) && (Counter == false))
	{
		FVector ActorLocation = GetOwner()->GetActorLocation();
		Counter = true;
		UE_LOG(LogTemp, Warning, TEXT("Close"))
		AActor* Owner = GetOwner();

		ActorLocation.Z -= 400.0f;

		/*while(ActorLocation.Z > DoorIsClosed)				give the door a smooth transition from open to closed
			{
				ActorLocation.Z -= 1.0f;
				UE_LOG(LogTemp, Warning, TEXT("Closing"))
			}*/
		GetOwner()->SetActorLocation(ActorLocation); 
	}
	else if ((PlateOneResult.Num() > 0) && (PlateTwoResult.Num() > 0) && (Counter == true))
	{
		FVector ActorLocation = GetOwner()->GetActorLocation();
		Counter = false;
		UE_LOG(LogTemp, Warning, TEXT("Open"))
		AActor* Owner = GetOwner();

		ActorLocation.Z += 400.0f;

	/*	while(ActorLocation.Z < DoorIsOpen)					give the door a smooth transitions from closed to open
			{
				ActorLocation.Z += 1.0f;
				UE_LOG(LogTemp, Warning, TEXT("Opening"))
			}*/
		GetOwner()->SetActorLocation(ActorLocation); 
	}
}