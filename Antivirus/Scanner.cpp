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
    ScanFile(dir);
  }
}

void CScanner::GetPathForDir(char *old_path, char *dir_name, char *new_path)
{
  strcpy_s(new_path, strlen(old_path) + 1, old_path);
  new_path[strlen(new_path) - 1] = '\0';// ������� '*' � ��������� '\'
  strcat_s(new_path, strlen(new_path) + 1 + strlen(dir_name), dir_name);
  strcat_s(new_path, strlen(new_path) + 1 + 3, "\\*");
}
//////////////////////////////////////////////////////////////////////////

CScanner::CScanner( CSignatureBase& _SignatureBase )
  : m_SignatureBase( _SignatureBase )
{
  m_SeqBuffer.Sequence = new char[array_max_size];
  m_SeqBuffer_Length = 0;
  m_Scan_result.open("Scanning results.txt");
}


CScanner::~CScanner()
{
  m_SeqBuffer.FreeMemory();
  m_Scan_result.close();
}

void CScanner::Scan()
{
  cout << "Scanning System..." << endl;

//   char dir[500];
//   strcpy_s( dir, 10, "D:\\TEST\\*" );
//   OpenDirectory(dir);

  DWORD mask = GetLogicalDrives();
  for ( char i = 'A'; i <= 'Z'; i++ )
  {
    if ( mask & 1 )
    {
      char dir[500];
      char disk[] = { i, ':', '\\', '*', '\0' };
      cout << "Disk " << disk << endl;
      strcpy_s( dir, 5, disk );
      OpenDirectory( dir);
    }
    mask >>= 1;
  }
}

bool CScanner::ScanFile(char* dir)
{
  HANDLE  hFile;

  // ��������� ���� ��� ������
  hFile = CreateFile(
    dir,   // ��� �����
    GENERIC_READ,          // ������ �� �����
    0,                     // ����������� ������ � �����
    NULL,                  // ������ ��� 
    OPEN_EXISTING,         // ��������� ������������ ����
    FILE_ATTRIBUTE_NORMAL, // ������� ����
    NULL                   // ������� ���
    );

  // ��������� �� �������� ��������
  if (hFile == INVALID_HANDLE_VALUE)
    return false;

  // ���������� ������ �����
  DWORD file_length = GetFileSize(hFile, NULL);
  CloseHandle(hFile);

  if (file_length != -1)
  {
    m_Fin.open(dir, ios_base::binary);
    //DWORD buff_len = ReplaceBuffer(file_length);
    
    while (file_length > 0)
    {
      DWORD buff_len = array_max_size > file_length ? file_length : array_max_size;
      file_length -= buff_len;

      m_SeqBuffer.SeqLength = buff_len;

      m_Fin.read(m_SeqBuffer.Sequence, buff_len * sizeof(char));

      // �������� �� ����� ����� ������� ���������, ���� ���� ������������ �� ������
      if ( file_length > 0 )
        m_Fin.seekg( -m_SignatureBase.GetMaxSignLen(), ios::cur );

      if (m_SignatureBase.IsInfected(m_SeqBuffer, m_VirusesStr))
      {
        m_Scan_result << "���� \"" << dir << "\" ������ ��������: " << m_VirusesStr << "\n\n";
      }
    }
    m_Fin.close();
  }

  return true;
}

// DWORD CScanner::ReplaceBuffer(DWORD new_length)
// {
//   new_length = new_length <= array_max_size ? new_length : array_max_size;   
// 
//   if (new_length > m_SeqBuffer_Length)
//   {
//     replace_char_array(m_SeqBuffer.Sequence, new_length);
//     m_SeqBuffer_Length = new_length;
//   }
// 
//   return m_SeqBuffer_Length;
// }
