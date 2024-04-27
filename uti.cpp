#include "uti.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

//remove terminal text
void screen_clear(){
  int result = system("clear");
  (void)result;
}

//reading stats of game elements
void readStatsFromFile(vector<string>& names, vector<int>& health, vector<int>& attack, vector<int>& defense, vector<int>& mana, vector<string>& difficulty) {
    ifstream file("Stats.txt");
    if (!file.is_open()) {
        cout << "Sorry warrior our code is bugged." << endl;
        return;
    }
    //using STL container Vector to store Sta
    string line;
    int lineN = 1;
    while (getline(file, line)) {
        string token;
        istringstream iss(line);
        while (iss >> token) {
            switch (lineN) {
                case 1:
                    names.push_back(token);
                    break;
                case 2:
                    health.push_back(stoi(token));
                    break;
                case 3:
                    attack.push_back(stoi(token));
                    break;
                case 4:
                    defense.push_back(stoi(token));
                    break;
                case 5:
                    mana.push_back(stoi(token));
                    break;
                case 6:
                    difficulty.push_back(token);
                    break;
                default:
                    break;
            }
        }
        lineN++;
    }

    file.close();
}

//screens after winning
void gamewin(){
  screen_clear();
  cout << "--------------------------------------------------------------" << endl <<"You win!" << endl << "-------------------------------------------------------------" << endl;
  sleep(2);
  screen_clear();
  cout << "--------------------------------------------------------------" << endl <<"Congratulations!" << endl << "-------------------------------------------------------------" << endl;
  sleep(2);
  screen_clear();
  cout << "--------------------------------------------------------------" << endl <<"You made it and you went back to reality." << endl << "-------------------------------------------------------------" << endl;
  sleep(3);
  screen_clear();
  cout << "--------------------------------------------------------------" << endl <<"Because of your real-life experience in the game, you improve it in many ways. " << endl << "-------------------------------------------------------------" << endl;
  sleep(3);
  screen_clear();
  cout << "--------------------------------------------------------------" << endl <<"This game became the the best-selling game in 2048..." << endl << "-------------------------------------------------------------" << endl;
  sleep(3);

  screen_clear();
  cout << "--------------------------------------------------------------" << endl <<"You are remembered as the best developer in the world."<< endl << "-------------------------------------------------------------" << endl;
}

//screens after losing
void gameover(){
  screen_clear();
  cout << "--------------------------------------------------------------" << endl <<"You Died" << endl << "-------------------------------------------------------------" << endl;
  sleep(2);
  screen_clear();
  cout << "--------------------------------------------------------------" << endl <<"Game Over" << endl << "-------------------------------------------------------------" << endl;
  sleep(2);
  screen_clear();
  cout << "--------------------------------------------------------------" << endl <<"You didn't make it, and you died in your own game." << endl << "-------------------------------------------------------------" << endl;
  sleep(3);
  screen_clear();
  cout << "--------------------------------------------------------------" << endl <<"No one knows where you are but your groupmates finished the game for you." << endl << "-------------------------------------------------------------" << endl;
  sleep(3);
  screen_clear();
  cout << "--------------------------------------------------------------" << endl <<"This game became the the best-selling game in 2048..." << endl << "-------------------------------------------------------------" << endl;
  sleep(3);

  screen_clear();
  cout << "--------------------------------------------------------------" << endl <<"You will be remembered as the best developer in the world."<< endl << "-------------------------------------------------------------" << endl;
}
