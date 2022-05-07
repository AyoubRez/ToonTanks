// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasePawn();

	virtual void HandleDestruction();

protected:
	void RotateTurret(FVector LookAtTarget) const;

	void Fire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tank|Component", meta=(AllowPrivateAccess="true"))
	class UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tank|Component", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tank|Component", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tank|Component", meta=(AllowPrivateAccess="true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Projectile")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category="Tank|Effects")
	UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category="Tank|Sounds")
	USoundBase* DestroySound;

	UPROPERTY(EditAnywhere, Category="Projectile|Camera")
	TSubclassOf<UCameraShakeBase> DestroyCameraShake;
};
