#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input_val(char *p) ;
int match_combination(int csum, int idx, int ucoins);

int		*coin_face_values;
int		num_of_coins;
int		sum_of_coins;
int		max_coins_to_use;

int main()
{
	int		ii;
	int		number_of_combinations = 0;

    
	num_of_coins = input_val("Enter number of coins to use: ");
	sum_of_coins = input_val("Enter sum of coins: ");
	max_coins_to_use = input_val("Enter how many coins max: ");

	printf("DEB: Coin values: enter from high -> low, e.g. 10, 5, 2, 1\n");
	coin_face_values = malloc(sizeof(num_of_coins) * num_of_coins);
	for (ii = 0; ii < num_of_coins; ii++) {
		printf("coin[%d] ", ii);
		coin_face_values[ii] = input_val("Enter face value of coin: ");
		// check no dups
		// sort the array of coins from high -> low
	}
	printf("\n\n");

	number_of_combinations = match_combination(0, 0, 0);

	printf("number_of_combinations of found: %d\n", number_of_combinations);

    return 0;
}

int match_combination(int csum, int idx, int ucoins)
{
	/* csum   == current sum of combination */
	/* idx    == index into array of coin_face_values to start with */
	/* ucoins == coins used so far */
	int		ii, ret;
	int		icoins = ucoins;
	int		isum = csum;

	for (ii = 0; ii < max_coins_to_use - icoins; ii++) {
		isum = ii * coin_face_values[idx]; 
		icoins++;
		printf("DEB: idx = %2d ii = %2d isum = %3d icoins = %3d\n", idx, ii, isum, icoins);
		if (isum == sum_of_coins) {
			printf("[idx = %3d] found combination\n", idx);
			return 1;
		}
		if (isum > sum_of_coins || idx >= num_of_coins || icoins > num_of_coins) {
			break;
		}
		if (isum < sum_of_coins && (idx < num_of_coins - 1)) {
			ret = match_combination(isum, idx + 1, icoins);
			// return ret;
		}
	}
	return 0;
} /* match_combination */


#define LINE_MAX 32

int input_val(char *p) {
	int		val, ret;
	char 	buf[LINE_MAX];

	// make func to grab int input

	printf("%s", p);
    if (fgets(buf, sizeof buf, stdin) != NULL) {
		buf[strlen(buf) - 1] = 0;
		val = strtol(buf, NULL, 10);
		return val;
	}
	// err
	printf("error scanf\n");
	exit(1);
}
