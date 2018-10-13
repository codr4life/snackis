#ifndef SNACKIS_DB_DEF_HPP
#define SNACKIS_DB_DEF_HPP

#include "snabl/sym.hpp"

namespace snackis::db {
  struct Def {
    const snabl::Sym id;
    Def(snabl::Sym id): id(id) { }
  };
}

#endif
