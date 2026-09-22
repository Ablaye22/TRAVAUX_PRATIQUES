#include<iostream>
int main()
{
    char s[] = "verte";
    char *p = s;
    std::cout << *p++;
    std::cout << *(p++);
    std::cout << (*p)++;
    std::cout << *++p;
    std::cout << *(p+1);
    std::cout << " " << s;
    return 0;
}


