#include <prenex.hpp>
#include <simplification.hpp>
#include <equivalence_elimination.hpp>
#include <negation_distribuition.hpp>
#include <disjunction_distribution.hpp>
#include <quantifier_extraction.hpp>
#include <initializer_list>

using namespace art;

Prenex::Prenex()
    : CompositeTransformation{
       std::make_shared<EquivalenceElimination>(),
       std::make_shared<NegationDistribution>(),
       std::make_shared<DisjunctionDistribution>(),
       std::make_shared<Simplification>(),
	   std::make_shared<QuantifierExtraction>()
    }
{}

