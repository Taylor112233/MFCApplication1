// CS_ZJ_Dig.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CS_ZJ_Dig.h"
#include "CS_ZJ_SEARCH.h"
#include <fstream>
#include <sstream>
#include <vector>



// CS_ZJ_Dig 对话框

IMPLEMENT_DYNAMIC(CS_ZJ_Dig, CDialogEx)


CS_ZJ_Dig::CS_ZJ_Dig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ZJ, pParent)
{

}

CS_ZJ_Dig::~CS_ZJ_Dig()
{
}

void CS_ZJ_Dig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ZJ, m_list);
}


BEGIN_MESSAGE_MAP(CS_ZJ_Dig, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CS_ZJ_Dig::OnBnClickedCancel)
	ON_BN_CLICKED(IIDC_BUTTON_SEARCH, &CS_ZJ_Dig::OnBnClickedButtonSearch)
	ON_COMMAND(ID_ABOUT, &CS_ZJ_Dig::OnAbout)
	ON_COMMAND(ID_HELP, &CS_ZJ_Dig::OnHelp)
	ON_COMMAND(ID_ZJ, &CS_ZJ_Dig::OnZj)
	ON_COMMAND(ID_YJ, &CS_ZJ_Dig::OnYj)
	ON_COMMAND(ID_MJ, &CS_ZJ_Dig::OnMj)
	ON_COMMAND(ID_LJ, &CS_ZJ_Dig::OnLj)
END_MESSAGE_MAP()


void CS_ZJ_Dig::ReadCSV(const CString& filePath)
{
	std::ifstream file(filePath); // 打开CSV文件
	if (!file.is_open())
	{
		// 处理文件打开失败的情况
		return;
	}

	m_list.DeleteAllItems(); // 清空列表

	std::string line;
	while (std::getline(file, line))
	{
		std::vector<CString> rowData; // 用于存储每行的数据

		std::stringstream ss(line);
		std::string cell;

		while (std::getline(ss, cell, ','))
		{
			rowData.push_back(CString(cell.c_str())); // 将每个单元格的数据添加到rowData中
		}

		if (rowData.size() != 5)
		{
			// 处理CSV文件格式错误的情况
			continue;
		}

		int row = m_list.GetItemCount();
		m_list.InsertItem(row, rowData[0]);

		for (int i = 1; i < 5; ++i)
		{
			m_list.SetItemText(row, i, rowData[i]);
		}
	}

	file.close(); // 关闭文件
}


// CS_ZJ_Dig 消息处理程序


void CS_ZJ_Dig::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	CSystemDig dlg;
	dlg.DoModal();
}


BOOL CS_ZJ_Dig::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//// TODO: 在此添加额外的初始化代码

	CMenu menu;
	m_Menu.LoadMenu(IDR_MENU);  //  IDR_MENU1
	SetMenu(&m_Menu);

	CString str[] = { TEXT("粘接剂"),TEXT("固化时间"),TEXT("零件名称") ,TEXT("材料名称"),TEXT("产品") };

	for (int i = 0; i < 5; i++)
	{
		// 设置表头 参数1 索引 2内容 3对齐方式 4列宽
		m_list.InsertColumn(i, str[i], LVCFMT_CENTER, 100);
	}

	CString csvFilePath = _T("./data/data.csv"); // 设置CSV文件的路径
	ReadCSV(csvFilePath); // 读取并显示CSV文件的内容

	//// 设置正文
	//// 表头不算正文的内容，索引从0开始
	//// m_list.InsertItem(0, TEXT("张三"));
	//int j;
	//for (int i = 0; i < 10; i++)
	//{
	//	j = 0;
	//	CString name;
	//	name.Format(TEXT("张三_%d"), i);
	//	m_list.InsertItem(i, name);
	//	// 性别和年龄
	//	m_list.SetItemText(i, ++j, TEXT("男"));
	//	m_list.SetItemText(i, ++j, TEXT("18"));
	//	m_list.SetItemText(i, ++j, TEXT("180"));
	//}

	// 设置属性 整行选中 显示网格
	m_list.SetExtendedStyle(m_list.GetExtendedStyle()|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);// 列表控件的使用

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CS_ZJ_Dig::OnBnClickedButtonSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	// CDialogEx::OnOK();
	CS_ZJ_SEARCH dlg;
	dlg.DoModal();
}


void CS_ZJ_Dig::OnAbout()
{
	// TODO: 在此添加命令处理程序代码
	CABOUT dlg;
	dlg.DoModal();
}


void CS_ZJ_Dig::OnHelp()
{
	// TODO: 在此添加命令处理程序代码
	CString strFilePath = _T("Help\\""help_ZJ.txt"); // 替换为实际的文件路径
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


void CS_ZJ_Dig::OnZj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_ZJ_Dig dlg;
	dlg.DoModal();
}


void CS_ZJ_Dig::OnYj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_YJ_Dig dlg;
	dlg.DoModal();
}


void CS_ZJ_Dig::OnMj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_MJ_Dig dlg;
	dlg.DoModal();
}


void CS_ZJ_Dig::OnLj()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CS_LJ_MOD_Dig dlg;
	dlg.DoModal();
}
