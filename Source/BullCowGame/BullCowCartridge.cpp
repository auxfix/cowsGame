// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("Welcome to cows world (-%s-) simulation"), *HiddenWord);
    PrintLine(TEXT("Look at this cute animals!!!))"));
    PrintLine(TEXT("Guess %i charecters word. \nOr they will die!!!"), HiddenWord.Len());

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    
    if (HiddenWord == Input) {
        PrintLine(TEXT("long live cows"));
    } else {
        if(Input.Len() != HiddenWord.Len()) {
            PrintLine(TEXT("Incorrect number of charecters (%i) \n -X-"), HiddenWord.Len());
        }
        PrintLine(TEXT("You killed all the fucking cows!!!"));
    }
}

void UBullCowCartridge::SetupGame() 
{
     HiddenWord = TEXT("fakez");
     Lives = 0;
}