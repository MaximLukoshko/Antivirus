// Antivirus.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Signature.h"
#include "SignatureBase.h"
#include "Scanner.h"

//TODO: 
// 1. Чтение базы сигнатур
// 2. Поиск подстроки в строке


int _tmain(int argc, _TCHAR* argv[])
{
  CSignatureBase sign_base;

  CScanner scanner( sign_base );

  scanner.Scan();

  return 0;
}

