#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 10
#define BIRD_X 5
#define MAX_PILLARS 3  // Number of pillars
#define MIN_GAP_DISTANCE 3  // Minimum distance between gaps

typedef struct {
    int y; // Bird's vertical position
} Bird;

typedef struct {
    int x;        // Pillar's horizontal position
    int gapY;     // Position of the gap
    int gapSize;  // Size of the gap
} Pillar;

void drawGame(Bird *bird, Pillar pillars[], int score) {
    system("CLS");

    // Top border
    printf("+");
    for (int i = 0; i < WIDTH; i++) printf("--");
    printf("+\n");

    // Draw the game space
    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (j == BIRD_X && i == bird->y) {
                printf("<>"); // Bird
            } else {
                int pillarDrawn = 0;
                for (int p = 0; p < MAX_PILLARS; p++) {
                    if (j == pillars[p].x && (i < pillars[p].gapY || i >= pillars[p].gapY + pillars[p].gapSize)) {
                        printf("[]"); // Pillar
                        pillarDrawn = 1;
                        break;
                    }
                }
                if (!pillarDrawn) {
                    printf("  "); // Empty space
                }
            }
        }
        printf("|\n");
    }

    // Bottom border
    printf("+");
    for (int i = 0; i < WIDTH; i++) printf("--");
    printf("+\n");

    printf("Score: %d\n", score);
}

int checkCollision(Bird *bird, Pillar pillars[]) {
    if (bird->y <= 0 || bird->y >= HEIGHT - 1) return 1; // Hits top or bottom
    for (int i = 0; i < MAX_PILLARS; i++) {
        if (pillars[i].x == BIRD_X && (bird->y < pillars[i].gapY || bird->y >= pillars[i].gapY + pillars[i].gapSize)) {
            return 1; // Hits any pillar
        }
    }
    return 0;
}

void movePillars(Pillar pillars[], int *score) {
    for (int i = 0; i < MAX_PILLARS; i++) {
        pillars[i].x--;

        // Check if the pillar is off screen and reset it
        if (pillars[i].x < 0) {
            pillars[i].x = WIDTH - 1;

            // Define minimum and maximum Y positions for the gap
            int minGapY = 3;  // Minimum y-position for the top of the gap
            int maxGapY = HEIGHT - 3 - pillars[i].gapSize;  // Maximum y-position for the bottom of the gap
            
            // Randomize new gap position
            pillars[i].gapY = rand() % (maxGapY - minGapY + 1) + minGapY;
            (*score)++; // Increase score for each pillar that goes off-screen
        }
    }
}

void updateBird(Bird *bird) {
    if (_kbhit() && _getch() == 'j') {
        bird->y -= 2; // Jump
    }
    bird->y++; // Gravity effect
    if (bird->y >= HEIGHT - 1) bird->y = HEIGHT - 1; // Prevent going out of bounds
    if (bird->y < 0) bird->y = 0; // Prevent going out of bounds
}

void showWelcomeScreen() {
    system("CLS");
    printf("Welcome to Flappy Bird!\n");
    printf("Instructions:\n");
    printf("1. Press 'j' to jump.\n");
    printf("2. Avoid the pillars!\n");
    printf("3. Score points by passing through the gaps.\n");
    printf("Press any key to start...\n");
    _getch();  // Wait for the user to press a key
}

int main() {
    srand(time(0));
    Bird bird = {HEIGHT / 2};

    // Show the welcome screen
    showWelcomeScreen();

    // Initialize multiple pillars
    Pillar pillars[MAX_PILLARS];
    for (int i = 0; i < MAX_PILLARS; i++) {
        pillars[i].x = WIDTH - 1 + (i * 6); // Set each pillar at an interval
        pillars[i].gapSize = 2; // Fixed gap size of 2
        // Initial gap position for the pillars
        int minGapY = 3; // Minimum y-position for the top of the gap
        int maxGapY = HEIGHT - 3 - pillars[i].gapSize; // Maximum y-position for the bottom of the gap
        pillars[i].gapY = rand() % (maxGapY - minGapY + 1) + minGapY;
    }

    int score = 0;

    while (1) {
        updateBird(&bird);
        movePillars(pillars, &score);

        if (checkCollision(&bird, pillars)) {
            printf("Game Over! Final Score: %d\n", score);
            break;
        }

        drawGame(&bird, pillars, score);
        Sleep(150);
    }

    return 0;
}
