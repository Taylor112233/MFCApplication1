// CSystemDig.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CSystemDig.h"
#include "MFCApplication1Dlg.h"
#include "CABOUT.h"
#include <Shellapi.h>



// CSystemDig 对话框

IMPLEMENT_DYNAMIC(CSystemDig, CDialogEx)

CSystemDig::CSystemDig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SYSTEM, pParent)
{

}

CSystemDig::~CSystemDig()
{
}

void CSystemDig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(CSystemDig, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ZJ, &CSystemDig::OnBnClickedButtonZj)
	ON_BN_CLICKED(IDC_BUTTON_YJ, &CSystemDig::OnBnClickedButtonYj)
	ON_BN_CLICKED(IDC_BUTTON_MJ, &CSystemDig::OnBnClickedButtonMj)
	ON_BN_CLICKED(IDC_BUTTON_LJ, &CSystemDig::OnBnClickedButtonLj)
	ON_COMMAND(ID_ABOUT, &CSystemDig::OnAbout)
	ON_COMMAND(ID_HELP, &CSystemDig::OnHelp)
	ON_COMMAND(ID_ZJ, &CSystemDig::OnZj)
	ON_COMMAND(ID_YJ, &CSystemDig::OnYj)
	ON_COMMAND(ID_MJ, &CSystemDig::OnMj)
	ON_COMMAND(ID_LJ, &CSystemDig::OnLj)
END_MESSAGE_MAP()


// CSystemDig 消息处理程序


void CSystemDig::OnBnClickedButtonZj()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CS_ZJ_Dig dlg;
	dlg.DoModal();
}


void CSystemDig::OnBnClickedButtonYj()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CS_LJ_MOD_Dig dlg;
	dlg.DoModal();
}


void CSystemDig::OnBnClickedButtonMj()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CS_YJ_Dig dlg;
	dlg.DoModal();
}


void CSystemDig::OnBnClickedButtonLj()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CS_MJ_Dig dlg;
	dlg.DoModal();
}


BOOL CSystemDig::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMenu menu;
	m_Menu.LoadMenu(IDR_MENU);  //  IDR_MENU1
	SetMenu(&m_Menu);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSystemDig::OnAbout()
{
	// TODO: 在此添加命令处理程序代码
	CABOUT dlg;
	dlg.DoModal();

}


void CSystemDig::OnHelp()
{
	CString strFilePath = _T("Help\\""help.txt"); // 替换为实际的文件路径
	SHELLEXECUTEINFO shExInfo = { 0 };
	shExInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	shExInfo.lpFile = strFilePath;
	shExInfo.lpVerb = _T("open");
	shExInfo.nShow = SW_SHOW;

	if (ShellExecuteEx(&shExInfo))
	{
		// 打开成功
	}
	else
	{
		// 打开失败，可以查看GetLastError()函数返回的错误码
		DWORD error = GetLastError();
		CString errorMessage;
		errorMessage.Format(_T("无法打开文件。错误码：%d"), error);
		AfxMessageBox(errorMessage);
	}
}



void CSystemDig::OnZj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_ZJ_Dig dlg;
	dlg.DoModal();
}


void CSystemDig::OnYj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_YJ_Dig dlg;
	dlg.DoModal();
}


void CSystemDig::OnMj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_MJ_Dig dlg;
	dlg.DoModal();
}


void CSystemDig::OnLj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_LJ_MOD_Dig dlg;
	dlg.DoModal();
}
