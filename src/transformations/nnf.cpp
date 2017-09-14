#include <nnf.hpp>
#include <simplification.hpp>
#include <equivalence_elimination.hpp>
#include <negation_distribuition.hpp>
#include <initializer_list>

using namespace art;

NNF::NNF()
    : CompositeTransformation{
       std::make_shared<EquivalenceElimination>(),
       std::make_shared<NegationDistribution>(),
       std::make_shared<Simplification>()
    }
{}
