#pragma once
#include "afxdialogex.h"
#include <vector>


// CS_ZJ_SEARCH 对话框

class CS_ZJ_SEARCH : public CDialogEx
{
	DECLARE_DYNAMIC(CS_ZJ_SEARCH)
private:
	std::vector<std::vector<CString>> m_data;

public:
	CS_ZJ_SEARCH(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CS_ZJ_SEARCH();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ZJ_SEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void ReadCSV(const CString& filePath);
	void SearchByName(const CString& name);
private:
	CListCtrl m_list;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSearch1();
	afx_msg void OnBnClickedButtonSearch2();
	afx_msg void OnBnClickedButtonSearch3();
	afx_msg void OnBnClickedButtonSearch4();
	afx_msg void OnBnClickedButtondel();
	afx_msg void OnBnClickedAbort();
	afx_msg void OnBnClickedButtonUnchoose();
	afx_msg void OnBnClickedButtonChoose();
	afx_msg void OnEnChangeEditSearch5();
	afx_msg void OnBnClickedButtonSearch5();
};
