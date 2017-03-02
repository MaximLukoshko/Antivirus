#pragma once
class CDiskInteraction
{
public:
	CDiskInteraction(size_t _BuffLen);
	~CDiskInteraction();

//Data
private:
  char* Buffer;
  size_t BuffLen;
  size_t Position;
};

