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
  InitFields( s.Name, s.Signature.SeqLength, s.Signature.Sequence );
}

CSignature::~CSignature()
{
	safe_delete(Name);
	safe_delete(Signature.Sequence);
}

void CSignature::InitFields( char* _Name, size_t _SignLength, char* _Signature )
{
  size_t name_len = strlen( _Name ) + 1;
  Name = new char[name_len];
  strcpy_s( Name, name_len, _Name );

  Signature.SeqLength = _SignLength;

  Signature.Sequence = new char[_SignLength];
  strcpy_s( Signature.Sequence, _SignLength, _Signature );
}
