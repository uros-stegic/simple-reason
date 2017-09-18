#include <rename.hpp>
#include <formulae.hpp>
#include <algorithm>

using namespace art;

Rename::Rename(std::string var, std::string to)
    : m_var(var)
    , m_to(to)
{}
Rename::Rename(const Term& t, std::string to)
    : m_var("")
    , m_to(to)
{
	m_var = static_cast<const Var*>(t.get())->name();
}

Formula Rename::transform(const Formula& f) const
{
    switch( f->get_type() ) {
        case CONJUNCTION: {
            const And* th = static_cast<const And*>(f.get());
            Formula left = th->get_left_operand()->transform(*this);
            Formula right = th->get_right_operand()->transform(*this);
            return std::make_shared<And>(left, right);
        }
        case DISJUNCTION: {
            const Or* th = static_cast<const Or*>(f.get());
            Formula left = th->get_left_operand()->transform(*this);
            Formula right = th->get_right_operand()->transform(*this);
            return std::make_shared<Or>(left, right);
        }
        case IMPLICATION: {
            const If* th = static_cast<const If*>(f.get());
            Formula left = th->get_left_operand()->transform(*this);
            Formula right = th->get_right_operand()->transform(*this);
            return std::make_shared<If>(left, right);
        }
        case EQUIVALENCE: {
            const Iff* th = static_cast<const Iff*>(f.get());
            Formula left = th->get_left_operand()->transform(*this);
            Formula right = th->get_right_operand()->transform(*this);
            return std::make_shared<Iff>(left, right);
        }
        case NEGATION: {
            const Not* th = static_cast<const Not*>(f.get());
            Formula op = th->get_operand()->transform(*this);
            return std::make_shared<Not>(op);
        }
        case PREDICATE: {
            const Predicate* th = static_cast<const Predicate*>(f.get());
            std::vector<Term> ts;
            for(auto &&i: th->terms()) {
                ts.push_back(i->transform(*this));
            }
            return std::make_shared<Predicate>(ts, th->name());
        }
        case EQUALS: {
            const Equals* th = static_cast<const Equals*>(f.get());
            std::vector<Term> ts;
            for(auto &&i: th->terms()) {
                ts.push_back(i->transform(*this));
            }
            return std::make_shared<Equals>(ts[0], ts[1]);
        }
        case NOT_EQUALS: {
            const NotEquals* th = static_cast<const NotEquals*>(f.get());
            std::vector<Term> ts;
            for(auto &&i: th->terms()) {
                ts.push_back(i->transform(*this));
            }
            return std::make_shared<NotEquals>(ts[0], ts[1]);
        }
        case FOR_ALL: {
            const ForAll* th = static_cast<const ForAll*>(f.get());
            Term t = th->var()->copy();
            std::string to = m_to;
            if( static_cast<const Var*>(th->var().get())->name() == m_var ) {
                if( to == "" ) {
                    to = BaseFormula::unique();
                }
                std::string next = to;
                t = std::make_shared<Var>(next);
            }
            Formula op = th->get_operand()->transform(Rename(m_var, to));
            return std::make_shared<ForAll>(op, t);
        }
        case EXISTS: {
            const Exists* th = static_cast<const Exists*>(f.get());
            Term t = th->var()->copy();
            std::string to = m_to;
            if( static_cast<const Var*>(th->var().get())->name() == m_var ) {
                if( to == "" ) {
                    to = BaseFormula::unique();
                }
                std::string next = to;
                t = std::make_shared<Var>(next);
            }
            Formula op = th->get_operand()->transform(Rename(m_var, to));
            return std::make_shared<Exists>(op, t);
        }
        default: {
            return f->copy();
        }
    }
}

Term Rename::transform(const Term &t) const
{
    switch( t->get_type() ) {
        case CONSTANT: {
            return t->copy();
        }
        case FUNCTION: {
            const Function* th = static_cast<const Function*>(t.get());
			auto terms = th->terms();
            std::vector<Term> ts;
            std::transform(
                std::begin(terms),
                std::end(terms),
                std::back_inserter(ts),
                [this](const Term& t) {
                    return t->transform(*this);
                }
            );
            return std::make_shared<Function>(th->name(), ts);
        }
        case VARIABLE: {
            const Var* v = static_cast<const Var*>(t.get());
            std::string next = v->name();
            if( v->name() == m_var ) {
                if( m_to == "" ) {
                    next = BaseFormula::unique();
                }
                else {
                    next = m_to;
                }
            }
            return std::make_shared<Var>(next);
        }
    }
}
