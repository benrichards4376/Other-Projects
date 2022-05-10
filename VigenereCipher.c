/*=============================================================================
| Assignment: pa01 - Encrypting a plaintext file using the Vigenere cipher
|
| Author: Benjamin Richards
| Language: c
|
| To Compile: javac pa01.java
| gcc -o pa01 pa01.c
| g++ -o pa01 pa01.cpp
|
| To Execute: java -> java pa01 kX.txt pX.txt
| or c++ -> ./pa01 kX.txt pX.txt
| or c -> ./pa01 kX.txt pX.txt
| where kX.txt is the keytext file
| and pX.txt is plaintext file
|
| Note: All input files are simple 8 bit ASCII input
|
| Class: CIS3360 - Security in Computing - Spring 2022
| Instructor: McAlpin
| Due Date: per assignment
|
+=============================================================================*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Removes all non-alphabetical characters and
// makes all characters lowercase
void get_shortened_text(char *string, char *buffer) 
{
	int i, str_len, index = 0;
	str_len = strlen(buffer);
	for (i = 0; i < str_len && index < 512; i++)
	{
		if (isalpha(buffer[i]))
		{
			
			string[index] = tolower(buffer[i]);
			index++;
			
		}
		else 
		{

			continue;
			
		}
		
	}
	
}

// Pads a string with characters depending on whether it is a key or plaintext
// (pads with x for plaintext and with the key repeated for a key)
void get_new_text(char *string, char version)
{
	int i, orig_str_len; 
	orig_str_len = strlen(string);
	if (version == 'p')
	{
		for (i = orig_str_len; i < 512; i++)
		{
			
			string[i] = 'x';
			
		}
	}
	else if (version == 'k') 
	{

		for (i = orig_str_len; i < 512; i++)
		{
			
			string[i] = string[i - orig_str_len];
			
		}
	}
}

// Performs the viginere cypher by converting letter range (0 - 26), adding the 
// plaintext and key and then taking the result modulo 26
void get_cipher_text(char *plain_text, char *key, char *cipher_text)
{
	
	int i;
	for (i = 0; i < 512; i++)
	{
		
		cipher_text[i] = (((plain_text[i] -'a') + (key[i] - 'a')) % 26) + 'a';
		
	}
	
}

// Uses fread to read the whole file and assigns its contents to either
// key or plaintext, depending on its respective version
void get_file_text(char *file_name, char *copy, char version)
{
	if (version == 'k' )
	{
		FILE *stream;
		stream = fopen(file_name, "r"); 
		fread(copy, sizeof(char), 2000, stream);
		
		fclose(stream);
	}
	
	else if (version == 'p')
	{
		
		FILE *stream;
		stream = fopen(file_name, "r"); 
		fread(copy, sizeof(char), 2000, stream);
		
		fclose(stream);
		
	}
}

// Prints the text in the proper format (80 characters max in each line)
void print_text(char *string)
{
	int i, j, str_len = strlen(string);
	for (i = 0; i < str_len; i++)
	{	
		if (i % 80 == 0)
		{
			printf("\n");
			
		}
		printf("%c", string[i]);
		
	}
}

// Reads 'plain_text' and 'key' from a file, and then performs a simple vigenere cipher with them
// and stores that in 'cipher_text' by passing the strings by reference
int main(int argc, char **argv) 
{
	
	int i, j;
	char *plain_text = malloc(sizeof(char) * 1000);
	char *key = malloc(sizeof(char) * 513);
	char *cipher_text = malloc(sizeof(char) * 513);
	char *key_copy = malloc(sizeof(char) * 2000);
	char *plain_text_copy = malloc(sizeof(char) * 2000);
	
	// Get and print the key
	get_file_text(argv[1], key_copy, 'k');
	printf("\n\nVigenere Key:\n");
	get_shortened_text(key, key_copy);
	print_text(key);
	get_new_text(key, 'k');
	
	// Get and print the plaintext
	get_file_text(argv[2], plain_text_copy, 'p');
	printf("\n\n\nPlaintext: \n");
	get_shortened_text(plain_text, plain_text_copy);
	get_new_text(plain_text, 'p');
	print_text(plain_text);
	
	// Get and print the ciphertext
	get_cipher_text(plain_text, key, cipher_text);
	printf("\n\n\nCiphertext: \n");
	print_text(cipher_text);
	printf("\n");
	
	free(key_copy);
	free(key);
	free(plain_text_copy);
	free(plain_text);
	free(cipher_text); 
}


/*=============================================================================
| I Benjamin Richards (4674000) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/