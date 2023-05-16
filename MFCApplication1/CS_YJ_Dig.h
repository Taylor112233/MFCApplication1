#pragma once
#include "afxdialogex.h"
#include "CSystemDig.h"
#include "CABOUT.h"


// CS_YJ_Dig 对话框

class CS_YJ_Dig : public CDialogEx
{
	DECLARE_DYNAMIC(CS_YJ_Dig)

public:
	CS_YJ_Dig(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CS_YJ_Dig();
	CMenu m_Menu;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_YJ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnAbout();
	afx_msg void OnHelp();
	afx_msg void OnZj();
	afx_msg void OnYj();
	afx_msg void OnMj();
	afx_msg void OnLj();
};
