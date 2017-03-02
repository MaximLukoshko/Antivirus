#pragma once
#include "SignatureBase.h"
#include "DiskInteraction.h"
class CScanner
{
public:
  CScanner( CSignatureBase& _SignatureBase, CDiskInteraction& _Disk );
  ~CScanner();

  void Scan();

//Data
private: 
  CSignatureBase& SignatureBase;
  CDiskInteraction& Disk;
};

