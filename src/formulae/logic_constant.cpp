#include <logic_constant.hpp>

using namespace art;

bool LogicConstant::operator <(const Formula&) const
{
    return true;
}
bool LogicConstant::m_is_equal(const Formula &f) const
{
    return true;
}

