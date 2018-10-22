#ifndef SNACKIS_LIB_GUI_HPP
#define SNACKIS_LIB_GUI_HPP

#include <snabl/lib.hpp>

#include "snackis/std.hpp"

namespace snackis::libs {  
  struct GUI: snabl::Lib {
    bool quit=false;
    
    GUI(snabl::Env &env);
    void init();
  };
}

#endif
