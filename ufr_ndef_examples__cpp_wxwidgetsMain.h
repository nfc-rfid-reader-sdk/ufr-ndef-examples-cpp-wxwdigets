/***************************************************************
 * Name:      ufr_ndef_examples__cpp_wxwidgetsMain.h
 * Purpose:   Defines Application Frame
 * Author:    Digital Logic (support@d-logic.rs)
 * Created:   2019-06-13
 * Copyright: Digital Logic (www.d-logic.net)
 * License:
 **************************************************************/

#ifndef UFR_NDEF_EXAMPLES__CPP_WXWIDGETSMAIN_H
#define UFR_NDEF_EXAMPLES__CPP_WXWIDGETSMAIN_H
#include "lib/include/uFCoder.h"


//(*Headers(ufr_ndef_examples__cpp_wxwidgetsFrame)
#include <wx/notebook.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/combobox.h>
#include <wx/statusbr.h>
//*)

class ufr_ndef_examples__cpp_wxwidgetsFrame: public wxFrame
{
    public:

        ufr_ndef_examples__cpp_wxwidgetsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ufr_ndef_examples__cpp_wxwidgetsFrame();

    private:

        //(*Handlers(ufr_ndef_examples__cpp_wxwidgetsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OncheckAdvancedClick(wxCommandEvent& event);
        void OnbtnReaderOpenClick(wxCommandEvent& event);
        void OnbtnReadCardClick(wxCommandEvent& event);
        void OnbtnWritePhoneNrClick(wxCommandEvent& event);
        void OnbtnWriteSMSClick(wxCommandEvent& event);
        void OnbtnWriteURIClick(wxCommandEvent& event);
        void OnbtnWriteVCardClick(wxCommandEvent& event);
        void OnbtnWriteBluetoothClick(wxCommandEvent& event);
        void OnbtnInitializeNDEFClick(wxCommandEvent& event);
        void OnbtnCardClearClick(wxCommandEvent& event);
        void OnbtnEraseLastRecordClick(wxCommandEvent& event);
        void OnbtnEraseAllRecordsClick(wxCommandEvent& event);
        void OnbtnWriteAARClick(wxCommandEvent& event);
        void OnbtnStorePhoneNrClick(wxCommandEvent& event);
        void OnbtnStoreSMSClick(wxCommandEvent& event);
        void OnbtnStoreURIClick(wxCommandEvent& event);
        void OnbtnStoreVCardClick(wxCommandEvent& event);
        void OnbtnStoreBluetoothClick(wxCommandEvent& event);
        void updatePayload(wxCommandEvent& event);
        void ndef_write_mirrorring();
        void OncheckUidAsciiMirrorClick(wxCommandEvent& event);
        void OnbtnReaderCloseClick(wxCommandEvent& event);
        void gridCellSelection(wxGridEvent& event);
        void countSMSChars(wxCommandEvent& event);
        void OnbtnStartDedicatedEmulationClick(wxCommandEvent& event);
        void OnbtnStartCombinedEmulationClick(wxCommandEvent& event);
        void OnbtnStopEmulationClick(wxCommandEvent& event);
        void OnbtnLockNVMemoryClick(wxCommandEvent& event);
        void OnbtnUnlockNVMemoryClick(wxCommandEvent& event);
        void print_status(UFR_STATUS status, std::string text);
        void OnpanelWriteURIPaint(wxPaintEvent& event);
        //*)

        //(*Identifiers(ufr_ndef_examples__cpp_wxwidgetsFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long ID_STATICBOX1;
        static const long ID_CHECKBOX1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_BUTTON3;
        static const long ID_GRID1;
        static const long ID_PANEL2;
        static const long ID_STATICTEXT12;
        static const long ID_TEXTCTRL11;
        static const long ID_BUTTON13;
        static const long ID_BUTTON14;
        static const long ID_PANEL5;
        static const long ID_STATICTEXT13;
        static const long ID_TEXTCTRL12;
        static const long ID_STATICTEXT14;
        static const long ID_STATICTEXT15;
        static const long ID_STATICTEXT16;
        static const long ID_TEXTCTRL13;
        static const long ID_BUTTON15;
        static const long ID_BUTTON16;
        static const long ID_PANEL6;
        static const long ID_STATICTEXT17;
        static const long ID_COMBOBOX1;
        static const long ID_STATICTEXT18;
        static const long ID_TEXTCTRL14;
        static const long ID_CHECKBOX3;
        static const long ID_CHECKBOX4;
        static const long ID_STATICTEXT19;
        static const long ID_TEXTCTRL15;
        static const long ID_STATICTEXT20;
        static const long ID_TEXTCTRL16;
        static const long ID_BUTTON17;
        static const long ID_BUTTON18;
        static const long ID_PANEL7;
        static const long ID_STATICTEXT21;
        static const long ID_TEXTCTRL17;
        static const long ID_STATICTEXT22;
        static const long ID_TEXTCTRL18;
        static const long ID_TEXTCTRL19;
        static const long ID_TEXTCTRL20;
        static const long ID_TEXTCTRL21;
        static const long ID_TEXTCTRL22;
        static const long ID_TEXTCTRL23;
        static const long ID_TEXTCTRL24;
        static const long ID_TEXTCTRL25;
        static const long ID_TEXTCTRL26;
        static const long ID_TEXTCTRL27;
        static const long ID_TEXTCTRL28;
        static const long ID_STATICTEXT23;
        static const long ID_STATICTEXT24;
        static const long ID_STATICTEXT25;
        static const long ID_STATICTEXT26;
        static const long ID_STATICTEXT27;
        static const long ID_STATICTEXT28;
        static const long ID_STATICTEXT29;
        static const long ID_STATICTEXT30;
        static const long ID_STATICTEXT31;
        static const long ID_STATICTEXT32;
        static const long ID_BUTTON19;
        static const long ID_BUTTON20;
        static const long ID_PANEL8;
        static const long ID_STATICBOX5;
        static const long ID_STATICTEXT33;
        static const long ID_TEXTCTRL29;
        static const long ID_BUTTON21;
        static const long ID_BUTTON22;
        static const long ID_PANEL9;
        static const long ID_NOTEBOOK2;
        static const long ID_STATICBOX2;
        static const long ID_STATICTEXT8;
        static const long ID_TEXTCTRL9;
        static const long ID_BUTTON23;
        static const long ID_PANEL3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_STATICBOX3;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT10;
        static const long ID_TEXTCTRL10;
        static const long ID_BUTTON8;
        static const long ID_BUTTON9;
        static const long ID_STATICBOX4;
        static const long ID_STATICTEXT11;
        static const long ID_BUTTON10;
        static const long ID_BUTTON11;
        static const long ID_BUTTON12;
        static const long ID_PANEL4;
        static const long ID_NOTEBOOK1;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL7;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL8;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL30;
        static const long ID_TEXTCTRL31;
        static const long ID_TEXTCTRL32;
        static const long ID_TEXTCTRL33;
        static const long ID_TEXTCTRL34;
        static const long ID_TEXTCTRL35;
        static const long ID_TEXTCTRL36;
        static const long ID_TEXTCTRL37;
        static const long ID_PANEL10;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(ufr_ndef_examples__cpp_wxwidgetsFrame)
        wxTextCtrl* txtCardEmpty;
        wxStaticText* StaticText10;
        wxTextCtrl* txtSkypeName;
        wxButton* btnStoreSMS;
        wxStaticText* StaticText22;
        wxStaticText* StaticText9;
        wxButton* btnCardClear;
        wxTextCtrl* txtReaderHW;
        wxTextCtrl* txtReaderStatus;
        wxTextCtrl* txtCardRecs;
        wxStaticText* StaticText20;
        wxTextCtrl* txtPortInterface;
        wxButton* btnWriteURI;
        wxTextCtrl* txtWritePhoneNr;
        wxStaticText* labelSMSCharCount;
        wxTextCtrl* txtBusinessPhone;
        wxPanel* panelWritePhone;
        wxButton* btnStopEmulation;
        wxComboBox* cmbUriId;
        wxStaticText* labelPortInterface;
        wxPanel* panelReaderOpen;
        wxButton* btnStorePhoneNr;
        wxStaticBox* StaticBox5;
        wxStaticText* lblAsciiPrefix;
        wxStaticText* labelSMSCharNr;
        wxStaticText* StaticText29;
        wxStaticText* StaticText33;
        wxStaticText* StaticText13;
        wxCheckBox* checkUidAsciiMirror;
        wxStaticText* StaticText30;
        wxPanel* panelWriteURI;
        wxStaticText* StaticText6;
        wxStaticText* StaticText26;
        wxTextCtrl* txtSMSNr;
        wxTextCtrl* txtLastName;
        wxTextCtrl* txtUri;
        wxPanel* panelWriteSMS;
        wxButton* btnStartDedicatedEmulation;
        wxStaticText* StaticText32;
        wxStaticText* StaticText8;
        wxTextCtrl* txtOpenArg;
        wxStaticText* StaticText11;
        wxButton* btnReadCard;
        wxTextCtrl* txtCompany;
        wxStaticText* StaticText18;
        wxButton* btnStoreVCard;
        wxTextCtrl* txtASCIIPrefix;
        wxTextCtrl* txtPrivateEmail;
        wxStaticText* StaticText31;
        wxTextCtrl* txtFirstName;
        wxStaticText* StaticText27;
        wxTextCtrl* txtDLLVer;
        wxButton* btnLockNVMemory;
        wxButton* btnUnlockNVMemory;
        wxStaticBox* StaticBox1;
        wxPanel* panelWriteNFCData;
        wxTextCtrl* txtTitle;
        wxTextCtrl* txtPrivatePhone;
        wxTextCtrl* txtReaderTypeEx;
        wxButton* btnReaderClose;
        wxTextCtrl* txtBluetoothAddress;
        wxStaticText* StaticText21;
        wxStaticBox* StaticBox2;
        wxStaticText* StaticText23;
        wxButton* btnWriteSMS;
        wxButton* btnWriteBluetooth;
        wxStaticText* StaticText24;
        wxTextCtrl* txtResultPayload;
        wxTextCtrl* txtCardType;
        wxTextCtrl* txtFunctionStatus;
        wxButton* btnInitializeNDEF;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxTextCtrl* txtReaderSN;
        wxPanel* panelTools;
        wxStatusBar* StatusBar1;
        wxPanel* panelReadNFCData;
        wxButton* btnStoreURI;
        wxButton* btnReaderOpen;
        wxTextCtrl* txtCardMsgs;
        wxTextCtrl* txtPkgName;
        wxNotebook* ndefOptions;
        wxTextCtrl* txtPassword;
        wxStaticBox* StaticBox3;
        wxStaticText* StaticText28;
        wxCheckBox* checkAdvanced;
        wxTextCtrl* txtWebisteURL;
        wxButton* btnWritePhoneNr;
        wxStaticText* StaticText12;
        wxButton* btnStoreBluetooth;
        wxButton* btnEraseAllRecords;
        wxCheckBox* checkNFCCounter;
        wxTextCtrl* txtCardTNF;
        wxButton* btnStartCombinedEmulation;
        wxTextCtrl* txtPortName;
        wxPanel* Panel10;
        wxTextCtrl* txtDisplayName;
        wxGrid* gridReadNdef;
        wxStaticText* StaticText25;
        wxTextCtrl* txtReadPayload;
        wxNotebook* Notebook2;
        wxButton* btnWriteVCard;
        wxStaticText* labelPortName;
        wxTextCtrl* txtReaderFW;
        wxTextCtrl* txtCellPhone;
        wxStaticText* StaticText17;
        wxButton* btnWriteAAR;
        wxStaticText* labelOpenArg;
        wxPanel* panelWriteBluetooth;
        wxStaticText* labelReaderTypeEx;
        wxStaticText* StaticText16;
        wxTextCtrl* txtBusinessEmail;
        wxPanel* panelWriteVCard;
        wxTextCtrl* txtSMSBody;
        wxStaticBox* StaticBox4;
        wxButton* btnEraseLastRecord;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // UFR_NDEF_EXAMPLES__CPP_WXWIDGETSMAIN_H
