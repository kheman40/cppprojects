#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 // Fuction to get the computers choice 
 int getComputerChoice() {
    //randomly generate a number between 0 and 2 
    return rand() %3;
 }
 // function to determine the wonner 
 string determineWinner(int userChoice, int ComputerChoice){
    if(userChoice == ComputerChoice){
        return "It is a tie";
    }

    //Determine if the user wins 
    if((userChoice == 0 && ComputerChoice == 2) || //Rock beats Scissors
    (userChoice == 1 && ComputerChoice == 0) || //Paper beats Rock
    (userChoice == 2 && ComputerChoice == 1) ){// scissors beats paper
    return "you win!";
    }
 
 // If not a tie and the user didn't win, the computer wins
 else{
    return "Computer wins!";
 }
}
 int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int >(time(0)));
    int userChoice;
    int ComputerChoice;
    string result;
   // Display game instructions
   cout<<"Welcome to Rock,Paper,Scissors!"<<endl;
   cout<<"Enter your choice :"<<endl;
   cout<<"0. Rock"<<endl;
   cout<<"1. Paper"<<endl;
   cout<<"2. Scissors"<<endl;
   cout<<"Your choice :";
   cin>>userChoice;
 
 // Validaate user input 
 if(userChoice < 0 || userChoice > 2) {
    cout<<"Invalid choice please enter a number between 0 and 2."<<endl;
    return 1; // Exit the game if invalide input
 }
 ComputerChoice = getComputerChoice();
 // display choices
 string choices[3] = {"Rock","Paper","Scissors"};
 cout<<"you chose:"<<choices[userChoice]<<endl;
 cout<<"computer chose:"<<choices[ComputerChoice]<<endl;
 // Determine and display the winner 
 result = determineWinner(userChoice, ComputerChoice);
 cout<<result<<endl;
 return 0;
}