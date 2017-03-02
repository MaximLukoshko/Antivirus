#pragma once
#include <vector>
#include "Signature.h"
class CSignatureBase
{
public:
	CSignatureBase();
	~CSignatureBase();

  bool isInfected(char* sequence);
//  size_t GetBufferLength();

private:
  void Init();

//Data
private:
  vector<CSignature> SignList;

};