#include "stdafx.h"
#include "SignatureBase.h"


CSignatureBase::CSignatureBase()
{
  Init();
}


CSignatureBase::~CSignatureBase()
{
}

bool CSignatureBase::IsInfected( ifstream& sequence )
{
  //TODO
  return false;
}

void CSignatureBase::Init()
{
  //TODO
  CSignature signature1( "Name1", 6, "12345" );
  CSignature signature2( signature1 );
  CSignature signature3 = signature2;

  SignList.push_back( signature1 );
  SignList.push_back( signature2 );
  SignList.push_back( signature3 );
}
