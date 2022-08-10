//https://open.kattis.com/problems/basicinterpreter
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define mp map <int, vector<string> >
mp program;
int value[26];
char input[1000];
char sep[] = " \n";

void output(mp::iterator it, bool newline)
{

    char first = it->second[1][0];

    if(first == '"')
        //for(int i = 1; i < it->second[1].size() - 1; ++i)
                printf("%s", it->second[1].c_str() + 1);
    else
        printf("%d", value[first - 'A']);

    if(newline)
        printf("\n");

}

void let(mp::iterator it)
{
    char cur = it->second[1][0] - 'A';
    string val = it->second[3];
    int newVal = isalpha(val[0])? value[val[0] - 'A'] : stoi(val);

    if(it->second.begin() + 4 != it->second.end())
    {
        char op = it->second[4][0];
        val = it->second[5];
        int rhs = isalpha(val[0])? value[val[0] - 'A'] : stoi(val);

        if(op == '+')
            newVal += rhs;
        else if(op == '-')
            newVal -= rhs;
        else if(op == '*')
            newVal *= rhs;
        else if(op == '/')
            newVal /= rhs;
    }

    value[cur] = newVal;
}

bool eval(int lhs, int rhs, string &op)
{
    if(op == "<" ) return lhs < rhs;
    if(op == ">" ) return lhs > rhs;
    if(op == "=" ) return lhs == rhs;
    if(op == "<>") return lhs != rhs;
    if(op == "<=") return lhs <= rhs;
    if(op == ">=") return lhs >= rhs;

    return 0;
}

void IF(mp::iterator &it)
{
    string lhs = it->second[1];
    string rhs = it->second[3];
    string op = it->second[2];

    int lval = isalpha(lhs[0])? value[lhs[0] - 'A'] : stoi(lhs);
    int rval = isalpha(rhs[0])? value[rhs[0] - 'A'] : stoi(rhs);

    if(eval(lval, rval, op))
    {
        int cur = stoi(it->second[6]);
        while(it->first < cur - 1)
            ++it;
        while(it->first >= cur)
            --it;
    }
}

int main() 
{
    memset(value, 0, sizeof(value));

    while(fgets(input, sizeof(input), stdin))
    {
        int num = atoi(strtok(input, sep));

        bool first = 1;
        while(char *token = strtok(0, sep))
        {
            program[num].push_back(token);
            if(first && (!strcmp(token, "PRINT") || (!strcmp(token, "PRINTLN"))))
            {
                token += strlen(token) + 1; //get next token
                token[strlen(token) - 1] = 0; //remove trainling new-line character
                program[num].push_back(token); //push_back string
                break;
            }

            first = 0;
        }
    }

    for(auto it = program.begin(); it != program.end(); ++it)
    {
        string cmd = it->second[0];

        if(cmd == "LET")
            let(it);
        else if(cmd == "IF")
            IF(it);
        else
            output(it, cmd == "PRINTLN");
    }

    return 0;
}
