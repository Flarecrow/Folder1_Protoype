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
    
    //get enemy to follow player 
	/*MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
    MoveDirection.Normalize();
    SetActorRotation(MoveDirection.Rotation());*/
}

// Called every frame
void AEnemyGrabber::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

   /* //set and constently update direction
    MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
    MoveDirection.Normalize();
    SetActorRotation(MoveDirection.Rotation());
    FVector NewLocation = GetActorLocation();
    NewLocation += (MoveDirection * Speed * DeltaTime);
    SetActorLocation(NewLocation);*/

}

void AEnemyGrabber::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent,
                        int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    UE_LOG(LogTemp, Warning, TEXT("COLLISION HAS BEEN MADE"))
    //UE_LOG(LogTemp, Warning, TEXT("Bullet Overlap %s"), *OtherActor->GetName())
    if(OtherActor->IsA(ALittleGirl::StaticClass()))
    {
        /** This function in finsihed form will slow the players main speed down, but since I can't get the enemyshooter to work
		 * I can't do much as of yet **/
        //HitPlayer = true;
        //PlayerMaxSpeed = PlayerMaxSpeed - FMath::FRandRange(MinReducedPlayerSpeed, MaxReducedPlayerSpeed);
		//Cast<ALittleGirl>(OtherActor)-> GetCharacterMovement()-> MaxWalkSpeed = FMath::FRandRange(MinReducedPlayerSpeed, MaxReducedPlayerSpeed); //Alternativt bare OtherActor->Destroy();
        
        //Destroy Bullet:
        Destroy();
    }
}

void AEnemyGrabber::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

