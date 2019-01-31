#include "stdafx.h"
#include "Dot.h"

size_t MAX_POSITION_SIZE = 4;

Dot::Dot(size_t id): DotBase(id)
{
    for (size_t i = 0; i < MAX_POSITION_SIZE; ++i)
    {
        m_adjacentDots[i] = nullptr;
    }
}

Dot::~Dot()
{
}

DotBase * Dot::getAdjacentDotAt(const Position& ePos) const
{
    return m_adjacentDots[static_cast<int>(ePos)];
}

void Dot::setAdjacentDotAt(DotBase * pAdjacentDot, const Position& ePos)
{
    size_t iPos = static_cast<int>(ePos);
    if (iPos >= 0 && iPos < MAX_POSITION_SIZE)
    {
        m_adjacentDots[iPos] = pAdjacentDot;
    }
}

bool Dot::isAdjacentOf(DotBase* pAdjacentDot) const
{
    for (auto dots: m_adjacentDots)
    {
        if (dots == pAdjacentDot)
        {
            return true;
        }
    }
    return false;
}

