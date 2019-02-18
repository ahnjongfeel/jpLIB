#include "stdafx.h"
#include "convenience.h"

void GetCurTime(char * dst)
{
	CString tmp;
	SYSTEMTIME st;
	
	GetLocalTime(&st);
	tmp.Format("[%02d:%02d:%02d]-", st.wHour, st.wMinute, st.wSecond);
	sprintf(dst, "%s", tmp.GetBuffer());
}


void GetIniFolderName(char* dst)
{
	char *pSearchPath, sz_folder_name[MAX_PATH];
		
	GetModuleFileName(NULL, sz_folder_name, sizeof(sz_folder_name) -1 );
	pSearchPath = strrchr(sz_folder_name, '\\');
	sz_folder_name[strlen(sz_folder_name) - strlen(pSearchPath)] = '\0';
	strcat(sz_folder_name, "\\");
	int last_index =strlen(sz_folder_name);
	char last_char;
	if(last_index -1 > 0) last_char = sz_folder_name[last_index-1];
	if(last_char != '\\') 	strcat(sz_folder_name, "\\");
		
	sprintf(dst, "%s", sz_folder_name);

}



void GetFolderPath(char *src_, char* dst)
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

void GetFileNameWithExt(char *src_, char* dst)
{
	char src[2048];
	sprintf(src, "%s", src_);

	char *pSearchPath;

	pSearchPath = strrchr(src, '\\') + 1;
	sprintf(dst, "%s", pSearchPath);

}


void GetFileNameWithOutExt(char *src, char* dst)
{
	char *pSearchPath;

	pSearchPath = strrchr(src, '\\') + 1;

	pSearchPath[strlen(pSearchPath) - 4] = '\0';

	sprintf(dst, "%s", pSearchPath);

}

bool makeFolder(char *src)
{
	return (bool) CreateDirectory(src, NULL);
}



void GetIniFolderFileName(char* ini_file_name, char* dst)
{
	char *pSearchPath, sz_folder_name[MAX_PATH];
		
	GetModuleFileName(NULL, sz_folder_name, sizeof(sz_folder_name) -1 );
	pSearchPath = strrchr(sz_folder_name, '\\');
	sz_folder_name[strlen(sz_folder_name) - strlen(pSearchPath)] = '\0';
	strcat(sz_folder_name, "\\");
	strcat(sz_folder_name, ini_file_name);

	sprintf(dst, "%s", sz_folder_name);
}


void GetIniAttribute_int(char* ini_file_name, char* section, TCHAR* name, int* iDst)
{
	char *pSearchPath, sz_folder_name[MAX_PATH];
		
	GetModuleFileName(NULL, sz_folder_name, sizeof(sz_folder_name) -1 );
	pSearchPath = strrchr(sz_folder_name, '\\');
	sz_folder_name[strlen(sz_folder_name) - strlen(pSearchPath)] = '\0';
	strcat(sz_folder_name, "\\");
	strcat(sz_folder_name, ini_file_name);

	int ireturn;
	ireturn = GetPrivateProfileInt(section, name, 0, sz_folder_name); 

	*iDst = ireturn;
}

void GetIniAttribute_str(char* ini_file_name, char* section, char* name, char* dst)
{
	char *pSearchPath, sz_folder_name[MAX_PATH];
			
	GetModuleFileName(NULL, sz_folder_name, sizeof(sz_folder_name) -1 );
	pSearchPath = strrchr(sz_folder_name, '\\');
	sz_folder_name[strlen(sz_folder_name) - strlen(pSearchPath)] = '\0';
	strcat(sz_folder_name, "\\");
	strcat(sz_folder_name, ini_file_name);

	char sz_buf[MAX_PATH];
	memset(sz_buf, 0x00, sizeof(sz_buf));
	GetPrivateProfileString("camera", "str", "0.0", sz_buf, sizeof(sz_buf), sz_folder_name);
	
	sprintf(dst, "%s", sz_buf);
}
//»ç¿ë¿¹ : UBEYE_LOG("%s", "IrisControlThr\r\n");


void UBEYE_LOG(char *p_msg, ...)
{
	char *pSearchPath, sz_folder_name[MAX_PATH];
		
	GetModuleFileName(NULL, sz_folder_name, sizeof(sz_folder_name) -1 );
	pSearchPath = strrchr(sz_folder_name, '\\');
	sz_folder_name[strlen(sz_folder_name) - strlen(pSearchPath)] = '\0';
	strcat(sz_folder_name, "\\");
	int last_index =strlen(sz_folder_name);
	char last_char;
	if(last_index -1 > 0) last_char = sz_folder_name[last_index-1];
	if(last_char != '\\') 	strcat(sz_folder_name, "\\");

	
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
	if(!fp)	{	fp = fopen(file_path, "w+t");	if(!fp)	return;	}

	va_start(vl, p_msg);
	vsprintf_s(tmp, p_msg, vl);
	va_end(vl);

	sprintf(buf, "[%02d:%02d:%02d]-", st.wHour, st.wMinute, st.wSecond);
	strcpy(context, buf);
	strcat(context, tmp);
	fputs(context, fp);

	fclose(fp);
}




void GetParsing_int(char* src, char* token, int section_index, int* iDst)
{
	char sz_src[MAX_PATH];
	char* sz_dst;
	char sz_token[MAX_PATH];
	strcpy(sz_src, src);
	strcpy(sz_token, token);
	int i;
	sz_dst = strtok(sz_src, sz_token);

	for (i = 0; i<section_index; i++)
	{
		sz_dst = strtok(NULL, sz_token);

	}
	*iDst = atoi(sz_dst);
}


void  GetParsing_str(char* src, char* token, int section_index, char* dst)
{
	char sz_src[MAX_PATH];
	char* sz_dst;
	char sz_token[MAX_PATH];
	strcpy(sz_src, src);
	strcpy(sz_token, token);
	int i;
	sz_dst = strtok(sz_src, sz_token);

	for (i = 0; i<section_index; i++)
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

bool isFileExists(const char *filename) 
{
	

	std::ifstream ifile(filename);
	return (bool)ifile;
}

void getPathWithOutExt(char *src_, char* dst)
{
	char src[2048];
	sprintf(src, "%s", src_);

	char *pSearchPath;

	pSearchPath = strrchr(src, '.');
	src[strlen(src) - strlen(pSearchPath)] = '\0';

	sprintf(dst, "%s", src);
}

