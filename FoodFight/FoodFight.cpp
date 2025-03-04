#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    vector<int> cnt;
    for (int i = 1; i < food.size(); i++)
    {
        int value = (int)(food[i] / 2);
        cnt.push_back(value);
    }
    for (int i = 0; i < cnt.size(); i++)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            answer += to_string(i+1);
        }
    }
    string rev = "";

    for (int i = answer.length() - 1; i >= 0; i--){
        rev += answer[i];
    }
    answer += '0';
    answer += rev;
    return answer;
}