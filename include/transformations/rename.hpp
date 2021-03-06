#ifndef RENAME_HPP
#define RENAME_HPP

#include <transformation.hpp>
#include <formula.hpp>
#include <formulae.hpp>

namespace art{

class Rename : public Transformation {
public:
    Rename(std::string, std::string = "");
    Rename(const Term&, std::string = "");
    virtual Formula transform(const Formula&) const override;
    virtual Term transform(const Term&) const override;

private:
    std::string m_var;
    std::string m_to;
};
}

#endif // RENAME_HPP

