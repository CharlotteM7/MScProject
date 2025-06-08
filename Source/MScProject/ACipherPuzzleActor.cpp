
#include "ACipherPuzzleActor.h"
#include "Blueprint/UserWidget.h"
// Sets default values
AACipherPuzzleActor::AACipherPuzzleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AACipherPuzzleActor::BeginPlay()
{
	Super::BeginPlay();
   
}

void AACipherPuzzleActor::ActivatePuzzle()
{
    if (!CipherWidgetInstance && CipherWidgetClass)
    {
        CipherWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), CipherWidgetClass);
    }

    if (!CipherWidgetInstance || CipherWidgetInstance->IsInViewport()) return;

    // Send puzzle reference to widget
    UFunction* SetOwnerFunc = CipherWidgetInstance->FindFunction(FName("PuzzleActor"));
    if (SetOwnerFunc)
    {
        struct FSetOwnerParams { AActor* PuzzleRef; };
        FSetOwnerParams Params;
        Params.PuzzleRef = this;
        CipherWidgetInstance->ProcessEvent(SetOwnerFunc, &Params);
    }

    // Set the encoded message
    UFunction* SetEncodedFunc = CipherWidgetInstance->FindFunction(FName("EncryptedMessage"));
    if (SetEncodedFunc)
    {
        struct FEncodedParams { FText Message; };
        FEncodedParams Params;
        Params.Message = FText::FromString(EncodedMessage);
        CipherWidgetInstance->ProcessEvent(SetEncodedFunc, &Params);
    }

    CipherWidgetInstance->AddToViewport();
}




void AACipherPuzzleActor::SubmitSolution(const FString& PlayerInput)
{
    if (!CipherWidgetInstance) return;

    FText Feedback;

    if (PlayerInput.Equals(CorrectSolution, ESearchCase::IgnoreCase))
    {
        bIsSolved = true;
        Feedback = FText::FromString("Correct!");
        CipherWidgetInstance->RemoveFromParent();
    }
    else
    {
        Feedback = FText::FromString("Try again.");
    }

    UFunction* FeedbackFunc = CipherWidgetInstance->FindFunction(FName("ShowFeedbackMessage"));
    if (FeedbackFunc)
    {
        struct FFeedbackParams
        {
            FText Feedback;
        };

        FFeedbackParams Params;
        Params.Feedback = Feedback;
       

        CipherWidgetInstance->ProcessEvent(FeedbackFunc, &Params);
    }
}

