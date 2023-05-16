// CS_LJ_unnorm_Dig.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CS_LJ_unnorm_Dig.h"


// CS_LJ_unnorm_Dig 对话框

IMPLEMENT_DYNAMIC(CS_LJ_unnorm_Dig, CDialogEx)

CS_LJ_unnorm_Dig::CS_LJ_unnorm_Dig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LJ_unnorm, pParent)
{

}

CS_LJ_unnorm_Dig::~CS_LJ_unnorm_Dig()
{
}

void CS_LJ_unnorm_Dig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CS_LJ_unnorm_Dig, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CS_LJ_unnorm_Dig::OnBnClickedCancel)
	ON_COMMAND(ID_ABOUT, &CS_LJ_unnorm_Dig::OnAbout)
	ON_COMMAND(ID_HELP, &CS_LJ_unnorm_Dig::OnHelp)
	ON_COMMAND(ID_ZJ, &CS_LJ_unnorm_Dig::OnZj)
	ON_COMMAND(ID_YJ, &CS_LJ_unnorm_Dig::OnYj)
	ON_COMMAND(ID_MJ, &CS_LJ_unnorm_Dig::OnMj)
	ON_COMMAND(ID_LJ, &CS_LJ_unnorm_Dig::OnLj)
END_MESSAGE_MAP()


// CS_LJ_unnorm_Dig 消息处理程序


void CS_LJ_unnorm_Dig::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	CSystemDig dlg;
	dlg.DoModal();

}


BOOL CS_LJ_unnorm_Dig::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMenu menu;
	m_Menu.LoadMenu(IDR_MENU);  //  IDR_MENU1
	SetMenu(&m_Menu);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CS_LJ_unnorm_Dig::OnAbout()
{
	// TODO: 在此添加命令处理程序代码
	CABOUT dlg;
	dlg.DoModal();
}


void CS_LJ_unnorm_Dig::OnHelp()
{
	// TODO: 在此添加命令处理程序代码
	CString strFilePath = _T("Help\\""help_LJ_unnorm.txt"); // 替换为实际的文件路径
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


void CS_LJ_unnorm_Dig::OnZj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_ZJ_Dig dlg;
	dlg.DoModal();
}


void CS_LJ_unnorm_Dig::OnYj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_YJ_Dig dlg;
	dlg.DoModal();
}


void CS_LJ_unnorm_Dig::OnMj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_MJ_Dig dlg;
	dlg.DoModal();
}


void CS_LJ_unnorm_Dig::OnLj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_LJ_MOD_Dig dlg;
	dlg.DoModal();
}
