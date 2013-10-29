
#include <iostream>
#include <cstdint>
#include <vector>

#define MAXMORTONKEY 1317624576693539401 //21 bits MAX morton key

std::vector<uint64_t> mortonkeyX;
std::vector<uint64_t> mortonkeyY;
std::vector<uint64_t> mortonkeyZ;

/*Compute a 256 array of morton keys at compile time*/
template <uint32_t i, uint32_t offset>
struct morton
{
	enum
	{
		//Use a little trick to calculate next morton key
		//mortonkey(x+1) = (mortonkey(x) - MAXMORTONKEY) & MORTONKEY
		value = (morton<i - 1, offset>::value - MAXMORTONKEY) & MAXMORTONKEY
	};
	static void add_values(std::vector<uint64_t>& v)
	{
		morton<i - 1, offset>::add_values(v);
		v.push_back(value<<offset);
	}
};

template <uint32_t offset>
struct morton<0, offset>
{
	enum
	{
		value = 0
	};
	static void add_values(std::vector<uint64_t>& v)
	{
		v.push_back(value);
	}
};

inline uint64_t encodeMortonKey(uint32_t x, uint32_t y, uint32_t z){
	uint64_t result = 0;
	result = mortonkeyZ[(z >> 16) & 0xFF] |
		mortonkeyY[(y >> 16) & 0xFF] |
		mortonkeyX[(x >> 16) & 0xFF];
	result = result << 48 |
		mortonkeyZ[(z >> 8) & 0xFF] |
		mortonkeyY[(y >> 8) & 0xFF] |
		mortonkeyX[(x >> 8) & 0xFF];
	result = result << 24 |
		mortonkeyZ[(z)& 0xFF] |
		mortonkeyY[(y)& 0xFF] |
		mortonkeyX[(x)& 0xFF];
	return result;
}

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