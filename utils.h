#ifndef _UTILS_H_
#define _UTILS_H_

void clear_ibuffer();
char* get_string(int size, const char* prompt, int* o_size);
int get_int(char* prompt);
char get_char(char* prompt);

#endif
