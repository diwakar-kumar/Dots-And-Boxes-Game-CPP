#pragma once
class BoardBase
{
public:
    BoardBase();
    virtual void buildBoard() = 0;
    virtual void draw() const = 0;

    size_t getRowSize() const;
    size_t getColSize() const;
    size_t getSize() const;

    void   setSize(size_t rowSize, size_t colSize);
    void   setRowSize(size_t rowSize);
    void   setColSize(size_t colSize);
    virtual ~BoardBase();
private:
    size_t m_rowSize;
    size_t m_colSize;
};

