#pragma once
struct SequenceData
{
  SequenceData()
  {
    Sequence = NULL;
    SeqLength = 0;
  }

  SequenceData( size_t _SignLength, char* _Sequence = NULL )
  {
    Sequence = _Sequence;
    SeqLength = _SignLength;
  }

  void FreeMemory()
  {
    safe_delete_array( Sequence );
  }

  void EndLine()
  {
    Sequence[SeqLength] = '\0';
  }

  char* Sequence;
  ULONGLONG SeqLength;
};

