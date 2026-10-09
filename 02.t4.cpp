#include <iostream>
using namespace std;

// 1. 初始化成绩数组（n为学⽣⼈数，scores为学⽣分数）
void initScores(int* scores, int n);
// 2. 录⼊成绩
void inputScores(int* scores, int n);
// 3. 计算平均分
double calcAverage(const int* scores, int n);
// 4. 安全查询
int safeGet(const int* scores, int n, int index);
// 5. 统计分数段（counts为各个分数段的个数）
void countGrades(const int* scores, int n, int* counts);
// 6. 找最⾼分与最低分
void findMinMax(const int* scores, int n, int* max, int* min);
//7.打印所有结果
void printResults(const int* scores, int n, double avg, const int* counts, int max, int min);

int main() 
{   
    const int MAX_STUDENTS=1000;
    int scores[MAX_STUDENTS];
    int n;
    int counts[5] = {0};
    int max = -1, min = -1;
    double avg = 0.0;
    int testIndex;

    // 1. 初始化数组
    initScores(scores, MAX_STUDENTS);

    // 2. 读取学⽣⼈数
    cout << "请输⼊学⽣⼈数：";
    cin >> n;

    // 3. 调⽤各函数（要求 0 <= score <= 100）
    inputScores(scores, n);
    avg = calcAverage(scores, n);
    findMinMax(scores, n, &max, &min);
    countGrades(scores, n, counts);
    
    // 7. 安全查询测试
    cout << "请输⼊要查询的下标：";
    cin >> testIndex;
    int queried = safeGet(scores, n, testIndex);
    if (queried == -1) {
    cout << "查询失败" << std::endl;
    } 
    else 
    {
    cout << "下标 " << testIndex << " 的成绩是：" << queried << std::endl;
    }
    // 8. 打印所有统计结果
    cin.get();
    cout<<"回车打印所有结果"<<endl;
    cin.get();
    printResults(scores, n, avg, counts, max, min);
    return 0;
}

  //1.初始化
void initScores(int* scores, int n)
{
    for(int i=0;i<n;i++)
    {
        *scores=0;
        scores++;
    }
}

  //2.录入成绩
void inputScores(int* scores, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"请输入学生"<<i<<"分数";
        cin>>*scores;
        scores++;
    }
}

  // 3. 计算平均分
double calcAverage(const int* scores, int n)
{
    double sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=*scores;
        scores++;
    }
    return sum/n;
}

  // 4. 安全查询
int safeGet(const int* scores, int n, int index)
{
    if(index<0||index>1000) 
    {
        cout<<"下标越界"<<endl;
        return -1;
    }
    if(index<=1000||index>n) return -1;
    return scores[index];
}

  // 5. 统计分数段（counts为各个分数段的个数）
void countGrades(const int* scores, int n, int* counts)
{
    for(int i=0;i<n;i++)
    {
        if(scores[i]>=0&&scores[i]<60) counts[0]++;
        else if(scores[i]>=60&&scores[i]<70) counts[1]++;
        else if(scores[i]>=70&scores[i]<80) counts[2]++;
        else if(scores[i]>=80&&scores[i]<90) counts[3]++;
        else if(scores[i]>=90&&scores[i]<=100) counts[4]++;
    }
}

  // 6. 找最⾼分与最低分
void findMinMax(const int* scores, int n, int* max, int* min)
{
    *max=scores[0];
    *min=scores[0];
    for(int i=1;i<n;i++)
    {
        if(scores[i]>*max) *max=scores[i];
        if(scores[i]<*min) *min=scores[i];
    }
}

  //7.打印所有结果
void printResults(const int* scores, int n, double avg, const int* counts, int max, int min)
{
    cout<<"学生人数为"<<n<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"下标"<<i<<"的成绩是"<<scores[i]<<endl;
    }
    cout<<"平均分为"<<avg<<endl;
    cout<<"0~60分人数为"<<counts[0]<<endl;
    cout<<"60~70分人数为"<<counts[1]<<endl;
    cout<<"70~80分人数为"<<counts[2]<<endl;
    cout<<"80~90分人数为"<<counts[3]<<endl;
    cout<<"90~100分人数为"<<counts[4]<<endl;
    cout<<"最高分为"<<max<<endl;
    cout<<"最低分为"<<min<<endl;
}








