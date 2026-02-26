#include "raylib.h"
#include <math.h>
#include <stdio.h>

#define W_WIDTH  1280
#define W_HEIGHT 1024

#define BRANCH_COLOR RAYWHITE

#define START_THICKNESS 30
#define START_LENGTH 250

void DrawBranch(Vector2 start, float length, float angle, float thickness); // Draws a branch of the fractal tree

int main(void)
{
    InitWindow(W_WIDTH, W_HEIGHT, "Fractal Tree");

    while (!WindowShouldClose()) 
    {
	SetTargetFPS(1);
        BeginDrawing();

            ClearBackground(BLACK);

	    Vector2 start = { W_WIDTH/2, W_HEIGHT };
	    float angle = (2 * M_PI) / 11;
	    
	    // Starts the drawing of the tree
	    DrawBranch(start, START_LENGTH, 0, START_THICKNESS);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void DrawBranch(Vector2 start, float length, float angle, float thickness)
{
    // Base case to stop recursion and prevent stack overflow
    if(length < 1.0f) return;

    // Calculating x_end and y_end of rectangle
    float x_end = start.x + sin(angle) * length;
    float y_end = start.y - cos(angle) * length;

    Vector2 end = { x_end, y_end };

    DrawLineEx(start, end, thickness, BRANCH_COLOR); // Draws the line
    
    // Calculating new length
    float newLength = length * 0.75f;

    // Calculating new thickness
    float newThickness = thickness * 0.75f;

    // Calculating new left and right angles
    float newAngleRight = angle + ((2 * M_PI) / 11);
    float newAngleLeft = angle - ((2 * M_PI) / 11);

    // Recursive call
    DrawBranch(end, newLength, newAngleRight, newThickness); // Right
    DrawBranch(end, newLength, newAngleLeft, newThickness); // Left
}
