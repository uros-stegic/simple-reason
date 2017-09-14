#include <naive_cnf.hpp>
#include <simplification.hpp>
#include <equivalence_elimination.hpp>
#include <negation_distribuition.hpp>
#include <disjunction_distribution.hpp>
#include <initializer_list>


using namespace art;

NaiveCNF::NaiveCNF()
    : CompositeTransformation{
       std::make_shared<EquivalenceElimination>(),
       std::make_shared<NegationDistribution>(),
       std::make_shared<DisjunctionDistribution>(),
       std::make_shared<Simplification>()
    }
{}
