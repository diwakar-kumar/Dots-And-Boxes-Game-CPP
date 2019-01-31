#include "stdafx.h"
#include "Game.h"

namespace
{
    size_t MAX_PLAYERS = 2;
    void swap(size_t& pos1, size_t& pos2)
    {
        pos1 = pos2 + pos1;
        pos2 = pos1 - pos2;
        pos1 = pos1 - pos2;
    }
}

Game::Game(): m_iTurn(0), m_iBountyCredit(1)
{
    m_players[0] = nullptr;
    m_players[1] = nullptr;
}

Game::~Game()
{
    delete m_players[0];
    delete m_players[1];
    m_players[0] = nullptr;
    m_players[0] = nullptr;
}

void Game::init()
{
    std::string name1, name2;
    std::cout << "Please enter name of Player 1: ";
    std::cin >> name1;
    m_players[0] = new Player(name1);
    std::cout << "Please enter name of Player 2: ";
    std::cin >> name2;
    m_players[1] = new Player(name2);
    m_board.setSize(4, 4);
    m_board.buildBoard();
}

void Game::play()
{
    std::cout << "**** Welcome to Dots and Boxes Game ****" << std::endl;
    do 
    {
        showCurrentScore();
        m_board.draw();
        Player* pPlayer = m_players[m_iTurn];
        size_t first = 0;
        size_t  second = 0;
        std::cout << pPlayer->name() << "'s turn" << std::endl;
        std::cout << "Select two dots (1-"<<m_board.getSize() <<"). Type (0) to exit: ";
        std::cin >> first;

        if (first == 0)
        {
            break;
        }

        std::cin >> second;

        if (first > second)
        {
            swap(first, second);
        }

        if (isValidMove(first, second))
        {
            bool bRightMove = (second - first) == 1;
            DotBase* pFirstDot = m_board.getDotAt(first - 1);
            DotBase* pSecondDot = m_board.getDotAt(second - 1);
            if (bRightMove)
            {
                pFirstDot->setAdjacentDotAt(pSecondDot, Dot::Position::eRight);
                pSecondDot->setAdjacentDotAt(pFirstDot, Dot::Position::eLeft);
            }
            else
            {
                pFirstDot->setAdjacentDotAt(pSecondDot, Dot::Position::eBottom);
                pSecondDot->setAdjacentDotAt(pFirstDot, Dot::Position::eTop);
            }

            int bounty = bountyEraned(pFirstDot, pSecondDot);
            if (bounty > 0)
            {
                pPlayer->addBounty(bounty);
            }
            else
            {
                m_iTurn = (++m_iTurn) % MAX_PLAYERS;
            }
        }
        else
        {
            std::cout << "***** Wrong move" << std::endl;
        }
    } while (!isGameOver());

    m_board.draw();
    showEndScore();  
    std::cout << "*** Thank you ***" << std::endl;
    getchar();
}

void Game::showEndScore() const
{
    showCurrentScore();

    if (m_players[0]->getBounty() == m_players[1]->getBounty())
    {
        std::cout << "It's a DRAW !!" << std::endl;
    } 
    else if (m_players[0]->getBounty() > m_players[1]->getBounty())
    {
        std::cout << "*** Winner is: "<< m_players[0]->name() << std::endl;
    } 
    else
    {
        std::cout << "*** Winner is: " << m_players[1]->name() << std::endl;
    }
}

void Game::showCurrentScore() const
{
    std::cout << "Current score: ";
    std::cout << m_players[0]->name() << ": " << m_players[0]->getBounty() << " ";
    std::cout << m_players[1]->name() << ": " << m_players[1]->getBounty() << " " << std::endl;
}

size_t Game::getBoxCount() const
{
    return (m_board.getColSize() - 1) * (m_board.getRowSize() - 1);
}

bool Game::isValidMove(size_t pos1, size_t pos2) const
{
    if (pos1 > pos2)
    {
        swap(pos1, pos2);
    }

    // Out of range input
    if ((pos2 - pos1) > m_board.getSize() - 1)
    {
        return false;
    }

    DotBase* firstDot = m_board.getDotAt(pos1 - 1);
    DotBase* secondDot = m_board.getDotAt(pos2 - 1);
    const size_t posDIff = pos2 - pos1;

    // Case 0: Check for boundary dots
    if (pos1 % m_board.getColSize() == 0 && posDIff == 1)
    {
        return false;
    }

    // Case 1: Check for same dots
    if (posDIff == 0)
    {
        return false;
    }
    else
    {
        // Case 2: Already moved
        if (posDIff == 1)  // horizontal line like 5 and 6
        {
            if (firstDot->getAdjacentDotAt(Dot::Position::eRight) != nullptr ||
                secondDot->getAdjacentDotAt(Dot::Position::eLeft) != nullptr)
            {
                return false;
            }
        }

        if (posDIff == m_board.getColSize()) // vertical line like 2 6 for col size 4
        {
            if (firstDot->getAdjacentDotAt(Dot::Position::eBottom) != nullptr ||
                secondDot->getAdjacentDotAt(Dot::Position::eTop) != nullptr)
            {
                return false;
            }
        }
        // Case 3: Diagonal move
        if (posDIff != 1 && (posDIff != m_board.getColSize()))
        {
            return false; // Diagonal move
        }
    }

    return true;
}

int Game::bountyEraned(DotBase* firstDot, DotBase* secondDot)
{
    bool bRightMove = secondDot->id() - firstDot->id() == 1;
    int bounty = 0;

    if (bRightMove)
    {
        if (isClosedPath(firstDot, secondDot, Dot::Position::eTop))
        {
            bounty += m_iBountyCredit;
            ++m_iBoxCount;
        }

        if (isClosedPath(firstDot, secondDot, Dot::Position::eBottom))
        {
            bounty += m_iBountyCredit;
            ++m_iBoxCount;
        }
    }
    else
    {
        if (isClosedPath(firstDot, secondDot, Dot::Position::eLeft))
        {
            bounty += m_iBountyCredit;
            ++m_iBoxCount;
        }

        if ( isClosedPath(firstDot, secondDot, Dot::Position::eRight) )
        {
            bounty += m_iBountyCredit;
            ++m_iBoxCount;
        }

    }
    return bounty;
}

bool Game::isClosedPath(DotBase* firstDot, DotBase* secondDot, const Dot::Position& pos) const
{
    Dot* firstDotAtPos = dynamic_cast<Dot*>(firstDot->getAdjacentDotAt(pos));
    if (firstDotAtPos != nullptr)
    {
        Dot* secondDotAtPos = dynamic_cast<Dot*>(secondDot->getAdjacentDotAt(pos));
        if (secondDotAtPos != nullptr)
        {
            if (firstDotAtPos->isAdjacentOf(secondDotAtPos))
            {
                return true;
            }
        }
    }        
    return false;
}

bool Game::isGameOver() const
{
    if (m_iBoxCount  == getBoxCount())
    {
        return true;
    }
    return false;
}
