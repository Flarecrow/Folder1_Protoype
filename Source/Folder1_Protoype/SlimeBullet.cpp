// Fill out your copyright notice in the Description page of Project Settings.

#include "SlimeBullet.h"
#include "EnemySpitter.h"
#include "LittleGirl.h"
#include "Folder1_Protoype.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
ASlimeBullet::ASlimeBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Collision object and RootObject
    RootSphere = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));
    RootComponent = RootSphere;
    RootSphere->SetGenerateOverlapEvents(true);
    RootSphere->OnComponentBeginOverlap.AddDynamic(this, &ASlimeBullet::OnOverlap);

}

// Called when the game starts or when spawned
void ASlimeBullet::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASlimeBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Setting Location
	FVector NewLocation = GetActorLocation();
    NewLocation += GetActorForwardVector() * Speed * DeltaTime;
    SetActorLocation(NewLocation);

}

void ASlimeBullet::LowerPlayerSpeed()//does the bullet hit the player
{
    if (HitPlayer == true)
    {    
        HitPlayer = false;
    }
}

void ASlimeBullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
                        UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
                        bool bFromSweep, const FHitResult &SweepResult)
{
    //UE_LOG(LogTemp, Warning, TEXT("Bullet Overlap %s"), *OtherActor->GetName())
    if(OtherActor->IsA(ALittleGirl::StaticClass()))
    {
        //randomize the playes speed upon hit
		Cast<ALittleGirl>(OtherActor)-> GetCharacterMovement()-> MaxWalkSpeed = FMath::FRandRange(MinReducedPlayerSpeed, MaxReducedPlayerSpeed);
        
        //Destroy bullet:
        Destroy();
    }
    
}

