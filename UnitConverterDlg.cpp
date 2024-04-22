// UnitConverterDlg.cpp : implementation file
//

#include "pch.h"
#include "UnitConverter.h"
#include "UnitConverterDlg.h"
#include "afxdialogex.h"
#include "resource.h"

// CUnitConverterDlg dialog

IMPLEMENT_DYNAMIC(CUnitConverterDlg, CDialog)

CUnitConverterDlg::CUnitConverterDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_UNITCONVERTER_DLG, pParent)	
	, m_lstFrom(_T(""))
	, m_lstTo(_T(""))
	, m_editFrom(0)
	, m_editTo(0)
{

}

CUnitConverterDlg::~CUnitConverterDlg()
{
}

void CUnitConverterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, ID_CONVERT_UNIT, m_Convert);
	DDX_LBString(pDX, IDC_LIST_FROM, m_lstFrom);
	DDX_LBString(pDX, IDC_LIST_TO, m_lstTo);	
	DDX_Control(pDX, IDC_LIST_FROM, m_lbFrom);
	DDX_Control(pDX, IDC_LIST_TO, m_lbTo);
	DDX_Control(pDX, IDC_EDIT_FROM, m_ebCtrlFrom);
	DDX_Control(pDX, IDC_EDIT_TO, m_ebCtrlTo);
	DDX_Text(pDX, IDC_EDIT_FROM, m_editFrom);
	DDX_Text(pDX, IDC_EDIT_TO, m_editTo);
}


BEGIN_MESSAGE_MAP(CUnitConverterDlg, CDialog)
	ON_WM_CREATE()
	ON_BN_CLICKED(ID_CONVERT_UNIT, &CUnitConverterDlg::OnClickedConvertUnit)
END_MESSAGE_MAP()


// CUnitConverterDlg message handlers


int CUnitConverterDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	

	return 0;
}


BOOL CUnitConverterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	/*CListBox *plstFrom = dynamic_cast<CListBox*> (GetDlgItem(IDC_LIST_FROM));
	plstFrom->AddString(TEXT("meter"));
	plstFrom->AddString(TEXT("cm"));
	plstFrom->AddString(TEXT("mm"));
	plstFrom->AddString(TEXT("km"));*/

	/*CListBox* plstTo = dynamic_cast<CListBox*> (GetDlgItem(IDC_LIST_TO));
	plstTo->AddString(TEXT("meter"));
	plstTo->AddString(TEXT("cm"));
	plstTo->AddString(TEXT("mm"));
	plstTo->AddString(TEXT("km"));*/

	m_lbFrom.AddString(TEXT("meter"));
	m_lbFrom.AddString(TEXT("cm"));
	m_lbFrom.AddString(TEXT("mm"));
	m_lbFrom.AddString(TEXT("km"));
	
	m_lbTo.AddString(TEXT("meter"));
	m_lbTo.AddString(TEXT("cm"));
	m_lbTo.AddString(TEXT("mm"));
	m_lbTo.AddString(TEXT("km"));	
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CUnitConverterDlg::LengthUnitConversion()
{
	// From meter to meter or km to km or same unit conversion
	if (m_lstFrom.CompareNoCase(m_lstTo.GetString()) == 0)
	{
		m_editTo = m_editFrom;		
		return;
	}

	// From km to meter / cm / mm
	if (m_lstFrom.CompareNoCase(TEXT("km")) == 0)
	{
		if (m_lstTo.CompareNoCase(TEXT("meter")) == 0)
		{
			m_editTo = m_editFrom * 1000;
		}
		else if (m_lstTo.CompareNoCase(TEXT("cm")) == 0)
		{
			m_editTo = m_editFrom * 1000 * 100;
		}
		else if (m_lstTo.CompareNoCase(TEXT("mm")) == 0)
		{
			m_editTo = m_editFrom * 1000 * 100 * 10;
		}
	}

	// From meter to cm / mm / km
	if (m_lstFrom.CompareNoCase(TEXT("meter")) == 0)
	{
		if (m_lstTo.CompareNoCase(TEXT("km")) == 0)
		{
			m_editTo = m_editFrom / 100;
		}
		else if (m_lstTo.CompareNoCase(TEXT("cm")) == 0)
		{
			m_editTo = m_editFrom * 100;
		}
		else if (m_lstTo.CompareNoCase(TEXT("mm")) == 0)
		{
			m_editTo = m_editFrom * 100 * 10;
		}
	}

	// From cm to meter / mm / km
	if (m_lstFrom.CompareNoCase(TEXT("cm")) == 0)
	{
		if (m_lstTo.CompareNoCase(TEXT("km")) == 0)
		{
			m_editTo = m_editFrom / 1000;
		}
		else if (m_lstTo.CompareNoCase(TEXT("meter")) == 0)
		{
			m_editTo = m_editFrom / 100;
		}
		else if (m_lstTo.CompareNoCase(TEXT("mm")) == 0)
		{
			m_editTo = m_editFrom * 10;
		}
	}

	// From mm to meter / cm / km
	if (m_lstFrom.CompareNoCase(TEXT("mm")) == 0)
	{
		if (m_lstTo.CompareNoCase(TEXT("km")) == 0)
		{
			m_editTo = m_editFrom / (1000 * 100 * 10);
		}
		else if (m_lstTo.CompareNoCase(TEXT("meter")) == 0)
		{
			m_editTo = m_editFrom / (100 * 10);
		}
		else if (m_lstTo.CompareNoCase(TEXT("cm")) == 0)
		{
			m_editTo = m_editFrom / 10;
		}
	}
}

void CUnitConverterDlg::OnClickedConvertUnit()
{
	// TODO: Add your control notification handler code here
	
	//Reading input value from Editbox

	CString strVal;
	m_ebCtrlFrom.GetWindowText(strVal);	
	m_editFrom = _tstof(strVal);
	
	
	//int index;
	int iSelection = m_lbFrom.GetCurSel();

	m_lbFrom.GetText(iSelection, m_lstFrom);	
	
	iSelection = m_lbTo.GetCurSel();
	m_lbTo.GetText(iSelection, m_lstTo);	
	
	LengthUnitConversion();

	CString strOut;
	strOut.Format(_T("%lf"), m_editTo);
	m_ebCtrlTo.SetWindowTextW(strOut);	
	Invalidate();

}

