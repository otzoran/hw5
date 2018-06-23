#include <stdio.h>

int main()
{
	int		coin_face_values[];
	int		num_of_coins;
	int		sum_of_coins;
	int		max_coins_to_use;
	int		ii;
	int		number_of_combinations = 0;

    
    printf("Enter number of coins to use: ");
		// make func to grab int input
	if (scanf("%d ", &num_of_coins) != 1) {
		printf("error scanf\n");
		exit(1);
	}

    printf("Enter sum of coins: ");
		// make func to grab int input
	if (scanf("%d ", &sum_of_coins) != 1) {
		printf("error scanf\n");
		exit(1);
	}

	// same func to grab max_coins_to_use
	

	coin_face_values = malloc(sizeof(num_of_coins) * num_of_coins);
	for (ii = 0; ii < num_of_coins; ii++) {
		printf("Enter face value of coin %d: ", ii);
		// check no dups
		if (scanf("%d ", coin_face_values[ii]) != 1) {
			printf("error scanf\n");
			exit(1);
		}
	}

	printf("number_of_combinations of found: %d\n", number_of_combinations);

    return 0;
}
