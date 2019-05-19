// Fill out your copyright notice in the Description page of Project Settings.

#include "LittleGirl.h"
//#include "Bullet.h"
#include "SlimeBullet.h"
#include "LittleGirlShadowDrop.h"
#include "EnemyGrabber.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

//#include "Components/BoxComponent.h"
//#include "Components/CapsuleComponent.h"
#include "Components/Decalcomponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/UObjectGlobals.h" 

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


// Sets default values
ALittleGirl::ALittleGirl()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    GetCharacterMovement() -> bOrientRotationToMovement = true;
    GetCharacterMovement() -> RotationRate = FRotator(0.0f, 540.0f, 0.0f);
    GetCharacterMovement() -> JumpZVelocity = 350.f;
    GetCharacterMovement() -> MaxWalkSpeed = 300.f;
    GetCharacterMovement() -> AirControl = 0.2f;
}

// Called when the game starts or when spawned
void ALittleGirl::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ALittleGirl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    //Return the players speed when timer goes down
    if ((GetCharacterMovement()-> MaxWalkSpeed != 300.f) && (GetCharacterMovement()-> MaxWalkSpeed != 0.f))
    {
        TimeMotionless += DeltaTime;
        if (TimeMotionless > TimeBeforeSpeedReturn)
        {
            GetCharacterMovement()-> MaxWalkSpeed = 300.f;
            GetCharacterMovement()-> JumpZVelocity = 350.f;
            TimeMotionless = 0;
        }
    }
    else if (GetCharacterMovement()-> MaxWalkSpeed == 0.f) //If your speed is 0 due to being grabbed, this function will kill you unless you break free
    {
        TimeGrabbed += DeltaTime;
        if (TimeGrabbed > TimeBeforeDeath)
        {
            CurrentHealth--;
            TimeGrabbed = 0;
            //UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
        }

    }

        if (CurrentHealth <= 0)
        {
            TimeDead += DeltaTime;
            if (TimeDead > TimeAfterDeath)
            {
                UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
            }
        }

}

// Called to bind functionality to input
void ALittleGirl::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//check(PlayerInputComponent);

    //Setting the Input Components
	InputComponent->BindAxis("MoveX", this, &ALittleGirl::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &ALittleGirl::Move_YAxis);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ALittleGirl::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ALittleGirl::StopJumping);

    InputComponent->BindAction("Jump", IE_Pressed, this, &ALittleGirl::BreakFree);

	// Respond when our shoot and sprint keys are pressed or released.
    InputComponent->BindAction("Shoot", IE_Pressed, this, &ALittleGirl::Shoot);
    InputComponent->BindAction("Sprint", IE_Pressed, this, &ALittleGirl::Sprint);

}

//Movement functions for x and y
void ALittleGirl::Move_XAxis(float AxisValue)
{
	 if (AxisValue != 0.0f)
	 {
		 AddMovementInput(FVector(1.0f, 0.0f, 0.0f), AxisValue);
	 }
}
void ALittleGirl::Move_YAxis(float AxisValue)
{
	if (AxisValue != 0.0f)
	 {
		 AddMovementInput(FVector(0.0f, 1.0f, 0.0f), AxisValue);
	 }
}

void ALittleGirl::Shoot()//This function spawns the shadow clone of the player if you have ammo, if not it returns the shadow
{
    ///Spawn one bullet if we have ammo
    if (Ammo > 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Shoot fired"))
        Ammo--;
        UWorld* world = GetWorld();	//Henter peker til spillverdenen
        if (world)			//checking if the world exists
        {
            FVector Location = GetActorLocation();   //getting the player pawn location
            world->SpawnActor<ALittleGirlShadowDrop>(ShotBlueprint, Location + FVector(-90.f, 0.f, 0.f), GetActorRotation());
        }

    }
    else
    {

        TArray<AActor *> FoundActors;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALittleGirlShadowDrop::StaticClass(), FoundActors);

        if (FoundActors.Num() > 0)
        {
            ((ALittleGirlShadowDrop *)FoundActors[0])->ReturnToPlayer();
        }

    }
}

void ALittleGirl::Sprint() //Sprint function
{
    if (GetCharacterMovement()-> MaxWalkSpeed == 300)
    {
        GetCharacterMovement()-> MaxWalkSpeed = 600;
    }
    
}

void ALittleGirl::BreakFree()//when grabbed by enemy, spam the JUMP key to break free from grasp
{
    //UE_LOG(LogTemp, Warning, TEXT("BreakFree is Active"))
    if (GetCharacterMovement()-> MaxWalkSpeed == 0.f)
    {
        UE_LOG(LogTemp, Warning, TEXT("Struggle"))
        StruggleCounter++;
        StruggleReleaseNumber = FMath::FRandRange(MinStruggle, MaxStruggle);

        //randomize the nummer of time jump must be pressed to be released
        if (StruggleCounter >= StruggleReleaseNumber)
        {
            UE_LOG(LogTemp, Warning, TEXT("RELEASED FROM GRASP"))
            GetCharacterMovement()-> MaxWalkSpeed = 600.f;
            GetCharacterMovement()-> JumpZVelocity = 350.f;
            StruggleCounter = 0.f;
            TimeGrabbed = 0.f;
        }
    }
}

void ALittleGirl::GainAmmo()//shadow ammo
{
    UE_LOG(LogTemp, Warning, TEXT("Press E to Drop Shadow"))
    Ammo++;
}

//OnCompHit, but dosn't work
void ALittleGirl::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, 
					UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
    {
        if(OtherActor->IsA(AEnemyGrabber::StaticClass()))
        {
            UE_LOG(LogTemp, Warning, TEXT("Player Hit"))
            GetCharacterMovement()-> MaxWalkSpeed = 0;
        }
    }

}
//OnOverlap, but dosn't work
void ALittleGirl::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent,
                        int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    if(OtherActor->IsA(AEnemyGrabber::StaticClass()))
    {
        UE_LOG(LogTemp, Warning, TEXT("Player Hit"))
        GetCharacterMovement()-> MaxWalkSpeed = 0;
    }

    if(OtherActor->IsA(ASlimeBullet::StaticClass()))
    {
        UE_LOG(LogTemp, Warning, TEXT("Player Hit"))
        GetCharacterMovement()-> MaxWalkSpeed = 0;
    }

    if(OtherActor->IsA(ALittleGirlShadowDrop::StaticClass()))
    {
        Ammo = 1;
        UE_LOG(LogTemp, Warning, TEXT("Player Picked Up Clip"))
        OtherActor->Destroy();
    }
}

