#ifndef SNACKIS_LIB_DB_HPP
#define SNACKIS_LIB_DB_HPP

#include <snabl/lib.hpp>

#include "snackis/std.hpp"

namespace snackis::db {
  struct ContextType;
  struct TableType;
  struct ColumnType;
}

namespace snackis::libs {  
  struct DB: snabl::Lib {
    db::ContextType &context_type;
    db::TableType &table_type;
    db::ColumnType &column_type;
    
    DB(snabl::Env &env);
    void init();
  };
}

#endif
