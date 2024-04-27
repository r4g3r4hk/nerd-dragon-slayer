#include "battlesys.h"
#include "uti.h"
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <string>
#include <vector>
#include <random>
#include <cmath>
using namespace std;
using std::right;

//random number generator (reference source: https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c)
int rdgen(int min, int max) {
  random_device rd;                          
  mt19937 gen(rd());                          
  uniform_int_distribution<int> dist(min, max); 

  return dist(gen);                               
}

//main game screen
void printgamingstats(vector<string>& names, vector<int>& health, vector<int>& attack, vector<int>& defense, vector<int>& mana, vector<string>& difficulty, vector<string>& picture, int& money, int& level, vector<string>& tempstring, string tempdh){
  
  // print game screen
  cout << "|" << left << setw(20) << names[0] << right << setw(20) << "Balance: $" + to_string(money) << "|             |" << left << setw(40) << names[level] << "|" << endl;
  cout  << left;
  cout << "|" << setw(40) << "Health: " + to_string(health[0]) + "/100" << "|             |" << setw(40) << "Health: " + to_string(health[level]) + "/" + tempdh << "|" << endl;
  cout << "|" << setw(40) << "Attack: " + to_string(attack[0]) << "|             |" << setw(40) << "Attack: " + to_string(attack[level]) << "|" << endl;
  cout << "|" << setw(40) << "Defense: " + to_string(defense[0]) << "|             |" << setw(40) << "Defense: " + to_string(defense[level]) << "|" << endl;
  cout << "|" << setw(40) << "Mana: " + to_string(mana[0]) << "|             |" << setw(40) << "Difficulty: " + difficulty[level] << "|" << endl;
  cout << "-------------------------------------------------------------------------------------------------" << endl;
  cout << "\033[1;31m"<< picture[level] << "\033[0m" << endl;
  cout << "\033[32m-------------------------------------------------------------------------------------------------\033[0m" << endl;
  cout << "History: " << endl << tempstring[0] << endl << tempstring[1] << endl << tempstring[2] << endl;
  cout << "\033[32m-------------------------------------------------------------------------------------------------\033[0m" << endl;
  cout << "\033[1mA - Attack   S - Smite(20 Mana) D - Defend  P - Shopping\033[0m" << endl;
}

//store screen
void printstore(vector<int>& health, vector<int>& attack, vector<int>& defense, int& money, int& level, vector<string>& tempstring){
  char buy;
  bool shopping = true;
      while (shopping == true) {
        //print store screen
          cout << left << setw(40) <<  "\033[1mShopping Menu\033[0m" << right << setw(20) << "Balance: $" + to_string(money) << endl;
          cout << endl;
          cout << "-------------------------------------------------------------------------------------------------" << endl;
          cout << left << setw(40) << "S - Sword Upgrade (+5 Attack)" << right << setw(20) << "\033[1;32mPrice: $30\033[0m" << endl;
          cout << "-------------------------------------------------------------------------------------------------" << endl;
          cout << left << setw(40) << "A - Armor Upgrade (+5 Defense)" << right << setw(20) << "\033[1;32mPrice: $25\033[0m" << endl;
          cout << "-------------------------------------------------------------------------------------------------" << endl;
          cout << left << setw(40) << "H - Heal (+20 Health)" << right << setw(20) << "\033[1;32mPrice: $20\033[0m" << endl;
          cout << "-------------------------------------------------------------------------------------------------" << endl;
          cout << left << setw(40) << "Q - Back to the fight" << right << setw(20) << "\033[1;32mPrice: $0\033[0m"  << endl;
          cout << "-------------------------------------------------------------------------------------------------" << endl;
          cout << "Type your choice: ";
          cin >> buy;
        
          //choice selection
          switch (buy) {
              case 'A':
              case 'a':
                  if (money >= 25){
                      defense[0] += 5;
                      money -= 25;
                      tempstring.push_back("Purchased Armor upgrade: Defense +5");
                      tempstring.erase(tempstring.begin());
                      screen_clear();
                      cout << "--------------------------------------------------------------------------" << endl <<"You purchased Armor Upgrade, Don't get killed!" << endl << "-------------------------------------------------------------------------" << endl;
                      sleep(2);
                      screen_clear();
                  }
                  else{
                      screen_clear();
                      cout << "--------------------------------------------------------------------------" << endl << "You don't have enough money to buy this item" << endl << "-------------------------------------------------------------------------" << endl;
                      sleep(2);
                      screen_clear();
                  }
                  break;
            
              case 'S':
              case 's':
                  if (money >= 30){
                    attack[0] += 5;
                    money -= 30;
                    tempstring.push_back("Purchased Sword upgrade: Attack +5");
                    tempstring.erase(tempstring.begin());
                    screen_clear();
                    cout << "--------------------------------------------------------------------------" << endl <<"You purchased Sword Upgrade, go kill the dragon!" << endl << "-------------------------------------------------------------------------" << endl;
                    sleep(2);
                    screen_clear();
                  }
                  else{
                    screen_clear();
                    cout << "--------------------------------------------------------------------------" << endl << "You don't have enough money to buy this item" << endl << "-------------------------------------------------------------------------" << endl;
                    sleep(2);
                    screen_clear();
                  }
                  break;
            
              case 'H':
              case 'h':
                  if (money >= 20 && health[0] < 100){
                    health[0] += 20;
                    money -= 20;
                    tempstring.push_back("Purchased Healing: Health +20");
                    tempstring.erase(tempstring.begin());
                    screen_clear();
                    cout << "--------------------------------------------------------------------------" << endl <<"God bless you!" << endl << "-------------------------------------------------------------------------" << endl;
                    sleep(2);
                    screen_clear();
                  }
                  else if (health[0] >= 100){
                    screen_clear();
                    cout << "--------------------------------------------------------------------------" << endl << "You health is full already!" << endl << "-------------------------------------------------------------------------" << endl;
                    sleep(2);
                    screen_clear();
                  }
                  else{
                    screen_clear();
                    cout << "--------------------------------------------------------------------------" << endl << "You don't have enough money to buy this item." << endl << "-------------------------------------------------------------------------" << endl;
                    sleep(2);
                    screen_clear();
                  }
                  break;
            
              case 'Q':
              case 'q':
                  screen_clear();
                  cout << "-----------------------------------" << endl << "See you next time." << endl << "----------------------------------" << endl;
                  sleep(1);
                  screen_clear();
                  shopping = false;
                  break;
              default:
                  screen_clear();
                  cout << "-------------------------------------" << endl <<"\033[1;31mInvalid\033[0m choice. Please try again." << endl << "------------------------------------" << endl;
                  sleep(1);
                  screen_clear();
            
          }
      }
}

//main function in battlesys.cpp
void gamelevel(vector<string>& names, vector<int>& health, vector<int>& attack, vector<int>& defense, vector<int>& mana, vector<string>& difficulty, vector<string>& picture, int money){
  screen_clear();

  //store history
  vector<string> tempstring;
  tempstring.push_back("None");
  tempstring.push_back("None");
  tempstring.push_back("None");
  
  //Narration
  for (int i = 1; i < 8; ++i){
    string tempdh = to_string(health[i]);
    cout << "\033[1;31m" << picture[i+7] << "\033[0m" << endl;
    sleep(1);
    switch (i) {
      case 1:
        cout << "This is your first enemy, it should be easy." << endl;
        sleep(1);
        cout << "Get ready! Don't forget to go to the shop to upgrade your stats!" << endl;
        sleep(2);
        break;
      case 2:
        cout << "Well done, you killed that baby dragon!" << endl;
        sleep(2);
        cout << "The next one is stronger, so watch out!" << endl;
        sleep(2);
      break;
      case 3:
        cout << "Keep going, warrior!" << endl;
        sleep(2);
        cout << "There's a long road ahead!" << endl;
        sleep(2);
