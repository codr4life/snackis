#ifndef SNACKIS_GUI_LOOP_HPP
#define SNACKIS_GUI_LOOP_HPP

#include <gtk/gtk.h>

#include "snackis/std.hpp"

namespace snackis::gui {
  void loop_exec(const function<void ()> &fn);
}

#endif
