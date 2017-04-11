#ifndef BYOCONF_H
#define BYOCONF_H

#include <wx/intl.h>
#include "configurationpanel.h"

class wxCommandEvent;
class wxFlexGridSizer;
class wxStaticBoxSizer;
class wxCheckBox;
class wxSpinCtrl;
class wxStaticText;
class wxButton;

class byoConf: public cbConfigurationPanel
{
	public:

		byoConf(wxWindow* parent,wxWindowID id = -1);
		virtual ~byoConf();

        wxString GetTitle() const { return _("C::B games"); }
        wxString GetBitmapBaseName() const { return _T("generic-plugin"); }
        void OnApply();
        void OnCancel(){}

	protected:

		//(*Identifiers(byoConf)
		static const long ID_CHECKBOX1;
		static const long ID_SPINCTRL1;
		static const long ID_CHECKBOX2;
		static const long ID_SPINCTRL2;
		static const long ID_CHECKBOX3;
		static const long ID_SPINCTRL3;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT3;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT4;
		static const long ID_BUTTON4;
		static const long ID_STATICTEXT5;
		static const long ID_BUTTON5;
		static const long ID_STATICTEXT6;
		static const long ID_BUTTON6;
		//*)
		//(*Handlers(byoConf)
		void BTWSRefresh(wxCommandEvent& event);
		void ColChangeClick(wxCommandEvent& event);
		//*)
		//(*Declarations(byoConf)
		wxStaticBoxSizer* StaticBoxSizer2;
		wxButton* m_Col1;
		wxStaticText* StaticText2;
		wxFlexGridSizer* FlexGridSizer3;
		wxCheckBox* m_OverworkChk;
		wxStaticText* StaticText6;
		wxCheckBox* m_MaxPlaytimeChk;
		wxButton* m_Col6;
		wxFlexGridSizer* FlexGridSizer2;
		wxStaticText* StaticText1;
		wxButton* m_Col2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText5;
		wxCheckBox* m_MinWorkChk;
		wxSpinCtrl* m_MinWorkSpn;
		wxButton* m_Col3;
		wxButton* m_Col4;
		wxStaticBoxSizer* StaticBoxSizer1;
		wxFlexGridSizer* FlexGridSizer1;
		wxSpinCtrl* m_OverworkSpn;
		wxButton* m_Col5;
		wxStaticText* StaticText4;
		wxSpinCtrl* m_MaxPlaytimeSpn;
		//*)

	private:

		DECLARE_EVENT_TABLE()
};

#endif // BYOCONF_H
