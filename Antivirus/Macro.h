#pragma once
#include "stdafx.h"
#include <intsafe.h>

// ������������ ������
#define safe_delete(ptr) if( ptr ) delete ptr; ptr = NULL;
#define safe_delete_array(ptr) if( ptr ) delete [] ptr; ptr = NULL;

//������ ������� �� ������ � �������� ������
#define replace_char_array(ptr, new_len) safe_delete_array(ptr); ptr = new char[new_len];

// ������������ ������ �������
#define array_max_size ( (DWORD) SHORT_MAX ) * SHORT_MAX

// ����
#define ULONGLONG unsigned long long