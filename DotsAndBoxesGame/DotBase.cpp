#include "stdafx.h"
#include "DotBase.h"

DotBase::DotBase(size_t id) : m_uid(id)
{
}

DotBase::~DotBase()
{
}

size_t DotBase::id() const
{
    return m_uid;
}
