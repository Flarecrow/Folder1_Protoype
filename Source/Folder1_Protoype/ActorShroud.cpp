// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorShroud.h"
#include "LittleGirl.h"
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

void AActorShroud::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
                        UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
                        bool bFromSweep, const FHitResult &SweepResult)
{
    //UE_LOG(LogTemp, Warning, TEXT("Bullet Overlap %s"), *OtherActor->GetName())
    if(OtherActor->IsA(ALittleGirl::StaticClass()))
    {
        /** This function in finsihed form will slow the players main speed down, but since I can't get the enemyshooter to work
		 * I can't do much as of yet **/
		OtherActor->Destroy();
        
        //Destroy Bullet:
        Destroy();
    }
}

