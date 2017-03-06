#pragma once
#include "stdafx.h"

#define safe_delete(ptr) if( ptr ) delete ptr; ptr = NULL;