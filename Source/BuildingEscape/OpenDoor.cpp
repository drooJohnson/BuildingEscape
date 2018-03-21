// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
    
    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor(){
    // Find owning Actor
    AActor* Owner = GetOwner();
    
    // Create a rotator
    // Pitch, Yaw, Roll != X, Y, Z.
    // Pitch — Nose moving up/down.
    // Yaw — Nose moving left/right.
    // Roll — Think "Barrel Roll."
    FRotator NewRotation = FRotator(0.f, 90.f, 0.f);
    
    // Set the door rotation
    Owner->SetActorRotation(NewRotation);
    // ...
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    if(PressurePlate->IsOverlappingActor(ActorThatOpens)){
        OpenDoor();
    }
    
}

