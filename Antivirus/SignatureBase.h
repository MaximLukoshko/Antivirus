#pragma once
#include <vector>
#include "Signature.h"

class CSignatureBase
{
public:
  CSignatureBase();
  ~CSignatureBase();

  bool IsInfected(SequenceData seq, string &viruses);

private:
  void Init();

//Data
private:
  vector<CSignature> SignList;
};