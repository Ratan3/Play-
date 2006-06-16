#include <stdio.h>
#include "ELFProgramView.h"
#include "PtrMacro.h"
#include "LayoutStretch.h"
#include "win32/Static.h"
#include "win32/LayoutWindow.h"

#define CLSNAME	_X("CELFProgramView")

using namespace Framework;

CELFProgramView::CELFProgramView(HWND hParent, CELF* pELF, uint16 nProgram)
{
	RECT rc;

	if(!DoesWindowClassExist(CLSNAME))
	{
		WNDCLASSEX wc;
		memset(&wc, 0, sizeof(WNDCLASSEX));
		wc.cbSize			= sizeof(WNDCLASSEX);
		wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW); 
		wc.hInstance		= GetModuleHandle(NULL);
		wc.lpszClassName	= CLSNAME;
		wc.lpfnWndProc		= CWindow::WndProc;
		RegisterClassEx(&wc);
	}

	m_pELF = pELF;
	m_nProgram = nProgram;

	SetRect(&rc, 0, 0, 1, 1);

	Create(NULL, CLSNAME, _X(""), WS_CHILD | WS_DISABLED | WS_CLIPCHILDREN, &rc, hParent, NULL);
	SetClassPtr();

	m_pType		= new CEdit(m_hWnd, &rc, _X(""), ES_READONLY);
	m_pOffset	= new CEdit(m_hWnd, &rc, _X(""), ES_READONLY);
	m_pVAddr	= new CEdit(m_hWnd, &rc, _X(""), ES_READONLY);
	m_pPAddr	= new CEdit(m_hWnd, &rc, _X(""), ES_READONLY);
	m_pFileSize	= new CEdit(m_hWnd, &rc, _X(""), ES_READONLY);
	m_pMemSize	= new CEdit(m_hWnd, &rc, _X(""), ES_READONLY);
	m_pFlags	= new CEdit(m_hWnd, &rc, _X(""), ES_READONLY);
	m_pAlign	= new CEdit(m_hWnd, &rc, _X(""), ES_READONLY);

	m_pLayout = new CGridLayout(2, 9);

	m_pLayout->SetObject(0, 0, CLayoutWindow::CreateTextBoxBehavior(100, 20, new CStatic(m_hWnd, _X("Type:"))));
	m_pLayout->SetObject(0, 1, CLayoutWindow::CreateTextBoxBehavior(100, 20, new CStatic(m_hWnd, _X("Offset:"))));
	m_pLayout->SetObject(0, 2, CLayoutWindow::CreateTextBoxBehavior(100, 20, new CStatic(m_hWnd, _X("Virtual Address:"))));
	m_pLayout->SetObject(0, 3, CLayoutWindow::CreateTextBoxBehavior(100, 20, new CStatic(m_hWnd, _X("Physical Address:"))));
	m_pLayout->SetObject(0, 4, CLayoutWindow::CreateTextBoxBehavior(100, 20, new CStatic(m_hWnd, _X("File Size:"))));
	m_pLayout->SetObject(0, 5, CLayoutWindow::CreateTextBoxBehavior(100, 20, new CStatic(m_hWnd, _X("Memory Size:"))));
	m_pLayout->SetObject(0, 6, CLayoutWindow::CreateTextBoxBehavior(100, 20, new CStatic(m_hWnd, _X("Flags:"))));
	m_pLayout->SetObject(0, 7, CLayoutWindow::CreateTextBoxBehavior(100, 20, new CStatic(m_hWnd, _X("Alignment:"))));

	m_pLayout->SetObject(1, 0, CLayoutWindow::CreateTextBoxBehavior(100, 20, m_pType));
	m_pLayout->SetObject(1, 1, CLayoutWindow::CreateTextBoxBehavior(100, 20, m_pOffset));
	m_pLayout->SetObject(1, 2, CLayoutWindow::CreateTextBoxBehavior(100, 20, m_pVAddr));
	m_pLayout->SetObject(1, 3, CLayoutWindow::CreateTextBoxBehavior(100, 20, m_pPAddr));
	m_pLayout->SetObject(1, 4, CLayoutWindow::CreateTextBoxBehavior(100, 20, m_pFileSize));
	m_pLayout->SetObject(1, 5, CLayoutWindow::CreateTextBoxBehavior(100, 20, m_pMemSize));
	m_pLayout->SetObject(1, 6, CLayoutWindow::CreateTextBoxBehavior(100, 20, m_pFlags));
	m_pLayout->SetObject(1, 7, CLayoutWindow::CreateTextBoxBehavior(100, 20, m_pAlign));
	m_pLayout->SetObject(1, 8, new CLayoutStretch);

	FillInformation();

	RefreshLayout();

}

CELFProgramView::~CELFProgramView()
{
	Destroy();
	DELETEPTR(m_pLayout);
}

long CELFProgramView::OnSize(unsigned int nType, unsigned int nX, unsigned int nY)
{
	RefreshLayout();
	return TRUE;
}

void CELFProgramView::FillInformation()
{
	ELFPROGRAMHEADER* pH;
	xchar sTemp[256];
	
	pH = m_pELF->GetProgram(m_nProgram);

	switch(pH->nType)
	{
	case 0x00:
		xstrcpy(sTemp, _X("PT_NULL"));
		break;
	case 0x01:
		xstrcpy(sTemp, _X("PT_LOAD"));
		break;
	case 0x02:
		xstrcpy(sTemp, _X("PT_DYNAMIC"));
		break;
	case 0x03:
		xstrcpy(sTemp, _X("PT_INTERP"));
		break;
	case 0x04:
		xstrcpy(sTemp, _X("PT_NOTE"));
		break;
	case 0x05:
		xstrcpy(sTemp, _X("PT_SHLIB"));
		break;
	case 0x06:
		xstrcpy(sTemp, _X("PT_PHDR"));
		break;
	default:
		xsnprintf(sTemp, countof(sTemp), _X("Unknown (0x%0.8X)"), pH->nType);
		break;
	}
	m_pType->SetText(sTemp);

	xsnprintf(sTemp, countof(sTemp), _X("0x%0.8X"), pH->nOffset);
	m_pOffset->SetText(sTemp);

	xsnprintf(sTemp, countof(sTemp), _X("0x%0.8X"), pH->nVAddress);
	m_pVAddr->SetText(sTemp);

	xsnprintf(sTemp, countof(sTemp), _X("0x%0.8X"), pH->nPAddress);
	m_pPAddr->SetText(sTemp);

	xsnprintf(sTemp, countof(sTemp), _X("0x%0.8X"), pH->nFileSize);
	m_pFileSize->SetText(sTemp);

	xsnprintf(sTemp, countof(sTemp), _X("0x%0.8X"), pH->nMemorySize);
	m_pMemSize->SetText(sTemp);

	xsnprintf(sTemp, countof(sTemp), _X("0x%0.8X"), pH->nFlags);
	m_pFlags->SetText(sTemp);

	xsnprintf(sTemp, countof(sTemp), _X("0x%0.8X"), pH->nAlignment);
	m_pAlign->SetText(sTemp);
}

void CELFProgramView::RefreshLayout()
{
	RECT rc;
	::GetClientRect(GetParent(), &rc);

	SetPosition(0, 0);
	SetSize(rc.right, rc.bottom);

	GetClientRect(&rc);

	SetRect(&rc, rc.left + 10, rc.top + 10, rc.right - 10, rc.bottom + m_pLayout->GetPreferredHeight());

	m_pLayout->SetRect(rc.left, rc.top, rc.right, rc.bottom);
	m_pLayout->RefreshGeometry();

	Redraw();
}