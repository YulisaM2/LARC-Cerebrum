#ifndef _BOAT_h
#define _BOAT_h

#include "Masks.h"

// Boats are the deposit areas where we need to leave the rods, we have two different areas where we can deposit rods in each boat, with a max height of 5 rods per stack

class Boat{
	public:
		Boat();

		byte howManyDepositedAtA();
		bool isAFull();
		void updateDepositedAtA();

		byte howManyDepositedAtB();
		bool isBFull();
		void updateDepositedAtB();

		byte howManyDepositedAtC();
		bool isCFull();
		void updateDepositedAtC();

		bool isBoatFull();

	private:
		byte depositedAtA;
		byte depositedAtB;
		byte depositedAtC;
		byte boatFull;

};

#endif