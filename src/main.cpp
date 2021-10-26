#include "raylib.h"
#include <iostream>

using namespace std;

int main(void)
{
    Rectangle a{40, 20, 50, 50};
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 vec = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT)) a.x += 3.0f;
        if (IsKeyDown(KEY_LEFT)) a.x -= 3.0f;
        if (IsKeyDown(KEY_UP)) a.y -= 3.0f;
        if (IsKeyDown(KEY_DOWN)) a.y += 3.0f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            
            DrawRectangleRec(a, YELLOW);
            ClearBackground(RAYWHITE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}