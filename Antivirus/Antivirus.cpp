// Antivirus.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Signature.h"
#include "SignatureBase.h"
#include "Scanner.h"

//TODO: 
// 1. ������ ���� ��������
// 2. ����� ��������� � ������


int _tmain(int argc, _TCHAR* argv[])
{
  CSignatureBase sign_base;

  CScanner scanner( sign_base );

  scanner.Scan();

  return 0;
}

