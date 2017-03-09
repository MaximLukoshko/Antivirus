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
  bool GetFileBuffer(char* dir);
//Data
private: 
  CSignatureBase& SignatureBase;
  SequenceData SeqBuffer;
  ofstream m_ScanResult;
  ofstream m_Log;
  string viruses;
};

