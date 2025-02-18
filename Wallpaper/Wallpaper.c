#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// wallpaper_len은 배열 wallpaper의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* wallpaper[], size_t wallpaper_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(4 * sizeof(int));

    int minx = -1;
    int miny = -1;
    int maxx = -1;
    int maxy = -1;
    bool first = false;

    for (size_t i = 0; i < wallpaper_len; i++)
    {
        for (size_t j = 0; j < strlen(wallpaper[i]); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                if (first == false)
                {
                    answer[1] = j;
                    answer[0] = i;
                    answer[3] = j;
                    answer[2] = i;
                    first = true;
                }
                else
                {
                    if (j < answer[1])
                        answer[1] = j;
                    if (answer[3] < j)
                        answer[3] = j;
                    if (answer[2] < i)
                        answer[2] = i;
                }
            }
        }
    }
    answer[2] += 1;
    answer[3] += 1;

    return answer;
}

int main()
{
    const char* wallpaper[] = { ".#...", "..#..", "...#." };
    size_t wallpaper_len = sizeof(wallpaper) / sizeof(char*);
    int* result = solution(wallpaper, wallpaper_len);
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", result[i]);
    }
}