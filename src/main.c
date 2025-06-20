#include "raylib.h"

int main(void) {
    InitWindow(1400, 800, "Poker con fondo personalizado");
    Font fuente = LoadFont("assets/BucklaneScript.otf");
    Texture2D fondo1 = LoadTexture("assets/img1.png");
    Texture2D fondo2 = LoadTexture("assets/img2.png");
    Texture2D fondoActual = fondo1;

    Rectangle boton1 = { 900, 250, 160, 40 };
    Rectangle boton2 = { 600, 600, 160, 40};
    Rectangle cerrar = { 1000, 700, 300, 40};
    bool mouseSobreBoton1 = false;
    bool mouseSobreBoton2 = false;
    bool mouseSobreCerrar = false;

    bool botonPresionado1 = false;
    bool botonPresionado2 = true;


    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();
        mouseSobreBoton1 = CheckCollisionPointRec(mouse, boton1);
        mouseSobreBoton2 = CheckCollisionPointRec(mouse, boton2);
        mouseSobreCerrar = CheckCollisionPointRec(mouse, cerrar);

        if (mouseSobreCerrar && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            CloseWindow();
        }

        if(!botonPresionado1){
            mouseSobreBoton1 = CheckCollisionPointRec(mouse, boton1);
            if (mouseSobreBoton1 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                fondoActual = (fondoActual.id == fondo1.id) ? fondo2 : fondo1;
                botonPresionado1 = true;  // Ya no se mostrará más
                botonPresionado2 = false;
            }
        }
        if(!botonPresionado2){
            mouseSobreBoton2 = CheckCollisionPointRec(mouse, boton2);
            if (mouseSobreBoton2 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                fondoActual = (fondoActual.id == fondo1.id) ? fondo2 : fondo1;
                botonPresionado2 = true;  // Ya no se mostrará más
                botonPresionado1 = false;
            }
        }

        BeginDrawing();

        DrawTexture(fondoActual, 0, 0, WHITE);
        ClearBackground(RAYWHITE);  // no afecta porque el fondo se dibuja encima

        DrawRectangleRec(cerrar, mouseSobreCerrar ? RED : CLITERAL(Color){ 139, 0, 0, 255 });
        DrawRectangleLinesEx(cerrar, 2, BLACK);
        DrawText("Tocame y eres gei", cerrar.x + 50, cerrar.y + 10, 20, WHITE);

        
        if (!botonPresionado1) {
            DrawRectangleRec(boton1, mouseSobreBoton1 ? DARKGRAY : GRAY);
            DrawRectangleLinesEx(boton1, 2, BLACK);
            DrawTextEx(fuente, "Clickeame", (Vector2){boton1.x + 10, boton1.y + 10}, 20, 2, BLACK);
            DrawTextEx(fuente, "Sabpe", (Vector2){800, 150}, 40, 2, DARKPURPLE);
        }
        if (!botonPresionado2) {
            DrawRectangleRec(boton2, mouseSobreBoton2 ? DARKGRAY : GRAY);
            DrawRectangleLinesEx(boton2, 2, BLACK);
            DrawTextEx(fuente, "ay wacala", (Vector2){boton2.x + 10, boton2.y + 10}, 20, 2, BLACK);
            DrawTextEx(fuente, "Nachiod", (Vector2){1000, 400}, 40, 2, LIGHTGRAY);
        }

        //DrawRectangleRec(boton, mouseSobreBoton ? DARKGRAY : GRAY);
        //DrawRectangleLinesEx(boton, 2, BLACK);
        //DrawTextEx(fuente,"Cambiar fondo", (Vector2){boton.x + 10, boton.y + 10}, 20, 2, BLACK);
        
        
        

        EndDrawing();
    }
    UnloadFont(fuente);

    UnloadTexture(fondo1);
    UnloadTexture(fondo2);
    CloseWindow();
    return 0;
}