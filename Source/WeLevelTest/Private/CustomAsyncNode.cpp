// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAsyncNode.h"
#include "Net/UnrealNetwork.h"
#include "TargetActor.h"

UCustomAsyncNode* UCustomAsyncNode::ListenToBooleanValueChange(ATargetActor* TargetActor)
{
    UCustomAsyncNode* CustomNode = NewObject<UCustomAsyncNode>();
    CustomNode->TargetActor = TargetActor;
    return CustomNode;
}

void UCustomAsyncNode::Activate()
{
    if (TargetActor)
    {
        TargetActor->OnBooleanValueChanged_TargetActor.AddDynamic(this, &UCustomAsyncNode::OnBooleanValueChanged);

        TargetActor->SetReplicates(true);
        TargetActor->SetReplicateMovement(false);
    }
}

void UCustomAsyncNode::OnBooleanValueChanged()
{
    // Broadcast the event when the boolean value changes
    OnBooleanValueChanged_CustomNode.Broadcast();
}