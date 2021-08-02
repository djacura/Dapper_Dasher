#include "raylib.h"

int main()
{
    // window dimensions
    const int windowWidth{512};
    const int windowHeight{380};

    // Initilize the window
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // Stop drawing
        EndDrawing();
    }
    CloseWindow();
}