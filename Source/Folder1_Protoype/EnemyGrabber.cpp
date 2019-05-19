#include "EnemyGrabber.h"
#include "LittleGirl.h"

#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/UObjectGlobals.h" 

// Sets default values
AEnemyGrabber::AEnemyGrabber()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyGrabber::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyGrabber::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

    if (IsGrabbing == true)
    {
        TimeInGrab += DeltaTime;
        if (TimeInGrab > TimeBeforeReleasing)
            {
                IsGrabbing = false;
                TimeInGrab = 0;
            }
    }
}


void AEnemyGrabber::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

