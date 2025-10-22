#include <stdio.h>
#include <string.h>

// Relevant portion only.
int functionss(char* varz) {
	char var2[12] = { '\0' };
	strcpy_s(var2, sizeof(var2), varz);
	if (strlen(var2) == 11) {
		if (var2[0] == 'A' && var2[3] == 'X' && var2[7] == 'X') {
			printf("Your key is valid proceed\n");
			return 1;
		}
		else {
			printf("Wrong key");
			return -1;
		}
	}
	else if (var2 > 11) {
		printf("Key length is above 11\n");
		return -1;
	}
	return 0;
}

int main(int argc, char* argv[]) {
	char input[12] = { '\0' };
	printf("Enter the key: ");
	scanf_s("%s", input, sizeof(input));
	functionss(input);
}
