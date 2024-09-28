# Flappy Bird on C
## Overview
This project is a simple Flappy Bird game implemented in C, where the player controls a bird that must navigate through pillars while avoiding collisions. The game features basic graphics and mechanics, running in a loop until the player decides to quit.

![Screenshot (120)](https://github.com/user-attachments/assets/f82fa438-3724-49f9-b410-fc1c3deb6b02)


## How to Play
1. **Controls:**
   * Press the **J** key to make the bird jump.
   * The bird will fall due to gravity when not in motion.
2. **Quit:**
   * Press **Q** at any time to exit the game.

## Game Rules
* The game is played by controlling a bird to fly between gaps in moving pillars.
* The bird starts at the center of the screen and continuously falls due to gravity.
* The player must time their jumps to navigate through gaps in the pillars.
* If the bird collides with a pillar or the top/bottom of the screen, the game ends, and the score is displayed.
* Points are scored each time the bird successfully passes through a pillar gap.

## Game Features
* **Dynamic Pillar Movement:** Pillars move towards the left of the screen, creating a challenging gameplay experience.
* **Randomized Gap Positioning:** Each new pillar has a randomly generated gap to keep the game unpredictable.
* **Scoring:** The score is displayed at the bottom of the screen, increasing each time the bird passes through a pillar gap.
* **Real-time Updates:** The game updates the screen continuously, displaying the bird, pillars, and current score.

## Code Breakdown
### Functions
1. **drawGame:** Clears the console and redraws the game scene, including the bird, pillars, and score.
2. **checkCollision:** Detects collisions between the bird and the pillars or screen boundaries, determining if the game should end.
3. **movePillars:** Updates the position of the pillars and resets them when they move off-screen, ensuring a continuous challenge.
4. **updateBird:** Updates the bird's position based on player input and gravity.
5. **main:** The main game loop that controls the flow of the game, including input handling, movement updates, collision checks, and screen redraws.

### Game Loop
The main game loop continuously runs until the player quits. In each iteration:
* It captures player input.
* Updates the bird’s position and moves the pillars.
* Checks for collisions and updates the score.
* The screen is updated to display the current game state.
* The loop runs at a controlled frame rate for smooth gameplay.

## Dependencies
* **<stdio.h>:** Standard input and output functions.
* **<stdlib.h>:** Standard utility functions, including random number generation.
* **<conio.h>:** Provides console input/output functions (e.g., **_kbhit()** and **_getch()**).
* **<windows.h>:** Includes the **Sleep()** function and other Windows-specific utilities.
* **<time.h>:** Used for seeding the random number generator with the current time.

## Compilation
To compile and run this game on a Windows system, you can use any C compiler such as **GCC** or **MSVC**. 

**Here's an example using GCC:**

    gcc flappy_bird_game.c -o flappy_bird_game.exe

**To run the code:**

    ./flappy_bird_game.exe

**Note:**
This game uses Windows-specific libraries (**<conio.h>**, **<windows.h>**). If you're compiling on a non-Windows system, modifications will be required to replace these dependencies.

## Future Improvements
* **Multiplayer Mode:** Add support for a second player, allowing cooperative play or competition.
* **Enhanced Graphics:** Implement graphical elements instead of text-based visuals for a better user experience.
* **Sound Effects:** Incorporate sound effects for jumps, collisions, and scoring to enhance gameplay.
* **Difficulty Levels:** Introduce different difficulty settings that affect pillar speed and gap size, catering to various skill levels.

