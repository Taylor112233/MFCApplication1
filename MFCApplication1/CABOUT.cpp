// CABOUT.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CABOUT.h"


// CABOUT 对话框

IMPLEMENT_DYNAMIC(CABOUT, CDialogEx)

CABOUT::CABOUT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

CABOUT::~CABOUT()
{
}

void CABOUT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CABOUT, CDialogEx)
END_MESSAGE_MAP()


// CABOUT 消息处理程序
