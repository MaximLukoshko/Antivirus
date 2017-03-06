#pragma once
#include "stdafx.h"

#define safe_delete(ptr) if( ptr ) delete ptr; ptr = NULL;
#define safe_delete_array(ptr) if( ptr ) delete [] ptr; ptr = NULL;
#define replace_char_array(ptr, new_len) safe_delete_array(ptr); ptr = new char[new_len];

#define ULONGLONG unsigned long long