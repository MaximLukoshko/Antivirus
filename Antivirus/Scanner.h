#pragma once
#include "SignatureBase.h"
#include "DiskInteraction.h"
class CScanner
{
public:
  CScanner( CSignatureBase& _SignatureBase, CDiskInteraction& _Disk );
  ~CScanner();

  void Scan();

private:
  void OpenDirectory(char* dir, int deep);
  void GetPathForDir(char *old_path, char *dir_name, char *new_path);
//Data
private: 
  CSignatureBase& SignatureBase;
  CDiskInteraction& Disk;
};

