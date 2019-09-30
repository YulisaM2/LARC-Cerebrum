#ifndef _BOAT_h
#define _BOAT_h

#include "Masks.h"

// Boats are the deposit areas where we need to leave the rods, we have two different areas where we can deposit rods in each boat, with a max height of 4 rods per stack

class Boat{
	public:
		Boat();

		byte howManyDepositedAtA();
		void updateDepositedAtA();

		byte howManyDepositedAtB();
		void updateDepositedAtB();

	private:
		byte depositedAtA;
		byte depositedAtB;

};

#endif