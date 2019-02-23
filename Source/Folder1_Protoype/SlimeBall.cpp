// Fill out your copyright notice in the Description page of Project Settings.

#include "SlimeBall.h"
#include "Enemy.h"
#include "MyPawn.h"
#include "Folder1_Protoype.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
ASlimeBall::ASlimeBall()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Collision object and RootObject
    RootSphere = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));
    RootComponent = RootSphere;
    RootSphere->SetGenerateOverlapEvents(true);
    RootSphere->OnComponentBeginOverlap.AddDynamic(this, &ASlimeBall::OnOverlap);

}

// Called when the game starts or when spawned
void ASlimeBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlimeBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
    NewLocation += GetActorForwardVector() * Speed * DeltaTime;
    SetActorLocation(NewLocation);

	TimeLived += DeltaTime;
    if (TimeLived > TimeBeforeDestroy)
    {
        this->Destroy();
    }

}

void ASlimeBall::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
                        UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
                        bool bFromSweep, const FHitResult &SweepResult)
{
    //UE_LOG(LogTemp, Warning, TEXT("Bullet Overlap %s"), *OtherActor->GetName())
    if(OtherActor->IsA(AEnemy::StaticClass()))
    {
        //Cast<AEnemy>(OtherActor)->ImHit(); //Alternativt bare OtherActor->Destroy();
        
        //Destroy Bullet:
        Destroy();
    }
}

// Called to bind functionality to input
/*void ASlimeBall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}*/

