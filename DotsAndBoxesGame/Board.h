#pragma once
#include <vector>

#include "BoardBase.h"
#include "Dot.h"

class Board : public BoardBase
{
public:
    Board();
    void buildBoard() override;
    void draw() const override;
    DotBase* getDotAt(size_t index) const;
    virtual ~Board();
private:
    std::vector<DotBase*> m_dots;
};

