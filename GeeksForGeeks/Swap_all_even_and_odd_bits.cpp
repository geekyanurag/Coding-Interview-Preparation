// Given the number swap the even bits and odd bits.
unsigned int swapBits(unsigned int n)
{
	unsigned int evenbits = n & 0xAAAAAAAA;   // 0xAAAAAAAA gives all the 32-bit even bits with 1 and odd bits with 0.
	unsigned int oddbits = n & 0x55555555;    // 0x55555555 gives all the 32-bit odd bits with 1 and even bits with 0.
	evenbits >>= 1;
	oddbits <<= 1;
	return (evenbits | oddbits);
}