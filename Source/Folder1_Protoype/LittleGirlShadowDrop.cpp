// Fill out your copyright notice in the Description page of Project Settings.

#include "LittleGirlShadowDrop.h"
#include "EnemyGrabber.h"
#include "LittleGirl.h"
#include "Folder1_Protoype.h"

#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
ALittleGirlShadowDrop::ALittleGirlShadowDrop()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Collision object and RootObject
    RootSphere = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));
    RootComponent = RootSphere;
    RootSphere->SetGenerateOverlapEvents(true);
    RootSphere->OnComponentBeginOverlap.AddDynamic(this, &ALittleGirlShadowDrop::OnOverlap);

}

// Called when the game starts or when spawned
void ALittleGirlShadowDrop::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALittleGirlShadowDrop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
    NewLocation += GetActorForwardVector() * Speed * DeltaTime;
    SetActorLocation(NewLocation);

    //InputComponent->BindAction("Shoot", IE_Pressed, this, &ALittleGirlShadowDrop::ReturnToPlayer);

	TimeLived += DeltaTime;
    if (TimeLived > TimeBeforeDestroy)
    {
        
        Speed = 300.f;
        MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
        MoveDirection.Normalize();
        SetActorRotation(MoveDirection.Rotation());
        FVector NewLocation = GetActorLocation();
        NewLocation += (MoveDirection * Speed * DeltaTime);
        SetActorLocation(NewLocation);
        //this->Destroy();
    }
}

/*void ALittleGirlShadowDrop::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    check(PlayerInputComponent);

	// Respond when our "Shoot" etc. keys are pressed or released.
    InputComponent->BindAction("Shoot", IE_Pressed, this, &ALittleGirlShadowDrop::ReturnToPlayer);

}*/

void ALittleGirlShadowDrop::ReturnToPlayer()
{
    Return = true;
}


void ALittleGirlShadowDrop::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
                        UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
                        bool bFromSweep, const FHitResult &SweepResult)
{
    //UE_LOG(LogTemp, Warning, TEXT("Bullet Overlap %s"), *OtherActor->GetName())
    if(OtherActor->IsA(ALittleGirl::StaticClass()))
    {
        Cast<ALittleGirl>(OtherActor)->GainAmmo(); //Alternativt bare OtherActor->Destroy();
        
        //Destroy Bullet:
        Destroy();
    }
}

