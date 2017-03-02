#pragma once
#include "Sequence.h"
class CDiskInteraction
{
public:
  CDiskInteraction();
  ~CDiskInteraction();

  SequenceData GetNextSequence();
  SequenceData GetCurrentSequence();
//Data
private:
  SequenceData CurrentFileSequence;
};

