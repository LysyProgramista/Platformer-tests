#include "raylib.h"
#include <iostream>

using namespace std;

int ball(int x, int y, int width, int height)
{
    DrawRectangle(x, y, width, height, BLUE);
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 3.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 3.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 3.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 3.0f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ball(0, 0, 10, screenHeight);
            ClearBackground(RAYWHITE);
                
            DrawRectangle(ballPosition.x, ballPosition.y, 60, 30, BLUE);
            

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}