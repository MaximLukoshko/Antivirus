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
  strcpy_s(viruses, 2, "");
  bool ret = false;
  for (CSignature sign : SignList)
  {
    for (unsigned int i = 0; i < seq.SeqLength - sign.Signature.SeqLength; i++)
    {
      bool virus_exists = true;
      for (unsigned int j = 0; j < sign.Signature.SeqLength; j++)
      {
        if (seq.Sequence[i + j] != sign.Signature.Sequence[j])
        {
          virus_exists = false;
          break;
        }
        if (!virus_exists)
          break;
      }
      if (virus_exists)
      {
        strcat_s(viruses, strlen(viruses) + strlen(sign.Name) + 1, sign.Name);
        strcat_s(viruses, strlen(viruses) + 3, ", ");
        ret = true;
        break;
      }
    }
  }

  return ret;
}

void CSignatureBase::Init()
{
  //TODO
  CSignature signature1( "12345_Virus", 5, "12345" );
  CSignature signature2("hg_Virus", 2, "hg");
  CSignature signature3("Maxim_Virus", 5, "virus");

  SignList.push_back( signature1 );
  SignList.push_back( signature2 );
  SignList.push_back( signature3 );
}
