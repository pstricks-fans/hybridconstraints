#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OrbitingComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYPROJECT_API UOrbitingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UOrbitingComponent();
	void BeginPlay() override;
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FVector InitPos;
	void SetPosition(float Time);
};
