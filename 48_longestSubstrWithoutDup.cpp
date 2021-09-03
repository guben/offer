//
// Created by 67598 on 2021/9/3.
//

#include <string>
#include <iostream>
using namespace std;
bool hasDuplication(const string&str,int position[]);

//暴力法
int longestSubstringWithoutDuplication_1(const std::string& str)
{
    int longest=0;
    int *position =new int[26];
    for(int start=0;start<str.length();++start){
        for(int end=start;end<str.length();++end){
            int count=end-start+1;
            const string& substring =str.substr(start,count);
            if(!hasDuplication(substring,position)){
                if(count>longest)
                    longest=count;
            }
            else
                break;
        }
    }
    delete[] position;
    return longest;
}

bool hasDuplication(const string&str,int position[]){
    for(int i=0;i<26;i++)
        position[i]=-1;
    for(int i=0;i<str.size();i++){
        int indexInPosition=str[i]-'a';
        if(position[indexInPosition]>=0)
            return true;
        position[indexInPosition]=indexInPosition;
    }
    return false;
}


// 方法一：动态规划
int longestSubstringWithoutDuplication_2(const std::string& str)
{
    int curLength=0;
    int maxLength=0;
    int* position=new int[26]; //他的思想，是用来记录上一个该字符所在的位置
    for(int i=0;i<26;i++)
        position[i]=-1;
    for(int i=0;i<str.length();i++){
        int prevIndex=position[str[i]-'a'];
        if(prevIndex<0||i-prevIndex>curLength) //前面的判断表示当前没有重复; 后面的判断表示当前有重复了，但是重复字符之间的长度比curLength（当前无重复）长
            ++curLength;
        else{
            if(curLength>maxLength)
                maxLength=curLength;//更新最长值
            curLength=i-prevIndex;//重新计算curLength为当前长度
        }
        position[str[i]-'a']=i;
    }
    if(curLength>maxLength)//结尾值
        maxLength=curLength;
    delete[] position;
    return maxLength;
}

// ====================测试代码====================
void testSolution1(const std::string& input, int expected)
{
    int output = longestSubstringWithoutDuplication_1(input);
    if(output == expected)
        std::cout << "Solution 1 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 1 FAILED, with input: " << input << std::endl;
}

void testSolution2(const std::string& input, int expected)
{
    int output = longestSubstringWithoutDuplication_2(input);
    if(output == expected)
        std::cout << "Solution 2 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 2 FAILED, with input: " << input << std::endl;
}

void test(const std::string& input, int expected)
{
    testSolution1(input, expected);
    testSolution2(input, expected);
}

void test1()
{
    const std::string input = "abcacfrar";
    int expected = 4;
    test(input, expected);
}

void test2()
{
    const std::string input = "acfrarabc";
    int expected = 4;
    test(input, expected);
}

void test3()
{
    const std::string input = "arabcacfr";
    int expected = 4;
    test(input, expected);
}

void test4()
{
    const std::string input = "aaaa";
    int expected = 1;
    test(input, expected);
}

void test5()
{
    const std::string input = "abcdefg";
    int expected = 7;
    test(input, expected);
}

void test6()
{
    const std::string input = "aaabbbccc";
    int expected = 2;
    test(input, expected);
}

void test7()
{
    const std::string input = "abcdcba";
    int expected = 4;
    test(input, expected);
}

void test8()
{
    const std::string input = "abcdaef";
    int expected = 6;
    test(input, expected);
}

void test9()
{
    const std::string input = "a";
    int expected = 1;
    test(input, expected);
}

void test10()
{
    const std::string input = "";
    int expected = 0;
    test(input, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}