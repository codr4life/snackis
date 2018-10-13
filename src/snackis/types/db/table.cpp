#include "snabl/box.hpp"
#include "snabl/env.hpp"
#include "snackis/types/db/table.hpp"

namespace snackis::db {
  TableType::TableType(snabl::Lib &lib, snabl::Sym id):
    snabl::PtrType<Table>(lib, id) { }

  void TableType::dump(const snabl::Box &val, ostream &out) const {
    out << "(Table " << val.as<TablePtr>()->id << ')';
  }
}
