#include <composite_transformation.hpp>
#include <numeric>

using namespace art;

CompositeTransformation::CompositeTransformation(std::initializer_list<std::shared_ptr<Transformation>> list)
    : m_transformations(list)
{}

Formula CompositeTransformation::transform(const Formula &f) const
{
    return std::accumulate(
        std::begin(m_transformations),
        std::end(m_transformations),
        f,
        [](Formula acc, std::shared_ptr<Transformation> t) {
            return acc->transform(*t);
        }
    );
}
