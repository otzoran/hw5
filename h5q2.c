#include <stdio.h>
#include <stdlib.h>

int input_val(char *p) ;

int main()
{
	int		*coin_face_values;
	int		num_of_coins;
	int		sum_of_coins;
	int		max_coins_to_use;
	int		ii;
	int		number_of_combinations = 0;

    
	num_of_coins = input_val("Enter number of coins to use: ");
	sum_of_coins = input_val("Enter sum of coins: ");
	max_coins_to_use = input_val("Enter how many coins max: ");

	coin_face_values = malloc(sizeof(num_of_coins) * num_of_coins);
	for (ii = 0; ii < num_of_coins; ii++) {
		printf("[coin[%d] ", ii);
		coin_face_values[ii] = input_val("Enter face value of coin: ");
		// check no dups4
	}

	printf("number_of_combinations of found: %d\n", number_of_combinations);

    return 0;
}

int input_val(char *p) {
	int		val, ret;

	// make func to grab int input
    printf("%s", p);
	ret = scanf("%d\n", &val);
	if (ret == 1) 
		return val;
	// err
	printf("error scanf\n");
	exit(1);
}
