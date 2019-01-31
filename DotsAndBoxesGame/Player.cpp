#include "stdafx.h"
#include "Player.h"


Player::Player(std::string sName):m_name(sName), m_bounty(0)
{
}

std::string Player::name() const
{
    return m_name;
}

size_t Player::playerId() const
{
    return m_uid;
}

void Player::addBounty(int bounty)
{
    m_bounty += bounty;
}

int Player::getBounty() const
{
    return  m_bounty;
}

Player::~Player()
{
}
