#include <valuation.hpp>
//#include <definitions.hpp>

#include <iostream>

using namespace AR;

Valuation::Valuation(const AtomSet& atoms)
{
    init(atoms);
}
void Valuation::init(const AtomSet& atoms)
{
    m_valuation.clear();
    for(const auto &atom : atoms) {
        m_valuation.insert(std::make_pair(atom, false));
    }
}

bool Valuation::get_value(unsigned int n) const
{
    auto i = m_valuation.find(n);
    if( i == m_valuation.end() ) {
        throw std::runtime_error("Letter doesn't exist");
    }
    return i->second;
}

void Valuation::set_value(unsigned int n, bool val)
{
    m_valuation[n] = val;
}

void Valuation::print_valuation() const
{
    for(const auto &val : m_valuation) {
        std::cout << val.first << " ";
    }
    std::cout << std::endl;

    for(const auto &val : m_valuation) {
        std::cout << val.second << " ";
    }
    std::cout << std::endl;
}

bool Valuation::next()
{
    auto it = m_valuation.rbegin();
    bool over = true;
    bool finished = true;
    for(;it != m_valuation.rend(); it++) {
        finished = finished && it->second;
        bool next_over = over && it->second;
        it->second = !(over == it->second);
        over = next_over;
    }
    return !finished;
}

