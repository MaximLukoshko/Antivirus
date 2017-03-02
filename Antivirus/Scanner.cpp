#include "stdafx.h"
#include "Scanner.h"
#include <iostream>


CScanner::CScanner( CSignatureBase& _SignatureBase, CDiskInteraction& _Disk )
  : SignatureBase( _SignatureBase ), Disk( _Disk )
{}


CScanner::~CScanner()
{}

void CScanner::Scan()
{
  cout << "Scanning System..." << endl;
}
