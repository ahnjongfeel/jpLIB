
// file_parser_udacityDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "file_parser_udacity.h"
#include "file_parser_udacityDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CfileparserudacityDlg 대화 상자



CfileparserudacityDlg::CfileparserudacityDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FILE_PARSER_UDACITY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CfileparserudacityDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CfileparserudacityDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FILE_OPEN, &CfileparserudacityDlg::OnBnClickedButtonFileOpen)
	ON_BN_CLICKED(IDC_BUTTON_FILE_WRITE, &CfileparserudacityDlg::OnBnClickedButtonFileWrite)
	ON_BN_CLICKED(IDC_BUTTON_FILE_OPEN3, &CfileparserudacityDlg::OnBnClickedButtonFileOpen3)
	ON_BN_CLICKED(IDC_BUTTON_FILE_WRITE2, &CfileparserudacityDlg::OnBnClickedButtonFileWrite2)
	ON_BN_CLICKED(IDC_BUTTON_FILE_CHECK, &CfileparserudacityDlg::OnBnClickedButtonFileCheck)
	ON_BN_CLICKED(IDC_BUTTON_FILE_OPEN4, &CfileparserudacityDlg::OnBnClickedButtonFileOpen4)
	ON_BN_CLICKED(IDC_BUTTON_FILE_CHECK2, &CfileparserudacityDlg::OnBnClickedButtonFileCheck2)
	ON_BN_CLICKED(IDC_BUTTON_FILE_CHECK3, &CfileparserudacityDlg::OnBnClickedButtonFileCheck3)
	ON_BN_CLICKED(IDC_BUTTON_FILE_CHECK4, &CfileparserudacityDlg::OnBnClickedButtonFileCheck4)
	ON_BN_CLICKED(IDC_BUTTON_FILE_TEST, &CfileparserudacityDlg::OnBnClickedButtonFileTest)
	ON_BN_CLICKED(IDC_BUTTON_FILE_TEST2, &CfileparserudacityDlg::OnBnClickedButtonFileTest2)
	ON_BN_CLICKED(IDC_BUTTON_FILE_TEST3, &CfileparserudacityDlg::OnBnClickedButtonFileTest3)
	ON_BN_CLICKED(IDC_BUTTON_FILE_TEST4, &CfileparserudacityDlg::OnBnClickedButtonFileTest4)
END_MESSAGE_MAP()


// CfileparserudacityDlg 메시지 처리기

BOOL CfileparserudacityDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CfileparserudacityDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CfileparserudacityDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CfileparserudacityDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#include <fstream>

void CfileparserudacityDlg::readCSVFile()
{
	m_fileNamesTXT.clear();
	
	CString cstrFilter;
	cstrFilter.Format("%s\\*.txt", m_strCSVFolderName);

	cv::glob(cstrFilter.GetBuffer(), m_fileNamesTXT, 1);

	printf("Txt file count : %d\n", m_fileNamesTXT.size());

}

void CfileparserudacityDlg::readJPGFile()
{
	m_fileNamesJPG.clear();

	CString cstrFilter;
	cstrFilter.Format("%s\\*.jpg", m_strJPGFolderName);

	cv::glob(cstrFilter.GetBuffer(), m_fileNamesJPG, 1);

	printf("Jpg file count : %d\n", m_fileNamesJPG.size());

}


void CfileparserudacityDlg::OnBnClickedButtonFileOpen()
{
	CFolderPickerDialog folderPickerDialog(NULL, OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_ENABLESIZING, this,
		sizeof(OPENFILENAME));

	if (folderPickerDialog.DoModal() == IDOK)
	{
		POSITION pos = folderPickerDialog.GetStartPosition();

		if (pos)
		{
			m_strCSVFolderName = folderPickerDialog.GetNextPathName(pos);
			m_strCSVFileName = folderPickerDialog.GetPathName();
			m_strCSVFileNameOnly = folderPickerDialog.GetFileName();
			m_strCSVFolderName = folderPickerDialog.GetFolderPath();
		}
		readCSVFile();
	}
}

void CfileparserudacityDlg::setRectRate(CTagRect &rect, cv::Mat cvmat)
{
	float x = rect.getCenterX();
	float y = rect.getCenterY();
	float w = rect.getWidth();
	float h = rect.getHeight();
	float imgW = cvmat.cols;
	float imgH = cvmat.rows;

	float rateX = x / imgW;
	float rateY = y / imgH;
	float rateW = w / imgW;
	float rateH = h / imgH;

	rect.rateX = rateX;
	rect.rateY = rateY;
	rect.rateW = rateW;
	rect.rateH = rateH;

	rect.fimgW = imgW;
	rect.fimgH = imgH;
}

void CfileparserudacityDlg::transCoordination_img_to_yolo(CTagRect * rect, cv::Mat cvmat)
{
	rect->rateX = rect->getCenterX() / (float)cvmat.cols;
	rect->rateY = rect->getCenterY() / (float)cvmat.rows;
	rect->rateW = rect->getWidth() / (float)cvmat.cols;
	rect->rateH = rect->getHeight() / (float)cvmat.rows;
}

void CfileparserudacityDlg::OnBnClickedButtonFileWrite()
{
	FILE *fp = NULL;
	int count = 0;
	for (int i = 0; i < m_fileNamesJPG.size(); i++)
	{
		//jpg
		auto stdstrPath = m_fileNamesJPG[i];
		CString jpgPath;
		jpgPath.Format("%s", stdstrPath.c_str());
		cv::Mat cvmat = cv::imread(jpgPath.GetBuffer());
		if (cvmat.empty()) continue;
		cv::Rect rectL;
		cv::Rect rectR;
		rectL.x = 0;
		rectL.y = 0;
		rectL.width = cvmat.cols / 2.0;
		rectL.height = cvmat.rows / 2.0;

		rectR.x = cvmat.cols / 2.0;;
		rectR.y = 0;
		rectR.width = cvmat.cols / 2.0;
		rectR.height = cvmat.rows / 2.0;

		cv::Mat cvmatL = cvmat(rectL);
		cv::Mat cvMatR  = cvmat(rectR);

		//txt
		CString txtPath;
		txtPath.Format("%s", m_fileNamesTXT[i].c_str());
		std::vector<CTagRect> vRect;
		fp = fopen(txtPath.GetBuffer(), "r");
		if (fp)
		{
			char szClass[50];
			char szl[50];
			char szr[50];
			char szt[50];
			char szb[50];

			char strTemp[500];
			int count = 0;

			while (fgets(strTemp, 2000, fp) != NULL)
			{
				jp::GetParsing_str(strTemp, " ", 0, szClass);
				jp::GetParsing_str(strTemp, " ", 4, szl);
				jp::GetParsing_str(strTemp, " ", 5, szt);
				jp::GetParsing_str(strTemp, " ", 6, szr);
				jp::GetParsing_str(strTemp, " ", 7, szb);

				float imgW = cvmat.cols;
				float imgH = cvmat.rows;

				CTagRect rect;
				rect.left = (float)atof(szl);
				rect.right = (float)atof(szr);
				rect.top = (float)atof(szt);
				rect.bottom = (float)atof(szb);
				transCoordination_img_to_yolo(&rect, cvmat);
				rect.cstrClassName.Format("%s", szClass);

				//0bicycle
				//1car
				//2motorbike
				//3person
				//4plate

				if (rect.cstrClassName.MakeLower() == "cyclist")
				{
					rect.cstrClassName = "0";
				}
				else if (rect.cstrClassName.MakeLower() == "car")
				{
					rect.cstrClassName = "1";
				}
				else if (rect.cstrClassName.MakeLower() == "pedestrian")
				{
					rect.cstrClassName = "3";
				}
				else if (rect.cstrClassName.MakeLower() == "person_sitting")
				{
					rect.cstrClassName = "3";
				}
				else if (rect.cstrClassName.MakeLower() == "truck")
				{
					rect.cstrClassName = "1";
				}
				else if (rect.cstrClassName.MakeLower() == "van")
				{
					rect.cstrClassName = "1";
				}
				else
				{
					continue;
				}
				vRect.push_back(rect);
			}
			fclose(fp);
			fp = NULL;
		}
		if (fp)  fclose(fp);  fp = NULL;


		CString writePath;
		writePath = jpgPath;
		writePath.Delete(writePath.GetLength() - 4, 4);
		writePath.AppendFormat(".txt");


		
		for (auto rect : vRect)
		{
			CString data;
			int classID = atoi(rect.cstrClassName.GetBuffer());
			data.Format("%d %f %f %f %f\n",
				classID,
				rect.rateX,
				rect.rateY,
				rect.rateW,
				rect.rateH);

			fp = fopen(writePath.GetBuffer(), "a");
			if (fp != NULL)
			{
				fprintf(fp, data);
				fclose(fp);
				fp = NULL;
			}
		}
		printf("write count : %d\n", count);
		count++;
	}
}




void CfileparserudacityDlg::OnBnClickedButtonFileOpen3()
{
	CFolderPickerDialog folderPickerDialog(NULL, OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_ENABLESIZING, this,
		sizeof(OPENFILENAME));

	if (folderPickerDialog.DoModal() == IDOK)
	{
		POSITION pos = folderPickerDialog.GetStartPosition();

		if (pos)
		{
			m_strJPGFolderName = folderPickerDialog.GetNextPathName(pos);
			m_strJPGFileName = folderPickerDialog.GetPathName();
			m_strJPGFileNameOnly = folderPickerDialog.GetFileName();
			m_strJPGFolderName = folderPickerDialog.GetFolderPath();
		}
		readJPGFile();
	}
}


void CfileparserudacityDlg::OnBnClickedButtonFileWrite2()
{
#if(1)
	FILE *fp = NULL;
	int count = 0;
	for (int i = 0; i < m_fileNamesTXT.size(); i++)
	{
		//txt
		CString txtPath;
		txtPath.Format("%s", m_fileNamesTXT[i].c_str());

		std::vector<CTagRect> vRect;

		fp = fopen(txtPath.GetBuffer(), "r");
		if (fp)
		{
			char szClass[50];
			char szx[50];
			char szy[50];
			char szw[50];
			char szh[50];

			char strTemp[500];
			int count = 0;

			while (fgets(strTemp, 2000, fp) != NULL)
			{
				jp::GetParsing_str(strTemp, " ", 0, szClass);
				jp::GetParsing_str(strTemp, " ", 1, szx);
				jp::GetParsing_str(strTemp, " ", 2, szy);
				jp::GetParsing_str(strTemp, " ", 3, szw);
				jp::GetParsing_str(strTemp, " ", 4, szh);

				CTagRect rect;
				rect.rateX = (float)atof(szx);
				rect.rateY = (float)atof(szy);
				rect.rateW = (float)atof(szw);
				rect.rateH = (float)atof(szh);

				//rect.cstrClassName.Format("%s", szClass);
				//0bicycle
				//1car
				//2motorbike
				//3person
				//4plate
				int nOldID = (int)atoi(szClass);

				if (nOldID >= m_tagInfo.m_vTag.size())   continue;
				
				rect.cstrClassName = m_tagInfo.m_vTag[nOldID].cstrName;

				if (rect.cstrClassName.MakeLower() == "bicycle")
				{
					rect.cstrClassName = "0";
				}
				else if (rect.cstrClassName.MakeLower() == "car")
				{
					rect.cstrClassName = "1";
				}
				else if (rect.cstrClassName.MakeLower() == "bus")
				{
					rect.cstrClassName = "1";
				}
				else if (rect.cstrClassName.MakeLower() == "truck")
				{
					rect.cstrClassName = "1";
				}
				else if (rect.cstrClassName.MakeLower() == "motorbike")
				{
					rect.cstrClassName = "2";
				}
				else if (rect.cstrClassName.MakeLower() == "motorcycle")
				{
					rect.cstrClassName = "2";
				}
				else if (rect.cstrClassName.MakeLower() == "person")
				{
					rect.cstrClassName = "3";
				}
				else
				{
					continue;
				}
				vRect.push_back(rect);
			}
			fclose(fp);
			fp = NULL;
		}
		if (fp)  fclose(fp);  fp = NULL;

		if (!vRect.size())   goto end;

		{
			CString writePath;
			CString writeResultPath;

			char szFolderPath[2048];
			char szFileName[256];


			writePath.Format("%s", m_fileNamesTXT[i].c_str());
			jp::GetFileNameWithExt(writePath.GetBuffer(), szFileName);


			writePath.Format("%s", m_fileNamesTXT[i].c_str());
			jp::GetFolderPath(writePath.GetBuffer(), szFolderPath);

			writePath.Format("%s\\AFTER_FILTER\\", szFolderPath);
			jp::makeFolder(writePath.GetBuffer());


			writeResultPath.Format("%s\\AFTER_FILTER\\%s", szFolderPath, szFileName);


#if(1)
			for (auto rect : vRect)
			{
				CString data;
				int classID = atoi(rect.cstrClassName.GetBuffer());
				data.Format("%d %f %f %f %f\n",
					classID,
					rect.rateX,
					rect.rateY,
					rect.rateW,
					rect.rateH);

				fp = fopen(writeResultPath.GetBuffer(), "a");
				if (fp)
				{
					fprintf(fp, data);
					fclose(fp);
					fp = NULL;
				}
			}
#endif
		}
		end:
		count++;
		printf("write count : %d\n", count);

	}
#endif
}






void CfileparserudacityDlg::OnBnClickedButtonFileOpen4()
{
	CFolderPickerDialog folderPickerDialog(NULL, OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_ENABLESIZING, this,
		sizeof(OPENFILENAME));

	if (folderPickerDialog.DoModal() == IDOK)
	{
		POSITION pos = folderPickerDialog.GetStartPosition();

		if (pos)
		{
			m_strJPGFolderName = folderPickerDialog.GetNextPathName(pos);
			m_strJPGFileName = folderPickerDialog.GetPathName();
			m_strJPGFileNameOnly = folderPickerDialog.GetFileName();
			m_strJPGFolderName = folderPickerDialog.GetFolderPath();
		}
		readJPGFile();
	}
}



void CfileparserudacityDlg::OnBnClickedButtonFileCheck()
{
	m_fileNamesJPG_delete.clear();
	int count = 0;
	for (auto path : m_fileNamesTXT)
	{
		char szTemp[2048];
		jp::getPathWithOutExt((char*)path.c_str(), szTemp);
		CString cstrPath;
		cstrPath.Format("%s.jpg", szTemp);
		bool bret = jp::isFileExists(cstrPath.GetBuffer());
		if (bret)
		{
			continue;
		}
		else
		{
			count++;
			printf("not exist count : %d\n", count);
			m_fileNamesJPG_delete.push_back(path);
			//DeleteFile(path.c_str());
		}
	}
	printf("done...\n");
}


void CfileparserudacityDlg::OnBnClickedButtonFileCheck2()
{
	m_fileNamesTXT_delete.clear();
	int count = 0;
	for (auto path : m_fileNamesJPG)
	{
		char szTemp[2048];
		jp::getPathWithOutExt((char*)path.c_str(), szTemp);
		CString cstrPath;
		cstrPath.Format("%s.txt", szTemp);
		bool bret = jp::isFileExists(cstrPath.GetBuffer());
		if (bret)
		{
			continue;
		}
		else
		{
			count++;
			printf("not exist count : %d\n", count);
			m_fileNamesTXT_delete.push_back(path);
			//DeleteFile(path.c_str());
		}
	}
	printf("done...\n");
}





void CfileparserudacityDlg::OnBnClickedButtonFileCheck3()
{
	int count = 0;
	for (auto path : m_fileNamesJPG_delete)
	{
		count++;
		printf("jpg delete count : %d\n", count);
		DeleteFile(path.c_str());
	}
	printf("done...\n");
}


void CfileparserudacityDlg::OnBnClickedButtonFileCheck4()
{
	int count = 0;
	for (auto path : m_fileNamesTXT_delete)
	{
		count++;
		printf("txt delete count : %d\n", count);
		DeleteFile(path.c_str());
	}
	printf("done...\n");
}


int gx = 25;
int gy = 5;
void CfileparserudacityDlg::OnBnClickedButtonFileTest()
{
	jp::line::linePoint x1 = jp::line::linePoint(20, 10);
	jp::line::linePoint x2 = jp::line::linePoint(30, 10);
	jp::line::linePoint x3 = jp::line::linePoint(20, 20);
	jp::line::linePoint x4 = jp::line::linePoint(30, 20);
	

	bool r = jp::line::sementIntersects(x1, x2, x3, x4);

	printf("cross ? : %d\n", r);



	std::vector<jp::line::linePoint> vRect;

	vRect.push_back(x1);
	vRect.push_back(x2);
	vRect.push_back(x3);
	vRect.push_back(x4);
	//vRect.push_back(x1);

	jp::line::linePoint pointCenter = jp::line::linePoint(gx, gy);

	//vRect.push_back(pointCenter);

	bool r1 = jp::line::isInside(pointCenter, vRect);
	printf("inside ? x(%d) y(%d) : %d\n", gx, gy, r1);


	gy++;


	int x = 0;
	int y = 0;



}
std::string a, b, c;
void CfileparserudacityDlg::OnBnClickedButtonFileTest2()
{
	if (a.empty())
	{
		a = jp::openFileDialog();
	}
	cv::Mat cvmat = cv::imread(a);
	IplImage * t = cvLoadImage(a.c_str(), 1);
	jp::setPutText(t, t, "딧스이즈 한글 ", cvPoint(10, 10), CV_RGB(255, 0, 0), CV_RGB(0, 255, 0), 100);
	cvShowImage("tt", t);
	
	jp::setPutText(cvmat, "딧스이즈 한글 ", cvPoint(10, 10), CV_RGB(255, 0, 0), CV_RGB(0, 255, 0), 100);
	cv::imshow("cvmat", cvmat);
	cvReleaseImage(&t);	

}


void CfileparserudacityDlg::OnBnClickedButtonFileTest3()
{
	OnBnClickedButtonFileTest4();


#if(1)
	CWnd * hw1 = FindWindow(NULL, "안종필");  // 대화방의 이름이 안종필임.
	CWnd * hw2 = FindWindowEx(hw1->m_hWnd, 0, "RichEdit20W", NULL); //카톡editbox이름 - 모두 동일함
	
	//::SendMessage(hw2->m_hWnd, 0x000c, 0, (LPARAM)"asdf");	

	
	//::PostMessage(hw2->m_hWnd, WM_PASTE, 0, 0);
	//hw2->ShowWindow(SW_HIDE);
	//::ShowWindow(hw1->m_hWnd, SW_SHOW);
	
	::SetForegroundWindow(hw2->m_hWnd);
	keybd_event(VK_CONTROL, 0, 0, 0); //키가 눌려짐(DOWN)
	keybd_event('V', 0, 0, 0); //키가 눌려짐(DOWN)
	keybd_event('V', 0, 2, 0); //키가 눌려짐(UP)
	keybd_event(VK_CONTROL, 0, 2, 0); //키가 올라옴(UP)
	
	keybd_event(VK_RETURN, 0, 0, 0); //키가 눌려짐(DOWN)
	keybd_event(VK_RETURN, 0, 2, 0); //키가 올라옴(UP)
	
	//::PostMessage(hw2->m_hWnd, WM_KEYDOWN, VK_RETURN, NULL);//enter
	//::PostMessage(hw2->m_hWnd, WM_KEYUP, VK_RETURN, NULL);//enter
	//::SendMessage(hw2->m_hWnd, 0x0100, 0xD, 0x1C001);//enter
	//::PostMessage(hw2->m_hWnd, WM_KEYDOWN, VK_CONTROL, NULL);
	//::PostMessage(hw2->m_hWnd, WM_KEYDOWN, VK_CONTROL, NULL);
	//::PostMessage(hw2->m_hWnd, WM_KEYDOWN, VkKeyScan('v'), NULL);
	//::PostMessage(hw2->m_hWnd, WM_KEYUP, VkKeyScan('v'), NULL);
	//::PostMessage(hw2->m_hWnd, WM_PASTE, VkKeyScan('v'), NULL);
	//::PostMessage(hw2->m_hWnd, WM_KEYUP, VK_CONTROL, NULL);//
	//::PostMessage(hw2->m_hWnd, 0x0100, 0xD, 0x1C001);//enter
#endif


	//::ShowWindow(hw1->m_hWnd, SW_HIDE);	
}





auto CfileparserudacityDlg::ConvertCVMatToBMP(cv::Mat frame)
{
	auto convertOpenCVBitDepthToBits = [](const int32_t value)
	{
		auto regular = 0u;

		switch (value)
		{
		case CV_8U:
		case CV_8S:
			regular = 8u;
			break;

		case CV_16U:
		case CV_16S:
			regular = 16u;
			break;

		case CV_32S:
		case CV_32F:
			regular = 32u;
			break;

		case CV_64F:
			regular = 64u;
			break;

		default:
			regular = 0u;
			break;
		}

		return regular;
	};

	auto imageSize = frame.size();
	assert(imageSize.width && "invalid size provided by frame");
	assert(imageSize.height && "invalid size provided by frame");

	if (imageSize.width && imageSize.height)
	{
		auto headerInfo = BITMAPINFOHEADER{};
		ZeroMemory(&headerInfo, sizeof(headerInfo));

		headerInfo.biSize = sizeof(headerInfo);
		headerInfo.biWidth = imageSize.width;
		headerInfo.biHeight = -(imageSize.height); // negative otherwise it will be upsidedown
		headerInfo.biPlanes = 1;// must be set to 1 as per documentation frame.channels();

		const auto bits = convertOpenCVBitDepthToBits(frame.depth());
		headerInfo.biBitCount = frame.channels() * bits;

		auto bitmapInfo = BITMAPINFO{};
		ZeroMemory(&bitmapInfo, sizeof(bitmapInfo));

		bitmapInfo.bmiHeader = headerInfo;
		bitmapInfo.bmiColors->rgbBlue = 0;
		bitmapInfo.bmiColors->rgbGreen = 0;
		bitmapInfo.bmiColors->rgbRed = 0;
		bitmapInfo.bmiColors->rgbReserved = 0;

		auto dc = GetDC();
		assert(dc != NULL && "Failure to get DC");
		auto bmp = CreateDIBitmap(dc->m_hDC,
			&headerInfo,
			CBM_INIT,
			frame.data,
			&bitmapInfo,
			DIB_RGB_COLORS);
		assert(bmp != nullptr && "Failure creating bitmap from captured frame");

		return bmp;
	}
	else
	{
		HBITMAP a = NULL;

		return a;
	}
}

auto CfileparserudacityDlg::PasteBMPToClipboard(void * bmp)
{
	assert(bmp != NULL && "You need a bmp for this function to work");

	if (OpenClipboard() && bmp != NULL)
	{
		EmptyClipboard();
		SetClipboardData(CF_BITMAP, bmp);
		CloseClipboard();
		return true;
	}
	else
	{
		return false;
	}
}

int choiceCnt = 0;
void CfileparserudacityDlg::OnBnClickedButtonFileTest4()
{
	cv::Mat cvmat;
	if (choiceCnt % 2)
	{
		cvmat = cv::imread("d:\\11.jpg");
	}
	else
	{
		cvmat = cv::imread("d:\\22.jpg");
	}

	auto bmp = ConvertCVMatToBMP(cvmat);
	if (bmp)
	{
		auto pasteResult = PasteBMPToClipboard(bmp);
		DeleteObject(bmp);
		bmp = NULL;
	}
	choiceCnt++;


}

