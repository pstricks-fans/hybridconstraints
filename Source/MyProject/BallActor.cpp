#include "BallActor.h"
#include "OrbitingComponent.h"


ABallActor::ABallActor()
{
	UStaticMeshComponent* SMC = GetStaticMeshComponent();

	SMC->SetRelativeScale3D(FVector(0.25f));

	SMC->SetMobility(EComponentMobility::Movable);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SM.Succeeded())
		SMC->SetStaticMesh(SM.Object);

	static ConstructorHelpers::FObjectFinder<UMaterial> M(TEXT("/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (M.Succeeded())
		SMC->SetMaterial(0, M.Object);

	SMC->SetSimulatePhysics(true);
	SMC->AddImpulse(FVector(0.f, 0.f, 5000.f));

	UOrbitingComponent* OC = CreateDefaultSubobject<UOrbitingComponent>(TEXT("Orbiting Component"));
}
