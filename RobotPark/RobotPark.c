#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// park_len�� �迭 park�� �����Դϴ�.
// routes_len�� �迭 routes�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(2*sizeof(int));
    
    int x, y;
    int width = strlen(park[0]);
    int height = park_len;

    for (size_t i = 0; i < park_len; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (park[i][j] == 'S')
            {
                x = j;
                y = i;
            }
        }
    }
    char* cp_direction;
    char* cp_len;
    char direction;
    int len;

    for (size_t i = 0; i < routes_len; i++)
    {
        char str[10];
        strcpy(str, routes[i]);
        cp_direction = strtok(str, " ");
        cp_len = strtok(NULL, " ");
        direction = cp_direction[0];
        len = cp_len[0] - '0';
        
        if (direction == 'E')
        {
            if (x + len > width-1)
                continue;
            else
            {
                bool bfence = false;
                for (int j = x; j < x + len + 1; j++)
                {
                    if (park[y][j] == 'X')
                    {
                        bfence = true;
                        break;
                    }
                }
                if (bfence == true)
                    continue;
                else
                {
                    x += len;
                }
            }
        }
        else if (direction == 'W')
        {
            if (x - len < 0)
                continue;
            else
            {
                bool bfence = false;
                for (int j = x; j > x - len - 1 ; j--)
                {
                    if (park[y][j] == 'X')
                    {
                        bfence = true;
                        break;
                    }
                }
                if (bfence == true)
                    continue;
                else
                {
                    x -= len;
                }
            }
        }
        else if (direction == 'N')
        {
            if (y - len < 0)
                continue;
            else
            {
                bool bfence = false;
                for (int j = y; j > y - len - 1; j--)
                {
                    if (park[j][x] == 'X')
                    {
                        bfence = true;
                        break;
                    }
                }
                if (bfence == true)
                    continue;
                else
                {
                    y -= len;
                }
            }
        }
        else if (direction == 'S')
        {
            if (y + len > height-1)
                continue;
            else
            {
                bool bfence = false;
                for (int j = y; j < y + len + 1; j++)
                {
                    if (park[j][x] == 'X')
                    {
                        bfence = true;
                        break;
                    }
                }
                if (bfence == true)
                    continue;
                else
                {
                    y += len;
                }
            }
        }

    }
    for (int i = 0; i < 2; i++)
    {
        answer[i] = malloc(sizeof(int) * 2);
    }
    answer[0] = y;
    answer[1] = x;

    return answer;
}

int main()
{
    const char* park[] = { "OSO", "OOO", "OXO", "OOO" };
    size_t park_len = sizeof(park) / sizeof(char*);
    //printf("%d", park_len);
    const char* routes[] = { "E 2", "S 3", "W 1" };
    size_t routes_len = sizeof(routes) / sizeof(char*);
    int* result = solution(park, park_len, routes, routes_len);
    for (int i = 0; i < 2; i++)
        printf("%d ", result[i]);

}