#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include "engine.h"

using std::cin;
using std::cout;
using std::string;
using std::stringstream;
using std::stack;




int main() {
    cin >> s;
    cin >> searched;
    cin >> k;
    string cur_ans;
    stack <int> cur_stack;
    cout << solution(0, cur_stack, 0);
    return 0;
}