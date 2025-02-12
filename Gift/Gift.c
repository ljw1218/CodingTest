#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// friends_len은 배열 friends의 길이입니다.
// gifts_len은 배열 gifts의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* friends[], size_t friends_len, const char* gifts[], size_t gifts_len) {
    int answer = 0;
    int* gift_point; // 선물지수
    gift_point = (int*)malloc(friends_len * sizeof(int));
    int** gift_graph; // 주고 받은 내역? 그런거
    gift_graph = (int**)malloc(sizeof(int*) * friends_len);
    int* total;
    total = (int*)malloc(friends_len * sizeof(int));

    for (size_t i = 0; i < friends_len; i++)
    {
        total[i] = 0;
        gift_point[i] = 0;
        gift_graph[i] = (int*)malloc(sizeof(int) * friends_len);
        for (size_t j = 0; j < friends_len; j++)
        {
            gift_graph[i][j] = 0;
        }
    }

    int flag = 0;
    char* send = "";
    char* receive = "";
    int row, col;
    int bp = 0;

    for (size_t i = 0; i < gifts_len; i++)  // 선물 for문
    {
        send = "";
        receive = "";
        row = 0;
        col = 0;
        bp = 0;
        flag = 0;
        char temp[] = "";
        strcpy(temp, gifts[i]);
        send = strtok(temp, " ");
        receive = strtok(NULL, " ");

        
        //for (size_t j = 0; j < strlen(gifts[i]); j++) // split 해서 보낸이 받은이 저장
        //{
        //    if (gifts[i][j] == ' ')
        //    {
        //        flag = 1;
        //        continue;
        //    }
        //    else if (flag == 0)
        //    {

        //    }
        //    else
        //    {
        //        receive_temp[j] = gifts[i][j];
        //    }
        //}

        for (size_t k = 0; k < friends_len; k++) // 2차원배열에 + 해줌
        {
            if (strcmp(friends[k],send) == 0)
            {
                row = k;
                bp += 1;
            }
            else if (strcmp(friends[k], receive) == 0)
            {
                col = k;
                bp += 1;
            }
            if (bp == 2)
            {
                gift_graph[row][col] += 1;
                gift_point[col] -= 1;
                gift_point[row] += 1;
                break;
            }
        }
    }

    for (size_t i = 0; i < friends_len; i++)
    {
        for (size_t j = 0; j < friends_len; j++)
        {
            if (i >= j)
                continue;
            if (gift_graph[i][j] > gift_graph[j][i])
            {
                total[i] += 1;
            }
            else if (gift_graph[i][j] == gift_graph[j][i])
            {
                if (gift_point[i] == gift_point[j])
                    continue;

                else if (gift_point[i] > gift_point[j])
                    total[i] += 1;

                else
                    total[j] += 1;
            }
            else
            {
                total[j] += 1;
            }
        }
    }
    answer = total[0];
    for (size_t i = 1; i < friends_len; i++)
    {
        if (answer < total[i])
            answer = total[i];
    }
    return answer;
}

int main() {
    const char* friends[] = { "joy", "brad", "alessandro", "conan", "david" };
    size_t friends_len = sizeof(friends)/sizeof(char*);
    const char* gifts[] = { "alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david" };
    size_t gifts_len = sizeof(gifts) / sizeof(char*);
    int result = solution(friends, friends_len, gifts, gifts_len);

    printf("%d", result);
    
}