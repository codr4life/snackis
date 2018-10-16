#include "snabl/box.hpp"
#include "snabl/env.hpp"
#include "snackis/types/db/column.hpp"

namespace snackis::db {
  ColumnType::ColumnType(snabl::Lib &lib, snabl::Sym id):
    snabl::PtrType<Column>(lib, id) { }

  void ColumnType::dump(const snabl::Box &val, ostream &out) const {
    out << "(Column " << val.as<ColumnPtr>()->id << ')';
  }
}
