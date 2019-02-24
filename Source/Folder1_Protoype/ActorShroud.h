// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorShroud.generated.h"

UCLASS()
class FOLDER1_PROTOYPE_API AActorShroud : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorShroud();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//setting the directinal movement
    FVector MoveDirection = FVector(1.f, 0.f, 0.f);

private:
    //setting the speed variable
    UPROPERTY(EditAnywhere)
    float Speed{50.f};

};
