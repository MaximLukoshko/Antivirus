#include "stdafx.h"
#include "Scanner.h"

void CScanner::OpenDirectory(char* dir)
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
      OpenDirectory(new_dir);
    } while (FindNextFile(hFind, &fileData));
  }
  else
  {
    dir[strlen(dir) - 2] = '\0';
    cout << "Scanning \"" << dir << "\" \n";
    if (GetFileBuffer(dir))
      if ( SignatureBase.IsInfected( SeqBuffer, viruses ) )
      {
        m_ScanResult << "Файл \"" << dir << "\" заражён вирусами: " << viruses.c_str() << "\n";
//        cout << "Файл \"" << dir << "\" заражён вирусами: " << viruses.c_str() << "\n";
      }
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
{
  m_ScanResult.open("Scanning results.txt");
  m_Log.open( "Log.txt" );
}


CScanner::~CScanner()
{
  SeqBuffer.FreeMemory();
  m_ScanResult.close();
  m_Log.close();
}

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
      OpenDirectory( dir);
    }
    mask >>= 1;
  }
}

bool CScanner::GetFileBuffer(char* dir)
{
  HANDLE  hFile;

  // открываем файл для чтения
  hFile = CreateFile(
    dir,   // имя файла
    GENERIC_READ,          // чтение из файла
    0,                     // монопольный доступ к файлу
    NULL,                  // защиты нет 
    OPEN_EXISTING,         // открываем существующий файл
    FILE_ATTRIBUTE_NORMAL, // обычный файл
    NULL                   // шаблона нет
    );

  // проверяем на успешное открытие
  if ( hFile == INVALID_HANDLE_VALUE )
  {
    m_Log << "Can not open \"" << dir << "\"" << endl;
//    cout << "Can not open \"" << dir << "\"" << endl;
    return false;
  }

  // определяем размер файла
  SeqBuffer.SeqLength = GetFileSize(hFile, NULL);
  CloseHandle(hFile);

  if (SeqBuffer.SeqLength != -1)
  {
    replace_char_array(SeqBuffer.Sequence, SeqBuffer.SeqLength + 1);
    ifstream fin(dir);
    for ( DWORD k = 0; k < SeqBuffer.SeqLength && !fin.eof(); k++ )
      fin >> SeqBuffer.Sequence[k];
  }

  return true;
}