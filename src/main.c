#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "Poker con Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("¡Raylib funciona!", 220, 280, 30, DARKBLUE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}