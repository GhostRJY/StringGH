#include <iostream>
#include "StringGH.h"

int main()
{

    setlocale(LC_ALL, "ru");

    StringGH s1("happy"), s2(" birthday"), s3;

    // проверка операторов сравнения
    std::cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2
              << "\"; s3 is \"" << s3 << '\"'
              << "\nрезультат сравнения"
              << "\ns2 == s1 "
              << (s2 == s1 ? "true" : "false")
              << "\ns2 != s1 "
              << (s2 != s1 ? "true" : "false")
              << "\ns2 >  s1 "
              << (s2 > s1 ? "true" : "false")
              << "\ns2 <  s1 "
              << (s2 < s1 ? "true" : "false")
              << "\ns2 >= s1 "
              << (s2 >= s1 ? "true" : "false")
              << "\ns2 <= s1 "
              << (s2 <= s1 ? "true" : "false");

    return 0;
}