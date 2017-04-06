#include <nnf.hpp>
#include <simplification.hpp>
#include <elimination.hpp>
#include <negation_distribuition.hpp>
#include <initializer_list>

using namespace AR;

NNF::NNF()
    : CompositeTransformation{
       std::make_shared<Elimination>(),
       std::make_shared<NegationDistribution>(),
       std::make_shared<Simplification>()
    }
{}
