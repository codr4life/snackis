#include "snabl/env.hpp"
#include "snabl/ptrs.hpp"

#include "snackis/db/table.hpp"
#include "snackis/libs/db.hpp"
#include "snackis/types/db/table.hpp"

namespace snackis::libs {
  using namespace snackis::db;

  DB::DB(snabl::Env &env): snabl::Lib(env, env.sym("db")) {
    auto &table_type(add_type<TableType>(env.sym("Table"), {&env.root_type}));

    add_fimp(env.sym("new-table"),
             {snabl::Box(env.sym_type)},
             [&env, &table_type](snabl::Fimp &fimp) {
               const auto id(env.pop().as_sym);
               env.push(table_type, TablePtr::make(&table_type.pool, id));
             });
  }
}
