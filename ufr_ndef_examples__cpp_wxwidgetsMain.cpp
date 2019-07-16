/***************************************************************
 * Name:      ufr_ndef_examples__cpp_wxwidgetsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Digital Logic (support@d-logic.rs)
 * Created:   2019-06-13
 * Copyright: Digital Logic (www.d-logic.net)
 * License:
 **************************************************************/

#include "ufr_ndef_examples__cpp_wxwidgetsMain.h"
#include <wx/msgdlg.h>
#include "lib/include/uFCoder.h"

std::string mPayload = "";
std::string URI_IDENTIFIER_CODE_TAG_OPEN = "<#";
std::string URI_IDENTIFIER_CODE_TAG_CLOSE = ">";
int URI_IDENTIFIER_CODE_TAG_LEN = URI_IDENTIFIER_CODE_TAG_OPEN.length() + URI_IDENTIFIER_CODE_TAG_CLOSE.length();
int mirror_pos = 0;


//(*InternalHeaders(ufr_ndef_examples__cpp_wxwidgetsFrame)
#include <wx/settings.h>
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

//(*IdInit(ufr_ndef_examples__cpp_wxwidgetsFrame)
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON1 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON2 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_PANEL1 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICBOX1 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_CHECKBOX1 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT1 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL1 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT2 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL2 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT3 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL3 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT4 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL4 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL5 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON3 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_GRID1 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_PANEL2 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT12 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL11 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON13 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON14 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_PANEL5 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT13 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL12 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT14 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT15 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT16 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL13 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON15 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON16 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_PANEL6 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT17 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_COMBOBOX1 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT18 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL14 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_CHECKBOX3 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_CHECKBOX4 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT19 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL15 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT20 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL16 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON17 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON18 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_PANEL7 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT21 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL17 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT22 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL18 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL19 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL20 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL21 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL22 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL23 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL24 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL25 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL26 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL27 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL28 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT23 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT24 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT25 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT26 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT27 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT28 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT29 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT30 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT31 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT32 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON19 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON20 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_PANEL8 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICBOX5 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT33 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL29 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON21 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON22 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_PANEL9 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_NOTEBOOK2 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICBOX2 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT8 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL9 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON23 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_PANEL3 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON4 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON5 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON6 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON7 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICBOX3 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT9 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT10 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL10 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON8 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON9 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICBOX4 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT11 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON10 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON11 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_BUTTON12 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_PANEL4 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_NOTEBOOK1 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL6 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT5 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL7 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT6 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL8 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATICTEXT7 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL30 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL31 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL32 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL33 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL34 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL35 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL36 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_TEXTCTRL37 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_PANEL10 = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::idMenuQuit = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::idMenuAbout = wxNewId();
const long ufr_ndef_examples__cpp_wxwidgetsFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ufr_ndef_examples__cpp_wxwidgetsFrame,wxFrame)
    //(*EventTable(ufr_ndef_examples__cpp_wxwidgetsFrame)
    //*)
END_EVENT_TABLE()

ufr_ndef_examples__cpp_wxwidgetsFrame::ufr_ndef_examples__cpp_wxwidgetsFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ufr_ndef_examples__cpp_wxwidgetsFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, _T("wxID_ANY"));
    SetClientSize(wxSize(550,745));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    panelReaderOpen = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(552,45), wxNO_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panelReaderOpen->SetBackgroundColour(wxColour(255,0,0));
    btnReaderOpen = new wxButton(panelReaderOpen, ID_BUTTON1, _("Reader Open"), wxPoint(50,8), wxSize(170,34), wxRAISED_BORDER, wxDefaultValidator, _T("ID_BUTTON1"));
    btnReaderOpen->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));
    btnReaderClose = new wxButton(panelReaderOpen, ID_BUTTON2, _("Reader Close"), wxPoint(320,8), wxSize(170,34), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    btnReaderClose->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Advanced options"), wxPoint(0,46), wxSize(552,90), wxNO_BORDER, _T("ID_STATICBOX1"));
    checkAdvanced = new wxCheckBox(this, ID_CHECKBOX1, _("Use Advanced options"), wxPoint(8,72), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    checkAdvanced->SetValue(false);
    labelReaderTypeEx = new wxStaticText(this, ID_STATICTEXT1, _("Reader type:"), wxPoint(8,104), wxSize(70,15), 0, _T("ID_STATICTEXT1"));
    labelReaderTypeEx->Disable();
    txtReaderTypeEx = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(80,100), wxSize(30,20), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    txtReaderTypeEx->Disable();
    labelPortName = new wxStaticText(this, ID_STATICTEXT2, _("Port name:"), wxPoint(120,104), wxSize(63,15), 0, _T("ID_STATICTEXT2"));
    labelPortName->Disable();
    txtPortName = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(188,100), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    txtPortName->Disable();
    labelPortInterface = new wxStaticText(this, ID_STATICTEXT3, _("Port interface:"), wxPoint(302,104), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    labelPortInterface->Disable();
    txtPortInterface = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(380,100), wxSize(30,20), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    txtPortInterface->Disable();
    labelOpenArg = new wxStaticText(this, ID_STATICTEXT4, _("Arg:"), wxPoint(416,104), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    labelOpenArg->Disable();
    txtOpenArg = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(445,100), wxSize(83,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    txtOpenArg->Disable();
    ndefOptions = new wxNotebook(this, ID_NOTEBOOK1, wxPoint(0,136), wxSize(550,480), 0, _T("ID_NOTEBOOK1"));
    panelReadNFCData = new wxPanel(ndefOptions, ID_PANEL2, wxPoint(167,92), wxSize(542,441), wxNO_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    txtReadPayload = new wxTextCtrl(panelReadNFCData, ID_TEXTCTRL5, _("Payload:"), wxPoint(8,344), wxSize(544,112), wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    btnReadCard = new wxButton(panelReadNFCData, ID_BUTTON3, _("Read Card"), wxPoint(8,8), wxSize(530,45), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    gridReadNdef = new wxGrid(panelReadNFCData, ID_GRID1, wxPoint(8,55), wxSize(536,288), wxSIMPLE_BORDER, _T("ID_GRID1"));
    gridReadNdef->CreateGrid(15,3);
    gridReadNdef->SetFocus();
    gridReadNdef->EnableEditing(true);
    gridReadNdef->EnableGridLines(true);
    gridReadNdef->SetColLabelValue(0, _("Type"));
    gridReadNdef->SetColLabelValue(1, _("Length"));
    gridReadNdef->SetColLabelValue(2, _("Payload"));
    gridReadNdef->SetDefaultCellFont( gridReadNdef->GetFont() );
    gridReadNdef->SetDefaultCellTextColour( gridReadNdef->GetForegroundColour() );
    panelWriteNFCData = new wxPanel(ndefOptions, ID_PANEL3, wxPoint(77,13), wxSize(542,435), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Notebook2 = new wxNotebook(panelWriteNFCData, ID_NOTEBOOK2, wxPoint(0,0), wxSize(552,352), 0, _T("ID_NOTEBOOK2"));
    panelWritePhone = new wxPanel(Notebook2, ID_PANEL5, wxPoint(147,132), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    StaticText12 = new wxStaticText(panelWritePhone, ID_STATICTEXT12, _("Phone number:"), wxPoint(8,24), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    txtWritePhoneNr = new wxTextCtrl(panelWritePhone, ID_TEXTCTRL11, wxEmptyString, wxPoint(8,48), wxSize(504,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    btnWritePhoneNr = new wxButton(panelWritePhone, ID_BUTTON13, _("Write Phone"), wxPoint(8,96), wxSize(504,60), 0, wxDefaultValidator, _T("ID_BUTTON13"));
    btnStorePhoneNr = new wxButton(panelWritePhone, ID_BUTTON14, _("Store phone number for tag emulation mode\n(miin. v.38.0 firmware and library needed)"), wxPoint(8,176), wxSize(504,60), 0, wxDefaultValidator, _T("ID_BUTTON14"));
    panelWriteSMS = new wxPanel(Notebook2, ID_PANEL6, wxPoint(125,16), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    StaticText13 = new wxStaticText(panelWriteSMS, ID_STATICTEXT13, _("Message text (max. 160 chars)"), wxPoint(8,8), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    txtSMSBody = new wxTextCtrl(panelWriteSMS, ID_TEXTCTRL12, wxEmptyString, wxPoint(8,28), wxSize(216,140), wxTE_MULTILINE|wxSUNKEN_BORDER|wxVSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    txtSMSBody->SetMaxLength(160);
    labelSMSCharNr = new wxStaticText(panelWriteSMS, ID_STATICTEXT14, _("Chars:"), wxPoint(160,176), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    labelSMSCharCount = new wxStaticText(panelWriteSMS, ID_STATICTEXT15, _("0"), wxPoint(200,176), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    StaticText16 = new wxStaticText(panelWriteSMS, ID_STATICTEXT16, _("Phone No."), wxPoint(8,200), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    txtSMSNr = new wxTextCtrl(panelWriteSMS, ID_TEXTCTRL13, wxEmptyString, wxPoint(8,220), wxSize(224,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    btnWriteSMS = new wxButton(panelWriteSMS, ID_BUTTON15, _("Write SMS"), wxPoint(240,24), wxSize(120,212), 0, wxDefaultValidator, _T("ID_BUTTON15"));
    btnStoreSMS = new wxButton(panelWriteSMS, ID_BUTTON16, _("Store SMS for tag emulation mode \n(miin. v.38.0 firmware and library needed)"), wxPoint(8,256), wxSize(352,50), 0, wxDefaultValidator, _T("ID_BUTTON16"));
    panelWriteURI = new wxPanel(Notebook2, ID_PANEL7, wxPoint(141,4), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    StaticText17 = new wxStaticText(panelWriteURI, ID_STATICTEXT17, _("URI Identifier Code:"), wxPoint(64,16), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    cmbUriId = new wxComboBox(panelWriteURI, ID_COMBOBOX1, wxEmptyString, wxPoint(168,13), wxSize(256,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    cmbUriId->Append(_("N/A. No prepending is done."));
    cmbUriId->SetSelection( cmbUriId->Append(_("http://www.")) );
    cmbUriId->Append(_("https://www."));
    cmbUriId->Append(_("http://"));
    cmbUriId->Append(_("https://"));
    cmbUriId->Append(_("tel:"));
    cmbUriId->Append(_("mailto:"));
    cmbUriId->Append(_("ftp://anonymous:anonymous@"));
    cmbUriId->Append(_("ftp://ftp."));
    cmbUriId->Append(_("ftps://"));
    cmbUriId->Append(_("sftp://"));
    cmbUriId->Append(_("smb://"));
    cmbUriId->Append(_("nfs://"));
    cmbUriId->Append(_("ftp://"));
    cmbUriId->Append(_("dav://"));
    cmbUriId->Append(_("news:"));
    cmbUriId->Append(_("telnet://"));
    cmbUriId->Append(_("imap:"));
    cmbUriId->Append(_("rtsp://"));
    cmbUriId->Append(_("urn:"));
    cmbUriId->Append(_("pop:"));
    cmbUriId->Append(_("sip:"));
    cmbUriId->Append(_("sips:"));
    cmbUriId->Append(_("tftp:"));
    cmbUriId->Append(_("btspp://"));
    cmbUriId->Append(_("btl2cap://"));
    cmbUriId->Append(_("btgoep://"));
    cmbUriId->Append(_("tcpobex://"));
    cmbUriId->Append(_("irdaobex://"));
    cmbUriId->Append(_("file://"));
    cmbUriId->Append(_("urn:epc:id:"));
    cmbUriId->Append(_("urn:epc:tag:"));
    cmbUriId->Append(_("urn:epc:pat:"));
    cmbUriId->Append(_("urn:epc:raw:"));
    cmbUriId->Append(_("urn:epc:"));
    cmbUriId->Append(_("urn:nfc:"));
    StaticText18 = new wxStaticText(panelWriteURI, ID_STATICTEXT18, _("URI field:"), wxPoint(64,64), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    txtUri = new wxTextCtrl(panelWriteURI, ID_TEXTCTRL14, wxEmptyString, wxPoint(64,80), wxSize(360,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    checkUidAsciiMirror = new wxCheckBox(panelWriteURI, ID_CHECKBOX3, _("Enable UID ASCII Mirror (NTAG21x only)"), wxPoint(64,120), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    checkUidAsciiMirror->SetValue(false);
    checkNFCCounter = new wxCheckBox(panelWriteURI, ID_CHECKBOX4, _("Enable NFC Counter ASCII Mirror (NTAG213/215/216 only)"), wxPoint(64,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    checkNFCCounter->SetValue(false);
    lblAsciiPrefix = new wxStaticText(panelWriteURI, ID_STATICTEXT19, _("ASCII Prefix (delimiter and parameter name):"), wxPoint(64,176), wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    lblAsciiPrefix->Disable();
    txtASCIIPrefix = new wxTextCtrl(panelWriteURI, ID_TEXTCTRL15, _("\?m="), wxPoint(64,200), wxSize(264,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    txtASCIIPrefix->Disable();
    StaticText20 = new wxStaticText(panelWriteURI, ID_STATICTEXT20, _("Result payload:"), wxPoint(8,225), wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    txtResultPayload = new wxTextCtrl(panelWriteURI, ID_TEXTCTRL16, wxEmptyString, wxPoint(8,248), wxSize(264,72), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    btnWriteURI = new wxButton(panelWriteURI, ID_BUTTON17, _("Write URI"), wxPoint(280,230), wxSize(248,40), 0, wxDefaultValidator, _T("ID_BUTTON17"));
    btnStoreURI = new wxButton(panelWriteURI, ID_BUTTON18, _("Store URL for tag emulation mode\n(min. v3.8.0 firmware and library needed)"), wxPoint(280,280), wxSize(248,40), 0, wxDefaultValidator, _T("ID_BUTTON18"));
    panelWriteVCard = new wxPanel(Notebook2, ID_PANEL8, wxPoint(214,5), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    StaticText21 = new wxStaticText(panelWriteVCard, ID_STATICTEXT21, _("*Display Name"), wxPoint(104,20), wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    txtDisplayName = new wxTextCtrl(panelWriteVCard, ID_TEXTCTRL17, wxEmptyString, wxPoint(184,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    StaticText22 = new wxStaticText(panelWriteVCard, ID_STATICTEXT22, _("*Last Name"), wxPoint(118,45), wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    txtLastName = new wxTextCtrl(panelWriteVCard, ID_TEXTCTRL18, wxEmptyString, wxPoint(184,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    txtFirstName = new wxTextCtrl(panelWriteVCard, ID_TEXTCTRL19, wxEmptyString, wxPoint(184,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
    txtBusinessPhone = new wxTextCtrl(panelWriteVCard, ID_TEXTCTRL20, wxEmptyString, wxPoint(184,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
    txtCellPhone = new wxTextCtrl(panelWriteVCard, ID_TEXTCTRL21, wxEmptyString, wxPoint(184,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL21"));
    txtPrivatePhone = new wxTextCtrl(panelWriteVCard, ID_TEXTCTRL22, wxEmptyString, wxPoint(184,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL22"));
    txtBusinessEmail = new wxTextCtrl(panelWriteVCard, ID_TEXTCTRL23, wxEmptyString, wxPoint(184,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL23"));
    txtPrivateEmail = new wxTextCtrl(panelWriteVCard, ID_TEXTCTRL24, wxEmptyString, wxPoint(184,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL24"));
    txtTitle = new wxTextCtrl(panelWriteVCard, ID_TEXTCTRL25, wxEmptyString, wxPoint(184,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL25"));
    txtCompany = new wxTextCtrl(panelWriteVCard, ID_TEXTCTRL26, wxEmptyString, wxPoint(184,232), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL26"));
    txtWebisteURL = new wxTextCtrl(panelWriteVCard, ID_TEXTCTRL27, wxEmptyString, wxPoint(184,258), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL27"));
    txtSkypeName = new wxTextCtrl(panelWriteVCard, ID_TEXTCTRL28, wxEmptyString, wxPoint(184,282), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL28"));
    StaticText23 = new wxStaticText(panelWriteVCard, ID_STATICTEXT23, _("First Name"), wxPoint(122,66), wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    StaticText24 = new wxStaticText(panelWriteVCard, ID_STATICTEXT24, _("Business Phone"), wxPoint(100,88), wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    StaticText25 = new wxStaticText(panelWriteVCard, ID_STATICTEXT25, _("Cell Phone"), wxPoint(122,113), wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    StaticText26 = new wxStaticText(panelWriteVCard, ID_STATICTEXT26, _("Private Phone"), wxPoint(105,138), wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    StaticText27 = new wxStaticText(panelWriteVCard, ID_STATICTEXT27, _("Business E-mail"), wxPoint(103,163), wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    StaticText28 = new wxStaticText(panelWriteVCard, ID_STATICTEXT28, _("Private E-mail"), wxPoint(103,188), wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    StaticText29 = new wxStaticText(panelWriteVCard, ID_STATICTEXT29, _("Title"), wxPoint(150,213), wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    StaticText30 = new wxStaticText(panelWriteVCard, ID_STATICTEXT30, _("Company"), wxPoint(125,238), wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    StaticText31 = new wxStaticText(panelWriteVCard, ID_STATICTEXT31, _("Website URL"), wxPoint(110,263), wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    StaticText32 = new wxStaticText(panelWriteVCard, ID_STATICTEXT32, _("Skype Name"), wxPoint(110,288), wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    btnWriteVCard = new wxButton(panelWriteVCard, ID_BUTTON19, _("Write vCard"), wxPoint(336,32), wxSize(192,40), 0, wxDefaultValidator, _T("ID_BUTTON19"));
    btnStoreVCard = new wxButton(panelWriteVCard, ID_BUTTON20, _("Store vCard for tag emulation mode\n(min. v3.8.0 firmware and\n library needed)"), wxPoint(336,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON20"));
    panelWriteBluetooth = new wxPanel(Notebook2, ID_PANEL9, wxPoint(289,11), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    StaticBox5 = new wxStaticBox(panelWriteBluetooth, ID_STATICBOX5, _("Bluetooth secure simple pairing"), wxPoint(64,24), wxSize(410,272), 0, _T("ID_STATICBOX5"));
    StaticText33 = new wxStaticText(panelWriteBluetooth, ID_STATICTEXT33, _("Bluetooth address:"), wxPoint(150,64), wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    txtBluetoothAddress = new wxTextCtrl(panelWriteBluetooth, ID_TEXTCTRL29, wxEmptyString, wxPoint(150,88), wxSize(230,20), 0, wxDefaultValidator, _T("ID_TEXTCTRL29"));
    btnWriteBluetooth = new wxButton(panelWriteBluetooth, ID_BUTTON21, _("Write Bluetooth Address"), wxPoint(150,140), wxSize(230,40), 0, wxDefaultValidator, _T("ID_BUTTON21"));
    btnStoreBluetooth = new wxButton(panelWriteBluetooth, ID_BUTTON22, _("Store Bluetooth Address for tag emulation mode\n(min. v3.8.0 firmware and library needed)"), wxPoint(120,200), wxSize(290,40), 0, wxDefaultValidator, _T("ID_BUTTON22"));
    Notebook2->AddPage(panelWritePhone, _("Phone"), false);
    Notebook2->AddPage(panelWriteSMS, _("SMS"), false);
    Notebook2->AddPage(panelWriteURI, _("URI"), false);
    Notebook2->AddPage(panelWriteVCard, _("vCard"), false);
    Notebook2->AddPage(panelWriteBluetooth, _("Bluetooth"), false);
    StaticBox2 = new wxStaticBox(panelWriteNFCData, ID_STATICBOX2, _("Add Launch Application (AAR)"), wxPoint(8,352), wxSize(528,96), 0, _T("ID_STATICBOX2"));
    StaticText8 = new wxStaticText(panelWriteNFCData, ID_STATICTEXT8, _("Pkg name:"), wxPoint(14,378), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    txtPkgName = new wxTextCtrl(panelWriteNFCData, ID_TEXTCTRL9, wxEmptyString, wxPoint(80,375), wxSize(440,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    btnWriteAAR = new wxButton(panelWriteNFCData, ID_BUTTON23, _("Write AAR to Tag"), wxPoint(16,408), wxSize(504,23), 0, wxDefaultValidator, _T("ID_BUTTON23"));
    panelTools = new wxPanel(ndefOptions, ID_PANEL4, wxPoint(156,6), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    btnInitializeNDEF = new wxButton(panelTools, ID_BUTTON4, _("Card Initialize for NDEF messages"), wxPoint(8,16), wxSize(384,40), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    btnEraseLastRecord = new wxButton(panelTools, ID_BUTTON5, _("Erase Last Record"), wxPoint(176,72), wxSize(216,40), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    btnEraseAllRecords = new wxButton(panelTools, ID_BUTTON6, _("Erase All Records"), wxPoint(176,128), wxSize(216,40), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    btnCardClear = new wxButton(panelTools, ID_BUTTON7, _("Card Clear"), wxPoint(176,184), wxSize(216,40), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    StaticBox3 = new wxStaticBox(panelTools, ID_STATICBOX3, _("NV Lock/Unlock"), wxPoint(8,232), wxSize(216,216), 0, _T("ID_STATICBOX3"));
    StaticText9 = new wxStaticText(panelTools, ID_STATICTEXT9, _(" (min. firmwarre v4.0.20 and library v4.0.22 needed)"), wxPoint(24,248), wxSize(176,40), 0, _T("ID_STATICTEXT9"));
    StaticText9->Disable();
    StaticText10 = new wxStaticText(panelTools, ID_STATICTEXT10, _("Password:"), wxPoint(16,308), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    txtPassword = new wxTextCtrl(panelTools, ID_TEXTCTRL10, wxEmptyString, wxPoint(72,304), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    txtPassword->SetMaxLength(8);
    btnUnlockNVMemory = new wxButton(panelTools, ID_BUTTON8, _("Unlock NV Memory"), wxPoint(24,344), wxSize(152,40), 0, wxDefaultValidator, _T("ID_BUTTON8"));
    btnLockNVMemory = new wxButton(panelTools, ID_BUTTON9, _("Lock NV Memory"), wxPoint(24,400), wxSize(152,40), 0, wxDefaultValidator, _T("ID_BUTTON9"));
    StaticBox4 = new wxStaticBox(panelTools, ID_STATICBOX4, _("Tag emulation mode"), wxPoint(256,232), wxSize(216,216), 0, _T("ID_STATICBOX4"));
    StaticText11 = new wxStaticText(panelTools, ID_STATICTEXT11, _("(min. firmware v3.9.2 and library v3.9.7 needed)"), wxPoint(280,248), wxSize(168,32), 0, _T("ID_STATICTEXT11"));
    StaticText11->Disable();
    btnStartDedicatedEmulation = new wxButton(panelTools, ID_BUTTON10, _("Start dedicated tag emulation mode"), wxPoint(264,288), wxSize(200,40), 0, wxDefaultValidator, _T("ID_BUTTON10"));
    btnStartCombinedEmulation = new wxButton(panelTools, ID_BUTTON11, _("Start combined tag emulation mode"), wxPoint(264,344), wxSize(200,40), 0, wxDefaultValidator, _T("ID_BUTTON11"));
    btnStopEmulation = new wxButton(panelTools, ID_BUTTON12, _("Stop tag emulation mode"), wxPoint(264,400), wxSize(200,40), 0, wxDefaultValidator, _T("ID_BUTTON12"));
    ndefOptions->AddPage(panelReadNFCData, _("Read NFC data"), false);
    ndefOptions->AddPage(panelWriteNFCData, _("Write NFC data"), false);
    ndefOptions->AddPage(panelTools, _("TOOLS"), false);
    Panel10 = new wxPanel(this, ID_PANEL10, wxPoint(0,616), wxSize(552,104), wxNO_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    txtCardType = new wxTextCtrl(Panel10, ID_TEXTCTRL6, wxEmptyString, wxPoint(64,8), wxSize(168,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    StaticText5 = new wxStaticText(Panel10, ID_STATICTEXT5, _("NDEF"), wxPoint(8,11), wxSize(37,15), wxALIGN_CENTRE|wxSIMPLE_BORDER, _T("ID_STATICTEXT5"));
    txtReaderSN = new wxTextCtrl(Panel10, ID_TEXTCTRL7, wxEmptyString, wxPoint(64,35), wxSize(152,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    StaticText6 = new wxStaticText(Panel10, ID_STATICTEXT6, _("DEVICE"), wxPoint(8,38), wxSize(47,15), wxALIGN_CENTRE|wxSIMPLE_BORDER, _T("ID_STATICTEXT6"));
    txtReaderStatus = new wxTextCtrl(Panel10, ID_TEXTCTRL8, wxEmptyString, wxPoint(64,64), wxSize(200,25), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    StaticText7 = new wxStaticText(Panel10, ID_STATICTEXT7, _("STATUS"), wxPoint(8,67), wxSize(49,16), wxALIGN_CENTRE|wxSIMPLE_BORDER, _T("ID_STATICTEXT7"));
    txtCardMsgs = new wxTextCtrl(Panel10, ID_TEXTCTRL30, wxEmptyString, wxPoint(240,8), wxSize(56,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL30"));
    txtCardRecs = new wxTextCtrl(Panel10, ID_TEXTCTRL31, wxEmptyString, wxPoint(300,8), wxSize(56,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL31"));
    txtCardEmpty = new wxTextCtrl(Panel10, ID_TEXTCTRL32, wxEmptyString, wxPoint(370,8), wxSize(56,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL32"));
    txtCardTNF = new wxTextCtrl(Panel10, ID_TEXTCTRL33, wxEmptyString, wxPoint(440,8), wxSize(56,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL33"));
    txtReaderHW = new wxTextCtrl(Panel10, ID_TEXTCTRL34, wxEmptyString, wxPoint(224,35), wxSize(65,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL34"));
    txtReaderFW = new wxTextCtrl(Panel10, ID_TEXTCTRL35, wxEmptyString, wxPoint(304,35), wxDefaultSize, wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL35"));
    txtDLLVer = new wxTextCtrl(Panel10, ID_TEXTCTRL36, wxEmptyString, wxPoint(416,35), wxDefaultSize, wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL36"));
    txtFunctionStatus = new wxTextCtrl(Panel10, ID_TEXTCTRL37, wxEmptyString, wxPoint(280,64), wxSize(232,25), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL37"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnReaderOpenClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnReaderCloseClick);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OncheckAdvancedClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnReadCardClick);
    Connect(ID_GRID1,wxEVT_GRID_SELECT_CELL,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::gridCellSelection);
    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnWritePhoneNrClick);
    Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStorePhoneNrClick);
    Connect(ID_TEXTCTRL12,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::countSMSChars);
    Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnWriteSMSClick);
    Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStoreSMSClick);
    Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::updatePayload);
    Connect(ID_TEXTCTRL14,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::updatePayload);
    Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OncheckUidAsciiMirrorClick);
    Connect(ID_CHECKBOX4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OncheckUidAsciiMirrorClick);
    Connect(ID_TEXTCTRL15,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::updatePayload);
    Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnWriteURIClick);
    Connect(ID_BUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStoreURIClick);
    Connect(ID_BUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnWriteVCardClick);
    Connect(ID_BUTTON20,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStoreVCardClick);
    Connect(ID_BUTTON21,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnWriteBluetoothClick);
    Connect(ID_BUTTON22,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStoreBluetoothClick);
    Connect(ID_BUTTON23,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnWriteAARClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnInitializeNDEFClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnEraseLastRecordClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnEraseAllRecordsClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnCardClearClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnUnlockNVMemoryClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnLockNVMemoryClick);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStartDedicatedEmulationClick);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStartCombinedEmulationClick);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStopEmulationClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ufr_ndef_examples__cpp_wxwidgetsFrame::OnAbout);
    //*)

    gridReadNdef->SetColumnWidth(2,260);
}

ufr_ndef_examples__cpp_wxwidgetsFrame::~ufr_ndef_examples__cpp_wxwidgetsFrame()
{
    //(*Destroy(ufr_ndef_examples__cpp_wxwidgetsFrame)
    //*)
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

std::string GetDlTypeName(uint8_t dl_type_code) {

	switch (dl_type_code) {
	case DL_MIFARE_ULTRALIGHT:
		return "DL_MIFARE_ULTRALIGHT";
	case DL_MIFARE_ULTRALIGHT_EV1_11:
		return "DL_MIFARE_ULTRALIGHT_EV1_11";
	case DL_MIFARE_ULTRALIGHT_EV1_21:
		return "DL_MIFARE_ULTRALIGHT_EV1_21";
	case DL_MIFARE_ULTRALIGHT_C:
		return "DL_MIFARE_ULTRALIGHT_C";
	case DL_NTAG_203:
		return "DL_NTAG_203";
	case DL_NTAG_210:
		return "DL_NTAG_210";
	case DL_NTAG_212:
		return "DL_NTAG_212";
	case DL_NTAG_213:
		return "DL_NTAG_213";
	case DL_NTAG_215:
		return "DL_NTAG_215";
	case DL_NTAG_216:
		return "DL_NTAG_216";
	case DL_MIKRON_MIK640D:
		return "DL_MIKRON_MIK640D";
	case DL_MIFARE_MINI:
		return "DL_MIFARE_MINI";
	case DL_MIFARE_CLASSIC_1K:
		return "DL_MIFARE_CLASSIC_1K";
	case DL_MIFARE_CLASSIC_4K:
		return "DL_MIFARE_CLASSIC_4K";
	case DL_MIFARE_PLUS_S_2K_SL0:
		return "DL_MIFARE_PLUS_S_2K_SL0";
	case DL_MIFARE_PLUS_S_4K_SL0:
		return "DL_MIFARE_PLUS_S_4K_SL0";
	case DL_MIFARE_PLUS_X_2K_SL0:
		return "DL_MIFARE_PLUS_X_2K_SL0";
	case DL_MIFARE_PLUS_X_4K_SL0:
		return "DL_MIFARE_PLUS_X_4K_SL0";
	case DL_MIFARE_DESFIRE:
		return "DL_MIFARE_DESFIRE";
	case DL_MIFARE_DESFIRE_EV1_2K:
		return "DL_MIFARE_DESFIRE_EV1_2K";
	case DL_MIFARE_DESFIRE_EV1_4K:
		return "DL_MIFARE_DESFIRE_EV1_4K";
	case DL_MIFARE_DESFIRE_EV1_8K:
		return "DL_MIFARE_DESFIRE_EV1_8K";
	case DL_MIFARE_DESFIRE_EV2_2K:
		return "DL_MIFARE_DESFIRE_EV2_2K";
	case DL_MIFARE_DESFIRE_EV2_4K:
		return "DL_MIFARE_DESFIRE_EV2_4K";
	case DL_MIFARE_DESFIRE_EV2_8K:
		return "DL_MIFARE_DESFIRE_EV2_8K";
	case DL_MIFARE_PLUS_S_2K_SL1:
		return "DL_MIFARE_PLUS_S_2K_SL1";
	case DL_MIFARE_PLUS_X_2K_SL1:
		return "DL_MIFARE_PLUS_X_2K_SL1";
	case DL_MIFARE_PLUS_EV1_2K_SL1:
		return "DL_MIFARE_PLUS_EV1_2K_SL1";
	case DL_MIFARE_PLUS_X_2K_SL2:
		return "DL_MIFARE_PLUS_X_2K_SL2";
	case DL_MIFARE_PLUS_S_2K_SL3:
		return "DL_MIFARE_PLUS_S_2K_SL3";
	case DL_MIFARE_PLUS_X_2K_SL3:
		return "DL_MIFARE_PLUS_X_2K_SL3";
	case DL_MIFARE_PLUS_EV1_2K_SL3:
		return "DL_MIFARE_PLUS_EV1_2K_SL3";
	case DL_MIFARE_PLUS_S_4K_SL1:
		return "DL_MIFARE_PLUS_S_4K_SL1";
	case DL_MIFARE_PLUS_X_4K_SL1:
		return "DL_MIFARE_PLUS_X_4K_SL1";
	case DL_MIFARE_PLUS_EV1_4K_SL1:
		return "DL_MIFARE_PLUS_EV1_4K_SL1";
	case DL_MIFARE_PLUS_X_4K_SL2:
		return "DL_MIFARE_PLUS_X_4K_SL2";
	case DL_MIFARE_PLUS_S_4K_SL3:
		return "DL_MIFARE_PLUS_S_4K_SL3";
	case DL_MIFARE_PLUS_X_4K_SL3:
		return "DL_MIFARE_PLUS_X_4K_SL3";
	case DL_MIFARE_PLUS_EV1_4K_SL3:
		return "DL_MIFARE_PLUS_EV1_4K_SL3";
	case DL_GENERIC_ISO14443_4:
		return "DL_GENERIC_ISO_14443_4";
	case DL_GENERIC_ISO14443_4_TYPE_B:
		return "DL_GENERIC_ISO14443_4_TYPE_B";
	case DL_GENERIC_ISO14443_3_TYPE_B:
		return "DL_GENERIC_ISO14443_3_TYPE_B";
	case DL_IMEI_UID:
		return "DL_IMEI_UID";
	}
	return "UNKNOWN CARD";
}

int getcardlen(uint8_t cardtype)
        {
            int data_len;

            switch (cardtype)
            {
                case DL_MIFARE_MINI:
                    data_len = 320;
                    break;
                case DL_MIFARE_CLASSIC_1K:
                    data_len = 752;
                    break;
                case DL_MIFARE_CLASSIC_4K:
                    data_len = 3440;
                    break;
                case DL_NTAG_203:
                    data_len = 144;
                    break;
                case DL_NTAG_213:
                    data_len = 144;
                    break;
                case DL_NTAG_215:
                    data_len = 504;
                    break;
                case DL_NTAG_216:
                    data_len = 888;
                    break;
                case DL_MIFARE_ULTRALIGHT:
                    data_len = 48;
                    break;
                case DL_MIFARE_ULTRALIGHT_C:
                    data_len = 144;
                    break;
                case DL_MIFARE_ULTRALIGHT_EV1_11:
                    data_len = 48;
                    break;
                case DL_MIFARE_ULTRALIGHT_EV1_21:
                    data_len = 144;
                    break;
                case DL_NT3H_1101:
                case DL_NT3H_2111:
                case DL_NT3H_2211:
                    data_len = 888;
                    break;
                case DL_NT3H_1201:
                    data_len = 1904;
                    break;
                case DL_UNKNOWN_ISO_14443_4:
                    data_len = 8192;
                    break;
                default:
                    data_len = 0;
                    break;

            }

            return data_len;
        }


void ufr_ndef_examples__cpp_wxwidgetsFrame::OncheckAdvancedClick(wxCommandEvent& event)
{
    if (checkAdvanced->IsChecked() == true){

        txtReaderTypeEx->Enable();
        txtPortName->Enable();
        txtPortInterface->Enable();
        txtOpenArg->Enable();

        labelReaderTypeEx->Enable();
        labelPortName->Enable();
        labelPortInterface->Enable();
        labelOpenArg->Enable();

    } else {

        txtReaderTypeEx->Disable();
        txtPortName->Disable();
        txtPortInterface->Disable();
        txtOpenArg->Disable();

        labelReaderTypeEx->Disable();
        labelPortName->Disable();
        labelPortInterface->Disable();
        labelOpenArg->Disable();

    }
}

void Convert(std::string str, uint8_t *arr) {

    for (unsigned int i = 0; i < str.length() / 2; i++) {

        std::string part = str.substr(i * 2, 2);

            char str1[32];
            char *ptr;
            strcpy(str1, part.c_str());

        arr[i] = (uint8_t)strtol(str1, &ptr, 16);

    }

}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnReaderOpenClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    if (checkAdvanced->IsChecked() == false){

        status = ReaderOpen();
    } else{

        wxString wxReaderType    = txtReaderTypeEx->GetValue();
        wxString wxPortName      = txtPortName->GetValue();
        wxString wxPortInterface = txtPortInterface->GetValue();
        wxString wxAddArg        = txtOpenArg->GetValue();

        wxReaderType    = wxReaderType.Trim();
        wxPortName      = wxPortName.Trim();
        wxPortInterface = wxPortInterface.Trim();
        wxAddArg        = wxAddArg.Trim();
        uint32_t reader_type = 0, port_interface = 0;

        try
        {
            reader_type = std::stoi((std::string)wxReaderType);
        }
        catch (const std::exception& e)
        {
            wxMessageBox("Invalid Advanced options parameter: Reader type");
            txtReaderTypeEx->SetFocus();
            return;
        }

        c_string port_name = "";
        if (wxPortName != "0"){
           port_name = wxPortName.c_str();
        }

        try{
            if (wxPortInterface == "T"){
                port_interface = 84;
            } else if (wxPortInterface == "U"){
                port_interface = 85;
            } else {
                port_interface = std::stoi((std::string)wxPortInterface);
            }
        }
        catch (const std::exception& e)
        {
            wxMessageBox("Invalid Advanced options parameter: Port interface");
            txtPortInterface->SetFocus();
            return;
        }
        c_string additional = "";
        if (wxAddArg != " ") {
            additional = wxAddArg.c_str();
        }

       status = ReaderOpenEx(reader_type, port_name, port_interface, (void *) additional);
    }

    print_status(status, " Reader opened");


    if (status == UFR_OK)
        {
            txtReaderStatus->SetValue(" CONNECTED ");
            panelReaderOpen->SetBackgroundColour(wxColour(0,200,0));
            txtReaderStatus->SetBackgroundColour(wxColour(0,255,0));
            Refresh();
            Update();
       } else
       {
            txtReaderStatus->SetValue(" Not connected ");
            panelReaderOpen->SetBackgroundColour(wxColour(255,0,0));
            Refresh();
            Update();
       }

        uint8_t reader_sn[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
        uint32_t reader_type = 0;
        uint8_t hw_major = 0, hw_minor = 0;
        uint8_t fw_major = 0, fw_minor = 0, fw_build = 0;

        std::string dll_ver_str = "";
        dll_ver_str = GetDllVersionStr();
        status = GetReaderSerialDescription(reader_sn);
        status = GetReaderType(&reader_type);
        status = GetReaderHardwareVersion(&hw_major, &hw_minor);
        status = GetReaderFirmwareVersion(&fw_major, &fw_minor);
        status = GetBuildNumber(&fw_build);

        if (status != UFR_OK){
            txtFunctionStatus->SetValue(" Error: " + std::to_string(status));
            txtFunctionStatus->SetBackgroundColour(wxColour(255,0,0));
            Refresh();
            Update();
            return;
        }
        std::string reader_sn_str(reinterpret_cast<char const*>(reader_sn), 8);

        wxString reader_fw_str = "";
        reader_fw_str = " FW: " + std::to_string(fw_major) + "." + std::to_string(fw_minor) + "." + std::to_string(fw_build);
        wxString reader_hw_str = "";
        reader_hw_str << " HW: " << std::to_string(hw_major) << "." << std::to_string(hw_minor);

        txtDLLVer->SetValue(" DLL: " + dll_ver_str);
        txtReaderSN->SetValue(reader_sn_str);
        txtReaderFW->SetValue(reader_fw_str);
        txtReaderHW->SetValue(reader_hw_str);
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnReaderCloseClick(wxCommandEvent& event)
{
    UFR_STATUS status;
    status = ReaderClose();
    print_status(status, " Reader closed");
    if (status == UFR_OK)
    {
        txtReaderStatus->SetValue(" NOT CONNECTED");
        txtReaderStatus->SetBackgroundColour(wxColor(255,0,0));
    }
}


void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnReadCardClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    uint8_t type[255];
    uint8_t id[255];
    uint8_t payload[1000];
    uint8_t type_length = 0, id_length = 0, tnf = 0;
    uint8_t record_nr = 0;
    uint8_t message_cnt = 0, record_cnt = 0, empty_record_cnt = 0;
    uint8_t record_cnt_array[100];
    uint8_t card_type = 0;
    uint32_t payload_length = 0;
    wxString wx_status = "";


    memset(type, 0, 255);
    memset(id, 0, 255);
    memset(payload, 0, 255);
    memset(record_cnt_array,0, 100);


    txtReadPayload->Clear();
    txtCardEmpty->Clear();
    txtCardMsgs->Clear();
    txtCardRecs->Clear();

    wxString aha = "";
    status = GetDlogicCardType(&card_type);
    if (status == UFR_OK){
        wxString wx_card_type = "";
        wx_card_type = (std::string)GetDlTypeName(card_type);
        txtCardType->SetValue(wx_card_type);
    } else {
        wx_status = (std::string)UFR_Status2String(status);
        txtFunctionStatus->SetValue(wx_status);
        txtFunctionStatus->SetBackgroundColour(wxColor(255,0,0));
        txtCardType->Clear();
        return;
    }
    status = get_ndef_record_count(&message_cnt, &record_cnt, record_cnt_array, &empty_record_cnt);

    if (status != UFR_OK){
        txtFunctionStatus->SetValue("Card is not initialized");
        return;
    }
    wxString output = "";
    output = "Msgs: " + std::to_string(message_cnt);
    txtCardMsgs->SetValue(output);
    output = "Recs: " + std::to_string(record_cnt);
    txtCardRecs->SetValue(output);
    output = "Empty: " + std::to_string(empty_record_cnt);
    txtCardEmpty->SetValue(output);

    gridReadNdef->ClearGrid();

    txtReadPayload->SetValue("Payload:");

    for (record_nr = 1; record_nr < record_cnt + 1; record_nr++){

        status = read_ndef_record(1, record_nr, &tnf, type, &type_length, id, &id_length, payload, &payload_length);

        if (status != UFR_OK){
            if (status == UFR_WRONG_NDEF_CARD_FORMAT)
                txtFunctionStatus->SetValue(" NDEF format error");
            else if (status == UFR_NDEF_MESSAGE_NOT_FOUND)
                txtFunctionStatus->SetValue(" NDEF message not found");
            else
                txtFunctionStatus->SetValue(" Error: " + std::to_string(status));
            txtFunctionStatus->SetBackgroundColour(wxColor(255,0,0));
            break;
        }
    //std::string payload_str(reinterpret_cast<char const*>(payload), payload_length);
    std::string payload_str = "";
    for (int x = 0; x <= payload_length; x++)
    {
        payload_str += (uint8_t)payload[x];
    }
    std::string type_str(reinterpret_cast<char*>(type), type_length);
    txtReadPayload->SetValue("Payload:" + payload_str);
    txtCardTNF->SetValue(std::to_string(tnf));

    txtFunctionStatus->SetValue(" Reading " + std::to_string(record_nr) + "/" + std::to_string(record_cnt));

    gridReadNdef->SetCellValue(type_str, record_nr-1,0); // type set
    gridReadNdef->SetCellValue(std::to_string(payload_length), record_nr-1,1); // type set
    gridReadNdef->SetCellValue(payload_str, record_nr-1,2); // type set
    }

    Update();
    Refresh();

    //txtFunctionStatus->SetValue("Reading DONE!");
    print_status(status, "Reading DONE!");

    if (message_cnt == 0 && empty_record_cnt == 0){

        txtFunctionStatus->SetValue("Card must be formatted first!");
    }
    else
    {
        if (message_cnt == 1 && empty_record_cnt == 1){
        txtFunctionStatus->SetValue("NFC formatted! Ready for use...");
        }
    }
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnWritePhoneNrClick(wxCommandEvent& event)
{
    // Tel TNF=1, Type = URI = "U", Type Length =1 , payload[0]=5
    UFR_STATUS status;
    uint8_t tnf = 1;
    uint8_t id[2];
    uint8_t id_length = 0;
    uint32_t payload_length  = 0;
    uint8_t message_nr = 1;
    uint8_t type_record = 85; // 'U' = URI
    uint8_t type_length = 1;
    uint8_t card_formatted = 0;


    wxString wx_phone_nr = txtWritePhoneNr->GetValue();
    if (wx_phone_nr == ""){
            wxMessageBox("Phone number is mandatory!");
            return;
    }

    payload_length = wx_phone_nr.length()+1;
    uint8_t payload[payload_length];
    payload[0] = 5;
    for (unsigned int i = 1; i <= wx_phone_nr.length() +1; i++){
        payload[i] = (uint8_t)wx_phone_nr[i-1];
    }
    status = write_ndef_record(message_nr, &tnf, &type_record, &type_length, id, &id_length, payload, &payload_length, &card_formatted);

    print_status(status, "Phone Written");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnWriteSMSClick(wxCommandEvent& event)
{
    //SMS TNF=1, Type = URI = "U", Type Length =1 , payload[0]=0 , "sms:", "?body:"
    UFR_STATUS status;
    uint8_t tnf = 1;
    uint8_t id[2];
    uint8_t id_length = 0;
    uint32_t payload_length  = 0;
    uint8_t message_nr = 1;
    uint8_t type_record = 85; // 'U' = URI
    uint8_t type_length = 1;
    uint8_t card_formatted = 0;

    std::string sms_body = (std::string)txtSMSBody->GetValue();
    std::string sms_nr = (std::string)txtSMSNr->GetValue();

    if ( (sms_body == "") || (sms_nr == "")){
        wxMessageBox("SMS message and number are mandatory!");
        return;
    }

    std::string sms_header1 = "sms: ";
    std::string sms_header2 = "?body=";
    std::string tmp_str_payload = sms_header1 + sms_nr + sms_header2 + sms_body;

    payload_length = tmp_str_payload.length() + 1;

    uint8_t payload[payload_length + 1];
    payload[0] = 0;
    for (unsigned int i = 1; i <= payload_length; i++){
        payload[i] = tmp_str_payload[i-1];
    }
    status = write_ndef_record(message_nr, &tnf, &type_record, &type_length, id, &id_length, payload, &payload_length, &card_formatted);

    print_status(status, "SMS Written");
}
void ufr_ndef_examples__cpp_wxwidgetsFrame::ndef_write_mirrorring()
{
    //URL TNF=1, Type = URI = "U", Type Length =1 , payload[0]=depends on identifier
    UFR_STATUS status;

    uint8_t tnf = 1;
    uint8_t id[2];
    uint8_t id_length = 0;
    uint32_t payload_length  = 0;
    uint8_t message_nr = 1;
    uint8_t type_record = 85; // 'U' = URI
    uint8_t type_length = 1;
    uint8_t card_formatted = 0;

    int use_counter_ascii_mirror = 0;
    int use_uid_ascii_mirror = 0;

    if(checkUidAsciiMirror->IsChecked() == true){
        use_uid_ascii_mirror = 1;
    } else {
        use_uid_ascii_mirror = 0;
    }

    if(checkNFCCounter->IsChecked() == true){
        use_counter_ascii_mirror = 1;
    } else {
        use_counter_ascii_mirror = 0;
    }

    std::string tmp_payload = mPayload;
    payload_length = tmp_payload.length();
    uint8_t payload[payload_length+1];
    memset(payload, 0, sizeof(payload));
    payload_length = sizeof(payload);
    payload[0] = cmbUriId->GetCurrentSelection();

    unsigned int i = 1;
    for (i = 1; i < payload_length + 2; i++){
        payload[i] = tmp_payload[i-1];
    }
    status = write_ndef_record_mirroring(message_nr, &tnf, &type_record, &type_length, id, &id_length, payload, &payload_length, &card_formatted,
                                         use_uid_ascii_mirror, use_counter_ascii_mirror, mirror_pos);
    print_status(status, "URI Written");
}
void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnWriteURIClick(wxCommandEvent& event)
{
  if (checkUidAsciiMirror->IsChecked() == true){
        ndef_write_mirrorring();
    } else {
        //URL TNF=1, Type = URI = "U", Type Length =1 , payload[0]=depends on identifier
        UFR_STATUS status;

        uint8_t tnf = 1;
        uint8_t id[2];
        uint8_t id_length = 0;
        uint32_t payload_length  = 0;
        uint8_t message_nr = 1;
        uint8_t type_record = 85; // 'U' = URI
        uint8_t type_length = 1;
        uint8_t card_formatted = 0;

        if (txtUri->GetValue() == ""){
            wxMessageBox("URL field is mandatory!");
            return;
        }

        std::string tmp_str_payload = (std::string)txtUri->GetValue();
        payload_length = tmp_str_payload.length() + 1;
        uint8_t payload[payload_length+1];
        payload[0] = cmbUriId->GetCurrentSelection();

        for (unsigned int i = 1; i < payload_length; i++){
            payload[i] = tmp_str_payload[i-1];
        }

        status = write_ndef_record(message_nr, &tnf, &type_record, &type_length, id, &id_length, payload, &payload_length, &card_formatted);

        print_status(status, "URI Written");

    }
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnWriteVCardClick(wxCommandEvent& event)
{
    //vCard TNF=2, Type = Mime = "text/x-vCard", Type length=12
    UFR_STATUS status;
    uint8_t tnf = 2;
    uint8_t id[2];
    uint8_t id_length = 0;
    uint32_t payload_length  = 0;
    uint8_t message_nr = 1;
    uint8_t type_length = 1;
    uint8_t card_formatted = 0;
    std::string tmp_str_payload = "";

    std::string display_name = (std::string)txtDisplayName->GetValue();
    std::string last_name = (std::string)txtLastName->GetValue();

    if ((display_name == "") || (last_name == "")){
        wxMessageBox("\"Display name\" and \"Last name\" fields are mandatory!");
        return;
    }

    std::string first_name = (std::string)txtFirstName->GetValue();
    std::string business_phone = (std::string)txtBusinessPhone->GetValue();
    std::string cell_phone = (std::string)txtCellPhone->GetValue();
    std::string private_phone = (std::string)txtPrivatePhone->GetValue();
    std::string business_email = (std::string)txtBusinessEmail->GetValue();
    std::string private_email = (std::string)txtPrivateEmail->GetValue();
    std::string title = (std::string)txtTitle->GetValue();
    std::string company = (std::string)txtCompany->GetValue();
    std::string website_url = (std::string)txtWebisteURL->GetValue();
    std::string skype_name = (std::string)txtSkypeName->GetValue();

    //format NDEF payload for vCard 3.30

    tmp_str_payload  = "BEGIN:VCARD\r\n";
    tmp_str_payload += "VERSION:3.0\r\n";
    tmp_str_payload += "N:" + last_name + ";";
    tmp_str_payload += first_name + ";;;\r\n";
    tmp_str_payload += "FN:" + display_name + "\r\n";

    if (cell_phone.length() != 0){
        tmp_str_payload += "TEL;CELL:" + cell_phone + "\r\n";
    }
    if (business_phone.length() != 0){
        tmp_str_payload += "TEL;WORK:" + business_phone + "\r\n";
    }
    if (private_phone.length() != 0){
        tmp_str_payload += "TEL;HOME:" + private_phone + "\r\n";
    }
    if (business_email.length() != 0){
        tmp_str_payload += "EMAIL;WORK:" + business_email + "\r\n";
    }
    if (private_email.length() != 0){
        tmp_str_payload += "EMAIL;HOME:" + private_email + "\r\n";
    }
    if (title.length() != 0){
        tmp_str_payload += "TITLE:" + title + "\r\n";
    }
    if (company.length() != 0){
        tmp_str_payload += "ORG:" + company + "\r\n";
    }
    if (website_url.length() != 0){
        tmp_str_payload += "URL:" + website_url + "\r\n";
    }
    if (skype_name.length() != 0){
        tmp_str_payload += "X-SKYPE:" + skype_name + "\r\n";
    }

    tmp_str_payload += "END:VCARD";

    payload_length = tmp_str_payload.length();

    uint8_t payload[payload_length];

    for (unsigned int i = 0; i <= payload_length; i++){
        payload[i] = tmp_str_payload[i];
     }

    std::string type_record_str = "text/x-vCard";
    type_length = (uint8_t)type_record_str.length();
    uint8_t type_record[type_length];
    for (int i = 0; i <= type_length; i++){
        type_record[i] = type_record_str[i];
    }

    status = write_ndef_record(message_nr, &tnf, type_record, &type_length, id, &id_length, payload, &payload_length, &card_formatted);

    print_status(status, "vCard Written");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnWriteBluetoothClick(wxCommandEvent& event)
{
    // bluetooth NDEF len 6 bytes + 2 for payload [0] and [1] preset bytes
    UFR_STATUS status;
    uint8_t tnf = 2;
    uint8_t id[2];
    uint8_t id_length = 0;
    uint32_t payload_length  = 0;
    uint8_t message_nr = 1;
    uint8_t type_length = 1;
    uint8_t card_formatted = 0;

    if (txtBluetoothAddress->GetValue() == ""){
        wxMessageBox("URL field is mandatory!");
        return;
    }

    std::string type_record_str = "application/vnd.bluetooth.ep.oob";
    type_length = (uint8_t)type_record_str.length();
    uint8_t type_record[type_length];
    for (int i = 0; i <= type_length; i++){
        type_record[i] = type_record_str[i];
    }

    std::string tmp_str_payload = (std::string)txtBluetoothAddress->GetValue();
    payload_length = (tmp_str_payload.length()/2) + 2;
    uint8_t payload[payload_length];
    memset(payload, 0, payload_length);

    payload[0] = 8;
    payload[1] = 0;

    for (unsigned int i = 0; i < tmp_str_payload.length() / 2; i++){
        std::string part = tmp_str_payload.substr(i*2, 2);
        char str1[32];
        char *ptr;
        strcpy(str1, part.c_str());
        payload[i+2] = strtol(str1, &ptr, 16);
    }

    status = write_ndef_record(message_nr, &tnf, type_record, &type_length, id, &id_length, payload, &payload_length, &card_formatted);

    print_status(status, "Bluetooth address written");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnInitializeNDEFClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    status = ndef_card_initialization();

     print_status(status, "Card initialized!");

}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnCardClearClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    uint8_t addressingmode = 0;
    uint8_t address = 0, address_max = 0, auth_mode = 0;
    uint8_t sectortrailer[16] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x80, 0x69, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint8_t DEFKey[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint16_t data_len = 0, bw = 0;

    uint8_t card_type = 0;

    status = GetDlogicCardType(&card_type);
    if (status != UFR_OK){
         print_status(status, "OK");
         return;
    }

    addressingmode = 0x01;
    address = 0x00;
    auth_mode = 0x61;

    if (card_type == DL_MIFARE_CLASSIC_1K){
        address_max = 16;
    } else if (card_type == DL_MIFARE_CLASSIC_4K){
        address_max = 40;
    } else {
        address_max = 0;
    }

    for (address = 0; address < address_max; address++){
        status = SectorTrailerWriteUnsafe_PK(addressingmode, address, sectortrailer, auth_mode, DEFKey);
    }

    data_len = (uint16_t) getcardlen(card_type);
    uint8_t data[data_len+1];
    memset(data, 0, data_len+1);

    if (card_type < DL_MIFARE_MINI){
        auth_mode = 0x60;
        }
    status = LinearWrite_PK(data, 0, data_len, &bw, auth_mode, DEFKey);

    print_status(status, "Card erased!");

}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnEraseLastRecordClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    status = erase_last_ndef_record(1);

    print_status(status, "Erased");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnEraseAllRecordsClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    status = erase_all_ndef_records(1);

    print_status(status, "Erased All");
}


void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStartDedicatedEmulationClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    status = TagEmulationStart();

    print_status(status, "dedicated emulation mode activated");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStartCombinedEmulationClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    status = CombinedModeEmulationStart();

    print_status(status, "combined emulation mode activated");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStopEmulationClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    status = TagEmulationStop();

    print_status(status, "emulation mode deactivated");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnLockNVMemoryClick(wxCommandEvent& event)
{
    UFR_STATUS status;
    std::string pw_str = "";
    pw_str = (std::string)txtPassword->GetValue();

    if (pw_str == ""){
        wxMessageBox("Password is mandatory!");
        txtPassword->SetFocus();
        return;
    }

    char *password = new char[pw_str.length() + 1];
    strcpy(password, pw_str.c_str());

    status = ReaderKeysLock((const uint8_t*)password);

    print_status(status, "NV Locked");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnUnlockNVMemoryClick(wxCommandEvent& event)
{
    UFR_STATUS status;
    std::string pw_str = "";
    pw_str = (std::string)txtPassword->GetValue();

    if (pw_str == ""){
        wxMessageBox("Password is mandatory!");
        txtPassword->SetFocus();
        return;
    }

    char *password = new char[pw_str.length() + 1];
    strcpy(password, pw_str.c_str());

    status = ReaderKeysUnlock((const uint8_t*)password);

    print_status(status, "NV Unlocked");
}



void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnWriteAARClick(wxCommandEvent& event)
{
    // URL TNF=4, Type= "android.com:pkg", Type Length= 15, payload[0]=1
    UFR_STATUS status;
    uint8_t tnf = 4;
    uint8_t id[2];
    uint8_t id_length = 0;
    uint32_t payload_length  = 0;
    uint8_t message_nr = 1;
    uint8_t type_length = 0;
    uint8_t card_formatted = 0;

    if (txtPkgName->GetValue() == ""){
        wxMessageBox("Pkg name is mandatory!");
        return;
    }

    std::string type_record_str = "android.com:pkg";
    type_length = (uint8_t)type_record_str.length();
    uint8_t type_record[type_length];
    for (int i = 0; i <= type_length; i++){
        type_record[i] = type_record_str[i];
    }

    std::string tmp_str_payload = (std::string)txtPkgName->GetValue();
    payload_length = (tmp_str_payload.length());
    uint8_t payload[payload_length];
    memset(payload, 0, payload_length);

     for (unsigned int i = 0; i <= tmp_str_payload.length(); i++){
        payload[i] = tmp_str_payload[i];
    }

    status = write_ndef_record(message_nr, &tnf, type_record, &type_length, id, &id_length, payload, &payload_length, &card_formatted);

    print_status(status, "AAR Written");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStorePhoneNrClick(wxCommandEvent& event)
{

    // Tel TNF=1, Type = URI = "U", Type Length =1 , payload[0]=5
    UFR_STATUS status;
    uint8_t tnf = 1;
    uint8_t id[2];
    uint8_t id_length = 0;
    uint32_t payload_length  = 0;
    uint8_t type_record = 85; // 'U' = URI
    uint8_t type_length = 1;

    wxString wx_phone_nr = txtWritePhoneNr->GetValue();
    if (wx_phone_nr == ""){
            wxMessageBox("Phone number is mandatory!");
            return;
    }

    payload_length = wx_phone_nr.length()+1;
    uint8_t payload[payload_length];
    payload[0] = 5;
    for (unsigned int i = 1; i <= wx_phone_nr.length(); i++){
        payload[i] = wx_phone_nr[i-1];
    }
    status = WriteEmulationNdef(tnf, &type_record, type_length, id, id_length, payload, payload_length);

    print_status(status, "Phone Written");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStoreSMSClick(wxCommandEvent& event)
{

    //SMS TNF=1, Type = URI = "U", Type Length =1 , payload[0]=0 , "sms:", "?body:"
    UFR_STATUS status;
    uint8_t tnf = 1;
    uint8_t id[2];
    uint8_t id_length = 0;
    uint32_t payload_length  = 0;
    uint8_t type_record = 85; // 'U' = URI
    uint8_t type_length = 1;

    std::string sms_body = (std::string)txtSMSBody->GetValue();
    std::string sms_nr = (std::string)txtSMSNr->GetValue();

    if ( (sms_body == "") || (sms_nr == "")){
        wxMessageBox("SMS message and number are mandatory!");
        return;
    }

    std::string sms_header1 = "sms: ";
    std::string sms_header2 = "?body=";
    std::string tmp_str_payload = sms_header1 + sms_nr + sms_header2 + sms_body;

    payload_length = tmp_str_payload.length() + 1;

    uint8_t payload[payload_length + 1];
    payload[0] = 0;
    for (unsigned int i = 1; i <= payload_length; i++){
        payload[i] = tmp_str_payload[i-1];
    }
    status = WriteEmulationNdef(tnf, &type_record, type_length, id, id_length, payload, payload_length);

    print_status(status, "SMS Written");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStoreURIClick(wxCommandEvent& event)
{

    //URL TNF=1, Type = URI = "U", Type Length =1 , payload[0]=depends on identifier
    UFR_STATUS status;
    uint8_t tnf = 1;
    uint8_t id[2];
    uint8_t id_length = 0;
    uint32_t payload_length  = 0;
    uint8_t type_record = 85; // 'U' = URI
    uint8_t type_length = 1;

    if (txtUri->GetValue() == ""){
        wxMessageBox("URL field is mandatory!");
        return;
    }
    std::string tmp_str_payload = (std::string)txtUri->GetValue();
    payload_length = tmp_str_payload.length() + 1;
    uint8_t payload[payload_length+1];
    payload[0] = cmbUriId->GetCurrentSelection();

    for (unsigned int i = 1; i <= payload_length; i++){
        payload[i] = tmp_str_payload[i-1];
    }
    status = WriteEmulationNdef(tnf, &type_record, type_length, id, id_length, payload, payload_length);

    print_status(status, "URI Written");

}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStoreVCardClick(wxCommandEvent& event)
{

    //vCard TNF=2, Type = Mime = "text/x-vCard", Type length=12
    UFR_STATUS status;
    uint8_t tnf = 2;
    uint8_t id[2];
    uint8_t id_length = 0;
    uint32_t payload_length  = 0;
    uint8_t type_length = 1;

    std::string tmp_str_payload = "";

    std::string display_name = (std::string)txtDisplayName->GetValue();
    std::string last_name = (std::string)txtLastName->GetValue();

    if ((display_name == "") || (last_name == "")){
        wxMessageBox("\"Display name\" and \"Last name\" fields are mandatory!");
        return;
    }

    std::string first_name = (std::string)txtFirstName->GetValue();
    std::string business_phone = (std::string)txtBusinessPhone->GetValue();
    std::string cell_phone = (std::string)txtCellPhone->GetValue();
    std::string private_phone = (std::string)txtPrivatePhone->GetValue();
    std::string business_email = (std::string)txtBusinessEmail->GetValue();
    std::string private_email = (std::string)txtPrivateEmail->GetValue();
    std::string title = (std::string)txtTitle->GetValue();
    std::string company = (std::string)txtCompany->GetValue();
    std::string website_url = (std::string)txtWebisteURL->GetValue();
    std::string skype_name = (std::string)txtSkypeName->GetValue();

    //format NDEF payload for vCard 3.30

    tmp_str_payload  = "BEGIN:VCARD\r\n";
    tmp_str_payload += "VERSION:3.0\r\n";
    tmp_str_payload += "N:" + last_name + ";";
    tmp_str_payload += first_name + ";;;\r\n";
    tmp_str_payload += "FN:" + display_name + "\r\n";

    if (cell_phone.length() != 0){
        tmp_str_payload += "TEL;CELL:" + cell_phone + "\r\n";
    }
    if (business_phone.length() != 0){
        tmp_str_payload += "TEL;WORK:" + business_phone + "\r\n";
    }
    if (private_phone.length() != 0){
        tmp_str_payload += "TEL;HOME:" + private_phone + "\r\n";
    }
    if (business_email.length() != 0){
        tmp_str_payload += "EMAIL;WORK:" + business_email + "\r\n";
    }
    if (private_email.length() != 0){
        tmp_str_payload += "EMAIL;HOME:" + private_email + "\r\n";
    }
    if (title.length() != 0){
        tmp_str_payload += "TITLE:" + title + "\r\n";
    }
    if (company.length() != 0){
        tmp_str_payload += "ORG:" + company + "\r\n";
    }
    if (website_url.length() != 0){
        tmp_str_payload += "URL:" + website_url + "\r\n";
    }
    if (skype_name.length() != 0){
        tmp_str_payload += "X-SKYPE:" + skype_name + "\r\n";
    }

    tmp_str_payload += "END:VCARD";

    payload_length = tmp_str_payload.length();

    uint8_t payload[payload_length];

    for (unsigned int i = 0; i <= payload_length; i++){
        payload[i] = tmp_str_payload[i];
     }

    std::string type_record_str = "text/x-vCard";
    type_length = (uint8_t)type_record_str.length();
    uint8_t type_record[type_length];
    for (int i = 0; i <= type_length; i++){
        type_record[i] = type_record_str[i];
    }

    status = WriteEmulationNdef(tnf, type_record, type_length, id, id_length, payload, payload_length);

    print_status(status, "vCard Written");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OnbtnStoreBluetoothClick(wxCommandEvent& event)
{

    // bluetooth NDEF len 6 bytes + 2 for payload [0] and [1] preset bytes
    UFR_STATUS status;
    uint8_t tnf = 2;
    uint8_t id[2];
    uint8_t id_length = 0;
    uint32_t payload_length  = 0;
    uint8_t type_length = 1;

    if (txtBluetoothAddress->GetValue() == ""){
        wxMessageBox("URL field is mandatory!");
        return;
    }

    std::string type_record_str = "application/vnd.bluetooth.ep.oob";
    type_length = (uint8_t)type_record_str.length();
    uint8_t type_record[type_length];
    for (int i = 0; i <= type_length; i++){
        type_record[i] = type_record_str[i];
    }

    std::string tmp_str_payload = (std::string)txtBluetoothAddress->GetValue();
    payload_length = (tmp_str_payload.length()/2) + 2;
    uint8_t payload[payload_length];
    memset(payload, 0, payload_length);

    payload[0] = 8;
    payload[1] = 0;

    for (unsigned int i = 0; i < tmp_str_payload.length() / 2; i++){
        std::string part = tmp_str_payload.substr(i*2, 2);
        char str1[32];
        char *ptr;
        strcpy(str1, part.c_str());
        payload[i+2] = strtol(str1, &ptr, 16);
    }

    status = WriteEmulationNdef(tnf, type_record, type_length, id, id_length, payload, payload_length);

    print_status(status, "Bluetooth address Written");
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::updatePayload(wxCommandEvent& event)
{
    std::string output = "";
    std::string temp = mPayload;
    mPayload = "";
    txtResultPayload->Clear();
    int UsedUriIdentifierCodeTagLen = -1;

    if (cmbUriId->GetSelection() != 0){
        UsedUriIdentifierCodeTagLen = URI_IDENTIFIER_CODE_TAG_LEN + std::to_string(cmbUriId->GetSelection()).length() - 1;
        output = URI_IDENTIFIER_CODE_TAG_OPEN + std::to_string(cmbUriId->GetSelection()) + URI_IDENTIFIER_CODE_TAG_CLOSE;
        txtResultPayload->SetValue(output);
    }

    output += txtUri->GetValue();
    mPayload += txtUri->GetValue();
    txtResultPayload->SetValue(output);

    if ((checkUidAsciiMirror->IsChecked() == true) && (checkNFCCounter->IsChecked() == true))
    {
        mirror_pos = txtResultPayload->GetValue().length() + txtASCIIPrefix->GetValue().length() - UsedUriIdentifierCodeTagLen;
        output += txtASCIIPrefix->GetValue() + "00000000000000x000000";
        mPayload += txtASCIIPrefix->GetValue() + "00000000000000x000000";
        txtResultPayload->SetValue(output);

    } else if ((checkUidAsciiMirror->IsChecked() == true) || (checkNFCCounter->IsChecked() == true)){
        if (checkUidAsciiMirror->IsChecked() == true){
            output += txtASCIIPrefix->GetValue() + "00000000000000";
            mPayload += txtASCIIPrefix->GetValue() + "00000000000000";
            txtResultPayload->SetValue(output);
        }
        if (checkNFCCounter->IsChecked() == true){
            output += txtASCIIPrefix->GetValue() + "000000";
            mPayload += txtASCIIPrefix->GetValue() + "000000";
            txtResultPayload->SetValue(output);
        }
    } else {
        mirror_pos = 0;
    }
        txtResultPayload->SetValue(output);
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::OncheckUidAsciiMirrorClick(wxCommandEvent& event)
{
    if ((checkUidAsciiMirror->IsChecked() == true) || (checkNFCCounter->IsChecked() == true))
    {
        lblAsciiPrefix->Enable();
        txtASCIIPrefix->Enable();
        btnStoreURI->Disable();
    } else {
        lblAsciiPrefix->Disable();
        txtASCIIPrefix->Disable();
        btnStoreURI->Enable();
    }
    updatePayload(event);
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::gridCellSelection(wxGridEvent& event)
{
    if(event.GetCol() % 2 == 0 && event.GetCol() != 0){
        wxString payload = gridReadNdef->GetCellValue(event.GetRow(),event.GetCol());
        txtReadPayload->SetValue("Payload:" + payload);

    }
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::countSMSChars(wxCommandEvent& event)
{
    labelSMSCharCount->SetLabelText(std::to_string(txtSMSBody->GetValue().length()));
}

void ufr_ndef_examples__cpp_wxwidgetsFrame::print_status(UFR_STATUS status, std::string ok_text)
{
    std::string msg = "";

    if (status == UFR_OK)
    {
        msg = " OK - " + ok_text;
        txtFunctionStatus->SetBackgroundColour(wxColor(0,255,0));
        Refresh();
        Update();
    }
    else
    {
        msg = " " + (std::string)UFR_Status2String(status);
        txtFunctionStatus->SetBackgroundColour(wxColor(255,0,0));
        Refresh();
        Update();
    }

    txtFunctionStatus->SetValue(msg);

}


void ufr_ndef_examples__cpp_wxwidgetsFrame::OnpanelWriteURIPaint(wxPaintEvent& event)
{
}
