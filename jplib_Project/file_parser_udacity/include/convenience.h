#pragma once
#include <fstream>
//#include <window.h>
//warning disable
#pragma warning(disable : 4819)
#pragma warning(disable : 4996)
#pragma warning(disable : 4267)
#pragma warning(disable : 4018)
#pragma warning(disable : 4244)
#pragma warning(disable : 4305)
#pragma warning(disable : 4288)

//folder name read

void GetCurTime(char *dst);
void GetIniFolderName(char* dst);
void GetIniFolderFileName(char* ini_file_name, char* dst);
//void GetIniAttribute_int(char* ini_file_name, char* section, char* name, int* iDst);
void GetIniAttribute_str(char* ini_file_name, char* section, char* name, char* dst);
void UBEYE_LOG(char *p_msg, ...);
void GetParsing_str(char* src, char* token, int section_index, char* dst);
void GetParsing_int(char* src, char* token, int section_index, int* iDst);

void GetFolderPath(char *src, char* dst);
void GetFileNameWithExt(char *src, char* dst);
void GetFileNameWithOutExt(char *src, char* dst);
void getPathWithOutExt(char *src, char* dst);
bool makeFolder(char *src);
bool isFileExists(const char *filename);









