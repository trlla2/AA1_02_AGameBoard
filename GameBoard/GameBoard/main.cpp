#include <iostream>
#include <Windows.h>

void gameOver();
void checkMovement();


int main()
{
    
    // CONFIG
    //DEBUG -------------- borrar

    bool userPressedUpKey = false;

    int frameCount = 0;
    const int FPS = 60;

    //GAMELOOP

    while (true)
    {
        //INPUT
        // ----------------- Debug borrar
        if (GetAsyncKeyState(VK_UP))//pillar arrow key up
        {
            userPressedUpKey = true;
        }

        //UPDATE
        // ----------------- Debug borrar
        if (userPressedUpKey)
        {
            userPressedUpKey = false;
            system("CLS");
        }
        if (frameCount >= 9 || userPressedUpKey) {
            frameCount = 0;

            userPressedUpKey = false;
        }
        //RENDER
        // ----------------- Debug borrar

        std::cout << frameCount++ << std::endl;

        // FRAME CONTROLS

        Sleep(1000 / FPS);
    }
}
