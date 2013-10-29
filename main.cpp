#include <iostream>
#include "mortonkeys.h"


#define TESTSIZE 512

int main()
{
	//init vectors with precomputed morton keys
	morton<256, 0>::add_values(mortonkeyX);
	morton<256, 1>::add_values(mortonkeyY);
	morton<256, 2>::add_values(mortonkeyZ);

	uint64_t key;

	for (int x = 0; x <= TESTSIZE; ++x)
	  for (int y = 0; y <= TESTSIZE; ++y)
	    for (int z = 0; z <= TESTSIZE; ++z)
	    {
		  key = encodeMortonKey(x, y, z);
	    }

	std::cout << key << std::endl;

}
