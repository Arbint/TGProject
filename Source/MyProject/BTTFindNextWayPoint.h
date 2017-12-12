// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTFindNextWayPoint.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTTFindNextWayPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blueprint")
	FBlackboardKeySelector IndexKey;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blueprint")
	FBlackboardKeySelector PatrolPointKey;
};
