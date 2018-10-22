#include <gtk/gtk.h>
#include <sqlite3.h>

#include <snabl/env.hpp>
#include <snabl/fmt.hpp>

#include "snackis/db/context.hpp"
#include "snackis/error.hpp"
#include "snackis/libs/db.hpp"
#include "snackis/libs/gui.hpp"
#include "snackis/types/db/context.hpp"

using namespace snackis;

snabl::Env env;
bool quit = false;

GtkBox *new_page (GtkNotebook *parent, const char *icon, const char *title) {
  auto f(gtk_box_new(GTK_ORIENTATION_VERTICAL, 0));
  auto l(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5));
  auto i(gtk_image_new_from_file(snabl::fmt("images/%0.png", {icon}).c_str()));
  gtk_container_add(GTK_CONTAINER(l), i);
  gtk_container_add(GTK_CONTAINER(l), gtk_label_new_with_mnemonic(title));
  gtk_notebook_append_page(parent, f, l);
  gtk_widget_show_all(l);
  return GTK_BOX(f);
}

static void init_console(GtkBox *parent) {
  auto c(gtk_text_view_new());
  auto s(gtk_scrolled_window_new(NULL, NULL));
  gtk_text_view_set_editable(GTK_TEXT_VIEW(c), false);
  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(c), GTK_WRAP_WORD);
  gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(s), false);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(s),
                                 GTK_POLICY_NEVER,
                                 GTK_POLICY_ALWAYS);
  gtk_container_add(GTK_CONTAINER(s), c);
  gtk_box_pack_end(parent, s, true, true, 0);
}

static void init_gui() {
  auto w(gtk_window_new(GTK_WINDOW_TOPLEVEL));
  gtk_window_set_icon_from_file(GTK_WINDOW(w), "images/snackis.ico", nullptr);
  gtk_window_set_title(GTK_WINDOW(w), "Snackis v0.1.1");
  gtk_window_maximize(GTK_WINDOW(w));

  auto ps(gtk_notebook_new());
  init_console(new_page(GTK_NOTEBOOK(ps), "console", "_0 Console"));
  new_page(GTK_NOTEBOOK(ps), "in", "_1 In");
  new_page(GTK_NOTEBOOK(ps), "out", "_2 Out");
  new_page(GTK_NOTEBOOK(ps), "peers", "_3 Peers");
  new_page(GTK_NOTEBOOK(ps), "threads", "_4 Threads");
  new_page(GTK_NOTEBOOK(ps), "settings", "_5 Settings");
  gtk_container_add(GTK_CONTAINER(w), ps);
  gtk_widget_show_all(w);
}

static void init_snabl() {
  auto &db_lib(env.add_lib<libs::DB>());
  env.add_lib<libs::GUI>();
  env.use(env.sym("s.abc"));

  sqlite3 *db(nullptr);

  if (sqlite3_open_v2("db.dat", &db,
                      SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE |
                      SQLITE_OPEN_FULLMUTEX | SQLITE_OPEN_SHAREDCACHE,
                      nullptr) != SQLITE_OK) {
    throw Error(snabl::fmt("Error opening db: %0", {sqlite3_errmsg(db)}));
  }

  env.let(env.sym("db"),
          db_lib.context_type,
          db::ContextPtr::make(&db_lib.context_type.pool, db));

  env.load("scripts/init.sl");
  env.jump(snabl::I64(0));
  env.run();
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);
  init_gui();
  init_snabl();
  return 0;
}
