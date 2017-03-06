// Antivirus.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Signature.h"
#include "SignatureBase.h"
#include "Scanner.h"


int _tmain(int argc, _TCHAR* argv[])
{
//   CSignature* signature1 = new CSignature( "Name1", 6, "12345" );
//   CSignature* signature2 = new CSignature( *signature1 );
//   CSignature signature3 = *signature2;
// 
//   safe_delete( signature1 );
//   safe_delete( signature2 );

  CSignatureBase sign_base;

  CScanner scanner( sign_base );

  scanner.Scan();

  return 0;
}

