#include <cstring>
#include <cstdio>

//题目和答案
class CMyString{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator=(const CMyString& str);
    void Print();

private:
    char* m_pData;
};

CMyString::CMyString(char* pData) {
    if(pData== nullptr){
        m_pData=new char[1];
        m_pData[1]='\0';
    }else{
        int length=strlen(pData);
        m_pData=new char[length+1];
        strcpy(m_pData,pData);
    }
}

CMyString::CMyString(const CMyString &str) {
    int length=strlen(str.m_pData);
    m_pData=new char[length+1];
    strcpy(m_pData,str.m_pData);
}

CMyString::~CMyString() {
    delete[] m_pData;
}

CMyString & CMyString::operator=(const CMyString &str) {
    if(this!=&str){
        CMyString Stmp(str.m_pData);
        char* pTmp=Stmp.m_pData;
        Stmp.m_pData=this->m_pData;
        this->m_pData=pTmp;
    }
    return *this;
}

//测试代码
void CMyString::Print() {
    printf("%s",this->m_pData);
}
//基础测试
void Test1(){
    printf("Test1 begins:\n");
    char* text="Cao ShiLiang Mama";
    CMyString str1(text);
    CMyString str2;
    str2=str1;
    printf("The expected result is:%s.\n",text);
    printf("The actual result is:");
    str2.Print();
    printf(".\n");
}
//赋值给自己
void Test2(){
    printf("Test2 begins:\n");
    char* text="Cao SL";
    CMyString str1(text);
    str1=str1;
    printf("The expected result is:%s.\n",text);
    printf("The actual result is:");
    str1.Print();
    printf(".\n");
}
// 连续赋值
void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
