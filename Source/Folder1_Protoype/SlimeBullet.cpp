// Fill out your copyright notice in the Description page of Project Settings.

#include "SlimeBullet.h"
#include "Enemy.h"
#include "EnemyShooter.h"
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

void ASlimeBullet::LowerPlayerSpeed()
{
    if (HitPlayer == true)
    {    
         //FMath::FRandRange(MinReducedPlayerSpeed, MaxReducedPlayerSpeed);
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
        /** This function in finsihed form will slow the players main speed down, but since I can't get the enemyshooter to work
		 * I can't do much as of yet **/
        //HitPlayer = true;
        //PlayerMaxSpeed = PlayerMaxSpeed - FMath::FRandRange(MinReducedPlayerSpeed, MaxReducedPlayerSpeed);
		Cast<ALittleGirl>(OtherActor)-> GetCharacterMovement()-> MaxWalkSpeed = FMath::FRandRange(MinReducedPlayerSpeed, MaxReducedPlayerSpeed); //Alternativt bare OtherActor->Destroy();
        
        //Destroy Bullet:
        Destroy();
    }
}

