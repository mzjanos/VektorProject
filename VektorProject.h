
// VektorProject.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CVektorProjectApp:
// Siehe VektorProject.cpp für die Implementierung dieser Klasse
//

class CVektorProjectApp : public CWinApp
{
public:
	CVektorProjectApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CVektorProjectApp theApp;
