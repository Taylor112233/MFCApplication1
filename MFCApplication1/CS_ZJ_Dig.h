#pragma once
#include "afxdialogex.h"
#include "CSystemDig.h"
#include "CABOUT.h"

// CS_ZJ_Dig 对话框

class CS_ZJ_Dig : public CDialogEx
{
	DECLARE_DYNAMIC(CS_ZJ_Dig)

public:
	CS_ZJ_Dig(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CS_ZJ_Dig();
	CMenu m_Menu;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ZJ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
	void ReadCSV(const CString& filePath);
	void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
private:
	CListCtrl m_list;
public:
	afx_msg void OnBnClickedButtonSearch();
	afx_msg void OnAbout();
	afx_msg void OnHelp();
	afx_msg void OnZj();
	afx_msg void OnYj();
	afx_msg void OnMj();
	afx_msg void OnLj();
};
