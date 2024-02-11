#include "text_editor.h"
#include "text_encryptor.h"
#include <Windows.h>

char buffer[BUF_LEN];
FILE* in;

int main(int argc, char* argv[]) {

	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	
	if (argc != 2) { // exception, if invalid arguments passed
		fputs("Usage: SIUC_text_editor filename.txt", stderr);
		return -1;
	}

	
	memset(buffer, 0, BUF_LEN);

	char state = init(); // if user wants to start editing, creates file, otherwise, quit the program. 
	if (state == 'i') {
		system("cls");

		fopen_s(&in, argv[1], "wb");
		//fopen_s(&in, "test.txt", "wb");

		if (in == NULL) {
			return -1;
		}

		while (1) {
			strcpy_s(buffer, sizeof(char) * BUF_LEN, process());
			if (buffer[strlen(buffer) - 1] == 27) { // if user wants to quit the program
				if (strlen(buffer) > 2) {
					buffer[strlen(buffer)] = NULL;
					buffer[strlen(buffer) - 1] = '\0';
					encrypt(in, buffer);
					// encrypt rest and save, then quit the program.
					break;
				}
				else {
					// don't have anything to save, so quitting the program.
					break;
				}
			}
			else {
				encrypt(in, buffer);
			}
			memset(buffer, 0, sizeof(char) * BUF_LEN);
		}
	}
	else if (state == 'p') {
		char cmdLine[BUF_LEN];
		strcpy_s(cmdLine, BUF_LEN, "SIUC.exe ");
		strcat_s(cmdLine, BUF_LEN, argv[1]);
		cmdLine[strlen(cmdLine) + 1] = '\0';
		
		CreateProcessA(NULL, cmdLine, NULL, NULL, false, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else {
		return 0;
	}

	memset(buffer, 0, sizeof(char) * BUF_LEN);
	_itoa_s(N, buffer, 10);
	fputs(buffer, in);
	fclose(in);
	return 0;
}