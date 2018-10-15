#ifndef SNACKIS_GUI_APP_HPP
#define SNACKIS_GUI_APP_HPP

#include <wx/wx.h>

namespace snackis::gui {
  struct App: wxApp {
    virtual bool OnInit();
  }; 
}

DECLARE_APP(snackis::gui::App)

#endif
