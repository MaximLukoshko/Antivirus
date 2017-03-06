#include "stdafx.h"
#include "SignatureBase.h"


CSignatureBase::CSignatureBase()
{
  Init();
}


CSignatureBase::~CSignatureBase()
{
  SeqBuffer.FreeMemory();
}

bool CSignatureBase::IsInfected( ifstream& sequence, ULONGLONG file_size )
{
  if ( file_size > SeqBuffer.SeqLength )
  {
    SeqBuffer.SeqLength = file_size;
    replace_char_array( SeqBuffer.Sequence, SeqBuffer.SeqLength + 1 );
  }

  for ( unsigned int i = 0; i < SeqBuffer.SeqLength && !sequence.eof(); i++ )
    sequence >> SeqBuffer.Sequence[i];
  SeqBuffer.EndLine();
  
  //TODO
  for ( unsigned int i = 0; i < SeqBuffer.SeqLength; i++ )
  {
    char sym = SeqBuffer.Sequence[i];
    cout << SeqBuffer.Sequence[i];
  }
  cout << endl;

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
