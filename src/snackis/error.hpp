#ifndef SNACKIS_ERROR_HPP
#define SNACKIS_ERROR_HPP

#include "snackis/std.hpp"

namespace snackis {
  struct Error: runtime_error {
    Error(): runtime_error("") { }
    Error(const string &msg): runtime_error(msg) { }
  };
}

#endif
