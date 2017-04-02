#include <letter.hpp>
#include <true_constant.hpp>
#include <false_constant.hpp>
#include <negation.hpp>
#include <conjunction.hpp>
#include <disjunction.hpp>
#include <implication.hpp>
#include <equivalence.hpp>

using namespace AR;

FormulaType Not::get_type() const
{
    return NEGATION;
}

void Not::m_print_formula(std::ostream& out) const
{
    out << "~";
}

bool Not::evaluate(const Valuation& val) const
{
    return !get_operand()->evaluate(val);
}

Formula Not::substitute(const Formula& from, const Formula& to) const
{
    if( get_type() != from->get_type() || !equals(from) ) {
        return std::make_shared<Not>(get_operand()->substitute(from, to));
    }
    return to;
}

Formula Not::simplify() const
{
    Formula tmp = get_operand()->simplify();
    
    if( tmp->get_type() == PROP_FALSE ) {
        return std::make_shared<True>();
    }
    else if( tmp->get_type() == PROP_TRUE ) {
        return std::make_shared<False>();
    }

    return std::make_shared<Not>(tmp);
}

Formula Not::m_nnf() const
{
    switch( get_operand()->get_type() ) {
        case NEGATION: {
            Not *n = (Not*)(get_operand().get());
            return n->get_operand()->nnf();
        }
        case CONJUNCTION: {
            And *con = (And*)(get_operand().get());
            return std::make_shared<Or>(
                std::make_shared<Not>(con->get_left_operand())->nnf(),
                std::make_shared<Not>(con->get_right_operand())->nnf()
            );
        }
        case DISJUNCTION: {
            Or *dis = (Or*)(get_operand().get());
            return std::make_shared<And>(
                std::make_shared<Not>(dis->get_left_operand())->nnf(),
                std::make_shared<Not>(dis->get_right_operand())->nnf()
            );
        }
        case IMPLICATION: {
            If *imp = (If*)(get_operand().get());
            return std::make_shared<And>(
                (imp->get_left_operand())->nnf(),
                std::make_shared<Not>(imp->get_right_operand())->nnf()
            );
        }
        case EQUIVALENCE: {
            Iff *iff = (Iff*)(get_operand().get());
            return std::make_shared<And>(
                std::make_shared<Or>(
                    iff->get_left_operand()->nnf(),
                    iff->get_right_operand()->nnf()
                ),
                std::make_shared<Or>(
                    std::make_shared<Not>(iff->get_left_operand())->nnf(),
                    std::make_shared<Not>(iff->get_right_operand())->nnf()
                )
            );
        }
        default: return shared_from_this();
    }
}

