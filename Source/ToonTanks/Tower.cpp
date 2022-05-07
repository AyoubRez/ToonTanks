// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"

ATower::ATower()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (InFireRange())
	{
		// rotate turret when tank in range
		RotateTurret(Tank->GetActorLocation());
	}
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();

	Destroy();
}


void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
	if (Tank == nullptr)return;
	if (InFireRange() && Tank->bAlive)
	{
		Fire();
	}
}

bool ATower::InFireRange()
{
	if (Tank)
	{
		const float Distance(FVector::Dist(GetActorLocation(), Tank->GetActorLocation()));
		return Distance <= FireRange;
	}
	return false;
}
