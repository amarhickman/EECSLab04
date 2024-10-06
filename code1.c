/*code1.c*/
#include <stdio.h>

/*defining point system*/
typedef enum {
    TD_2PT,
    TD_FG,
    TD,
    FG,
    SAFETY
} ScoringPlay;

int scoringPlays[] = {8, 7, 6, 3, 2};

/*Function to mkake all possible combos */
void generateCombinations(int score, int td_2pt, int td_fg, int td, int fg, int safety) {
    if (score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_fg, td, fg, safety);
        return;
    }

    for (int i = 0; i < 5; i++) {/*Loops through all five use cases it can score*/
        int newScore = score - scoringPlays[i]; /*Goes through iteration by subtracting score by possible ways to score*/
        if (newScore >= 0) {
            switch (i) {/*switch command to change between scoring cases */
                case TD_2PT: /*Touchdown and 2Point Conversion*/
                    generateCombinations(newScore, td_2pt + 1, td_fg, td, fg, safety);
                    break;
                case TD_FG: /*Touchdown and Fieldgoal*/
                    generateCombinations(newScore, td_2pt, td_fg + 1, td, fg, safety);
                    break;
                case TD: /*Touchdown*/
                    generateCombinations(newScore, td_2pt, td_fg, td + 1, fg, safety);
                    break;
                case FG: /*Fieldgoal*/
                    generateCombinations(newScore, td_2pt, td_fg, td, fg + 1, safety);
                    break;
                case SAFETY: /*Safety*/
                    generateCombinations(newScore, td_2pt, td_fg, td, fg, safety + 1);
                    break;
            }
        }
    }
}

int main() {
    int score;
    printf("Enter 0 or 1 to STOP\n");
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }
        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
        generateCombinations(score, 0, 0, 0, 0, 0);
    }
    return 0;
}