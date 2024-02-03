#include "text_encryptor.h"

void encrypt(FILE* file, char* data) {
	char encrypted[BUF_LEN];
	memset(encrypted, 0, sizeof(char) * BUF_LEN);
	int result = 0;
	int idx;
	while (*data != NULL) {
		idx = 0;
		while ((*data * E) > (N * idx)) {
			idx++;
		}
		idx -= 1;
		result = (*data * E) - (N * idx);
		_itoa_s(result, encrypted, 10);
		encrypted[strlen(encrypted)] = '\0';
		fputs(encrypted, file);
		fputc(cutter, file);
		memset(encrypted, 0, sizeof(char) * BUF_LEN);
		_itoa_s(idx, encrypted, 10);
		encrypted[strlen(encrypted)] = '\0';
		fputs(encrypted, file);
		fputc(cutter, file);
		data++;
	}
	fputs("32", file);
	fputc(cutter, file);
}