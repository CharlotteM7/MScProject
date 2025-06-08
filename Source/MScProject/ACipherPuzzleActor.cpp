
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

	if (CipherWidgetClass)
	{
		CipherWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), CipherWidgetClass);
	}
    ActivatePuzzle();
}

void AACipherPuzzleActor::ActivatePuzzle()
{
    if (!CipherWidgetInstance && CipherWidgetClass)
    {
        CipherWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), CipherWidgetClass);
    }

    if (CipherWidgetInstance && !CipherWidgetInstance->IsInViewport())
    {
        UFunction* SetOwnerFunc = CipherWidgetInstance->FindFunction(FName("PuzzleActor"));
        if (SetOwnerFunc)
        {
            struct FSetOwnerParams
            {
                AActor* PuzzleRef;
            };

            FSetOwnerParams Params;
            Params.PuzzleRef = this;
            CipherWidgetInstance->ProcessEvent(SetOwnerFunc, &Params);
        }

        CipherWidgetInstance->AddToViewport();
    }

    UFunction* SetEncodedFunc = CipherWidgetInstance->FindFunction(FName("EncryptedMessage"));
    if (SetEncodedFunc)
    {
        struct FEncodedParams { FText Message; };
        FEncodedParams Params;
        Params.Message = FText::FromString(EncodedMessage); // Convert FString to FText
        CipherWidgetInstance->ProcessEvent(SetEncodedFunc, &Params);
    }

}



void AACipherPuzzleActor::SubmitSolution(const FString& PlayerInput)
{
    if (!CipherWidgetInstance) return;

    FText Feedback;

    if (PlayerInput.Equals(CorrectSolution, ESearchCase::IgnoreCase))
    {
        bIsSolved = true;
        Feedback = FText::FromString("Correct!");
        OnPuzzleSolved(); // Optional: Do more stuff here
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



