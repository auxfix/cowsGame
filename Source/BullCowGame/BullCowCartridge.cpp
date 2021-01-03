// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameIsOver) {
        SetupGame();
    } else {
        if (HiddenWord == Input) {
            PrintLine(TEXT("long live cows"));
            EndGame();
        } else {
            if(Input.Len() != HiddenWord.Len()) {
                PrintLine(TEXT("Incorrect number of charecters (%i)"), HiddenWord.Len());
                PrintLine(TEXT("All cows are dead. Try harder next time!!!"), *HiddenWord);
                EndGame();
            }
        }
    }
}

void UBullCowCartridge::SetupGame() 
{
    HiddenWord = TEXT("fakez");
    Lives = 0;
    bGameIsOver = false;

    ClearScreen();

    PrintLine(TEXT("Welcome to cows world (-%s-) simulation"), *HiddenWord);
    PrintLine(TEXT("Look at this cute animals!!!))"));
    PrintLine(TEXT("Guess %i charecters word. \nOr they will die!!!"), HiddenWord.Len());
}

void UBullCowCartridge::EndGame() 
{    
    bGameIsOver = true;
    PrintLine(TEXT("Click enter to try save cows again..."), *HiddenWord);
}