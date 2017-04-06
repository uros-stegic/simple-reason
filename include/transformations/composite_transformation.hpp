#ifndef COMPOSITE_TRANSFORMATION_HPP
#define COMPOSITE_TRANSFORMATION_HPP

#include <transformation.hpp>
#include <vector>
#include <initializer_list>
#include <memory>
#include <formula.hpp>

namespace AR {
class CompositeTransformation : public Transformation {
public:
    CompositeTransformation(std::initializer_list<std::shared_ptr<Transformation>>);

    virtual Formula transform(const Formula &) const override;

protected:
    std::vector<std::shared_ptr<Transformation>> m_transformations;
};
}

#endif // COMPOSITE_TRANSFORMATION
