#ifndef RENAME_HPP
#define RENAME_HPP

#include <transformation.hpp>
#include <formula.hpp>

namespace art{

class Rename : public Transformation {
public:
    Rename(std::string, std::string = "");
    virtual Formula transform(const Formula&) const override;
    virtual Term transform(const Term&) const override;

private:
    std::string m_var;
    std::string m_to;
};
}

#endif //PRENEX_HPP
