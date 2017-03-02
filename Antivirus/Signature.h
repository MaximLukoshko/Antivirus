#pragma once
#include "stdafx.h"
#include "Sequence.h"

using namespace std;

class CSignature
{
public:
	CSignature(char* _Name, size_t _SignLength, char* _Signature);
  CSignature( const CSignature &s );
	~CSignature();

private:
  void InitFields( char* _Name, size_t _SignLength, char* _Signature );

//Data
public:
	char* Name;
  SequenceData Signature;
};

