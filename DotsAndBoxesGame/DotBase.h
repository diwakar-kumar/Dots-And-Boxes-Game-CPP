#pragma once

class DotBase
{
public:
    enum class Position
    {
        eTop = 0,
        eRight = 1,
        eBottom = 2,
        eLeft = 3
    };

public:

    DotBase(size_t id);
    size_t id() const;
    virtual DotBase* getAdjacentDotAt(const Position& ePos) const = 0;
    virtual void setAdjacentDotAt(DotBase* pAdjacentDot, const Position& ePos) = 0;
    virtual ~DotBase();
private:
    size_t m_uid;
};
