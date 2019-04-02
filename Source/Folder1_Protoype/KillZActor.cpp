// Fill out your copyright notice in the Description page of Project Settings.

#include "KillZActor.h"
#include "LittleGirl.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AKillZActor::AKillZActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKillZActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKillZActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKillZActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent,
                        int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    if(OtherActor->IsA(ALittleGirl::StaticClass()))
    {
        UE_LOG(LogTemp, Warning, TEXT("Player Hit"))
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
    }
}

