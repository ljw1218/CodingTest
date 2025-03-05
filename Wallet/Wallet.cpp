#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    while (true) {
        if (wallet[0] >= bill[0])
        {
            if (wallet[1] >= bill[1])
            {
                break;
            }
        }
        if (wallet[0] >= bill[1])
        {
            if (wallet[1] >= bill[0])
            {
                break;
            }
        }
        if (bill[0] > bill[1])
        {
            bill[0] /= 2;
            answer++;
        }
        else {
            bill[1] /= 2;
            answer++;
                
        }
    }

    return answer;
}

void main() {
    vector<int> wallet = { 50,50 };
    vector<int> bill = { 100,241 };
    int result = solution(wallet, bill);
    cout << result << endl;
}