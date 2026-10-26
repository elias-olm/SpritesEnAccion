#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector
#endif

#include "raylib.h"


int main(void)
{
    // Inicializacion
    InitWindow(1080, 720, "Sprites en Accion");
    SetTargetFPS(60);
    

    // Carga

   Texture2D vault_guy = LoadTexture("sprite.png");
   SetTextureFilter(vault_guy, TEXTURE_FILTER_BILINEAR);

    Vector2 posicion1 = {840,200};
    Vector2 posicion2 = {300,200};
    Color color1 = RED;
    Color color2 = BLUE;
    int rotacion1 = 0;
    int rotacion2 = 90;
    float escala1 = 0.5; 
    float escala2 = 0.75;
    int contador = 10;
    int rojoX = 700;
    int azulX = 0;
    
    // Bucle principal
    while (!WindowShouldClose())
    {
        // Actualizacion

        if (IsKeyPressed(KEY_SPACE)) {

            int aux;   
            aux = azulX;
            azulX = rojoX;
            rojoX = aux;
            
            
            float tempRot = rotacion1;
            rotacion1 = rotacion2;
            rotacion2 = tempRot;

            float tempEsc = escala1;
            escala1 = escala2;
            escala2 = tempEsc;


            Color tempColor = color1;
            color1 = color2;
            color2 = tempColor;
        }

        // Dibujado
        BeginDrawing(); 
        ClearBackground(WHITE);

        DrawTextureEx(vault_guy,posicion1,rotacion1,escala1,color1);
        DrawTextureEx(vault_guy,posicion2,rotacion2,escala2,color2);
        
        DrawText("Presionar espacio para invertir propiedades",0 ,0, 20, BLACK);
        DrawText("Color=Azul Escala=0.75 Rotacion=90",azulX,100,20,BLACK);
        DrawText("Color=Rojo Escala=0.5 Rotacion=0", rojoX, 100, 20, BLACK);
        
        posicion1.x++;
        posicion2.x++;
        contador--;

        if (contador == 0) {
            posicion1.x= posicion1.x-10;
            posicion2.x = posicion2.x - 10;
            contador = 10;
        }


        EndDrawing();


    }

    // Descarga
    UnloadTexture(vault_guy);



    // Cierre
    CloseWindow();

    return 0;
}

