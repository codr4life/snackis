#ifndef SNACKIS_DB_COLUMN_HPP
#define SNACKIS_DB_COLUMN_HPP

#include "snabl/ptr.hpp"
#include "snackis/db/def.hpp"

namespace snackis::db {
  
  struct Column: Def {
    Column(snabl::Sym id): Def(id) { }
  };
  
  using ColumnPtr = snabl::Ptr<Column>;
}

#endif
