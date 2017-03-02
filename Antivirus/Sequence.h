#pragma once
struct SequenceData
{
  SequenceData()
  {
    Sequence = NULL;
    SeqLength = 0;
  }

  SequenceData( char* _Sequence, size_t _SignLength )
  {
    Sequence = _Sequence;
    SeqLength = _SignLength;
  }

  char* Sequence;
  size_t SeqLength;
};

