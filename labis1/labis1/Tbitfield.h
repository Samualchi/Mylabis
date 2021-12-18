#include <iostream>
#pragma once

using namespace std;

typedef int TELEM;

class TBitField
{
private:
	int _razmer;// len bit field - max count bit
	TELEM* pMem; // memory for len bit field
	int  MemLen, Elem; // count mem for  bit field
	int   GetMemIndex(const int n) const; // indx pmem for bit n     
	TELEM GetMemMask(const int n) const; // bit mask for bit n 

	// methods of realization

public:
	//                              
	TBitField(const TBitField& bf);  // copy             
	TBitField(int Elem);
	TBitField();

	TBitField& resize(int size);  //we use resize every time the new array is not equal to the old one

	~TBitField();
	// ostup into bit   
	int GetLength(void) const;      // get len          
	void SetBit(const int i);       // set bit                      
	void ClrBit(const int i);       // clear bit                     
	int  GetBit(const int i) const; // get sign bit              
	TBitField& operator=(const TBitField& bf); // assign          

	TBitField operator>>(int k); //moving to the right
	TBitField operator<<(int k); //moving to the left
	bool operator==(const TBitField& bf); // if equal
	bool operator!=(const TBitField& bf); // if not equal
	TBitField operator|(const TBitField& bf); // or
	TBitField operator~(void); //inventor

	TBitField  operator&(const TBitField& bf); // and
	void print_array();
	bool test();
};

