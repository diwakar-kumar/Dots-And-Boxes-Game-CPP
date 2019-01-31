#pragma once
#include "DotBase.h"

class Dot : public DotBase
{
public:
    Dot(size_t id);
    DotBase* getAdjacentDotAt(const Position& ePos) const override;
    void setAdjacentDotAt(DotBase* pAdjacentDot,const Position& ePos) override;
    bool isAdjacentOf(DotBase* pAdjacentDot) const;
    virtual ~Dot();
private:
    DotBase *m_adjacentDots[4];
};

