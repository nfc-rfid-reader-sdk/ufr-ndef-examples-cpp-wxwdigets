/***************************************************************
 * Name:      ufr_ndef_examples__cpp_wxwidgetsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Digital Logic (support@d-logic.rs)
 * Created:   2019-06-13
 * Copyright: Digital Logic (www.d-logic.net)
 * License:
 **************************************************************/

#include "ufr_ndef_examples__cpp_wxwidgetsApp.h"

//(*AppHeaders
#include "ufr_ndef_examples__cpp_wxwidgetsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ufr_ndef_examples__cpp_wxwidgetsApp);

bool ufr_ndef_examples__cpp_wxwidgetsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ufr_ndef_examples__cpp_wxwidgetsFrame* Frame = new ufr_ndef_examples__cpp_wxwidgetsFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
