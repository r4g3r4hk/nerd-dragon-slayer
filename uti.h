#ifndef UTI_H
#define UTI_H

#include <vector>
#include <string>
using namespace std;

void screen_clear();
void readStatsFromFile(vector<string>& names, vector<int>& health, vector<int>& attack, vector<int>& defense, vector<int>& mana, vector<string>& difficulty);
void gamewin();
void gameover();

#endif
