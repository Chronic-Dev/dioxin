#include "includes/libdioxin.h"
#include "stdio.h"

int main() {
	iDevice *iphone = new iDevice();
	if (iphone != NULL) {
		int blah = iphone->enter_recovery();
		printf("%d", blah);
	}
	return 0;
}
