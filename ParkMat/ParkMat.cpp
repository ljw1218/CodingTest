#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;

    int maxx;
    int maxy;
    int max_size = 0;

    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] != "-1")
                continue;
            maxx = -1;
            maxy = 0;
            
            for (int h = i; h < park.size(); h++)
            {
                int temp_x = 0;
                if (park[h][j] != "-1")
                    break;
                maxy += 1;
                for (int k = j; k < park[h].size(); k++)
                {
                    if (park[h][k] == "-1")
                        temp_x += 1;
                    else
                    {
                        break;
                    }
                }
                if (maxx == -1 || temp_x < maxx)
                    maxx = temp_x;
                if (maxx <= maxy)
                {
                    if (maxx < maxy)
                        maxy -= 1;
                    break;
                }
            }
            if (max_size < maxy)
                max_size = maxy;
        }
    }
    for (int i = 0; i < mats.size(); i++)
    {
        if (mats[i] <= max_size)
        {
            if (answer < mats[i])
                answer = mats[i];
        }
    }
    return answer;
}

void main() {
    vector<int> mats = { 5,3,2 };
    vector<vector<string>> park = { {"A", "A", "-1", "B", "B", "B", "B", "-1"},{"A", "A", "-1", "B", "B", "B", "B", "-1"},
        {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"},{"D", "D", "-1", "-1", "-1", "-1", "E", "-1"}
    ,{"D", "D", "-1", "-1", "-1", "-1", "-1", "F"},{"D", "D", "-1", "-1", "-1", "-1", "E", "-1"} };

    int result = solution(mats, park);
    cout << result << endl;
}