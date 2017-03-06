#pragma once
#include <vector>
#include "Signature.h"

class CSignatureBase
{
public:
  CSignatureBase();
  ~CSignatureBase();

  bool IsInfected(ifstream& sequence, ULONGLONG file_size);

private:
  void Init();

//Data
private:
  vector<CSignature> SignList;
  SequenceData SeqBuffer;

};