#pragma once
#include <vector>
#include "Signature.h"

class CSignatureBase
{
public:
  CSignatureBase();
  ~CSignatureBase();

  bool IsInfected(SequenceData seq, char* viruses);
  LONG GetMaxSignLen();
private:
  void Init();
  void CountMaxSignLen();

//Data
private:
  vector<CSignature> m_SignList;
  LONG m_MaxSignLen; // Микрооптимизация
};