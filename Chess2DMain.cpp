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
#include <wx/log.h>
#include "Board.h"


//(*InternalHeaders(Chess2DDialog)
#include <wx/bitmap.h>
#include <wx/image.h>
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

wxBitmapButton* board[64];
wxBitmap images[26];

//(*IdInit(Chess2DDialog)
const long Chess2DDialog::ID_BITMAPBUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Chess2DDialog,wxDialog)
    //(*EventTable(Chess2DDialog)
    //*)
END_EVENT_TABLE()

Chess2DDialog::Chess2DDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Chess2DDialog)
    wxFlexGridSizer* FlexGridSizer1;
    wxGridSizer* GridSizer1;

    Create(parent, id, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    GridSizer1 = new wxGridSizer(8, 8, -4, -4);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("images\\Pieces\\brB.png"))), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    GridSizer1->Add(BitmapButton1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer1->Add(GridSizer1, 1, wxALL|wxEXPAND, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Chess2DDialog::OnBitmapButton1Click);
    //*)

    images[0] = wxBitmap(wxImage("images/B.jpg"));
    images[1] = wxBitmap(wxImage("images/D.jpg"));
    images[2] = wxBitmap(wxImage(_("images/Pieces/brB.png")));
    images[3] = wxBitmap(wxImage(_("images/Pieces/brD.png")));
    images[4] = wxBitmap(wxImage(_("images/Pieces/bnB.png")));
    images[5] = wxBitmap(wxImage(_("images/Pieces/bnD.png")));
    images[6] = wxBitmap(wxImage(_("images/Pieces/bbB.png")));
    images[7] = wxBitmap(wxImage(_("images/Pieces/bbD.png")));
    images[8] = wxBitmap(wxImage(_("images/Pieces/bqB.png")));
    images[9] = wxBitmap(wxImage(_("images/Pieces/bqD.png")));
    images[10] = wxBitmap(wxImage(_("images/Pieces/bkB.png")));
    images[11] = wxBitmap(wxImage(_("images/Pieces/bkD.png")));
    images[12] = wxBitmap(wxImage(_("images/Pieces/bpB.png")));
    images[13] = wxBitmap(wxImage(_("images/Pieces/bpD.png")));
    images[14] = wxBitmap(wxImage(_("images/Pieces/wrB.png")));
    images[15] = wxBitmap(wxImage(_("images/Pieces/wrD.png")));
    images[16] = wxBitmap(wxImage(_("images/Pieces/wnB.png")));
    images[17] = wxBitmap(wxImage(_("images/Pieces/wnD.png")));
    images[18] = wxBitmap(wxImage(_("images/Pieces/wbB.png")));
    images[19] = wxBitmap(wxImage(_("images/Pieces/wbD.png")));
    images[20] = wxBitmap(wxImage(_("images/Pieces/wqB.png")));
    images[21] = wxBitmap(wxImage(_("images/Pieces/wqD.png")));
    images[22] = wxBitmap(wxImage(_("images/Pieces/wkB.png")));
    images[23] = wxBitmap(wxImage(_("images/Pieces/wkD.png")));
    images[24] = wxBitmap(wxImage(_("images/Pieces/wpB.png")));
    images[25] = wxBitmap(wxImage(_("images/Pieces/wpD.png")));

    //---------------------------------------------------------------------------------------------------------------------------------------
    board[0] = BitmapButton1;
    board[1] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/bnD.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[2] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/bbB.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[3] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/bqD.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[4] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/bkB.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[5] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/bbD.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[6] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/bnB.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[7] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/brD.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);


    for(int j = 0; j < 8; j++){
            if((j)%2 == 0){
                board[8+j] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/bpD.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
            }else{
                board[8+j] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/bpB.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);

            }
    }


    for(int i = 2; i < 6; i++){
        for(int j = 0; j < 8; j++){
            if((i+j)%2 == 0){
                board[8*i+j] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/B.jpg"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
            }else{
                board[8*i+j] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/D.jpg"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
            }
        }
    }


    for(int j = 0; j < 8; j++){
        if((j)%2 != 0){
            board[48+j] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/wpD.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
        }else{
            board[48+j] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/wpB.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);

        }
    }

    board[56] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/wrD.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[57] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/wnB.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[58] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/wbD.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[59] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/wqB.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[60] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/wkD.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[61] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/wbB.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[62] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/wnD.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[63] = new wxBitmapButton(this, wxNewId(), wxBitmap(wxImage(_T("images/Pieces/wrB.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);

    for(int i = 0;i < 8; i++){
        for(int j = 0; j < 8; j++){
        if(i + j == 0){
            j++;
        }
        GridSizer1->Add(board[8*i+j], 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
        Connect(board[8*i+j]->GetId(),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Chess2DDialog::OnBitmapButton1Click);


        }
    }

    Board _board;
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

void Chess2DDialog::OnBitmapButton1Click(wxCommandEvent& event)
{
}
