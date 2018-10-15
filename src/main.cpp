#include <gtk/gtk.h>
#include "snabl/env.hpp"
#include "snabl/fmt.hpp"
#include "snackis/libs/db.hpp"

using namespace snackis;

GtkWidget *new_page (GtkNotebook *parent, const char *icon, const char *title) {
  auto f(gtk_box_new(GTK_ORIENTATION_VERTICAL, 0));
  auto l(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5));
  auto i(gtk_image_new_from_file(snabl::fmt("images/%0.png", {icon}).c_str()));
  gtk_container_add(GTK_CONTAINER(l), i);
  gtk_container_add(GTK_CONTAINER(l), gtk_label_new_with_mnemonic(title));
  gtk_notebook_append_page(parent, f, l);
  gtk_widget_show_all(l);
  return f;
}

static void on_activate(GtkApplication *app, gpointer user_data) {
  auto w(gtk_application_window_new(app));
  gtk_window_set_icon_from_file(GTK_WINDOW(w), "images/snackis.ico", nullptr);
  gtk_window_set_title(GTK_WINDOW(w), "Snackis v0.1.1");
  gtk_window_maximize(GTK_WINDOW(w));

  auto ps(gtk_notebook_new());
  new_page(GTK_NOTEBOOK(ps), "console", "_0 Console");
  new_page(GTK_NOTEBOOK(ps), "in", "_1 In");
  new_page(GTK_NOTEBOOK(ps), "out", "_2 Out");
  new_page(GTK_NOTEBOOK(ps), "peers", "_3 Peers");
  new_page(GTK_NOTEBOOK(ps), "threads", "_4 Threads");
  new_page(GTK_NOTEBOOK(ps), "settings", "_5 Settings");
  gtk_container_add(GTK_CONTAINER(w), ps);
  gtk_widget_show_all(w);
  
  snabl::Env env;
  env.add_lib<libs::DB>();
  env.use(env.sym("s.abc"));
  //env.load("scripts/init.sl");
}

int main(int argc, char *argv[]) {
  GtkApplication *app;
  int status;
  app = gtk_application_new("codr4life.snackis", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  return status;
}
