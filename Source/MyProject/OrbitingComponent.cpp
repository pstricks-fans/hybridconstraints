#include "OrbitingComponent.h"
#include "Components/PrimitiveComponent.h"

UOrbitingComponent::UOrbitingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UOrbitingComponent::BeginPlay()
{
	Super::BeginPlay();
	UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	PrimitiveComponent->GetBodyInstance()->bLockZTranslation = true; // neither true nor false works.
	PrimitiveComponent->GetBodyInstance()->SetDOFLock(EDOFMode::XYPlane);

	InitPos = GetOwner()->GetActorLocation();
	SetPosition(0.f);
}

void UOrbitingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	float Time = GetOwner()->GetGameTimeSinceCreation();
	SetPosition(Time);

	// UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
}

void UOrbitingComponent::SetPosition(float Time)
{
	float X = InitPos.X + 100 * FMath::Cos(2 * PI * 0.5f * Time);
	float Y = InitPos.Y + 100 * FMath::Sin(2 * PI * 0.5f * Time);
	float Z = InitPos.Z;

	GetOwner()->SetActorLocation(FVector(X, Y, Z));
}

