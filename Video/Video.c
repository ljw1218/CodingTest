#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>



char* change(char* pos, char* command) {
    
}

char* solution(const char* video_len, const char* pos, const char* op_start, const char* op_end, const char* commands[], size_t commands_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    commands_len = strlen(*commands) - 1;
    int forlen = commands_len;
    int ipos, ivlen ,istart,iend;
    ivlen = (video_len[0] - '0') * 1000 + (video_len[1] - '0') * 100 + (video_len[3] - '0') * 10 + (video_len[4] - '0');
    ipos = (pos[0] - '0') * 1000 + (pos[1] - '0') * 100 + (pos[3] - '0') * 10 + (pos[4] - '0');
    istart = (op_start[0] - '0') * 1000 + (op_start[1] - '0') * 100 + (op_start[3] - '0') * 10 + (op_start[4] - '0');
    iend = (op_end[0] - '0') * 1000 + (op_end[1] - '0') * 100 + (op_end[3] - '0') * 10 + (op_end[4] - '0');

    if (ipos >= istart && ipos <= iend) {
        pos = op_end;
        ipos = iend;
    }

    for (int i = 0; i < commands_len; i++)
    {
        if (commands[i] == "prev") {
            ipos -= 10;
            if (ipos / 100 >= 60) {
                ipos -= 40;
            }
            if (ipos < 0) {
                ipos = 0;
            }
        }
        else if (commands[i] == "next") {
            ipos += 10;
            if (ipos / 100 >= 60) {
                ipos += 40;
            }
            if (ipos > ivlen) {
                ipos = ivlen;
            }
        }

        if (ipos >= istart && ipos <= iend) {
            ipos = iend;
        }
    }
    
    char* answer = (char*)malloc(strlen(video_len));
    sprintf(answer, "%02d:%02d", ipos / 100, ipos % 100);

    return answer;
}

void main() {
    char* commands[] = { "prev", "next", "next",NULL };
    //char* result = solution("10:55", "00:05", "00:15", "06:55",commands,3);
    //printf("%s", result);
    size_t a = 11;
    int b = a;
    printf("%d", b);
    
}