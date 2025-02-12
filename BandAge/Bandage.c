#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len은 배열 bandage의 길이입니다.
// attacks_rows는 2차원 배열 attacks의 행 길이, attacks_cols는 2차원 배열 attacks의 열 길이입니다.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int answer = 0;
    int hp_now = health;
    int healtime = 0;

    for (size_t i = 0; i < attacks_rows; i++)
    {
        hp_now -= attacks[i][1];
        if (hp_now <= 0)
        {
            answer = -1;
            break;  
        }
        if (i == (attacks_rows-1))
        {
            answer = hp_now;
            break;
        }
        healtime = attacks[i + 1][0] - attacks[i][0] - 1;
        hp_now += bandage[1] * healtime + bandage[2] * (healtime / bandage[0]);
        if (hp_now > health)
            hp_now = health;

    }

    return answer;
}
