//
// Created by Мхитарян Нарек on 18/11/2018.
//

#ifndef FORMALKI_ENGINE_H
#define FORMALKI_ENGINE_H
#include <string>
#include <stack>
#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::stringstream;
using std::stack;

int k;
char searched;
string s;

bool solution(int start_point, stack <int>& cur_stack, int how_many)
{
    if(how_many > k)
    {
        return false;
    }
    for(int i = start_point; i < s.length(); ++i)
    {
        char c = s[i];
        if(c == '*')
        {
            if(cur_stack.size() <  1)
            {
                cout << "ERROR";
                exit(0);
            }
            int keys = cur_stack.top();
            cur_stack.pop();
            if(keys == 0)
            {
                cur_stack.push(keys);
                continue;
            }
            int cur_sch = 0;
            bool ans = false;
            while(cur_sch<= k)
            {
                auto an_st = cur_stack;
                an_st.push(cur_sch);
                ans = std::max(ans, solution(i+1, an_st, 0));
                cur_sch+=keys;
                if(ans)
                    return ans;
            }
            return ans;
        }
        else if(c == '+')
        {
            if(cur_stack.size() < 2)
            {
                cout << "ERROR";
                exit(0);
            }
            int another2 = cur_stack.top();
            cur_stack.pop();
            int  another1 = cur_stack.top();
            cur_stack.pop();
            if(another1 == another2)
            {
                cur_stack.push(another1);
                continue;
            }
            stack <int> first = cur_stack;
            //stack <int> second = cur_stack;
            first.push(another1);
            cur_stack.push(another2);
            return std::max(solution(i+1, first, how_many), solution(i+1, cur_stack, how_many));
        }
        else if(c == '.')
        {
            if(cur_stack.size() < 2)
            {
                cout << "ERROR";
                exit(0);
            }
            int another2 = cur_stack.top();
            cur_stack.pop();
            int  another1 = cur_stack.top();
            cur_stack.pop();
            another1 += another2;
            cur_stack.push(another1);
        }
        else
        {
            int h = 0;
            if(c == searched)
                h++;
            cur_stack.push(h);
        }

    }
    if(cur_stack.size() !=  1)
    {
        cout << "ERROR";
        exit(0);
    }
    auto ans = cur_stack.top();
    return (ans == k);
}
#endif //FORMALKI_ENGINE_H
