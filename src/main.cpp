#include <gtk/gtk.h>
#include "snabl/env.hpp"
#include "snabl/fmt.hpp"
#include "snackis/libs/db.hpp"

using namespace snackis;

static gboolean on_key(gpointer _, GdkEventKey *ev, gpointer __) {
  cout << stderr << ev->keyval << endl;
  //gtk_widget_grab_focus();
  return false;
}

GtkWidget *new_page (GtkNotebook *parent, const char *title) {
  auto f(gtk_box_new(GTK_ORIENTATION_VERTICAL, 0));
  gtk_notebook_append_page(parent, f, gtk_label_new(title));
  return f;
}

static void on_activate(GtkApplication *app, gpointer user_data) {
  auto w(gtk_application_window_new(app));
  gtk_window_set_icon_from_file(GTK_WINDOW(w), "snackis.ico", nullptr);
  g_signal_connect(G_OBJECT(w), "key_press_event", G_CALLBACK(on_key), nullptr);
  gtk_window_set_title(GTK_WINDOW(w), "Snackis v0.1.1");
  gtk_window_maximize(GTK_WINDOW(w));

  auto ps(gtk_notebook_new());
  new_page(GTK_NOTEBOOK(ps), "0 Console");
  new_page(GTK_NOTEBOOK(ps), "1 In");
  new_page(GTK_NOTEBOOK(ps), "2 Out");
  new_page(GTK_NOTEBOOK(ps), "4 Peers");
  new_page(GTK_NOTEBOOK(ps), "5 Threads");
  new_page(GTK_NOTEBOOK(ps), "6 Settings");
  gtk_container_add(GTK_CONTAINER(w), ps);
  gtk_widget_show_all(w);
  
  snabl::Env env;
  env.add_lib<libs::DB>();
  env.use(env.sym("s.abc"));
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
