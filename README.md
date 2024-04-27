![Logo](https://images.cooltext.com/5696966.png)

# Developers
  [Chu Ming Chit](https://github.com/PeterPan246)&ensp;&ensp;UID:3036224963
  [Woo Dee](https://github.com/r4g3r4hk)&ensp;&ensp;UID:3036226167


# Introduction
### Game Background:

  You are a game developer who fell asleep while coding his game, Nerd Dragon Slayer, and wakes up trapped inside it.
  Without a functioning quit feature, you must defeat the dragon within the game to escape. 
  There are only two ways to end this game, either by defeating the dragons, or by dying.



### Game Rules:

  The player starts with initial values for Health, Attack, Defense, Mana, and Money.
  These attributes define the player's capabilities within the game.
  You can choose to increase your Attack, Defense or heal yourself by spending money in the shop.
  You will have 3 options to fight the dragon, Attack, Defend, and Smite.
    1. Attack: You will attack the dragon, dealing damage to it based on your attack stat. (+Money, +Mana)
    2. Defend: You will defend against the dragon's attack, reducing the damage based on your defense stat. (+Mana)
    3. Smite: You will attack the dragon with fixed 2.2x damage, consuming mana in the process. (+Extra Money)
  During each round, the dragon will also attack the player and your health will decrease accordingly. You must manage your resources and abilities strategically to survive and defeat the dragons. Good luck, warrior!




To compile the program files, type the command "make" in terminal to compile the program file to main.
Then, type "./main" to execute it.

Code requirements:

1. Generation of random sets: the amount of damage dealt, damage received, mana and money gained are determined randomly based on your stats.

2. Data structures for storing game status:
- vector to store the stats of the player and the dragons, and the sprites
- integer to store the level number, the damage, money and mana gained at runtime

3. Dynamic memory management
- vector to store the stats of the player and the dragons, and the sprites

4. File input/output
- read the stats of the player and the dragons from "Stats.txt"

5. Program codes in multiple files
- "picture.cpp" is used to store the sprites of the dragons into the game
- "picture.h" is the header file of "picture.cpp"
- "battlesys.cpp" includes a rng, a battle system, prints game screen and part of the end screen
- "battlesys.h" is the header file of "battlesys.cpp"
- "uti.cpp" is used to read from file, clear screen and prints part of the end screen
- "uti.h" is the header file of "uti.cpp"
- "main.cpp" stores the stats, prints the main menu, and starting and rules screen
