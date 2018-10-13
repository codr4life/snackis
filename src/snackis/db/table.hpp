#ifndef SNACKIS_DB_TABLE_HPP
#define SNACKIS_DB_TABLE_HPP

#include "snabl/ptr.hpp"
#include "snackis/db/def.hpp"

namespace snackis::db {
  struct Table: public Def {
    Table(snabl::Sym id): Def(id) { }
  };
  
  using TablePtr = snabl::Ptr<Table>;
}

#endif
