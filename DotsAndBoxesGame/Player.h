#pragma once
class Player
{
public:
    Player(std::string sName);
    std::string name() const;
    size_t playerId() const;
    void addBounty(int bounty);
    int getBounty() const;
    virtual ~Player();
private:
    std::string m_name;
    size_t m_uid;
    int m_bounty;
};

