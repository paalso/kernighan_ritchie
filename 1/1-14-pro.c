// Еще одна версия для:
// Упражнение 1.14. Напишите программу, печатающую гистограммы частот встречаемости вводимых символов.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void print_symbols_row(char c, int n) {
	for (int i = 0; i < n; ++i)
		putchar(c);
	printf("\n");
}

int max_array_element_index(int* array, int len) {
	int max_index = 0;
	int max = array[max_index];
	for (int i = 1; i < len; ++i) {
		if (array[i] > max) {
			max_index = i;
			max = array[max_index];
		}
	}
	return max_index;
}


int main(int argc, char* argv[]) {
	const int MAX_SYMBOLS_ROW_LEN = 40;
	int symbols = 0, words = 0, lines = 0, total_letters = 0, digits = 0, vowels = 0;
	int letters[26] = {};
	int c;
	bool is_in_word = false;


	char input_filename[64];
	FILE *f;

	if (argc < 2) {
	    printf("Incorrect input.\nUsage: ./text_analuze input_file");
	    return 1;
	}

	strcpy(input_filename, argv[1]);
 
    if ((f = fopen(input_filename, "r")) == NULL) {
        printf("Can't open %s for reading.\n",input_filename);
        return 2;
    }

  	while ((c = fgetc(f)) != EOF) { 

  		if (c == ' ' || c == '\t' || c == '\n')
  			is_in_word = false;
  		else if (! is_in_word) {
  				is_in_word = true;
  				words += 1;
  		}
  		symbols += 1;
  		if (c == '\n')
  			lines += 1;
  		if (isdigit(c))
  			digits += 1;
  		if (isalpha(c)) {
  			total_letters += 1;
  			char l = tolower(c); 
  			letters[l - 'a'] += 1;
            if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u' || l == 'y')
                ++vowels;
  		}

	}

	fclose(f);

	// most frequent letter analyze

	int most_frequent_letter_index = max_array_element_index(letters, 26);
	float most_frequent_letter_share = (float) letters[most_frequent_letter_index] / total_letters;


	// --- Output ---------------------------
	printf("File %s processed\n\n", input_filename);
	printf("Total lines: %10d\n", lines);
	printf("Total words: %10d\n", words);
	printf("Total symbols: %8d\n", symbols);
	printf("      letters: %8d (%4.1f%%)\n", total_letters, (float) total_letters / symbols * 100);
	printf("      digits: %9d (%4.1f%%)\n", digits, (float) digits / symbols * 100);
	printf("Average word length: %.1f\n", (float) total_letters / words);
	printf("Letters info\n");
    printf("    vowels : %10d (%4.1f%%)\n", vowels, (float) vowels / total_letters * 100);
    printf(" consonant : %10d (%4.1f%%)\n", total_letters - vowels, (float) (total_letters - vowels) / total_letters * 100);
	printf("\n");
	for (int c = 'a'; c <= 'z'; ++c) {
		int letters_quant = letters[c - 'a'];
		printf("  %c %8d %5.1f%%  ",c, letters_quant, (float) letters_quant / total_letters * 100);
		int columns = (int)(((float) letters_quant / total_letters) / most_frequent_letter_share * MAX_SYMBOLS_ROW_LEN);

		// printf("%5.1f %5.1f \n", (float) letters_quant / total_letters * 100, most_frequent_letter_share * 100);

		print_symbols_row('*', columns);

	}


    return 0;
}