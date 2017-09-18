#ifndef EQUALS_HPP
#define EQUALS_HPP

#include <predicate.hpp>

namespace art {
class Equals : public Predicate{
  public:
    Equals(const Term&, const Term&);
    virtual void print_formula(std::ostream & out) const override;
    FormulaType get_type() const override;

private:
    Term m_t1, m_t2;
};
}


/*Класа Equals наслеђује класу Predicate и
у конструктору прима два терма. Онда
позива конструктор надкласе
(предиката) и при позиву прослеђује
ад-хок направљен вектор
иницијализован са ова два предиката
(иницијализацију радиш init-listom). Поред
овога, конструктору надкласе се
прослеђује и стринг "=" јер је то симбол
ове класе (сама класа Equals га не прима у
конструктору). Поред овога оверајдуј
функцију print_formula да се не би исписивало
"=(x, y)" него направи да се исписује "x = y".*/
#endif //EQUALS_HPP
