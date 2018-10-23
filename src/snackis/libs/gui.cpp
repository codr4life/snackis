#include <gtk/gtk.h>

#include <snabl/env.hpp>
#include <snabl/ptrs.hpp>

#include "snackis/libs/gui.hpp"

namespace snackis::libs {
  GUI::GUI(snabl::Env &env): snabl::Lib(env, env.sym("gui")) { init(); }

  void GUI::init() {
    add_fimp(env.sym("refresh-console"),
             {},
             [this](snabl::Fimp &fimp) {
               env.push_async([this]() -> optional<snabl::Box> {
                   if (stdout.tellp()) {
                     auto buf(gtk_text_view_get_buffer(GTK_TEXT_VIEW(console)));
                     GtkTextIter start;
                     gtk_text_buffer_get_start_iter(buf, &start);
                     gtk_text_buffer_place_cursor(buf, &start);
                     const auto s(stdout.str());
                     gtk_text_buffer_insert_at_cursor(buf, s.c_str(), s.size());
                     stringstream().swap(stdout);
                   }

                   return nullopt;
                 });
             });

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
