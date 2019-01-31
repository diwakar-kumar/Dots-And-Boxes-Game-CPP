// DotsAndBoxesGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

int main()
{
    Game dotboxGame;
    dotboxGame.init();
    dotboxGame.play();

    getchar();
    return 0;
}

