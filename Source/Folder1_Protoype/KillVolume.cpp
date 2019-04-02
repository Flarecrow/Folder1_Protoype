// Fill out your copyright notice in the Description page of Project Settings.

#include "KillVolume.h"
#include "LittleGirl.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AKillVolume::AKillVolume()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKillVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKillVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKillVolume::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AKillVolume::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent,
                        int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    if(OtherActor->IsA(ALittleGirl::StaticClass()))
    {
        UE_LOG(LogTemp, Warning, TEXT("Player Hit"))
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
    }
}

