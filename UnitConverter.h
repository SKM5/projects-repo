
// UnitConverter.h : main header file for the UnitConverter application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CUnitConverterApp:
// See UnitConverter.cpp for the implementation of this class
//

class CUnitConverterApp : public CWinApp
{
public:
	CUnitConverterApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUnitConverterApp theApp;
