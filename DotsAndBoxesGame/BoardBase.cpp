#include "stdafx.h"
#include "BoardBase.h"

BoardBase::BoardBase(): m_rowSize(0), m_colSize(0)
{
}

BoardBase::~BoardBase()
{
}

size_t BoardBase::getRowSize() const
{
    return m_rowSize;
}

size_t BoardBase::getColSize() const
{
    return m_colSize;
}

size_t BoardBase::getSize() const
{
    return m_rowSize * m_colSize;
}

void BoardBase::setSize(size_t rowSize, size_t colSize)
{
    setRowSize(rowSize);
    setColSize(colSize);
}

void BoardBase::setRowSize(size_t rowSize)
{
    m_rowSize = rowSize;
}

void BoardBase::setColSize(size_t colSize)
{
    m_colSize = colSize;
}
