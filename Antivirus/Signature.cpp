#include "stdafx.h"
#include "Signature.h"
#include "Macro.h"
#include <string.h>


CSignature::CSignature(char* _Name, size_t _SignLength, char* _Signature)
{
  InitFields( _Name, _SignLength, _Signature );
}


CSignature::CSignature( const CSignature &s )
{
  InitFields( s.Name, s.SignLength, s.Signature );
}

CSignature::~CSignature()
{
	safe_delete(Name);
	safe_delete(Signature);
}

void CSignature::InitFields( char* _Name, size_t _SignLength, char* _Signature )
{
  size_t name_len = strlen( _Name ) + 1;
  Name = new char[name_len];
  strcpy_s( Name, name_len, _Name );

  SignLength = _SignLength;

  Signature = new char[_SignLength];
  strcpy_s( Signature, _SignLength, _Signature );
}
