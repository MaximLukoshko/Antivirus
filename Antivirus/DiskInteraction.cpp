#include "stdafx.h"
#include "DiskInteraction.h"


CDiskInteraction::CDiskInteraction( size_t _BuffLen ) : BuffLen( _BuffLen )
{
  Position = 0;
  Buffer = NULL;
}


CDiskInteraction::~CDiskInteraction()
{
}
