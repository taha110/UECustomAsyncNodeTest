// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetActor.h"
#include "Net/UnrealNetwork.h"

ATargetActor::ATargetActor()
{
    // Set the initial value of the boolean variable
    bBooleanValue = false;

    // Enable network replication for the boolean variable
    SetReplicates(true);
    SetReplicateMovement(false);
}

void ATargetActor::SetBooleanValue(bool NewValue)
{
    if (bBooleanValue != NewValue)
    {
        bBooleanValue = NewValue;

        // Broadcast the event when the boolean value changes
        OnBooleanValueChanged_TargetActor.Broadcast();
       
        UE_LOG(LogTemp, Display, TEXT("setting bool value from C++"));

    }
}

bool ATargetActor::GetBooleanValue() const
{
    return bBooleanValue;
}

void ATargetActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ATargetActor, bBooleanValue);
}

void ATargetActor::OnRep_BooleanValue()
{
    // Broadcast the event when the replicated boolean value changes
    OnBooleanValueChanged_TargetActor.Broadcast();
}