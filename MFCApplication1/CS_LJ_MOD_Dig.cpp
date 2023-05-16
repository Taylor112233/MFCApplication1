// CS_LJ_MOD_Dig.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CS_LJ_MOD_Dig.h"


// CS_LJ_MOD_Dig 对话框

IMPLEMENT_DYNAMIC(CS_LJ_MOD_Dig, CDialogEx)

CS_LJ_MOD_Dig::CS_LJ_MOD_Dig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LJ_MOD, pParent)
{

}

CS_LJ_MOD_Dig::~CS_LJ_MOD_Dig()
{
}

void CS_LJ_MOD_Dig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CS_LJ_MOD_Dig, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_norm, &CS_LJ_MOD_Dig::OnBnClickedButtonnorm)
	ON_BN_CLICKED(IDC_BUTTON_unnorm, &CS_LJ_MOD_Dig::OnBnClickedButtonunnorm)
	ON_BN_CLICKED(IDCANCEL, &CS_LJ_MOD_Dig::OnBnClickedCancel)
END_MESSAGE_MAP()


// CS_LJ_MOD_Dig 消息处理程序


void CS_LJ_MOD_Dig::OnBnClickedButtonnorm()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CS_LJ_Dig dlg;
	dlg.DoModal();
}


void CS_LJ_MOD_Dig::OnBnClickedButtonunnorm()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CS_LJ_unnorm_Dig dlg;
	dlg.DoModal();
}


void CS_LJ_MOD_Dig::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	CSystemDig dlg;
	dlg.DoModal();
	// HANDLE MyProcess = GetCurrentProcess();
	// TerminateProcess(MyProcess,0);
	// return;
}
