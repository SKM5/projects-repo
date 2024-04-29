
// ChildView.cpp : implementation of the CChildView class
//
//Adding comment to make new submition within GitHub 

#include "pch.h"
#include "framework.h"
#include "UnitConverter.h"
#include "ChildView.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "UnitConverterDlg.h"


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()	
	ON_COMMAND(ID_BUTTON_UNITCONVERTER, &CChildView::OnButtonUnitConverter)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_unitConverter.Create(TEXT("Lenght Converter"), WS_BORDER | WS_CHILD | WS_VISIBLE, CRect(100, 120, 250, 220), this, ID_BUTTON_UNITCONVERTER);

	return 0;
}


void CChildView::OnButtonUnitConverter()
{
	// TODO: Add your command handler code here
	CUnitConverterDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		//dlg.CreateControl()
	}
}
