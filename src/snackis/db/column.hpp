#ifndef SNACKIS_DB_COLUMN_HPP
#define SNACKIS_DB_COLUMN_HPP

#include <snabl/ptr.hpp>

#include "snackis/db/def.hpp"

namespace snackis::db {  
  struct Type { };

  struct Bin: Type {
    static const Bin type;
  };
  
  struct I64: Type {
    static const I64 type;
  };
      
  struct Str: Type {
    static const Str type;
  };
  
  struct Column: Def {
    const Type &type;
    Column(const Type &type, snabl::Sym id): Def(id), type(type) { }
  };

  using ColumnPtr = snabl::Ptr<Column>;
}

#endif
