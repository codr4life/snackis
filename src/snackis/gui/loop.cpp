#include "snackis/gui/loop.hpp"

namespace snackis::gui {
  static gboolean callback(gpointer _fn) {
    auto fn(reinterpret_cast<function<void ()> *>(_fn));
    (*fn)();
    delete fn;
    return false;
  }

  void loop_exec(const function<void ()> &fn) {
    g_main_context_invoke(nullptr, callback, new function<void()>(fn));
  }
}
