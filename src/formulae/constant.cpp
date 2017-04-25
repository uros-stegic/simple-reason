#include <constant.hpp>

using namespace AR;

bool Constant::operator <(const Formula&) const
{
    return true;
}
bool Constant::m_is_equal(const Formula &f) const
{
    return true;
}

