#include "stdafx.h"
#include "SignatureBase.h"


CSignatureBase::CSignatureBase()
{
  Init();
}


CSignatureBase::~CSignatureBase()
{
}

bool CSignatureBase::IsInfected( SequenceData seq, char* viruses )
{

  //TODO

//   for (unsigned int i = 0; i < seq.SeqLength; i++)
//   {
//     char sym = seq.Sequence[i];
//     cout << seq.Sequence[i];
//   }
//   cout << endl;
  strcpy_s(viruses, 30, "TEST_VIRUS");

  return true;
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
