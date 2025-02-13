#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    map<string, int> run;
    
    for (int i = 0; i < players.size(); i++)
    {
        run.insert({ players[i], i });
    }

    for (vector<string>::iterator iter = callings.begin(); iter != callings.end(); ++iter)
    {
        int idx = run[*iter];
        string temp = players[idx-1];
        players[idx - 1] = players[idx];
        players[idx] = temp;
        run[temp]++;
        run[*iter]--;
    }

    for (vector<string>::iterator iter = players.begin(); iter != players.end(); ++iter)
        answer.push_back(*iter);

    return answer;
}

int main() {
    vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
    vector<string> callings = { "kai", "kai", "mine", "mine" };

    vector<string> result = solution(players, callings);

    for (vector<string>::iterator iter = result.begin(); iter != result.end(); ++iter)
        cout << *iter << "\n";
}