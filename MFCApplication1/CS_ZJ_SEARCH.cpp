// CS_ZJ_SEARCH.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CS_ZJ_SEARCH.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<std::vector<CString>> m_data;

// CS_ZJ_SEARCH 对话框

IMPLEMENT_DYNAMIC(CS_ZJ_SEARCH, CDialogEx)

CS_ZJ_SEARCH::CS_ZJ_SEARCH(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ZJ_SEARCH, pParent)
{

}

CS_ZJ_SEARCH::~CS_ZJ_SEARCH()
{
}

void CS_ZJ_SEARCH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SEARCH, m_list);
}


BEGIN_MESSAGE_MAP(CS_ZJ_SEARCH, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_SEARCH1, &CS_ZJ_SEARCH::OnBnClickedButtonSearch1)
    ON_BN_CLICKED(IIDC_BUTTON_SEARCH2, &CS_ZJ_SEARCH::OnBnClickedButtonSearch2)
    ON_BN_CLICKED(IDC_BUTTON_SEARCH3, &CS_ZJ_SEARCH::OnBnClickedButtonSearch3)
    ON_BN_CLICKED(IDC_BUTTON_SEARCH4, &CS_ZJ_SEARCH::OnBnClickedButtonSearch4)
    ON_BN_CLICKED(IDC_BUTTON_del, &CS_ZJ_SEARCH::OnBnClickedButtondel)
    ON_BN_CLICKED(IDC_BUTTON_UNCHOOSE, &CS_ZJ_SEARCH::OnBnClickedButtonUnchoose)
    ON_BN_CLICKED(IDC_BUTTON_CHOOSE, &CS_ZJ_SEARCH::OnBnClickedButtonChoose)
    ON_BN_CLICKED(IDC_BUTTON_SEARCH5, &CS_ZJ_SEARCH::OnBnClickedButtonSearch5)
END_MESSAGE_MAP()


// CS_ZJ_SEARCH 消息处理程序

void CS_ZJ_SEARCH::ReadCSV(const CString& filePath)
{
    std::ifstream file(filePath); // 打开CSV文件
    if (!file.is_open())
    {
        // 处理文件打开失败的情况
        return;
    }

    m_list.DeleteAllItems(); // 清空列表
    m_data.clear(); // 清空数据

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

        m_data.push_back(rowData); // 将每行数据存储到m_data中

        int row = m_list.GetItemCount();
        m_list.InsertItem(row, rowData[0]);

        for (int i = 1; i < 5; ++i)
        {
            m_list.SetItemText(row, i, rowData[i]);
        }
    }

    file.close(); // 关闭文件
}

    void CS_ZJ_SEARCH::OnBnClickedButtonSearch1()
    {
        CString keyword;
        GetDlgItemText(IDC_EDIT_SEARCH1, keyword); // 获取搜索关键字

        m_list.DeleteAllItems(); // 清空列表

        for (const auto& rowData : m_data)
        {
            // 在姓名、性别、年龄、身高这四个字段中进行匹配
            if (rowData[0].Find(keyword) != -1 )
            {
                int row = m_list.GetItemCount();
                m_list.InsertItem(row, rowData[0]);

                for (int i = 1; i < 5; ++i)
                {
                    m_list.SetItemText(row, i, rowData[i]);
                }
            }
        }
    }


    void CS_ZJ_SEARCH::OnBnClickedButtonSearch2()
    {
        // TODO: 在此添加控件通知处理程序代码
        CString keyword;
        GetDlgItemText(IDC_EDIT_SEARCH2, keyword); // 获取搜索关键字

        m_list.DeleteAllItems(); // 清空列表

        for (const auto& rowData : m_data)
        {
            // 在姓名、性别、年龄、身高这四个字段中进行匹配
            if (rowData[1].Find(keyword) != -1)
            {
                int row = m_list.GetItemCount();
                m_list.InsertItem(row, rowData[0]);

                for (int i = 1; i < 5; ++i)
                {
                    m_list.SetItemText(row, i, rowData[i]);
                }
            }
        }
    }


    void CS_ZJ_SEARCH::OnBnClickedButtonSearch3()
    {
        // TODO: 在此添加控件通知处理程序代码
        CString keyword;
        GetDlgItemText(IDC_EDIT_SEARCH3, keyword); // 获取搜索关键字

        m_list.DeleteAllItems(); // 清空列表

        for (const auto& rowData : m_data)
        {
            // 在姓名、性别、年龄、身高这四个字段中进行匹配
            if (rowData[2].Find(keyword) != -1)
            {
                int row = m_list.GetItemCount();
                m_list.InsertItem(row, rowData[0]);

                for (int i = 1; i < 5; ++i)
                {
                    m_list.SetItemText(row, i, rowData[i]);
                }
            }
        }
    }


    void CS_ZJ_SEARCH::OnBnClickedButtonSearch4()
    {
        // TODO: 在此添加控件通知处理程序代码
        CString keyword;
        GetDlgItemText(IDC_EDIT_SEARCH4, keyword); // 获取搜索关键字

        m_list.DeleteAllItems(); // 清空列表

        for (const auto& rowData : m_data)
        {
            // 在姓名、性别、年龄、身高这四个字段中进行匹配
            if (rowData[3].Find(keyword) != -1)
            {
                int row = m_list.GetItemCount();
                m_list.InsertItem(row, rowData[0]);

                for (int i = 1; i < 5; ++i)
                {
                    m_list.SetItemText(row, i, rowData[i]);
                }
            }
        }
    }


    void CS_ZJ_SEARCH::OnBnClickedButtonSearch5()
    {
        // TODO: 在此添加控件通知处理程序代码
        CString keyword;
        GetDlgItemText(IDC_EDIT_SEARCH5, keyword); // 获取搜索关键字

        m_list.DeleteAllItems(); // 清空列表

        for (const auto& rowData : m_data)
        {
            // 在姓名、性别、年龄、身高这四个字段中进行匹配
            if (rowData[4].Find(keyword) != -1)
            {
                int row = m_list.GetItemCount();
                m_list.InsertItem(row, rowData[0]);

                for (int i = 1; i < 5; ++i)
                {
                    m_list.SetItemText(row, i, rowData[i]);
                }
            }
        }

    }



    void CS_ZJ_SEARCH::OnBnClickedButtondel()
    {
        // TODO: 在此添加控件通知处理程序代码
        SetDlgItemText(IDC_EDIT_SEARCH1, _T(""));
        SetDlgItemText(IDC_EDIT_SEARCH2, _T(""));
        SetDlgItemText(IDC_EDIT_SEARCH3, _T(""));
        SetDlgItemText(IDC_EDIT_SEARCH4, _T(""));
        SetDlgItemText(IDC_EDIT_SEARCH5, _T(""));
        m_list.DeleteAllItems(); // 清空列表

    }


    void CS_ZJ_SEARCH::OnBnClickedButtonChoose()
    {
        // TODO: 在此添加控件通知处理程序代码
        for (int i = 0; i < m_list.GetItemCount(); i++)
        {
            m_list.SetCheck(i, TRUE);
        }
    }

    void CS_ZJ_SEARCH::OnBnClickedButtonUnchoose()
    {
        // TODO: 在此添加控件通知处理程序代码
        for (int i = 0; i < m_list.GetItemCount(); i++)
        {
            if (m_list.GetCheck(i) == FALSE)  //未被选中的
            {
                m_list.SetCheck(i, TRUE);
            }
            else  //选中的
            {
                m_list.SetCheck(i, FALSE);
            }
        }
    }

    BOOL CS_ZJ_SEARCH::OnInitDialog()
    {
        CDialogEx::OnInitDialog();

        // TODO:  在此添加额外的初始化
        CString str[] = { TEXT("粘接剂"),TEXT("固化时间"),TEXT("零件名称") ,TEXT("材料名称"),TEXT("产品") };

        for (int i = 0; i < 5; i++)
        {
            // 设置表头 参数1 索引 2内容 3对齐方式 4列宽
            m_list.InsertColumn(i, str[i], LVCFMT_CENTER, 110);
        }

        CString csvFilePath = _T("./data/data.csv"); // 设置CSV文件的路径
        ReadCSV(csvFilePath); // 读取并显示CSV文件的内容
        m_list.DeleteAllItems(); // 清空列表

        m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);// 列表控件的使用
        return TRUE;  // return TRUE unless you set the focus to a control
        // 异常: OCX 属性页应返回 FALSE
    }
  


