#pragma once
#include "stdafx.h"
#include "SignatureBase.h"
#include "Sequence.h"

class CScanner
{
public:
  CScanner( CSignatureBase& _SignatureBase );
  ~CScanner();

  void Scan();

private:
  void OpenDirectory(char* dir);
  void GetPathForDir(char *old_path, char *dir_name, char *new_path);
  bool ScanFile(char* dir);
//  DWORD ReplaceBuffer(DWORD new_length);

  //Data
private: 
  CSignatureBase& m_SignatureBase;
  SequenceData m_SeqBuffer;
  DWORD m_SeqBuffer_Length;
  ofstream m_Scan_result;
  ifstream m_Fin;
  char m_VirusesStr[500];
};

