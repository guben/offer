//
// Created by 67598 on 2021/9/6.
//
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
class CharStatistics{
public:
    CharStatistics():index(0){
        for(int i=0;i<256;i++)
            occurrence[i]=-1;
    }
    void Insert(char c){
        if(occurrence[c]==-1){
            occurrence[c]=index;
        }else if(occurrence[c]>=0){
            occurrence[c]=-1;
        }
        index++;
    }
    char FirstAppearingOnce(){
        char ch='\0';
        int minIndex=INT_MAX;
        for(int i=0;i<256;i++){
            if(occurrence[i]==-1 || occurrence[i]==-2)
                continue;
            else if(occurrence[i]<minIndex){
                minIndex=occurrence[i];
                ch=(char)i;
            }
        }
        return ch;
    }
private:
    int index;
    int occurrence[256];
};

// ====================测试代码====================
void Test(const char* testName, CharStatistics chars, char expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(chars.FirstAppearingOnce() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    CharStatistics chars;

    Test("Test1", chars, '\0');

    chars.Insert('g');
    Test("Test2", chars, 'g');

    chars.Insert('o');
    Test("Test3", chars, 'g');

    chars.Insert('o');
    Test("Test4", chars, 'g');

    chars.Insert('g');
    Test("Test5", chars, '\0');

    chars.Insert('l');
    Test("Test6", chars, 'l');

    chars.Insert('e');
    Test("Test7", chars, 'l');

    return 0;
}
