#include <stdio.h>
#include <string.h>

// It's not 100% accurate but this is bare bones the relevant code.
void functionss(char* varz) {
	char var2[12] = { '\0' };
	strcpy_s(var2, sizeof(var2), varz);
	if (strlen(var2) == 11) {
		if (var2[0] == 'A' && var2[3] == 'X' && var2[7] == 'X') {
			printf("Your key is valid proceed\n");
		}
		else {
			printf("Wrong key");
		}
	}
	else {
		printf("Key length is above 11\n");
	}
}

int main(int argc, char* argv[]) {
	char input[12] = { '\0' };
	printf("Enter the key: ");
	scanf_s("%s", input, sizeof(input));
	functionss(input);
}
