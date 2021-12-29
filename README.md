# **Randomizer! - C++ OOP text-based RPG**

## **About**

**Randomizer!** is a text-based RPG written in C++.

The goal of the game is to **kill the enemies**, or **be killed yourself**!

## **Features**

### ***Version 0.1***

- Choose a name for your hero...
- ...and a starting type
- The game gives you a set of **armor** (split into Head, Body and Legs) and a **weapon**, with random stats
- The starting type sets the base stats:
    - **Health Points (HP)**
    - **Stamina** - dictates how many times you can attack the enemy consecutively, before being forced to parry
    - **Defence** - splits any incoming attack as follows:
        - Most of the damage gets absorbed by a piece of armor
        - The rest goes directly to your HP
    - **Parry** - adds a small buff to your defence when you're parrying an attack
- You can either attack the enemy, or parry his attack.

### ***Version 0.2***

- You can now fight multiple enemies!
- You can also heal yourself using either:
  - A **small potion** that heals 1/4 of your base HP
  - A **big potion** that heals 1/2 of your base HP
- You are rewarded with a potion every 4 successful attacks on an enemy
- The **big potion** is rarer than the **small potion**

### ***Version 0.3***

- You now have the option to fight a **boss**
  - Choose between three difficulties: **easy**, **medium** and **hard**
  - Depending on which difficulty you chose, the boss drops:
    - One **small potion** - *easy boss*
    - One **big potion** - *medium boss*
    - A **small potion** and a **big potion** - *hard boss*