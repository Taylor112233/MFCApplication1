#pragma once
#include "afxdialogex.h"
#include "CS_LJ_Dig.h"
#include "CS_LJ_unnorm_Dig.h"


// CS_LJ_MOD_Dig 对话框

class CS_LJ_MOD_Dig : public CDialogEx
{
	DECLARE_DYNAMIC(CS_LJ_MOD_Dig)

public:
	CS_LJ_MOD_Dig(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CS_LJ_MOD_Dig();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LJ_MOD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonnorm();
	afx_msg void OnBnClickedButtonunnorm();
	afx_msg void OnBnClickedCancel();
};
