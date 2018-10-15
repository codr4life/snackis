#include "snabl/env.hpp"
#include "snackis/gui/app.hpp"
#include "snackis/libs/db.hpp"

IMPLEMENT_APP(snackis::gui::App);

namespace snackis::gui { 
  bool App::OnInit() {
    snabl::Env env;
    env.add_lib<libs::DB>();
    env.use(env.sym("s.abc"));
    //env.load("init.sl");

    wxFrame *f(new wxFrame(nullptr, -1, "Snackis"));
    f->Maximize(true);
    f->Show(true);
    SetTopWindow(f);
    return true;
  }
}
