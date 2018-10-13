#ifndef SNACKIS_LIB_DB_HPP
#define SNACKIS_LIB_DB_HPP

#include "snackis/std.hpp"
#include "snabl/lib.hpp"

namespace snackis::libs {
  struct DB: public snabl::Lib {
  public:
    DB(snabl::Env &env, const string &parent_qid);
  };
}

#endif
