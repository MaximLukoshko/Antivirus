#pragma once
#include "stdafx.h"
#include "SignatureBase.h"

class CScanner
{
public:
  CScanner( CSignatureBase& _SignatureBase );
  ~CScanner();

  void Scan();

private:
  void OpenDirectory(char* dir, ULONGLONG file_size);
  void GetPathForDir(char *old_path, char *dir_name, char *new_path);
//Data
private: 
  CSignatureBase& SignatureBase;
};

