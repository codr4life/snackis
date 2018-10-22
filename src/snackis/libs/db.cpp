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
    init();
  }

  void DB::init() {
    add_fimp(env.sym("new-table"),
             {snabl::Box(env.sym_type), snabl::Box(env.seq_type),
                 snabl::Box(env.seq_type)},
             [this](snabl::Fimp &fimp) {
               const auto &cols(env.pop().iter());
               const auto &key(env.pop().iter());
               const auto id(env.pop().as_sym);
               auto t(TablePtr::make(&table_type.pool, id));               
               optional<snabl::Box> c;
               while ((c = key->call())) { t->add_key_column(c->as<ColumnPtr>()); }
               while ((c = cols->call())) { t->add_column(c->as<ColumnPtr>()); }
               env.push(table_type, t);
             });

    add_fimp(env.sym("new-bin-column"),
             {snabl::Box(env.sym_type)},
             [this](snabl::Fimp &fimp) {
               const auto id(env.pop().as_sym);
               env.push(column_type,
                        ColumnPtr::make(&column_type.pool, Bin::type, id));
             });

    add_fimp(env.sym("new-i64-column"),
             {snabl::Box(env.sym_type)},
             [this](snabl::Fimp &fimp) {
               const auto id(env.pop().as_sym);
               env.push(column_type,
                        ColumnPtr::make(&column_type.pool, I64::type, id));
             });

    add_fimp(env.sym("new-str-column"),
             {snabl::Box(env.sym_type)},
             [this](snabl::Fimp &fimp) {
               const auto id(env.pop().as_sym);
               env.push(column_type,
                        ColumnPtr::make(&column_type.pool, Str::type, id));
             });

    add_fimp(env.sym("create"),
             {snabl::Box(context_type), snabl::Box(table_type)},
             [this](snabl::Fimp &fimp) {
               auto t(env.pop().as<TablePtr>());
               auto db(env.pop().as<ContextPtr>());
               
               auto out(async(env, [t, db]() {
                     t->create(*db);
                     return nullopt;
                   }));

               if (out) { env.push(*out); }
             });
  }
}
