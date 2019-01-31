#pragma once
#include "GameBase.h"
#include "Player.h"
#include "Board.h"

class Game : public GameBase
{
public:
    Game();
    void init() override;
    void play() override;
    virtual ~Game();

private:
    void showEndScore() const;
    void showCurrentScore() const;
    int  bountyEraned(DotBase* firstDot, DotBase* secondDot);
    bool isValidMove(size_t pos1, size_t pos2) const;
    bool isGameOver() const;
    bool isClosedPath(DotBase* firstDot, DotBase* secondDot, const Dot::Position& pos) const;
    size_t getBoxCount() const;

    size_t m_iTurn;
    size_t m_iBoxCount;
    int m_iBountyCredit;
    Player* m_players[2];
    Board  m_board;
};

