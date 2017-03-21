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
  for (CSignature sign : m_SignList)
  {
    for ( long i = 0; i < seq.SeqLength - sign.Signature.SeqLength; i++ )
    {
      bool virus_exists = true;
      for ( long j = 0; j < sign.Signature.SeqLength; j++ )
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

LONG CSignatureBase::GetMaxSignLen()
{
  return m_MaxSignLen;
}

void CSignatureBase::Init()
{
  //TODO
  m_SignList.push_back(CSignature("12345_Virus", 5, "12345"));
  m_SignList.push_back(CSignature("hghghghghg_Virus", 10, "hghghghghg"));
  m_SignList.push_back(CSignature("Maxim_Virus", 5, "virus"));
  m_SignList.push_back(CSignature("Maximus_Virus", 7, "Maximus"));

  CountMaxSignLen();
}

void CSignatureBase::CountMaxSignLen()
{
  m_MaxSignLen = -1;
  for ( CSignature sign : m_SignList )
    if ( m_MaxSignLen < sign.Signature.SeqLength )
      m_MaxSignLen = sign.Signature.SeqLength;
}
