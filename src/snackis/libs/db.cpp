#include <snabl/env.hpp>
#include <snabl/ptrs.hpp>

#include "snackis/db/table.hpp"
#include "snackis/libs/db.hpp"
#include "snackis/types/db/context.hpp"
#include "snackis/types/db/column.hpp"
#include "snackis/types/db/table.hpp"

namespace snackis::libs {
  using namespace snackis::db;

  DB::DB(snabl::Env &env):
    snabl::Lib(env, env.sym("db")),
    context_type(add_type<db::ContextType>(env.sym("Context"), {&env.root_type})),
    table_type(add_type<db::TableType>(env.sym("Table"), {&env.root_type})), 
    column_type(add_type<db::ColumnType>(env.sym("Column"), {&env.root_type})) {
    add_fimp(env.sym("new-table"),
             {snabl::Box(env.sym_type)},
             [this, &env](snabl::Fimp &fimp) {
               const auto id(env.pop().as_sym);
               env.push(table_type, TablePtr::make(&table_type.pool, id));
             });
  }
}
