#include "text_editor.h"

char init() {
	char c;
	fputs("------------------------------\n", stdout);
	fputs("|                            |\n", stdout);
	fputs("|            SIUC            |\n", stdout);
	fputs("|           ver 0.1          |\n", stdout);
	fputs("|    i to start, q to exit   |\n", stdout);
	fputs("|       p to interprete      |\n", stdout);
	fputs("------------------------------\n", stdout);
	while (1) {
		c = getchar();
		if (c == 'i' || c == 'q' || c == 'p') {
			break;
		}
	}
	return c;
}

char* process() {
	//char* buffer = (char*)malloc(sizeof(char) * BUF_LEN);
	char buffer[BUF_LEN]; // string buffer
	memset(buffer, 0, sizeof(char) * BUF_LEN);
	int idx = 0; // string index
	char ch = ' '; // input value

	while (1) { 
		ch = _getch();
		putc(ch, stdout);

		if (ch == 27) { // if esc entered
			printf("\n");
			printf("Quit and save the program? r to resume, q to save and quit\n");
			ch = _getch();
			if (ch == 'r') {
				printf("\n");
				ch = ' ';
				continue;
			}
			else if (ch == 'q') {
				buffer[idx] = 27;
				buffer[idx + 1] = '\0';
				return buffer;
			}
		}

		if (ch == 13) { // if enter given, passes the string
			printf("\n");
			break;
		}

		if (idx > 0 && ch == 8) { // if backspaced, sub 1 from string index
			idx--;
		}
		else if(idx <= 0 && ch == 8){ // if index is at 0, keep it 0
			idx = 0;
		}
		buffer[idx] = ch;
		idx++;
	}

	buffer[idx] = '\0'; // putting terminal 0 to the end of the string.
	return buffer;
}