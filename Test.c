/*
 ============================================================================
 Name        : TestScoreStats.c
 Author      : Me
 Version     :
 Copyright   : Your copyright notice
 Description : Test Score Stats program in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); // Turn off output buffering. Required for automated testing.

	float score = 0.0; // variable that will hold the scores inputed by the user in a float form
	float sumScores = 0.0; // will hold the sum of the scores
	float sumScoresSquared = 0.0; // will hold the sum scores squared
	float minScores; // will hold the minimum scores
	float maxScores; // will hold the maximum scores
	float averageScores = 0.0; // will hold the average of the scores
	float standardDeviation = 0.0; // will hold the standard deviation of the scores

	char buffer[BUFSIZ + 1]; // buffer containing BUFSIZ bytes

	printf("Enter scores, one per line. Press <ENTER> on a blank line to end. \n");

	int counter = 0; // counter to count the number of floating point number entered by the user

	do {
		char* input = fgets(buffer, BUFSIZ, stdin);
		if (strlen(input) == 1) {
			break;
		}

		score = atof(input);
		counter++; // incrementation of the counter
		sumScores = sumScores + score; // the count of scores
		sumScoresSquared = sumScoresSquared + (score * score); // the standard deviation

		if (counter == 1) {
			minScores = maxScores = score;
		} else {
			if (score < minScores) { // the min score
				minScores = score;
			}
			if (score > maxScores) { // the max score
				maxScores = score;
			}
		}
		//printf("%f ", score);
	} while (buffer[0] != '\n');
	if (counter >= 1) {
		averageScores = (sumScores / counter); // the average of the scores
		standardDeviation = sqrt(
				(sumScoresSquared - ((sumScores * sumScores) / counter))
						/ counter); // formula of the standard deviation computation
	}

	printf("%d\t%f\t%f\t%f\t%f\n", counter, minScores, maxScores, averageScores,
			standardDeviation);

}

