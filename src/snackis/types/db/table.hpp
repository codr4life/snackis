#ifndef SNACKIS_TYPE_DB_TABLE_HPP
#define SNACKIS_TYPE_DB_TABLE_HPP

#include "snabl/type.hpp"
#include "snackis/db/table.hpp"
#include "snackis/std.hpp"

namespace snackis::db {
  using namespace snackis::db;
  
  struct TableType: snabl::PtrType<Table> {
    TableType(snabl::Lib &lib, snabl::Sym id);
    void dump(const snabl::Box &val, ostream &out) const override;
  };
}

#endif
