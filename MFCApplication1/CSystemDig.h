#pragma once
#include "afxdialogex.h"
#include "CS_ZJ_Dig.h"
#include "CS_YJ_Dig.h"
#include "CS_LJ_MOD_Dig.h"
#include "CS_MJ_Dig.h"

// CSystemDig 对话框

class CSystemDig : public CDialogEx
{
	DECLARE_DYNAMIC(CSystemDig)

public:
	CSystemDig(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSystemDig();
	CMenu m_Menu;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SYSTEM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonZj();
	afx_msg void OnBnClickedButtonYj();
	afx_msg void OnBnClickedButtonMj();
	afx_msg void OnBnClickedButtonLj();
	virtual BOOL OnInitDialog();
	afx_msg void OnAbout();
	afx_msg void OnHelp();
	afx_msg void OnZj();
	afx_msg void OnYj();
	afx_msg void OnMj();
	afx_msg void OnLj();
};
