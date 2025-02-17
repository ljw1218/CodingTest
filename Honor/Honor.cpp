#include <string>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    int* honor = new int[k];
    int minimum = 0;

    int templength = k;
    if (score.size() < k){
        templength = score.size();
    }
    
    for (int i = 0; i < templength; i++){
        if (i == 0)
            minimum = score[i];
        else if (minimum > score[i])
            minimum = score[i];
        honor[i] = score[i];
        answer.push_back(minimum);
    }
    for (int i = k; i < score.size(); i++)
    {
        if (score[i] > minimum)
        {
            int tempmini = score[i];
            int flag = 0;
            for (int j = 0; j < k; j++)
            {
                
                if (honor[j] == minimum && flag == 0){
                    flag = 1;
                    honor[j] = score[i];
                }
                if (honor[j] <= tempmini)
                    tempmini = honor[j];
            }
            minimum = tempmini;
        }
        answer.push_back(minimum);
    }
    
    return answer;
}