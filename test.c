#include <stdio.h>

int main( void ) {
	printf("Valeur decalage : %ld\nValeur puissace : %d", 2147483649 %( 2 << 30), 5*16*16);
}

// 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1
// -------------------------------+----
//                          1   1



// x % (2 << 30)