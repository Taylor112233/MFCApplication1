// CS_YJ_Dig.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CS_YJ_Dig.h"


// CS_YJ_Dig 对话框

IMPLEMENT_DYNAMIC(CS_YJ_Dig, CDialogEx)

CS_YJ_Dig::CS_YJ_Dig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_YJ, pParent)
{

}

CS_YJ_Dig::~CS_YJ_Dig()
{
}

void CS_YJ_Dig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CS_YJ_Dig, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CS_YJ_Dig::OnBnClickedCancel)
	ON_COMMAND(ID_ABOUT, &CS_YJ_Dig::OnAbout)
	ON_COMMAND(ID_HELP, &CS_YJ_Dig::OnHelp)
	ON_COMMAND(ID_ZJ, &CS_YJ_Dig::OnZj)
	ON_COMMAND(ID_YJ, &CS_YJ_Dig::OnYj)
	ON_COMMAND(ID_MJ, &CS_YJ_Dig::OnMj)
	ON_COMMAND(ID_LJ, &CS_YJ_Dig::OnLj)
END_MESSAGE_MAP()


// CS_YJ_Dig 消息处理程序


void CS_YJ_Dig::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	CSystemDig dlg;
	dlg.DoModal();
}


BOOL CS_YJ_Dig::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMenu menu;
	m_Menu.LoadMenu(IDR_MENU);  //  IDR_MENU1
	SetMenu(&m_Menu);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CS_YJ_Dig::OnAbout()
{
	// TODO: 在此添加命令处理程序代码
	CABOUT dlg;
	dlg.DoModal();
}


void CS_YJ_Dig::OnHelp()
{
	// TODO: 在此添加命令处理程序代码
	CString strFilePath = _T("Help\\""help_YJ.txt"); // 替换为实际的文件路径
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


void CS_YJ_Dig::OnZj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_ZJ_Dig dlg;
	dlg.DoModal();
}


void CS_YJ_Dig::OnYj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_YJ_Dig dlg;
	dlg.DoModal();
}


void CS_YJ_Dig::OnMj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_MJ_Dig dlg;
	dlg.DoModal();
}


void CS_YJ_Dig::OnLj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_LJ_MOD_Dig dlg;
	dlg.DoModal();
}
