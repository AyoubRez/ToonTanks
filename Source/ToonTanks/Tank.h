// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void HandleDestruction() override;
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category="Tank|Camera")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category="Tank|Camera")
	class UCameraComponent* FollowCamera;

	void Move(float Value);

	void Turn(float Value);

	UPROPERTY(EditAnywhere, Category="Tank|Movement")
	float Speed{200.f};

	UPROPERTY(EditAnywhere, Category="Tank|Movement")
	float TurnRate{45.f};

	UPROPERTY()
	APlayerController* TankPlayerController;
public:
	FORCEINLINE APlayerController* GetTankPlayerController() const { return TankPlayerController; }

	bool bAlive{true};
};
