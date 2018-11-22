//
// Created by Мхитарян Нарек on 18/11/2018.
//

#ifndef FORMALKI_TESTS_H
#define FORMALKI_TESTS_H
#pragma once
#include <gtest/gtest.h>
#include "engine.h"

TEST(Unit, classic_test)
{
    s = "aba.+*b.a.aab.+*.";
    searched = 'a';
    k = 2;
    stack <int> cur_stack;
    int a = solution(0, cur_stack, 0);
    EXPECT_EQ(1, a);
}

TEST(Unit, a_long_one)
{
    s = "acb..bab.c.*.ab.ba.+.+*a.";
    searched = 'a';
    k = 0;
    stack <int> cur_stack;
    int a = solution(0, cur_stack, 0);
    EXPECT_EQ(0, a);
}

TEST(Unit, not_so_obvious)
{
    s = "acb..bab.c.*.ab.ba.+.+*a.";
    searched = 'a';
    k = 10;
    stack <int> cur_stack;
    int a = solution(0, cur_stack, 0);
    EXPECT_EQ(1, a);
}

TEST(Unit, massive_test)
{
    s = "a*b*c*..";
    searched = 'c';
    k = 100000;
    stack <int> cur_stack;
    int a = solution(0, cur_stack, 0);
    EXPECT_EQ(1, a);
}

#endif //FORMALKI_TESTS_H
