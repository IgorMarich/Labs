
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <cstring>


char* reverseChar(char* s2,char* s,  int c)
{
	char* temp;
	temp = s2;
	for (int i = 0; i < c; i++)
		*s2++ = *s++;
	return temp;
}

int main()
{
	
	char s[] = "www.some_address.and_something_else.com";
	char s2[10] ;
	
	char* standard_result = strncpy(s2,s,9);
	
	char* my_result = reverseChar(s2,s,9);
	s2[9] = '\0';
	
	printf("Standard: %s\nMy version: %s\n" , standard_result,my_result);

	 
}
