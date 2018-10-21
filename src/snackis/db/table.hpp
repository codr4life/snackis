#ifndef SNACKIS_DB_TABLE_HPP
#define SNACKIS_DB_TABLE_HPP

#include <snabl/ptr.hpp>

#include "snackis/db/column.hpp"
#include "snackis/std.hpp"

namespace snackis::db {
  struct Context;
  
  struct Table: Def {
    vector<ColumnPtr> key;
    vector<ColumnPtr> columns;
    
    Table(snabl::Sym id): Def(id) { }

    void add_key_column(const ColumnPtr &c) {
      key.emplace_back(c);
      add_column(c);
    }
    
    void add_column(const ColumnPtr &c) { columns.emplace_back(c); }
    void create(Context &cx) const;
  };
  
  using TablePtr = snabl::Ptr<Table>;
}

#endif
