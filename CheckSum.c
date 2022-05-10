/*=============================================================================
| Assignment: pa02 - Calculating an 8, 16, or 32 bit
| checksum on an ASCII input file
|
| Author: Benjamin Richards
| Language: c
|
| To Compile: javac pa02.java
| gcc -o pa02 pa02.c
| g++ -o pa02 pa02.cpp
| go build pa02.go
| python pa02.py //Caution - expecting input parameters
|
| To Execute: java -> java pa02 inputFile.txt 8
| or c++ -> ./pa02 inputFile.txt 8
| or c -> ./pa02 inputFile.txt 8
| or go -> ./pa02 inputFile.txt 8
| or python-> python pa02.py inputFile.txt 8
| where inputFile.txt is an ASCII input file
| and the number 8 could also be 16 or 32
| which are the valid checksum sizes, all
| other values are rejected with an error message
| and program termination
|
| Note: All input files are simple 8 bit ASCII input
|
| Class: CIS3360 - Security in Computing - Spring 2022
CIS3360-McAlpin PA 2 
| Instructor: McAlpin
| Due Date: per assignment
|
+=============================================================================*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_padded_text(char *string, int version)
{
	int i, new_str_len, orig_str_len;
		
	orig_str_len = strlen(string);
	string[orig_str_len + 1] = '\0';
	if (version == 16 && orig_str_len % 2 != 0)
	{
		
		string[orig_str_len] = 'X';
		string[orig_str_len + 1] = '\0';
	}
	
	if (version == 32 && orig_str_len % 4 != 0)
	{
		
		while (orig_str_len % 4 != 0)
		{
			
			string[orig_str_len++] = 'X';
			
		}
		string[orig_str_len + 1] = '\0';

	}
	
	return string;
	
}

char *get_file_text(char *file_name, char *copy)
{
		
	FILE *stream;
	stream = fopen(file_name, "r"); 
	fgets(copy, 2000, stream);
	
	fclose(stream);
	return copy;
}

void print_text(char *string)
{
	int i, str_len = strlen(string);
	
	for (i = 0; i < str_len; i++)
	{	
		if (i != 0 && i % 80 == 0)
		{
			printf("\n");
			
		}
		printf("%c", string[i]);
		
	}
	
}


long unsigned int get_check_sum(unsigned char *plain_text, int version)
{
	int i, j;
	int str_len = strlen(plain_text);
	long unsigned int check_sum = 0;
	long unsigned int m = 256 * 256;
	m *= 256;
	m *= 256;
	if (version == 8)
	{
		for (i = 0; i < str_len; i++)
		{
			
			check_sum += plain_text[i];
			if (check_sum > 256)
				check_sum %= 256;
		}
	}
	
	else if (version == 16)
	{
		
		for (i = 0; i < str_len; i += 2)
		{
			
			check_sum += (plain_text[i] * 256);			
			check_sum += plain_text[i + 1];
		}
		check_sum %= (256 * 256);
	}
	
	else if (version == 32)
	{
		for (i = 0; i < str_len; i += 4)
		{
			
			check_sum += (plain_text[i] * 256 * 256 * 256);			
			check_sum += (plain_text[i + 1] * 256) * 256;
			check_sum += (plain_text[i + 2] * 256);
			check_sum += (plain_text[i + 3]);
			
		}		
		check_sum %= m;
	}
	return (long unsigned int) check_sum;
}

int main(int argc, char **argv)
{
	char *plain_text = malloc(sizeof(char) * 2000);
	long unsigned int check_sum;
	int version = atoi(argv[2]);
	int character_count;
	if (version != 8 && version != 16 && version != 32)
	{
		
		fprintf(stderr, "Valid checksum sizes are 8, 16, or 32\n");
		return 0;
		
	}
	
	plain_text = get_file_text(argv[1], plain_text); 
	plain_text = get_padded_text(plain_text, version);
	character_count = strlen(plain_text);
	printf("\n");
	print_text(plain_text);
	printf("\n");
	check_sum = get_check_sum(plain_text, version);
	printf("%2d bit checksum is %8lx for all %4d chars\n", version, check_sum, character_count);
	
	
	free(plain_text);
	
}

/*=============================================================================
| I Benjamin Richards 4674000 affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/