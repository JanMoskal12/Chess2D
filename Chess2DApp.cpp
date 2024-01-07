/***************************************************************
 * Name:      Chess2DApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2024-01-07
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Chess2DApp.h"

//(*AppHeaders
#include "Chess2DMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Chess2DApp);

bool Chess2DApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Chess2DDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
