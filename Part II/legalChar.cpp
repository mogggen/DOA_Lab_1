#include "legalChar.h"

char legalChar(char value)
{
	value = value | ('A' ^ 'a');
	if ('a' <= value && value <= 'z')
		return value;
	else
		return '\\';
}