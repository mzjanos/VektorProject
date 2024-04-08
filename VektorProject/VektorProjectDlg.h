
// VektorProjectDlg.h: Headerdatei
//

#pragma once
#include <vector>
#include "Headerdateien/m_vector.h"
// CVektorProjectDlg-Dialogfeld
class CVektorProjectDlg : public CDialogEx
{
// Konstruktion
public:
	CVektorProjectDlg(CWnd* pParent = nullptr);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VEKTORPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	virtual void OnOk() {}
private: 
	int status = 0;
	std::vector<m_vector<double>> file_content;
	std::vector<m_vector<double>> vectors;
// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButton1();
	CString text_input_value;
	CButton button;
};
