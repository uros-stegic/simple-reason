#include <sat.hpp>

#include <fstream>

using namespace AR;

SAT::SAT()
    : m_num_clauses(0)
    , m_name("")
    , m_cnf(std::make_shared<CNF>())
{}
SAT::SAT(const Formula& f)
    : m_num_clauses(0)
    , m_name("")
{
    m_cnf = std::make_shared<CNF>(std::move(CNF::get_cnf(f->cnf())));
    m_vars = f->get_atoms();
    m_num_clauses = m_cnf->size();
}

SAT SAT::from_dimacs(const std::string& filename)
{
    std::ifstream in(filename);
    SAT sat;
    in >> sat;
    return sat;
}

void SAT::to_dimacs(const std::string& filename) const
{
    std::ofstream out(filename);
    out << *this;
}

SAT::operator Formula() const
{
    return static_cast<Formula>(*m_cnf);
}

void SAT::set_name(const std::string& name)
{
    m_name = name;
}

SAT& SAT::operator<<(const Clause& c)
{
    m_cnf->push_back(c);
    m_num_clauses++;
    AtomSet new_set = ((Formula)c)->get_atoms();
    m_vars.insert(new_set.begin(), new_set.end());
    return *this;
}

unsigned int SAT::count_vars() const
{
    return m_vars.size();
}

std::ostream& AR::operator <<(std::ostream& out, const SAT& sat)
{
    if( sat.m_name != "" ) {
        out << "c " << sat.m_name << std::endl;
    }
    out << "p cnf " << sat.m_vars.size() << " " << sat.m_num_clauses << std::endl;
    out << *(sat.m_cnf);
    return out;
}
std::istream& AR::operator >>(std::istream& in, SAT& sat)
{
    char c;
    int _;
    std::string s_tmp;

    in >> c;
    if( c == 'c' ) {
        in >> std::noskipws >> c >> std::skipws;
        std::getline(in, sat.m_name);

        in >> c;
        if( c == 'p' ) {
            in >> s_tmp;
            in >> _;
            in >> sat.m_num_clauses;
        }
    }
    else if( c == 'p' ) {
        in >> s_tmp;
        in >> _;
        in >> sat.m_num_clauses;
    }
    in >> *(sat.m_cnf);

    return in;
}

