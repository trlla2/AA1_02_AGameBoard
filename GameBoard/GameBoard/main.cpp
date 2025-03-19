#include <iostream>
#include <Windows.h>
#include "Player.h"
#include "Board.h"

enum PlayerMovement{ EMPTY, UP, DOWN, LEFT, RIGHT};

bool checkMovement(int& playerX, int& playerY, PlayerMovement& nextMove, Board& board);
void movePlayer(Player* player, PlayerMovement& nextMove, Board* board);
bool gameOver(Player& player, Board& board, bool* win);

int main()
{
    // CONFIG
    srand(time(NULL)); // Generate seed for random


    Player player;
    Board board;
    PlayerMovement nextMove = EMPTY;
    bool win = false;

    board.initialieBoard(&player);

    board.printBoard();

    
    

    
    const int FPS = 60;

    //GAMELOOP

    while (!gameOver(player ,board , &win))
    {
        //INPUT
        if (GetAsyncKeyState(VK_UP))// arrow key up
        {
            nextMove = UP;
        }
        else if (GetAsyncKeyState(VK_DOWN))// arrow key down
        {
            nextMove = DOWN;
        }
        else if (GetAsyncKeyState(VK_LEFT))// arrow key down
        {
            nextMove = LEFT;
        }
        else if (GetAsyncKeyState(VK_RIGHT))// arrow key down
        {
            nextMove = RIGHT;
        }

        //UPDATE
        
        if (nextMove != EMPTY)
        {   
            if (checkMovement(player.posX, player.posY, nextMove, board)) { // check next Move
                movePlayer(&player, nextMove, &board);
            }
            
            system("CLS");
        }
        //RENDER
        
        if (nextMove != EMPTY)
        {
            nextMove = EMPTY;
            board.printBoard();
        }


        // FRAME CONTROLS

        Sleep(1000 / FPS);
    }
    system("CLS");

    if (win) {
        cout << "You win";
    }
    else {
        cout << "You lose";
    }
    

    board.destroyBoard();

}


bool checkMovement(int& playerX, int& playerY, PlayerMovement& nextMove, Board& board) {
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
        board->box[player->posX][player->posY] = '.'; // set last position to '.'
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
        board->box[player->posX][player->posY] = '.'; // set last position to '.'
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
        board->box[player->posX][player->posY] = '.'; // set last position to '.'
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
        board->box[player->posX][player->posY] = '.'; // set last position to '.'
        player->setPosition(player->posX, player->posY + 1);
        break;
    default:
        break;
    }

}

bool gameOver(Player& player, Board& board, bool* win) {
    if (!player.isAlive) {
        *win = false;
        return true;
    }
    else if (board.numGems <= 0) {
        *win = true;
        return true;
    }
    else {
        return false;
    }
}