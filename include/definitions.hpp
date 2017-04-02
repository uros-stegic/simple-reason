#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <memory>
#include <set>
#include <vector>

namespace AR {
class BaseFormula;

typedef std::shared_ptr<const BaseFormula> Formula;
typedef std::set<unsigned int> AtomSet;
}

#endif // DEFINITIONS_H

