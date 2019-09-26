#ifndef _ROD_h
#define _ROD_h

#include "Masks.h"

class Rod{
	public:
		Rod();
		Rod(byte bStatus);
		void setStatus(byte bStatus);
		byte getStatus();
		void printRod();
		bool isBlocked();
	private:
		byte status; // red green blue accesible 
};
#endif