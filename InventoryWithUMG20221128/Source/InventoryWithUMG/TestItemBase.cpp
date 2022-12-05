// Fill out your copyright notice in the Description page of Project Settings.


#include "TestItemBase.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/Engine.h"

// Sets default values
ATestItemBase::ATestItemBase()
{
 	//Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	RootComponent = SceneComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Shape"));
	StaticMesh->AddRelativeLocation(FVector(0.f, 0.f, 0.f));

	StaticMesh->SetupAttachment(RootComponent);


	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	//CollisionBox->AddRelativeLocation(FVector(0.f, 0.f, 0.f));
	CollisionBox->SetBoxExtent(FVector(1.f, 1.f, 1.f));
	CollisionBox->SetCollisionProfileName("Trigger");
	
	CollisionBox->SetupAttachment(RootComponent);


	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ATestItemBase::OnOverlapBegin);


	CustomItemShape = CreateDefaultSubobject<UStaticMesh>(TEXT("Custom Item Shape"));
}

// Called when the game starts or when spawned
void ATestItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




void ATestItemBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "overlap begin");
}

