#pragma once

#include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define EPSILON 0.0001
#define WINDOW 1
#define GEOMETRY 1
#define OPENCV_KOREAN 1

// 소팅 알고리즘  std 소팅
// 링크드 리스트 넣고
// 욜로 이미지 변환하는거 image변환하는거 넣고
// 욜로 색상 받아오는거 넣고
//  roi  영역 내부인지 확인하는 알고리즘
// 기본 윈도우 창 윈도우 창 파일 불러오기 알고리즘
// 폴더 로딩 불러오기
// 파일 저장
// 파일 읽기



#pragma warning(disable : 4819)
#pragma warning(disable : 4996)
#pragma warning(disable : 4267)
#pragma warning(disable : 4018)
#pragma warning(disable : 4244)
#pragma warning(disable : 4305)
#pragma warning(disable : 4288)


#ifdef _DEBUG
#pragma comment(lib, "opencv_core310d.lib")
#pragma comment(lib, "opencv_imgcodecs310d.lib")
#pragma comment(lib, "opencv_imgproc310d.lib")
#pragma comment(lib, "opencv_highgui310d.lib")
#pragma comment(lib, "opencv_videoio310d.lib")
#else
#pragma comment(lib, "opencv_core310.lib")
#pragma comment(lib, "opencv_imgcodecs310.lib")
#pragma comment(lib, "opencv_imgproc310.lib")
#pragma comment(lib, "opencv_highgui310.lib")
#pragma comment(lib, "opencv_videoio310.lib")
#endif


#ifdef _DEBUG
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#else
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


namespace jp
{
	void GetCurTime(char *dst);
	void GetIniFolderName(char* dst);
	void GetIniFolderFileName(char* ini_file_name, char* dst);
	void GetIniAttribute_int(char* ini_file_name, char* section, char* name, int* iDst);
	void GetIniAttribute_str(char* ini_file_name, char* section, char* name, char* dst);
	void JP_LOG(char *p_msg, ...);
	void GetParsing_str(char* src, char* token, int section_index, char* dst);
	void GetParsing_int(char* src, char* token, int section_index, int* iDst);
	void GetFolderPath(char *src, char* dst);
	void GetFileNameWithExt(char *src, char* dst);
	void GetFileNameWithOutExt(char *src, char* dst);
	void getPathWithOutExt(char *src, char* dst);
	bool makeFolder(char *src);
	bool isFileExists(const char *filename);
	std::string getConverting_CString2StdString(CString src);
	CString getConverting_StdString2CString(std::string src);
	cv::Mat getConverting_iplimage2Mat(IplImage *src);
	IplImage* getConverting_mat2IplImage(cv::Mat src);


#if(OPENCV_KOREAN)
	void setPutText(cv::Mat cvmat,		/* 원영상 */		
		char * text,                     		/* 텍스트 */
		CvPoint textPos,	                	/* 텍스트 위치 */
		CvScalar color,			                /* 텍스트 색상 */
		CvScalar edge_color,			        /* 텍스트테두리 색상 */
		int fontSize = 10);

	void setPutText(IplImage * src_image,		/* 원영상 */
		IplImage *dst_image,                    /* 저장할 영상 */
		char * text,                     		/* 텍스트 */
		CvPoint textPos,	                	/* 텍스트 위치 */
		CvScalar color,			                /* 텍스트 색상 */
		CvScalar edge_color,			        /* 텍스트테두리 색상 */
		int fontSize = 10);
	HBITMAP setTextToBitmap(char* text, CvScalar color, int fontSize);	// Text To Bitmap	
	IplImage * setBitmapToIplImage(HBITMAP hBitmap);		// Bitmap to IplImage
#endif

#if(GEOMETRY)
	namespace line
	{
		struct linePoint
		{
			double x, y;
			linePoint(double _x, double _y)
			{
				x = _x, y = _y;
			}
			double cross(const linePoint& other) const
			{
				return x * other.y - y * other.x;
			}
			linePoint operator * (double r) const {
				return linePoint(x*r, y*r);
			}
			linePoint operator + (linePoint other) const {
				return linePoint(x + other.x, y + other.y);
			}
			linePoint operator - (linePoint other) const {
				return linePoint(x - other.x, y - other.y);
			}
			bool operator == (linePoint other) const
			{
				return x == other.x && y == other.y;
			}
			bool operator < (linePoint other) const
			{
				return x < other.x && y < other.y;
			}
		};
		bool isInside(linePoint B, const std::vector<linePoint>& p);  //real use
		bool lineIntersection(linePoint a, linePoint b, linePoint c, linePoint d, linePoint& x);  //real use
		bool sementIntersects(linePoint a, linePoint b, linePoint c, linePoint d); //real use
		float area(int x1, int y1, int x2, int y2, int x3, int y3);   
		double ccw(linePoint p, linePoint a, linePoint b);
		double ccw(linePoint a, linePoint b);
		
#endif
		

	}


#if(WINDOW)
	std::string openFolderDialog();
	std::string openFileDialog(std::string filter = ".*");
#endif
	std::vector<cv::String> getFileList(char* szPath, char* szFilter, bool bSearchSubFolder = 0);
}





