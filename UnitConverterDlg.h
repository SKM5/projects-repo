#pragma once
#include <CString>

// CUnitConverterDlg dialog

class CUnitConverterDlg : public CDialog
{
	DECLARE_DYNAMIC(CUnitConverterDlg)

public:
	CUnitConverterDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUnitConverterDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UNITCONVERTER_DLG};
#endif


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:

	CButton m_Convert;
	CString m_lstFrom;
	CString m_lstTo;
	CListBox m_lbFrom;
	CListBox m_lbTo;

	double m_editFrom;
	double m_editTo;
	int m_inputVal;

	CEdit m_ebCtrlFrom;
	CEdit m_ebCtrlTo;

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedConvertUnit();

	void LengthUnitConversion();

};
