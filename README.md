![Logo](https://images.cooltext.com/5696966.png)

# Developers👨🏻‍💻
  [Chu Ming Chit](https://github.com/EricMingChit)&ensp;&ensp;UID:3036224963
  
  [Woo Dee](https://github.com/r4g3r4hk)&ensp;&ensp;UID:3036226167


# Introduction📚

  Welcome, brave warrior!🗡️
  
  This is our new C++ text-based game, Nerd Dragon Slayer!!! In this game you experience engaging classic battle with different dragons.

  Please watch our [demo video](https://www.youtube.com/watch?v=fQ3mu96rIiU)!

  Here is a little strategy if you can't pass all 7 levels. Please read it after trying!!!

  ⬇️⬇️⬇️⬇️⬇️⬇️⬇️⬇️⬇️
  <details>
  <summary>Click to reveal the strategy!</summary>
  > Upgrade defense in the early stage to save mana, save money in the mid-stage, Upgrade attack in the late-stage.
  </details>
  ⬆️⬆️⬆️⬆️⬆️⬆️⬆️⬆️⬆️

  
## Game Background📝

  You are a game developer who fell asleep while coding his game, Nerd Dragon Slayer, and wakes up trapped inside it.
  
  Without a functioning quit feature, you must defeat all the dragons within the game to escape. 
  
  There are only two ways to end this game, either by defeating the dragons, or by dying.



## Game Rules:🗒️

  The player starts with initial values for Health, Attack, Defense, Mana, and Money.
  
  ### These attributes define the player's capabilities within the game.
  
  ```bash
  |Eric                       Balance: $100|   
  |Health: 100/100                         | 
  |Attack: 10                              |        
  |Defense: 5                              | 
  |Mana: 5                                 | 
  ```

  ### You can choose to increase your Attack, Defense or heal yourself by spending money in the shop.

  ```bash
  Shopping Menu                          Balance: $100

  -------------------------------------------------------------------------------------------------
  S - Sword Upgrade (+5 Attack)           Price: $30
  -------------------------------------------------------------------------------------------------
  A - Armor Upgrade (+5 Defense)          Price: $25
  -------------------------------------------------------------------------------------------------
  H - Heal (+20 Health)                   Price: $20
  -------------------------------------------------------------------------------------------------
  Q - Back to the fight                   Price: $0
  -------------------------------------------------------------------------------------------------
  Type your choice:
  ```
  
  ### You will have 3 options to fight the dragon, Attack, Defend, and Smite.
  
  1. Attack: You will attack the dragon, dealing damage to it based on your attack stat. (+Money, +Mana)⚔️
    
  2. Defend: You will defend against the dragon's attack, reducing the damage based on your defense stat. (+Mana)𐂫
    
  3. Smite: You will attack the dragon with fixed 2.2x damage, consuming mana in the process. (+Extra Money)🩸

  ```bash
  A - Attack   S - Smite(20 Mana) D - Defense  P - Shopping
  Enter your choice: 
  ```
  
  
  ### During each round, the dragon will also attack the player and your health will decrease accordingly.

  ```bash
  -------------------------------------------------------------------------
  You deal 6 damage to Emberclaw but it also hit you with 12 damage!!!
  -------------------------------------------------------------------------
  ```
  
  You must manage your resources and abilities strategically to survive and defeat the dragons.
  
  Good luck, warrior!

# Code requirements💻

  ### 1. Generation of random sets: 
  - the amount of damage dealt, damage received, mana and money gained are determined randomly based on your stats.

  ### 2. Data structures for storing game status:
  - vector to store the stats of the player and the dragons, and the sprites.
  - integer to store the level number, the damage, money and mana gained at runtime.

  ### 3. Dynamic memory management
  - vector to store the previous 3 in-game events .

  ### 4. File input/output
  - read the stats of the player and the dragons from "Stats.txt".

  ### 5. Program codes in multiple files
  - "picture.cpp" is used to store the sprites of the dragons into the game.
  - "picture.h" is the header file of "picture.cpp".
  - "battlesys.cpp" includes a rng, a battle system, prints game screen and part of the end screen.
  - "battlesys.h" is the header file of "battlesys.cpp".
  - "uti.cpp" is used to read from file, clear screen and prints part of the end screen.
  - "uti.h" is the header file of "uti.cpp".
  - "main.cpp" stores the stats, prints the main menu, and starting and rules screen.

# Non-standard libraries📖
  No Non-standard linraries are used in this project and integrated to our code repo.

# Compilation and execution instructions🏃🏻

  To compile the program files, type the command 

  ```bash
  make
  ```

  in terminal to compile the program file to main.
  Then, type 

  ```bash
  ./main
  ```
  to execute it.
