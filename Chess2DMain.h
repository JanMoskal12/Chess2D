/***************************************************************
 * Name:      Chess2DMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2024-01-07
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef CHESS2DMAIN_H
#define CHESS2DMAIN_H

//(*Headers(Chess2DDialog)
#include <wx/dialog.h>
//*)

class Chess2DDialog: public wxDialog
{
    public:

        Chess2DDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~Chess2DDialog();

    private:

        //(*Handlers(Chess2DDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(Chess2DDialog)
        //*)

        //(*Declarations(Chess2DDialog)
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // CHESS2DMAIN_H
