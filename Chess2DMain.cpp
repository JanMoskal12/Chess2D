/***************************************************************
 * Name:      Chess2DMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2024-01-07
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Chess2DMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Chess2DDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Chess2DDialog)
//*)

BEGIN_EVENT_TABLE(Chess2DDialog,wxDialog)
    //(*EventTable(Chess2DDialog)
    //*)
END_EVENT_TABLE()

Chess2DDialog::Chess2DDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Chess2DDialog)
    Create(parent, id, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    //*)
}

Chess2DDialog::~Chess2DDialog()
{
    //(*Destroy(Chess2DDialog)
    //*)
}

void Chess2DDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Chess2DDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
