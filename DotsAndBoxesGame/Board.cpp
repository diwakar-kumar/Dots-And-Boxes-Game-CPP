#include "stdafx.h"
#include "Board.h"
#include "Dot.h"

Board::Board(): BoardBase()
{
}

Board::~Board()
{
    for (auto dot : m_dots)
    {
        delete dot;
    }
}

void Board::buildBoard()
{
    for (size_t index = 0; index < getSize(); ++index)
    {
        Dot* dot = new Dot(index);
        m_dots.push_back(dot);
    }
}
void Board::draw() const
{
    for (size_t i = 0; i < getRowSize(); ++i)
    {
        for (size_t j = 0; j < getColSize(); ++j)
        {
            const size_t index = 0 + (getColSize() * i + j);
            if (m_dots[index]->getAdjacentDotAt(Dot::Position::eRight))
            {
                std::cout << "*--";
            }
            else
            {
                std::cout << "*  ";
            }
        }

        std::cout << std::endl;
        for (size_t j = 0; j < getColSize(); ++j)
        {
            const size_t index = 0 + (getColSize() * i + j);
            if (m_dots[index]->getAdjacentDotAt(Dot::Position::eBottom))
            {
                std::cout << "|  ";
            }
            else
            {
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

DotBase* Board::getDotAt(size_t index) const
{
    if (index <= m_dots.size() - 1)
        return m_dots[index];
    return nullptr;
}


