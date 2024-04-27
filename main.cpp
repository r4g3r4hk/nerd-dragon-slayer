#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include "uti.h"
#include "picture.h"
#include "battlesys.h"
using namespace std;

//store player and level stats
vector<string> names;
vector<int> health;
vector<int> attack;
vector<int> defense;
vector<int> mana;
vector<string> difficulty;
vector<string> picture;
int money = 100;

//starting screen after pressing S
void PlayerBuildScreen(){
  string playername;
  screen_clear();
  cout << "What is your name, warrior? (under 20 letters): ";
  cin >> playername;
  //replace the vector with the player name
  names[0] = playername;
  cout << "\033[1;31;40m" << picture[17] << "\033[0m" << endl;
  sleep(1);
  cout << "\033[1m" << names[0] << ", these are your starting stats.\033[0m" << endl;
  sleep(1);
  cout << "Health: " << health[0] << endl;
  sleep(1);
  cout << "Attack: " << attack[0] << endl;
  sleep(1);
  cout << "Defense: " << defense[0] << endl;
  sleep(1);
  cout << "Mana: " << mana[0] << endl;
  sleep(1);
  cout << "You will soon fight your first enemy, are you ready?" << endl;
  sleep(2);
  screen_clear();
  for (int i = 0; i < 3; ++i) {
    usleep(500000);
    cout << "Loading..." << endl;
  }
  gamelevel(names, health, attack, defense, mana, difficulty, picture, money);
}

//Rule screen after pressing R
void Rules_Screen(){
  screen_clear();

  char choice3;
  bool loop2 = true;
    while (loop2 == true) {
      cout << "\033[1;31;40m" << picture[16] << "\033[0m" << endl;
      cout << "\033[1mBackground: \033[0m" << endl;
      cout << "You are a game developer who fell asleep while coding his game, Nerd Dragon Slayer, and wakes up trapped inside it." << endl;
      cout << "Without a functioning quit feature, you must defeat all the dragons within the game to escape. "<< endl;
      cout << "\033[0mThere are only two ways to end this game, either by defeating the dragons, or by \033[1,31mdying.\033[0m" << endl << endl;

      cout << "\033[1mRules: \033[0m" << endl;
      cout << "The player starts with initial values for \033[1mHealth, Attack, Defense, Mana, and Money.\033[0m" << endl;
      cout << "These attributes define the player's capabilities within the game." << endl;
      cout << "You can choose to increase your \033[1mAttack, Defense\033[0m or heal yourself by spending money in the shop." << endl;
      cout << "You will have 3 options to fight the dragon, \033[1mAttack, Defend, and Smite.\033[0m" << endl;
      cout << "  1. \033[1,31mAttack\033[0m: You will attack the dragon, dealing damage to it based on your attack stat. (+Money, +Mana)" << endl;
      cout << "  2. \033[1,31mDefend\033[0m: You will defend against the dragon's attack, reducing the damage based on your defense stat. (+Mana)" << endl; 
      cout << "  3. \033[1,31mSmite\033[0m: You will attack the dragon with fixed 2.2x damage, consuming mana in the process. (+ Extra Money)" << endl;
      cout << "During each round, the dragon will also attack the player and your health will decrease accordingly. You must manage your resources and abilities strategically to survive and defeat the dragons. \033[1:33mGood luck, warrior!\033[0m" << endl;
      // rule screen menu
      cout << "\033[1mMain Menu\033[0m" << endl;
      cout << "\033[32m---------------------\033[0m" << endl;
      cout << "S - Start" << endl;
      cout << "B - Back to menu" << endl;
      cout << "\033[32m---------------------\033[0m" << endl;
      cout << "Enter your choice: ";
      cin >> choice3;

      switch (choice3) {
      case 'S':
      case 's':
        PlayerBuildScreen();
        loop2 = false;
      case 'B':
      case 'b':
        loop2 = false;
        screen_clear();
        break;
      default:
          screen_clear();
          cout << "-------------------------------------" << endl <<"\033[1;31mInvalid\033[0m choice. Please try again." << endl << "------------------------------------" << endl;
          sleep(1);
          screen_clear();

      }
    }
}

int main(){
  //clear previous output 
  screen_clear();
  //reading stats of game elements
  readStatsFromFile(names, health, attack, defense, mana, difficulty);
  readPic(picture);

//menu
char choice;
bool loop1 = true;
    while (loop1 == true) {
        cout << "\033[1;31;40m" << picture[15] << "\033[0m" << endl;
      
        cout << "\033[1mMain Menu\033[0m" << endl;
        cout << "\033[32m---------------------\033[0m" << endl;
        cout << "S - Start" << endl;
        cout << "R - Rules and Background" << endl;
        cout << "Q - Quit" << endl;
        cout << "\033[32m---------------------\033[0m" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'R':
            case 'r':
                Rules_Screen();
                break;
            case 'S':
            case 's':
                PlayerBuildScreen();
                loop1 = false;
                break;
            case 'Q':
            case 'q':
                screen_clear();
                cout << "-----------------------------------" << endl << "See you next time, warrior." << endl << "----------------------------------" << endl;
                return 0;
            
            default:
                screen_clear();
                cout << "-------------------------------------" << endl <<"\033[1;31mInvalid\033[0m choice. Please try again." << endl << "------------------------------------" << endl;
                sleep(1);
                screen_clear();
        }
    }

    return 0;
}
