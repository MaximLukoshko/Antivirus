#pragma once

#define safe_delete(ptr) if( ptr ) delete ptr; ptr = NULL;