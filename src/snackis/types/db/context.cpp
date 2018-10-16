#include <snabl/box.hpp>
#include <snabl/env.hpp>

#include "snackis/types/db/context.hpp"

namespace snackis::db {
  ContextType::ContextType(snabl::Lib &lib, snabl::Sym id):
    snabl::PtrType<Context>(lib, id) { }

  void ContextType::dump(const snabl::Box &val, ostream &out) const {
    out << "(Context " << val.as<ContextPtr>().get() << ')';
  }
}
