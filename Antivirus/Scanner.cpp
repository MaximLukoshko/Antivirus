#include "stdafx.h"
#include "Scanner.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <fstream>

void CScanner::OpenDirectory(char* dir, int deep)
{
	HANDLE hFind;
	WIN32_FIND_DATA fileData;
	hFind = FindFirstFile(dir, &fileData);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (fileData.cFileName[0] == '.')
				continue;

			char new_dir[500];
			GetPathForDir(dir, (char*)fileData.cFileName, new_dir);
			OpenDirectory(new_dir, deep + 2);
		} while (FindNextFile(hFind, &fileData));
	}
	else
	{
		dir[strlen(dir) - 3] = '\0';
		ifstream fin(dir);
		if (!fin.is_open())
		{
			
		}
		//SignatureBase.IsInfected(seq);
		fin.close();
	}
}

void CScanner::GetPathForDir(char *old_path, char *dir_name, char *new_path)
{
	strcpy_s(new_path, strlen(old_path) + 1, old_path);
	new_path[strlen(new_path) - 1] = '\0';// убираем '*' и добавляем '\'
	strcat_s(new_path, strlen(new_path) + 1 + strlen(dir_name), dir_name);
	strcat_s(new_path, strlen(new_path) + 1 + 3, "\\*");
}
//////////////////////////////////////////////////////////////////////////

CScanner::CScanner( CSignatureBase& _SignatureBase, CDiskInteraction& _Disk )
  : SignatureBase( _SignatureBase ), Disk( _Disk )
{}


CScanner::~CScanner()
{}

void CScanner::Scan()
{
  cout << "Scanning System..." << endl;

  DWORD mask = GetLogicalDrives();
  for(char i='A'; i<='Z'; i++)
  {
//	  cout << " " << ((mask & 1) ? i : '\0');
	  mask >>= 1;
	  char dir[500];
	  strcpy_s(dir, 5, i + ":\\*");
	  OpenDirectory(dir, 0);
  }
}