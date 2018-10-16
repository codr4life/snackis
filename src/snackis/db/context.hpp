#ifndef SNACKIS_DB_CONTEXT_HPP
#define SNACKIS_DB_CONTEXT_HPP

#include <sqlite3.h>

#include <snabl/ptr.hpp>

#include "snackis/error.hpp"

namespace snackis::db {
  struct Context {
    sqlite3 *imp;

    Context(const Context &)=delete;
    const Context &operator =(const Context &)=delete;
    
    Context(sqlite3 *imp): imp(imp) { }

    void close() {
      if (sqlite3_close_v2(imp) != SQLITE_OK) { throw Error("Error closing db"); }
      imp = nullptr;
    }

    ~Context() { close(); }
  };

  using ContextPtr = snabl::Ptr<Context>;
}

#endif
