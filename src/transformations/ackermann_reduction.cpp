#include <ackermann_reduction.hpp>
#include <nnf.hpp>
#include <ackermann_step.hpp>
#include <initializer_list>

using namespace art;

AckermannReduction::AckermannReduction()
    : CompositeTransformation{
       std::make_shared<NNF>(),
       std::make_shared<AckermannStep>()
    }
{}
