#ifndef SNACKIS_LIB_DB_HPP
#define SNACKIS_LIB_DB_HPP

#include "snackis/std.hpp"
#include "snabl/lib.hpp"

namespace snackis::libs {
  struct DB: snabl::Lib {
    DB(snabl::Env &env);
  };
}

#endif
