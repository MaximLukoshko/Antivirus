#pragma once
#include "stdafx.h"

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
	size_t SignLength;
	char* Signature;
};

