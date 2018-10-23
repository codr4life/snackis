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
                 env.push(*async(env, [this]() {
                       return snabl::Box(env.bool_type, false);
                     }));
               } else {
                 env.push(*async(env, [this]() {
                       if (gtk_events_pending()) { gtk_main_iteration(); }
                       return snabl::Box(env.bool_type, true);
                     }));
               }
             });
  }
}
