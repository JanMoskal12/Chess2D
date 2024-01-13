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
#include "Square.h"
#include "Board.h"

//(*Headers(Chess2DDialog)
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
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
        void OnBitmapButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(Chess2DDialog)
        static const long ID_BITMAPBUTTON1;
        //*)

        //(*Declarations(Chess2DDialog)
        wxBitmapButton* BitmapButton1;
        //*)

        DECLARE_EVENT_TABLE()
        Board* _insanity;


};

#endif // CHESS2DMAIN_H
