#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int* input_value = new int[2];
    cin >> input_value[0] >> input_value[1];
    cin.ignore();
    map<pair<string, string>, string> m;

    vector<string> tag;
    for (int i = 0; i < input_value[0]; i++)
    {
        string query;
        getline(cin, query);
        int flag = 0;
        int flag2 = 0;
        string temp, at_name, at_val;
        string tag_temp;
      
        for (int j = 0; j < query.length(); j++)
        {

            if (j == 0)
                continue;
            else if (query[j] == '/') {
                tag.pop_back();
                break;
            }
                
            else if (query[j] == ' ' || query[j] == '>')
            {
                if (flag == 0)
                {
                    tag.push_back(tag_temp);
                    tag_temp = "";
                    flag = 1;
                }
                if (flag2 == 0 && flag == 1 && temp != "")
                {
                    at_name = temp;
                    temp = "";
                    flag2 = 1;
                }
                else
                {
                    temp = "";
                }
                continue;
            }
            else if (temp != "" && query[j] == '"')
            {
                at_val = temp;
                temp = "";
                flag2 = 0;
                for (int k = 0; k < tag.size(); k++)
                {
                    if (k > 0)
                        temp += ".";
                    temp += tag[k];
                }
                m[{temp, at_name}] = at_val;

                temp = "";
                at_val = "";
                at_name = "";
            }
            else {
                if (query[j] == '"')
                    continue;
                
                if (flag == 0)
                    tag_temp += query[j];
                else
                    temp += query[j];
            }

        }
        
    }
    for (int i = 0; i < input_value[1]; i++)
    {
        string qry;
        cin >> qry;
        string target, name;
        int flag = 0;
        for (int j = 0; j < qry.length(); j++)
        {
            if (qry[j] == '~')
            {
                flag = 1;
                continue;
            }

            if (flag == 0)
                target += qry[j];

            else
                name += qry[j];

        }
        if (m[{target, name}] == "")
        {
            cout << "Not Found!" << endl;
        }
        else
            cout << m[{target, name}] << endl;
    }
}
