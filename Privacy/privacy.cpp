#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> day_split(string str,int type)
{
    istringstream iss(str);
    string buffer;

    vector<string> result;

    if (type != 2)
    {
        getline(iss, buffer, '.');
        result.push_back(buffer);
        getline(iss, buffer, '.');
        result.push_back(buffer);
        getline(iss, buffer, ' ');
        result.push_back(buffer);
        if (type == 3)
        {
            getline(iss, buffer, ' ');
            result.push_back(buffer);
        }
    }
    else
    {
        getline(iss, buffer, ' ');
        result.push_back(buffer);
        getline(iss, buffer, ' ');
        result.push_back(buffer);
    }
    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    map<string, int> map_term;

    vector<string> v_today = day_split(today, 1);
    vector<int> i_today;
    vector<int> i_Nprivacies;

    for (int i = 0; i < v_today.size(); i++)
    {
        i_today.push_back(atoi(v_today[i].c_str()));
    }

    vector<string> strtemp;

    for (int i = 0; i < terms.size(); i++)
    {
        strtemp = day_split(terms[i], 2);
        map_term.insert({ strtemp[0], atoi(strtemp[1].c_str()) });
        strtemp.clear();
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        strtemp = day_split(privacies[i], 3);
        for (int j = 0; j < 3; j++)
        {
            i_Nprivacies.push_back(atoi(strtemp[j].c_str()));
        }
        i_Nprivacies[1] += map_term[strtemp[3]];
        if (i_Nprivacies[1] > 12)
        {
            int year;
            if (i_Nprivacies[1] % 12 == 0)
                year = (i_Nprivacies[1] / 12) - 1;
            else
                year = i_Nprivacies[1] / 12;
            i_Nprivacies[0] += 1*year;
            i_Nprivacies[1] -= 12*year;
        }
        for (int k = 0; k < 3; k++)
        {
            if (k == 2)
            {
                if (i_Nprivacies[k] <= i_today[k])
                    answer.push_back(i+1);
            }
            else {
                if (i_Nprivacies[k] < i_today[k])
                {
                    answer.push_back(i + 1);
                    break;
                }
                else if (i_Nprivacies[k] > i_today[k])
                    break;
            }
        }
        strtemp.clear();
        i_Nprivacies.clear();
    }

    return answer;
}

void main()
{
    string today = "2022.05.19";
    vector<string> terms = { "Z 27", "D 29" };
    vector<string> privacies = { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" };
    
    /*vector<string> test = day_split(privacies[0], 3);
    for (vector<string>::iterator iter = test.begin(); iter != test.end(); ++iter)
    {
        cout << *iter << " ";
    }*/

    vector<int> result = solution(today, terms, privacies);
    for (vector<int>::iterator iter=result.begin(); iter != result.end(); ++iter)
    {
        cout << *iter << " ";
    }
}