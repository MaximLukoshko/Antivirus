#pragma once
#include <vector>
#include "Signature.h"
#include <fstream>

class CSignatureBase
{
public:
  CSignatureBase();
  ~CSignatureBase();

  bool IsInfected(ifstream& sequence);

private:
  void Init();

//Data
private:
  vector<CSignature> SignList;

};