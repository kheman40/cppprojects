#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
class guessingGame{
    private :
    int lower,upper;
    int secreteNumber;
    int userGuess;
    int attempCount;

    public:
    guessingGame(int lower =1, int upper = 100):lower(lower),upper(upper),attempCount(0){
        srand(static_cast<unsigned int>(time(0))); // initialize random seed
        secreteNumber = rand()%(upper - lower + 1 ) + lower; //Generate random number
    }
    void startGame(){
        cout<<"Welcome to Number Guessing Game"<<endl;
        cout<<"I have selected a number between"<<lower<<"And "<<upper<<". Try to Guess it"<<endl;
    do{
        cout<<"Enter your guess:";
        cin>>userGuess;
        attempCount++;
        if(userGuess < secreteNumber){
            cout<<"To Low! Try again."<<endl;
        }else if(userGuess > secreteNumber){
            cout<<"To high! Try again."<<endl;
        }else{
            cout<<"Congratulation! you've guessed the correct number"<<secreteNumber<<"!"<<endl;
            cout<<"It took you"<<attempCount<<"attempts."<<endl;
            saveStatistics(true);
        }
    }while(userGuess != secreteNumber);
    if(userGuess != secreteNumber){
        saveStatistics(false);
    }
    }
    void saveStatistics(bool win){
        ofstream file("game_statistics.txt" ,ios::app);
        if(file.is_open()){
            file<<"Game Result :"<<(win ?"Win" : "Loss")<<endl;
            file<<"Number of Attempts :"<<attempCount<<endl;
            file<<"secrete Number :"<<secreteNumber<<endl;
            file<<"--------------------------------------"<<endl;
            file.close();
        }else{
            cout<<"Unable to open the file to save statistics!"<<endl;

        }
    }
    void displayStatistics(){
        string line;
        ifstream file("game_statistics.txt");
        if(file.is_open()){
            cout<<"Game Statistics :"<<endl;
            while(getline(file , line)){
                cout<<line<<endl;
            }
            file.close();
        }else{
            cout<<"No ststistics found!"<<endl;
        }
    }
};
int main() {
    int lower = 1, upper = 100;
    guessingGame game(lower, upper);
    game.startGame();
    char viewStats;
    cout<<"Do you want to view previous statistics? (y/n) :";
    cin>>viewStats;
    if(viewStats == 'y' || viewStats == 'Y'){
        game.displayStatistics();
    }
    return 0;
}