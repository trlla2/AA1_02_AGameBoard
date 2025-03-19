#include <iostream>
#include <Windows.h>
#include "Player.h"
#include "Board.h"

enum PlayerMovement{ EMPTY, UP, DOWN, LEFT, RIGHT};

bool checkMovement(int playerX, int playerY, PlayerMovement& nextMove, Board& board);
void movePlayer(Player* player, PlayerMovement& nextMove, Board* board);
void gameOver();

int main()
{
    // CONFIG
    srand(time(NULL)); // Generate seed for random


    Player player;
    Board board;

    board.initialieBoard(&player);

    board.printBoard();

    board.destroyBoard();
    //
    ////DEBUG -------------- borrar

    //bool userPressedUpKey = false;

    //int frameCount = 0;
    //const int FPS = 60;

    ////GAMELOOP

    //while (true)
    //{
    //    //INPUT
    //    // ----------------- Debug borrar
    //    if (GetAsyncKeyState(VK_UP))//pillar arrow key up
    //    {
    //        userPressedUpKey = true;
    //    }

    //    //UPDATE
    //    // ----------------- Debug borrar
    //    if (userPressedUpKey)
    //    {
    //        userPressedUpKey = false;
    //        system("CLS");
    //    }
    //    if (frameCount >= 9 || userPressedUpKey) {
    //        frameCount = 0;

    //        userPressedUpKey = false;
    //    }
    //    //RENDER
    //    // ----------------- Debug borrar

    //    std::cout << frameCount++ << std::endl;

    //    // FRAME CONTROLS

    //    Sleep(1000 / FPS);
    //}
}


bool checkMovement(int playerX, int playerY, PlayerMovement& nextMove, Board& board) {
    switch (nextMove)
    {
    case UP:
        return board.box[playerX - 1][playerY] != 'W'; // if its not a wall
        break;
    case DOWN:
        return board.box[playerX + 1][playerY] != 'W'; // if its not a wall
        break;
    case LEFT:
        return board.box[playerX][playerY - 1] != 'W'; // if its not a wall
        break;
    case RIGHT:
        return board.box[playerX][playerY + 1] != 'W'; // if its not a wall
        break;
    default:
        return false;
        break;
    }

    return false;
}

void movePlayer(Player* player, PlayerMovement& nextMove, Board* board) { // assume that we have checked the movement previously 
    switch (nextMove)
    {
    case UP:
        switch (board->box[player->posX - 1][player->posY]) // check if is a gem or spike
        {
        case 'G':
            player->addScore();
            board->numGems--; // - 1 gem of gem counter
            break;
        case 'S':
            player->isAlive = false; // set is alive to false
            break;
        default:
            break;
        }

        // move player
        board->box[player->posX - 1][player->posY] = 'P'; // set player position on the board
        player->setPosition(player->posX - 1, player->posY);
        break;
    case DOWN:
        switch (board->box[player->posX + 1][player->posY]) // check if is a gem or spike
        {
        case 'G':
            player->addScore();
            board->numGems--; // - 1 gem of gem counter
            break;
        case 'S':
            player->isAlive = false; // set is alive to false
            break;
        default:
            break;
        }

        // move player
        board->box[player->posX + 1][player->posY] = 'P'; // set player position on the board
        player->setPosition(player->posX + 1, player->posY);
        break;
    case LEFT:
        switch (board->box[player->posX][player->posY - 1]) // check if is a gem or spike
        {
        case 'G':
            player->addScore();
            board->numGems--; // - 1 gem of gem counter
            break;
        case 'S':
            player->isAlive = false; // set is alive to false
            break;
        default:
            break;
        }

        // move player
        board->box[player->posX][player->posY - 1] = 'P'; // set player position on the board
        player->setPosition(player->posX, player->posY - 1);
        break;
    case RIGHT:
        switch (board->box[player->posX][player->posY + 1]) // check if is a gem or spike
        {
        case 'G':
            player->addScore();
            board->numGems--; // - 1 gem of gem counter
            break;
        case 'S':
            player->isAlive = false; // set is alive to false
            break;
        default:
            break;
        }

        // move player
        board->box[player->posX ][player->posY + 1] = 'P'; // set player position on the board
        player->setPosition(player->posX, player->posY + 1);
        break;
    default:
        break;
    }

}