#ifndef SNACKIS_TYPE_DB_CONTEXT_HPP
#define SNACKIS_TYPE_DB_CONTEXT_HPP

#include "snabl/type.hpp"
#include "snackis/db/context.hpp"
#include "snackis/std.hpp"

namespace snackis::db {
  using namespace snackis::db;
  
  struct ContextType: snabl::PtrType<Context> {
    ContextType(snabl::Lib &lib, snabl::Sym id);
    void dump(const snabl::Box &val, ostream &out) const override;
  };
}

#endif
