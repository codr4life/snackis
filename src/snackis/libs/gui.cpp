#include <gtk/gtk.h>

#include <snabl/env.hpp>
#include <snabl/ptrs.hpp>

#include "snackis/libs/gui.hpp"

namespace snackis::libs {
  GUI::GUI(snabl::Env &env): snabl::Lib(env, env.sym("gui")) { init(); }

  void GUI::init() {
    add_fimp(env.sym("run"),
             {},
             [this](snabl::Fimp &fimp) {
               if (quit) {
                 env.push_async([this]() {
                     return snabl::Box(env.bool_type, false);
                   });
               } else {
                 env.push_async([this]() {
                     gtk_main_iteration();
                     return snabl::Box(env.bool_type, true);
                   });
               }
             });
  }
}
