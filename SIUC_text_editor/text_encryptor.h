#pragma once
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

#define BUF_LEN 256

const int N = 234;
const int E = 12345;
const char cutter = ' ';

void encrypt(FILE* file, char* data);