#include "stdafx.h"
#include "jpLib.h"

void jp::GetCurTime(char * dst)
{
	CString tmp;
	SYSTEMTIME st;

	GetLocalTime(&st);
	tmp.Format("[%02d:%02d:%02d]-", st.wHour, st.wMinute, st.wSecond);
	sprintf(dst, "%s", tmp.GetBuffer());
}
void jp::GetIniFolderName(char* dst)
{
	char *pSearchPath, sz_folder_name[MAX_PATH];

	GetModuleFileName(NULL, sz_folder_name, sizeof(sz_folder_name) - 1);
	pSearchPath = strrchr(sz_folder_name, '\\');
	sz_folder_name[strlen(sz_folder_name) - strlen(pSearchPath)] = '\0';
	strcat(sz_folder_name, "\\");
	int last_index = strlen(sz_folder_name);
	char last_char;
	if (last_index - 1 > 0) last_char = sz_folder_name[last_index - 1];
	if (last_char != '\\') 	strcat(sz_folder_name, "\\");

	sprintf(dst, "%s", sz_folder_name);

}
void jp::GetFolderPath(char *src_, char* dst)
{
	char src[2048];
	sprintf(src, "%s", src_);

	char *pSearchPath;

	pSearchPath = strrchr(src, '\\');
	src[strlen(src) - strlen(pSearchPath)] = '\0';
	strcat(src, "\\");
	int last_index = strlen(src);
	char last_char;
	if (last_index - 1 > 0) last_char = src[last_index - 1];
	if (last_char != '\\') 	strcat(src, "\\");

	sprintf(dst, "%s", src);

}
void jp::GetFileNameWithExt(char *src_, char* dst)
{
	char src[2048];
	sprintf(src, "%s", src_);

	char *pSearchPath;

	pSearchPath = strrchr(src, '\\') + 1;
	sprintf(dst, "%s", pSearchPath);

}
void jp::GetFileNameWithOutExt(char *src, char* dst)
{
	char *pSearchPath;

	pSearchPath = strrchr(src, '\\') + 1;

	pSearchPath[strlen(pSearchPath) - 4] = '\0';

	sprintf(dst, "%s", pSearchPath);

}
bool jp::makeFolder(char *src)
{
	return (bool)CreateDirectory(src, NULL);
}
void jp::GetIniFolderFileName(char* ini_file_name, char* dst)
{
	char *pSearchPath, sz_folder_name[MAX_PATH];

	GetModuleFileName(NULL, sz_folder_name, sizeof(sz_folder_name) - 1);
	pSearchPath = strrchr(sz_folder_name, '\\');
	sz_folder_name[strlen(sz_folder_name) - strlen(pSearchPath)] = '\0';
	strcat(sz_folder_name, "\\");
	strcat(sz_folder_name, ini_file_name);

	sprintf(dst, "%s", sz_folder_name);
}
void jp::GetIniAttribute_int(char* ini_file_name, char* section, char* name, int* iDst)
{
	char *pSearchPath, sz_folder_name[MAX_PATH];

	GetModuleFileName(NULL, sz_folder_name, sizeof(sz_folder_name) - 1);
	pSearchPath = strrchr(sz_folder_name, '\\');
	sz_folder_name[strlen(sz_folder_name) - strlen(pSearchPath)] = '\0';
	strcat(sz_folder_name, "\\");
	strcat(sz_folder_name, ini_file_name);

	int ireturn;
	ireturn = GetPrivateProfileInt(section, name, 0, sz_folder_name);

	*iDst = ireturn;
}
void jp::GetIniAttribute_str(char* ini_file_name, char* section, char* name, char* dst)
{
	char *pSearchPath, sz_folder_name[MAX_PATH];

	GetModuleFileName(NULL, sz_folder_name, sizeof(sz_folder_name) - 1);
	pSearchPath = strrchr(sz_folder_name, '\\');
	sz_folder_name[strlen(sz_folder_name) - strlen(pSearchPath)] = '\0';
	strcat(sz_folder_name, "\\");
	strcat(sz_folder_name, ini_file_name);

	char sz_buf[MAX_PATH];
	memset(sz_buf, 0x00, sizeof(sz_buf));
	GetPrivateProfileString("camera", "str", "0.0", sz_buf, sizeof(sz_buf), sz_folder_name);

	sprintf(dst, "%s", sz_buf);
}
void jp::JP_LOG(char *p_msg, ...)
{
	char *pSearchPath, sz_folder_name[MAX_PATH];

	GetModuleFileName(NULL, sz_folder_name, sizeof(sz_folder_name) - 1);
	pSearchPath = strrchr(sz_folder_name, '\\');
	sz_folder_name[strlen(sz_folder_name) - strlen(pSearchPath)] = '\0';
	strcat(sz_folder_name, "\\");
	int last_index = strlen(sz_folder_name);
	char last_char;
	if (last_index - 1 > 0) last_char = sz_folder_name[last_index - 1];
	if (last_char != '\\') 	strcat(sz_folder_name, "\\");


	FILE *fp;
	TCHAR file_path[MAX_PATH];
	SYSTEMTIME st;
	char tmp[512];
	char buf[25];
	char context[1024];
	va_list vl;

	GetLocalTime(&st);
	//strcpy(file_path, gStr_root);
	//strcat(file_path, "\\");
	//strcat(file_path, LOG_FILE_NAME);
#define LOG_FILE_NAME "logfile"
	sprintf(file_path, "%s\\%04d%02d%02d_%s", sz_folder_name, st.wYear, st.wMonth, st.wDay, LOG_FILE_NAME);

	fp = fopen(file_path, "a+t");
	if (!fp) { fp = fopen(file_path, "w+t");	if (!fp)	return; }

	va_start(vl, p_msg);
	vsprintf_s(tmp, p_msg, vl);
	va_end(vl);

	sprintf(buf, "[%02d:%02d:%02d]-", st.wHour, st.wMinute, st.wSecond);
	strcpy(context, buf);
	strcat(context, tmp);
	fputs(context, fp);

	fclose(fp);
}
void jp::GetParsing_int(char* src, char* token, int section_index, int* iDst)
{
	char sz_src[MAX_PATH];
	char* sz_dst;
	char sz_token[MAX_PATH];
	strcpy(sz_src, src);
	strcpy(sz_token, token);
	int i;
	sz_dst = strtok(sz_src, sz_token);

	for (i = 0; i < section_index; i++)
	{
		sz_dst = strtok(NULL, sz_token);

	}
	*iDst = atoi(sz_dst);
}
void jp::GetParsing_str(char* src, char* token, int section_index, char* dst)
{
	char sz_src[MAX_PATH];
	char* sz_dst;
	char sz_token[MAX_PATH];
	strcpy(sz_src, src);
	strcpy(sz_token, token);
	int i;
	sz_dst = strtok(sz_src, sz_token);

	for (i = 0; i < section_index; i++)
	{
		sz_dst = strtok(NULL, sz_token);
		if (!sz_dst)
		{
			sprintf(dst, "%s", "\0");
			return;
		}


	}
	sprintf(dst, "%s", sz_dst);
}
bool jp::isFileExists(const char *filename)
{


	std::ifstream ifile(filename);
	return (bool)ifile;
}
std::string jp::getConverting_CString2StdString(CString src)
{
	std::string dst;
	dst = src.GetBuffer();
	return dst;
}
CString jp::getConverting_StdString2CString(std::string src)
{
	CString dst;
	dst.Format("%s", src.c_str());
	return dst;
}

cv::Mat jp::getConverting_iplimage2Mat(IplImage * src)
{
	return cv::cvarrToMat(src);
}

IplImage *jp::getConverting_mat2IplImage(cv::Mat src)
{
	return (new IplImage(src));
}

std::vector<cv::String> jp::getFileList(char * szPath, char * szFilter, bool bSearchSubFolder)
{
	std::vector< cv::String> vTemp;
	std::string strFilter_;

	strFilter_ += szPath;
	strFilter_ += "\\";
	strFilter_ += szFilter;
	
	cv::glob(strFilter_, vTemp, bSearchSubFolder);
	printf("file count : %d\n", vTemp.size());
	
	return vTemp;

}

void jp::getPathWithOutExt(char *src_, char* dst)
{
	char src[2048];
	sprintf(src, "%s", src_);

	char *pSearchPath;

	pSearchPath = strrchr(src, '.');
	src[strlen(src) - strlen(pSearchPath)] = '\0';

	sprintf(dst, "%s", src);
}


#if(WINDOW)
std::string jp::openFolderDialog()
{
	CFolderPickerDialog folderPickerDialog(NULL, OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_ENABLESIZING, NULL,
		sizeof(OPENFILENAME));
	CString cstrFolderName;
	if (folderPickerDialog.DoModal() == IDOK)
	{
		POSITION pos = folderPickerDialog.GetStartPosition();

		if (pos)
		{
			cstrFolderName = folderPickerDialog.GetNextPathName(pos);
		}
	}
	return getConverting_CString2StdString(cstrFolderName);
}
std::string jp::openFileDialog(std::string filter)
{
	char szFilter[100];
	sprintf(szFilter, _T("All File (*%s)|*%s||"), filter.c_str(), filter.c_str());

	CFileDialog dlg(TRUE, 0, 0, OFN_ALLOWMULTISELECT | OFN_ENABLESIZING | OFN_FILEMUSTEXIST,
		_T(szFilter));
	
	CString retFileName;
	if (dlg.DoModal() == IDOK)
	{
		retFileName = dlg.GetPathName();
	}

	return retFileName;
}
#endif

double jp::line::ccw(linePoint a, linePoint b)
{
	return a.cross(b);
}

double jp::line::ccw(linePoint p, linePoint a, linePoint b)
{
	return ccw(a - p, b - p);
}

bool jp::line::lineIntersection(linePoint a, linePoint b, linePoint c, linePoint d, linePoint & x)
{
	double det = (b - a).cross(d - c);
	//두선이 평행인 경우
	if (fabs(det) < EPSILON) return false;
	x = a + (b - a)*((c - a).cross(d - c) / det);

	double minx = fmin(a.x, b.x);
	double maxx = fmax(a.x, b.x);

	return true;
}

bool jp::line::sementIntersects(linePoint a, linePoint b, linePoint c, linePoint d)
{
	double ab = ccw(a, b, c)*ccw(a, b, d);
	double cd = ccw(c, d, a)*ccw(c, d, b);
	//두 선분이 한 직선에 위에 있거나 끝점이 겹치는 경우
	if (ab == 0 && cd == 0) {
		if (b < a) std::swap(a, b);
		if (d < c) std::swap(c, d);
		return !(b < c || d < a);
	}
	return ab <= 0 && cd <= 0;
}

float jp::line::area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool jp::line::isInside(linePoint B, const std::vector<linePoint>& p)
{
	int x1 = p[0].x;
	int y1 = p[0].y;
	int x2 = p[1].x;
	int y2 = p[1].y;
	int x3 = p[2].x;
	int y3 = p[2].y;
	int x4 = p[3].x;
	int y4 = p[3].y;
	int x = B.x;
	int y = B.y;


	/* Calculate area of rectangle ABCD */
	float A = area(x1, y1, x2, y2, x3, y3) +
		area(x1, y1, x4, y4, x3, y3);

	/* Calculate area of triangle PAB */
	float A1 = area(x, y, x1, y1, x2, y2);

	/* Calculate area of triangle PBC */
	float A2 = area(x, y, x2, y2, x3, y3);

	/* Calculate area of triangle PCD */
	float A3 = area(x, y, x3, y3, x4, y4);

	/* Calculate area of triangle PAD */
	float A4 = area(x, y, x4, y4, x1, y1);

	/* Check if sum of A1, A2, A3 and A4
	   is same as A */
	return (A >= A1 + A2 + A3 + A4);	
}

#if(OPENCV_KOREAN)
void jp::setPutText(cv::Mat cvmat, char * text, CvPoint textPos, CvScalar color, CvScalar edge_color, int fontSize)
{
	IplImage *cvimage = jp::getConverting_mat2IplImage(cvmat);
	//IplImage *cvimage2 = jp::getConverting_mat2IplImage(cvmat);
	setPutText(cvimage, cvimage, text, textPos, color, edge_color, fontSize);
	cvmat = getConverting_iplimage2Mat(cvimage);
}
void jp::setPutText(IplImage * src_image, IplImage * dst_image, char * text, CvPoint textPos, CvScalar color, CvScalar edge_color, int fontSize)
{
	if (src_image->nChannels == 1)									// 명암도 영상일때
		cvMerge(src_image, src_image, src_image, NULL, dst_image);
	else if (src_image->nChannels != 1)								// 컬러 영상일때
		cvCopy(src_image, dst_image);


	int width = src_image->width - 1;
	int height = src_image->height - 1;
	int x = textPos.x;
	int y = textPos.y;
	if (x < 0 || x >= width)			return;  //이부분때문에 에러남 -1333333값이 들어옴
	if (y < 0 || y >= height)		return;



	// 범위 초과시 처리.
	if ((textPos.y > src_image->height) || (textPos.x > src_image->width))// 텍스트 크기가 그림 크기보다 크다면..
	{
		cvCopy(src_image, dst_image);
	}
	// 메모리 증가하는 문제 수정할 것...
	CvScalar var = { 0,0,0,0 };
	CvScalar var2 = edge_color;



	HBITMAP hBitmap = setTextToBitmap(text, color, fontSize);			// Text to Bimap
	IplImage * text_image = 0;
	text_image = setBitmapToIplImage(hBitmap);	// Bitmap to IplImage	

	// 텍스트 영상을 관심영역으로 간주.
	for (int nRow = textPos.y; nRow < (textPos.y + text_image->height); nRow++)
	{
		for (int nCol = textPos.x; nCol < (textPos.x + text_image->width); nCol++)
		{
			if (nRow + 2 >= height || nCol + 2 >= width)	continue;
			if (nRow - 2 < 0 || nCol - 2 < 0)	continue;

			if (var.val[0] == color.val[0] && var.val[1] == color.val[1] && var.val[2] == color.val[2])
			{
				cvSet2D(dst_image, nRow - 1, nCol - 1, var2);
				cvSet2D(dst_image, nRow - 1, nCol + 1, var2);
				cvSet2D(dst_image, nRow + 1, nCol - 1, var2);
				cvSet2D(dst_image, nRow + 1, nCol + 1, var2);

				cvSet2D(dst_image, nRow + 1, nCol, var2);
				cvSet2D(dst_image, nRow - 1, nCol, var2);
				cvSet2D(dst_image, nRow, nCol - 1, var2);
				cvSet2D(dst_image, nRow, nCol + 1, var2);
			}
			var = cvGet2D(text_image, nRow - textPos.y, nCol - textPos.x);
		}
	}


	for (int nRow = textPos.y; nRow < (textPos.y + text_image->height); nRow++)
	{
		for (int nCol = textPos.x; nCol < (textPos.x + text_image->width); nCol++)
		{
			if (nRow >= height || nCol >= width)	continue;
			var = cvGet2D(text_image, nRow - textPos.y, nCol - textPos.x);


			if (var.val[0] == color.val[0] && var.val[1] == color.val[1] && var.val[2] == color.val[2])
			{
				cvSet2D(dst_image, nRow, nCol, var);
			}
		}
	}
	if (text_image->imageData)  free(text_image->imageData);
	if (text_image)             cvReleaseImage(&text_image);
	DeleteObject(hBitmap);
}

HBITMAP jp::setTextToBitmap(char * text, CvScalar color, int fontSize)
{
	int textLength = (int)strlen(text);


	if (textLength <= 0) return NULL;


	HDC hTextDC = CreateCompatibleDC(NULL);

	HFONT hOldFont = (HFONT)SelectObject(hTextDC, (HFONT)GetStockObject(SYSTEM_FIXED_FONT));// 시스템 폰트로 지정
	HBITMAP hDstBMP = NULL;


	RECT textArea = { 0, 0, 0, 0 };

	CFont font;

	font.CreateFont(fontSize, 0, 0, 10, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, "굴림");

	::SelectObject(hTextDC, font);

	DrawText(hTextDC, (LPCTSTR)text, textLength, &textArea, DT_CALCRECT);			// DC에 텍스트 임시로 쓰기..


	if ((textArea.right > textArea.left) && (textArea.bottom > textArea.top))
	{
		BITMAPINFOHEADER  bitmapInfoHeader;
		memset(&bitmapInfoHeader, 0x0, sizeof(BITMAPINFOHEADER));


		void *lpvBits = NULL;


		bitmapInfoHeader.biSize = sizeof(bitmapInfoHeader);
		bitmapInfoHeader.biWidth = textArea.right - textArea.left;
		bitmapInfoHeader.biHeight = textArea.bottom - textArea.top;
		bitmapInfoHeader.biPlanes = 1;
		bitmapInfoHeader.biBitCount = 32;
		bitmapInfoHeader.biCompression = BI_RGB;

		hDstBMP = CreateDIBSection(hTextDC,
			(LPBITMAPINFO)&bitmapInfoHeader,
			0,
			(LPVOID*)&lpvBits,
			NULL,
			0);

		HBITMAP hOldBMP = (HBITMAP)SelectObject(hTextDC, hDstBMP);	// DC에서 비트맵 정보를 가져옴


		if (hOldBMP != NULL)
		{
			int TEXT_RED = (int)color.val[2];
			int TEXT_GREEN = (int)color.val[1];
			int TEXT_BLUE = (int)color.val[0];

			SetTextColor(hTextDC, RGB(TEXT_RED, TEXT_GREEN, TEXT_BLUE));		// 글자색상.
			SetBkColor(hTextDC, 0x00EFFEFF);									// 배경 색상
			SetBkMode(hTextDC, OPAQUE);											// 투명하게 처리


			DrawText(hTextDC, (LPCTSTR)text, textLength, &textArea, DT_NOCLIP);
		}
		::SelectObject(hTextDC, hOldBMP);

	}
	::SelectObject(hTextDC, hOldFont);
	if (hTextDC) { ::DeleteDC(hTextDC); }
	if (hOldFont) { ::DeleteObject(hOldFont); }

	::DeleteObject(font);
	return hDstBMP;
}

IplImage * jp::setBitmapToIplImage(HBITMAP hBitmap)
{
	BITMAP bitmap;
	GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&bitmap);


	int nChannels = (bitmap.bmBitsPixel == 1) ? 1 : bitmap.bmBitsPixel * 0.125;
	int depth = (bitmap.bmBitsPixel == 1) ? IPL_DEPTH_1U : IPL_DEPTH_8U;

	IplImage *	mImage = cvCreateImageHeader(cvSize(bitmap.bmWidth, bitmap.bmHeight), depth, nChannels);

	mImage->imageData = (char*)malloc(bitmap.bmHeight * bitmap.bmWidth * nChannels * sizeof(char));
	memcpy(mImage->imageData, (char*)(bitmap.bmBits), bitmap.bmHeight * bitmap.bmWidth * nChannels);


	cvFlip(mImage, mImage, 0);											// 상하 뒤집기
	return mImage;
}
#endif