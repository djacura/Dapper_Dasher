#include "raylib.h"

int main()
{
    // window dimensions
    const int windowWidth{512};
    const int windowHeight{380};

    // Initilize the window
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    // acceleration due to gravity (pixels per second) per second (p/s)/s
    const int gravity{1'000};

    // is rectangle in the air?
    bool isInAir{};

    // nebula variables
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");


    //scarfy variables
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height;

    // animation frame
    int frame{};
    // amount of time before we update animation time
    const float updateTime{1.0 / 12.0};
    float runningTime{};

    // jump velocity pixels per second
    const int jumpVel{-600};

    int velocity{0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Delta time (time since last frame)
        const float dT{GetFrameTime()};

        // Start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // ground check
        if (scarfyPos.y >= windowHeight - scarfyRec.height)
        {
            // rectangle is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // rectangle is in the air
            velocity += gravity * dT;
            isInAir = true;
        }

        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }

        // update position
        scarfyPos.y += velocity * dT;

        // update running time
        runningTime += dT;
        if (runningTime >= updateTime)
        {
            runningTime = 0;
            // update animation frame
            scarfyRec.x = frame * scarfyRec.width;
            frame++;
            if (frame > 5)
            {
                frame = 0;
            }
        }

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        // Stop drawing
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();
}