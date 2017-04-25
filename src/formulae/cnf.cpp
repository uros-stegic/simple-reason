#include <cnf.hpp>
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <boost/iterator/zip_iterator.hpp>
#include <boost/tuple/tuple.hpp>

using namespace AR;

CNF::CNF()
{}

CNF::CNF(const std::initializer_list<Formula> &clauses)
{
    std::for_each(
        clauses.begin(),
        clauses.end(),
        [](const Formula& clause) {
            if( clause->get_type() != CNF_CLAUSE ) {
                throw new std::runtime_error("Cannot create CNF with non-clause formulas");
            }
        }
    );
    m_clauses = std::set<Formula, FormulaCompare>(clauses.begin(), clauses.end());
}

FormulaType CNF::get_type() const
{
   return CNF_FORM;
}
void CNF::print_formula(std::ostream& out) const
{
    out << "CNF[" << m_clauses.size() << "] ";
    if( m_clauses.size() == 0 ) {
        return;
    }
    else if( m_clauses.size() == 1 ) {
        Formula f = *m_clauses.begin();
        f->print_formula(out);
        return;
    }
    else {
        Formula f = *m_clauses.begin();
        f->print_formula(out);
        std::for_each(
            ++m_clauses.begin(),
            m_clauses.end(),
            [&](const Formula& clause) {
                out << " & ";
                clause->print_formula(out);
            }
        );
    }
}
int CNF::complexity() const
{
    return 0;
}
bool CNF::is_literal() const
{
    return false;
}

bool CNF::operator <(const Formula& f) const
{
    const CNF *cnf = static_cast<const CNF*>(f.get());

    return std::accumulate(
        boost::make_zip_iterator(
            boost::make_tuple(
                m_clauses.begin(),
                cnf->m_clauses.begin()
            )
        ),
        boost::make_zip_iterator(
            boost::make_tuple(
                m_clauses.end(),
                cnf->m_clauses.end()
            )
        ),
        false,
        [&](bool acc, const boost::tuple<const Formula&, const Formula&>& t) {
            return acc || t.get<0>() < t.get<1>();
        }
    );
}

bool CNF::evaluate(const Valuation&) const
{
    return false;
}


Formula CNF::join(const Formula& f) const
{
    if( f->get_type() != CNF_FORM ) {
        throw new std::runtime_error("Cannot join non-CNF (or non-clause) into existing CNF");
    }

    CNF* result = new CNF();
    std::set_union(
        m_clauses.cbegin(), m_clauses.cend(),
        static_cast<const CNF*>(f.get())->m_clauses.cbegin(), static_cast<const CNF*>(f.get())->m_clauses.cend(),
        std::inserter(result->m_clauses, result->m_clauses.begin())
    );
    return std::shared_ptr<CNF>(result);
}

Formula CNF::substitute(const Formula& f, const Formula& g) const
{
    return std::make_shared<CNF>();
}

bool CNF::m_is_equal(const Formula& f) const
{
    if( f->get_type() != CNF_FORM ) {
        return false;
    }
    const CNF *cnf = static_cast<const CNF*>(f.get());
    return cnf->m_clauses == m_clauses;
}
void CNF::m_get_atoms(AtomSet& atoms) const
{
    std::for_each(m_clauses.cbegin(), m_clauses.cend(), [&](const Formula& clause) {
        AtomSet A = clause->get_atoms();
        for(auto &&i: A) {
            atoms.insert(i);
        }
    });
}
