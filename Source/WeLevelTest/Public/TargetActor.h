// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetActor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBooleanValueChangedDelegate_TargetActor);


UCLASS()
class WELEVELTEST_API ATargetActor : public AActor
{
	GENERATED_BODY()
	
public:
    ATargetActor();

    UPROPERTY(BlueprintAssignable)
        FBooleanValueChangedDelegate_TargetActor OnBooleanValueChanged_TargetActor;


    UFUNCTION(BlueprintCallable)
        void SetBooleanValue(bool NewValue);

    UFUNCTION(BlueprintPure)
        bool GetBooleanValue() const;

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_BooleanValue)
        bool bBooleanValue;

    UFUNCTION()
        void OnRep_BooleanValue();
};
