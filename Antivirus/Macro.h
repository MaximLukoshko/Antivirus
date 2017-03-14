#pragma once
#include "stdafx.h"
#include <intsafe.h>

// Освобождение памяти
#define safe_delete(ptr) if( ptr ) delete ptr; ptr = NULL;
#define safe_delete_array(ptr) if( ptr ) delete [] ptr; ptr = NULL;

//Замена массива на массив с заданной длиной
#define replace_char_array(ptr, new_len) safe_delete_array(ptr); ptr = new char[new_len];

// Максимальный размер массива
#define array_max_size ( (DWORD) SHORT_MAX ) * SHORT_MAX

// Типы
#define ULONGLONG unsigned long long