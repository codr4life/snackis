#ifndef SNACKIS_TYPE_DB_COLUMN_HPP
#define SNACKIS_TYPE_DB_COLUMN_HPP

#include "snabl/type.hpp"
#include "snackis/db/column.hpp"
#include "snackis/std.hpp"

namespace snackis::db {
  using namespace snackis::db;
  
  struct ColumnType: snabl::PtrType<Column> {
    ColumnType(snabl::Lib &lib, snabl::Sym id);
    void dump(const snabl::Box &val, ostream &out) const override;
  };
}

#endif
