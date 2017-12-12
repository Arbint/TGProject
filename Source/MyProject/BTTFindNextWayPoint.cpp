// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTFindNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolComp.h"
EBTNodeResult::Type UBTTFindNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* blackBoardUsed = OwnerComp.GetBlackboardComponent();
	
	if (blackBoardUsed!= nullptr)
	{
		int index = blackBoardUsed->GetValueAsInt(IndexKey.SelectedKeyName);
		FString name = IndexKey.SelectedKeyName.ToString();
	
		AAIController* AIC = OwnerComp.GetAIOwner();
		if (AIC)
		{
			APawn* AIGuard = Cast<APawn>(AIC->GetPawn());
			if (AIGuard)
			{
				UPatrolComp* PatrolComponent = Cast<UPatrolComp>(AIGuard->GetComponentByClass(UPatrolComp::StaticClass()));
				if (PatrolComponent == nullptr)
				{
					return EBTNodeResult::Failed;
				}
				TArray<AActor*> ArrayOfWaypoints = PatrolComponent->PatrolPoints;
				if (ArrayOfWaypoints.Num() == 0)
				{
					return EBTNodeResult::Failed;
				}
				AActor* NewWayPoint = ArrayOfWaypoints[index];
				blackBoardUsed->SetValueAsObject(PatrolPointKey.SelectedKeyName, NewWayPoint);
				++index;
				index = index%ArrayOfWaypoints.Num();
				blackBoardUsed->SetValueAsInt(IndexKey.SelectedKeyName, index);
			}
		}
	}
	return EBTNodeResult::Succeeded;
}
