#include <wx/notebook.h>

#include "snabl/env.hpp"
#include "snackis/gui/app.hpp"
#include "snackis/libs/db.hpp"

IMPLEMENT_APP(snackis::gui::App);

namespace snackis::gui { 
  bool App::OnInit() {
    snabl::Env env;
    env.add_lib<libs::DB>();
    env.use(env.sym("s.abc"));

    auto f(new wxFrame(nullptr, -1, "Snackis"));
    f->Maximize(true);

    auto p(new wxPanel(f));
    auto ps(new wxNotebook(p, wxID_ANY));
    auto s(new wxBoxSizer(wxVERTICAL));
    p->SetSizer(s);
    s->Add(ps, 1, wxEXPAND);

    ps->AddPage(new wxPanel(ps), "1 Console");
    ps->AddPage(new wxPanel(ps), "2 Peers");
    ps->AddPage(new wxPanel(ps), "3 Threads");
    ps->AddPage(new wxPanel(ps), "4 Settings");
    ps->AddPage(new wxPanel(ps), "5 In");
    ps->AddPage(new wxPanel(ps), "6 Out");

    //env.load("init.sl");
    f->Show(true);
    SetTopWindow(f);
    return true;
  }
}
