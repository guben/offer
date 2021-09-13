//
// Created by 67598 on 2021/9/6.
//

#include <cstdio>
#include <string>

char FirstNotRepeatingChar(const char* pString)
{
    if(pString== nullptr)
        return '\0';
    int* hashA=new int[256]{0};
    for(const char *p= (pString); *p != '\0'; p++){
        hashA[*p]++;
    }
    char retc='\0';
    for(const char *p= (pString); *p != '\0'; p++){
        if(hashA[*p]!=1)
            continue;
        else {
            retc=*p;
            break;
        }
    }
    return retc;
}

// ====================测试代码====================
void Test(const char* pString, char expected)
{
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入nullptr
    Test(nullptr, '\0');

    return 0;
}
