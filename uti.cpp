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
