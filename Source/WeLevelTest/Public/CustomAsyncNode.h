// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "CustomAsyncNode.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBooleanValueChangedDelegate_CustomNode);
/**
 * 
 */
UCLASS()
class WELEVELTEST_API UCustomAsyncNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	

public:
    UFUNCTION(BlueprintCallable, Category = "CustomAsyncNode")
        static UCustomAsyncNode* ListenToBooleanValueChange(class ATargetActor* TargetActor);

    UPROPERTY(BlueprintAssignable)
        FBooleanValueChangedDelegate_CustomNode OnBooleanValueChanged_CustomNode;

    virtual void Activate() override;

private:
    UFUNCTION()
        void OnBooleanValueChanged();

    UPROPERTY()
        class ATargetActor* TargetActor;

};
