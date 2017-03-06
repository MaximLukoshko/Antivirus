#include "stdafx.h"
#include "Scanner.h"

void CScanner::OpenDirectory(char* dir, ULONGLONG file_size)
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
      file_size = ( fileData.nFileSizeHigh *  ( (ULONGLONG) MAXDWORD + 1 ) ) + fileData.nFileSizeLow;
      OpenDirectory(new_dir, file_size);
    } while (FindNextFile(hFind, &fileData));
  }
  else
  {
    dir[strlen(dir) - 2] = '\0';

    ifstream fin(dir);
    if (!fin.is_open())
    {
      cout << "Can't open " << dir << "\n";
    }
    
    if ( SignatureBase.IsInfected( fin, file_size) )
    {
      //TODO: Вывести информацию о том, что файл заражён

    }

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

CScanner::CScanner( CSignatureBase& _SignatureBase )
  : SignatureBase( _SignatureBase )
{}


CScanner::~CScanner()
{}

void CScanner::Scan()
{
  cout << "Scanning System..." << endl;

  DWORD mask = GetLogicalDrives();
  for ( char i = 'A'; i <= 'Z'; i++ )
  {
    if ( mask & 1 )
    {
      char dir[500];
      char disk[] = { i, ':', '\\', '*', '\0' };
      strcpy_s( dir, 5, disk );
      OpenDirectory( dir, 0 );
    }
    mask >>= 1;
  }
}