#ifndef _FUNCTIONSVIEW_H_
#define _FUNCTIONSVIEW_H_

#include "win32/MDIChild.h"
#include "win32/ListView.h"
#include "win32/Button.h"
#include "VerticalLayout.h"
#include "MIPS.h"
#include "ELF.h"
#include "Event.h"

class CFunctionsView : public Framework::CMDIChild
{
public:
								CFunctionsView(HWND, CMIPS*);
								~CFunctionsView();
	void						SetELF(CELF*);
	void						Refresh();

	Framework::CEvent<uint32>	m_OnFunctionDblClick;
	Framework::CEvent<int>		m_OnFunctionsStateChange;

protected:
	long						OnSize(unsigned int, unsigned int, unsigned int);
	long						OnCommand(unsigned short, unsigned short, HWND);
	long						OnNotify(WPARAM, NMHDR*);
	long						OnSysCommand(unsigned int, LPARAM);

private:
	void						CreateListColumns();
	void						ResizeListColumns();
	void						RefreshLayout();
	void						RefreshList();

	void						OnListDblClick();
	void						OnNewClick();
	void						OnDeleteClick();
	void						OnImportClick();

	Framework::CListView*		m_pList;
	Framework::CButton*			m_pNew;
	Framework::CButton*			m_pDelete;
	Framework::CButton*			m_pImport;

	Framework::CVerticalLayout*	m_pLayout;
	CMIPS*						m_pCtx;
	CELF*						m_pELF;
};

#endif