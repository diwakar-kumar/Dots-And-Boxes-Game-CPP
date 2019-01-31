#pragma once
class GameBase
{
public:
    virtual void init() = 0;
    virtual void play() = 0;
    virtual ~GameBase() {};
};

