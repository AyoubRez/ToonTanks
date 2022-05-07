// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Projectile|Mesh", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Movement")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	           const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	float Damage{50.f};

	UPROPERTY(EditAnywhere, Category="Projectile|Effects")
	UParticleSystem* HitParticles;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Effects")
	UParticleSystemComponent* TrailParticles;

	UPROPERTY(EditAnywhere, Category="Projectile|Sounds")
	USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category="Projectile|Sounds")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category="Projectile|Camera")
	TSubclassOf<UCameraShakeBase> HitCameraShake;
};
