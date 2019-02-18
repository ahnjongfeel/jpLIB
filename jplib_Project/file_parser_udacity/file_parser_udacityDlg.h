
// file_parser_udacityDlg.h: 헤더 파일
//

#pragma once
#include "jpLib.h"
#include <vector>
class CNames
{
public:
	CString cstrName;
	int nIndex = 0;
};
class CTagInfo
{
public:
	char sziniPath[2048];
	std::vector<CNames> m_vTag;
	//int m_iChoceIndex = 0;
	CTagInfo()
	{
		memset(sziniPath, 0x00, sizeof(sziniPath));
		jp::GetIniFolderFileName("names.txt", sziniPath);

		FILE *fp;
		fp = fopen(sziniPath, "r");
		if (!fp) return;

		CString data;
		char ch[256] = { 0, };
		int indexNames = 0;
		while (fgets(ch, 256, fp) != NULL)
		{
			data.Format("%s", ch);   // 한줄을 저장시켜버림. 20110203\n에서 \n까지 저장해버림.  윗줄에 null은 EOF임
			/*int len = data.GetLength();
			data = data.Mid(0, len);*/

			int index = data.Find('\n', 0);
			if (index > 0)
			{
				data.Delete(index, 1);
			}
			CNames name;
			name.cstrName = data;
			name.nIndex = indexNames;

			m_vTag.push_back(name);
			indexNames++;
		}
		fclose(fp);

	}
};

class CTagRect
{
public:
	CString cstrClassName;
	CString cstrFileNameOnly;
	int id = -1;
	float left = 0;
	float right = 0;
	float top = 0;
	float bottom = 0;

	float rateX = 0;
	float rateY = 0;
	float rateW = 0;
	float rateH = 0;

	float fimgW = 0;
	float fimgH = 0;



	float getWidth()
	{
		return (right - left);
	}
	float getHeight()
	{
		return (bottom - top);
	}

	float getCenterX()
	{
		return (left + right) / 2.0;
	}
	float getCenterY()
	{
		return (top + bottom) / 2.0;
	}
};

class CFileInfo
{
public:
	float rateX = 0;
	float rateY = 0;
	float rateW = 0;
	float rateH = 0;

	float fimgW = 0;
	float fimgH = 0;


	CString strPathImg;
	CString strPathTxt;
	cv::Mat cvMat;
	CTagRect rect;
	std::vector<CTagRect> vRect;
	std::vector<CTagRect> vRectAdd;
	int iTagNameIndex = -1;
	bool bVideoGrabMode = 0;
	bool bFullSizeClassify = 0;

	int iFrameNumber = 0;
	bool bLoadAnnotation = 0;

};

// CfileparserudacityDlg 대화 상자
class CfileparserudacityDlg : public CDialogEx
{
// 생성입니다.
public:
	CfileparserudacityDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILE_PARSER_UDACITY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strCSVFileName;
	CString m_strCSVFileNameOnly;
	CString m_strCSVFolderName;

	CString m_strJPGFileName;
	CString m_strJPGFileNameOnly;
	CString m_strJPGFolderName;


	std::vector<cv::String> m_fileNamesTXT;
	std::vector<cv::String> m_fileNamesJPG;
	std::vector<cv::String> m_fileNamesTXT_delete;
	std::vector<cv::String> m_fileNamesJPG_delete;


	std::vector<CTagRect> m_vInfo;


	void setRectRate(CTagRect &rect, cv::Mat cvmat);
	void transCoordination_img_to_yolo(CTagRect * rect, cv::Mat cvmat);
	void readCSVFile();
	void readJPGFile();
	CTagInfo m_tagInfo;
	afx_msg void OnBnClickedButtonFileOpen();
	afx_msg void OnBnClickedButtonFileWrite();
	afx_msg void OnBnClickedButtonFileOpen3();
	afx_msg void OnBnClickedButtonFileWrite2();
	afx_msg void OnBnClickedButtonFileCheck();
	afx_msg void OnBnClickedButtonFileOpen4();
	afx_msg void OnBnClickedButtonFileCheck2();
	afx_msg void OnBnClickedButtonFileCheck3();
	afx_msg void OnBnClickedButtonFileCheck4();
	afx_msg void OnBnClickedButtonFileTest();
	afx_msg void OnBnClickedButtonFileTest2();
};
