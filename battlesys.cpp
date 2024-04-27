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
        break;
      case 4:
        cout << "You're halfway there!" << endl;
        sleep(2);
        cout << "You must defeat all the dragons! Push on!" << endl;
        sleep(2);
        break;
      case 5:
        cout << "You got this, warrior!" << endl;
        sleep(2);
        cout << "You mustn't lose now!" << endl;
        sleep(2);
        break;
      case 6:
        cout << "You're almost at the final stretch!" << endl;
        sleep(2);
        cout << "Don't you give in now!" << endl;
        sleep(2);
        break;
      case 7:
        cout << "This is the last fight." << endl;
        sleep(2);
        cout << "You've gathered all this strength," << endl;
        sleep(2);
        cout << "and now the only thing standing between you and victory," << endl;
        sleep(2);
        cout << "is this final boss." << endl;
        sleep(2);
        cout << "So give it your all," << endl;
        sleep(2);
        cout << "and go give 'em hell!" << endl;
        sleep(2);
        break;
     }
    screen_clear();
    
  //battle choice
    while (health[0] > 0 && health[i] > 0) {
      int dragondamage = 0, protection = 0, playerdamage = 0, blockeddamage = 0, moneygain = 0, managain = 0;
      bool attacking = false;
      printgamingstats(names, health, attack, defense, mana, difficulty, picture, money, i, tempstring, tempdh);
      while (attacking == false){
        
        char choice;
        cout << "Enter your choice: ";
        cin >> choice;

        //attacking make damge with range, it can be reduced by dragon defense. earning money and mana)
        switch (choice) {
        case 'a':
        case 'A':
          dragondamage = rdgen(attack[0]/1.6, attack[0]*1.6);
          if (dragondamage >= defense[i])
            dragondamage -= defense[i];
          else 
            dragondamage = 0;
          managain = rdgen(2, 10);
          mana[0] += managain;
          moneygain = rdgen(7, 20);
          money += moneygain;
          attacking = true;
          break;

        //smite make a solid damge, cant be reduced. earn money only but 2x.
        case 'S':
        case 's':
          if (mana[0] >= 20) {
              mana[0] -= 20;
              dragondamage = attack[0]*2.2;
              moneygain = rdgen(20, 35);
              money += moneygain;
              attacking = true;
              break;
          }
          else {
            screen_clear();
            cout << "-------------------------------------" << endl <<"You need more \033[34mMana\033[0m!" << endl << "------------------------------------" << endl;
            sleep(1);
            screen_clear();
            printgamingstats(names, health, attack, defense, mana, difficulty, picture, money, i, tempstring, tempdh);
            break;
          }

          //make zero damge to dragon by defensing yourself with range, only earned mana but.
        case 'd':
        case 'D':
          protection = rdgen(defense[0]/1.6, defense[0]*1.6);
          managain = rdgen(2, 10);
          mana[0] += managain;
          attacking = true;
          break;

          //go shopping
        case 'P':
        case 'p':
          screen_clear();
          printstore(health, attack, defense, money, i, tempstring);
          screen_clear();
          printgamingstats(names, health, attack, defense, mana, difficulty, picture, money, i, tempstring, tempdh);
          break;
          
        default:
          screen_clear();
          cout << "-------------------------------------" << endl <<"\033[1;31mInvalid\033[0m choice. Please try again." << endl << "------------------------------------" << endl;
          sleep(1);
          screen_clear();
          printgamingstats(names, health, attack, defense, mana, difficulty, picture, money, i, tempstring, tempdh);
        } 
      }

      //damage system
      playerdamage = (rdgen(attack[i]/1.7, attack[i]*1.7));
      if (protection >= playerdamage)
        blockeddamage = 0;
      else 
        blockeddamage = playerdamage - protection;
      health[i] -= dragondamage;
      

      //print damage
      if (health[i] <= 0) {
        tempstring.push_back("Killed level " + to_string(i) + " dragon!"+ " | " + "Money earned: " + to_string(moneygain) + " | " + "Mana gained: " + to_string(managain));
        tempstring.erase(tempstring.begin());
        screen_clear();
        cout << "--------------------------------------------------------------------------" << endl << " You killed the dragon with \033[1;31m" + to_string(dragondamage) + "\033[0m damage!" << endl << "-------------------------------------------------------------------------" << endl;
        sleep(2);
        screen_clear();
        }
      else {
        health[0] -= blockeddamage;
        tempstring.push_back("Blocked: " + to_string(protection) + " damage" + " | " + "Dealt: " + to_string(dragondamage) + " damage" + " | " + "Enemy dealt: " + to_string(playerdamage) + " damage" + " | " + "Money earned: " + to_string(moneygain) + " | " + "Mana gained: " + to_string(managain));
        tempstring.erase(tempstring.begin());
        screen_clear();
        cout << "--------------------------------------------------------------------------" << endl <<"You deal \033[1;31m" + to_string(dragondamage) + "\033[0m damage to " + names[i] + " but it also hit you with \033[1;31m" + to_string(blockeddamage) + "\033[0m damage!!!" << endl << "-------------------------------------------------------------------------" << endl;
        sleep(3);
        screen_clear();
      }
    }
  //game over
  if (health[0] <= 0){
      char choice1;
      bool loop3 = true;
          while (loop3 == true) {
              cout << "\033[1;31mYou died!\033[0m" << endl;
              cout << "\033[32m-------------------------\033[0m" << endl;
              cout << "R - Restart" << endl;
              cout << "Q - Quit" << endl;
              cout << "\033[32m-------------------------\033[0m" << endl;
              cout << "Enter your choice: ";
              cin >> choice1;

              switch (choice1) {
                  case 'R':
                  case 'r':
                      health[0] = 100;
                      gamelevel(names, health, attack, defense, mana, difficulty, picture, money);
                      break;
                  case 'Q':
                  case 'q':
                      loop3 = false;
                      break;
                  default:
                      screen_clear();
                      cout << "-------------------------------------" << endl <<"Invalid choice. Please try again." << endl << "------------------------------------" << endl;
                      sleep(1);
                      screen_clear();
              }
          }          
      gameover();
      break;
      }  
    
  else if (i == 7 && health[0] > 0){
      gamewin();
      break;
      }  
  }
}
