// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	ATower();
	virtual void Tick(float DeltaSeconds) override;
	virtual void HandleDestruction() override;
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class ATank* Tank;

	UPROPERTY(EditDefaultsOnly, Category="Tower|Fire")
	float FireRange{300.f};

	FTimerHandle FireTimerHandle;

	UPROPERTY(EditAnywhere, Category="Tower|Fire")
	float FireRate{2.f};

	void CheckFireCondition();

	bool InFireRange();
};
