#include <naive_cnf.hpp>
#include <simplification.hpp>
#include <elimination.hpp>
#include <negation_distribuition.hpp>
#include <disjunction_distribution.hpp>
#include <initializer_list>


using namespace art;

NaiveCNF::NaiveCNF()
    : CompositeTransformation{
       std::make_shared<Elimination>(),
       std::make_shared<NegationDistribution>(),
       std::make_shared<DisjunctionDistribution>(),
       std::make_shared<Simplification>()
    }
{}
