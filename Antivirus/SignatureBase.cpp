#include "stdafx.h"
#include "SignatureBase.h"


CSignatureBase::CSignatureBase()
{
  Init();
}


CSignatureBase::~CSignatureBase()
{
}

bool CSignatureBase::IsInfected( SequenceData seq, string &viruses )
{
  viruses = "";
  for (CSignature sig : SignList)
    if ( strstr( seq.Sequence, sig.Signature.Sequence ) ) //TODO
    {
      viruses += sig.Name;
      viruses += ", ";
    }
  
  if ( viruses.empty() )
    return false;
  
  return true;
}

void CSignatureBase::Init()
{
  //TODO
  CSignature signature1( "Name1", 12, "01234567890" );
  CSignature signature2( "Name2", 9, "00012345" );
  CSignature signature3( "Name3", 9, "12345777" );

  SignList.push_back( signature1 );
  SignList.push_back( signature2 );
  SignList.push_back( signature3 );
}
