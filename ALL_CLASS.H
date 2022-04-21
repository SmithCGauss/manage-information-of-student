#ifndef ALL_CLASS_H
#define ALL_CLASS_H
#include <iostream>

/**
 *@author yubo chen
 *@date 4/19/2022
 *@param name 学生名字
 *@param score 学生成绩
 *@param rank 学生排名
 *@param place 学生段位
 */
const int best = 4;   //成绩优秀
const int good = 3;   //成绩良好
const int medium = 2; //成绩中等
const int pass = 1;   //成绩合格
const int bad = 0;    //成绩不及格

class Student
{
public:
    Student(std::string number = "0000", std::string name = "none", int score = 0, int rank = 0, int place = 0)
    {
        Name = name;
        Score = score;
        Rank = rank;
        Place = place;
        Number = number;
    }
    void setName(std::string name);     //设置名字
    void setScore(float score);         //设置分数
    void setRank(int rank);             //设置拍名
    void setPlace(int place);           //设置段位
    void setNumber(std::string number); //设置学号

    std::string showName();
    float showScore();
    int showRank();
    int showPlace();
    std::string showNumber();

    ~Student()
    {
    }

private:
    std::string Name;   //名字
    std::string Number; //学号
    float Score;        //成绩
    int Rank;           //排名
    int Place;          //段位
};

void Student::setNumber(std::string number)
{
    if (number.length() != 4)
        std::cout << "Number is only 4 chars!" << std::endl;
    else
        Number = number;
}
std::string Student::showNumber()
{
    return Number;
}
std::string Student::showName()
{
    return Name;
}
float Student::showScore()
{
    return Score;
}
int Student::showRank()
{
    return Rank;
}
int Student::showPlace()
{
    return Place;
}
void Student::setName(std::string name)
{
    Name = name;
}
void Student::setScore(float score)
{
    if (score > 100 || score < 0)
        std::cout << "score is error!" << std::endl;
    else
        Score = score;
}
void Student::setRank(int rank)
{
    Rank = rank;
}
void Student::setPlace(int place)
{
    Place = place;
}

/**
 *@author yubo chen
 *@date 4/19/2022
 */
class Statistics
{
public:
    //统计结果初始化
    Statistics(int best_num = 0, int good_num = 0, int medium_num = 0, int pass_num = 0, int bad_num = 0,
               float best_prt = 0, float good_prt = 0, float medium_prt = 0, float pass_prt = 0, float bad_prt = 0,
               float ave_scores = 0)
    {
        Best_num = best_num;
        Good_num = good_num;
        Medium_num = medium_num;
        Pass_num = pass_num;
        Bad_num = bad_num;
        Best_prt = best_prt;
        Good_prt = good_prt;
        Medium_prt = medium_prt;
        Pass_prt = pass_prt;
        Bad_prt = bad_prt;
        Ave_scores = ave_scores;
    }
    ~Statistics()
    {
    }
    //设置总人数
    void setAll_num(int all_num);
    //设置人数及其所占比例
    void setBest_numprt(int best_num);
    void setBest_numprt(float best_prt);

    void setGood_numprt(int good_num);
    void setGood_numprt(float good_prt);

    void setMedium_numprt(int medium_num);
    void setMedium_numprt(float medium_prt);

    void setPass_numprt(int pass_num);
    void setPass_numprt(float pass_prt);

    void setBad_numprt(int bad_num);
    void setBad_numprt(float bad_prt);

    void setAve_scores(float ave);

    void clear(); //清零

    float sta_show(int some, bool numprt); //返回所要查询的人数(true，默认)/比例(false)
    int show_allnum();
    float showAve_scores();

private:
    int All_num;                                             //总人数
    int Best_num, Good_num, Medium_num, Pass_num, Bad_num;   //各段位人数
    float Best_prt, Good_prt, Medium_prt, Pass_prt, Bad_prt; //各段位所占比例
    float Ave_scores;                                        //成绩平均数
};
void Statistics::clear()
{
    Best_num = 0;
    Good_num = 0;
    Medium_num = 0;
    Pass_num = 0;
    Bad_num = 0;
    Best_prt = 0;
    Good_prt = 0;
    Medium_prt = 0;
    Pass_prt = 0;
    Bad_prt = 0;
    Ave_scores = 0;
}
float Statistics::showAve_scores()
{
    return Ave_scores;
}
void Statistics::setAve_scores(float ave)
{
    Ave_scores = ave;
}
int Statistics::show_allnum()
{
    return All_num;
}
void Statistics::setAll_num(int all_num)
{
    All_num += all_num;
}
void Statistics::setBest_numprt(int best_num)
{
    Best_num += best_num;
    Best_prt = float(Best_num) / All_num;
}
void Statistics::setBest_numprt(float best_prt)
{
    Best_prt = best_prt;
    float num;
    for (int i = 0; i <= 100; i++)
    {
        num = i - Best_prt * All_num;
        if (num >= 0.0 && num < 1.0)
        {
            Best_num = i;
            break;
        }
    }
}
void Statistics::setGood_numprt(int good_num)
{
    Good_num += good_num;
    Good_prt = float(Good_num) / All_num;
}
void Statistics::setGood_numprt(float good_prt)
{
    Good_prt = good_prt;
    float num;
    for (int i = 0; i <= 100; i++)
    {
        num = i - Good_prt * All_num;
        if (num >= 0.0 && num < 1.0)
        {
            Good_num = i;
            break;
        }
    }
}
void Statistics::setMedium_numprt(int medium_num)
{
    Medium_num += medium_num;
    Medium_prt = float(Medium_num) / All_num;
}
void Statistics::setMedium_numprt(float medium_prt)
{
    Medium_prt = medium_prt;
    float num;
    for (int i = 0; i <= 100; i++)
    {
        num = i - Medium_prt * All_num;
        if (num >= 0.0 && num < 1.0)
        {
            Medium_num = i;
            break;
        }
    }
}
void Statistics::setPass_numprt(int pass_num)
{
    Pass_num += pass_num;
    Pass_prt = float(Pass_num) / All_num;
}
void Statistics::setPass_numprt(float pass_prt)
{
    Pass_prt = pass_prt;
    float num;
    for (int i = 0; i <= 100; i++)
    {
        num = i - Pass_prt * All_num;
        if (num >= 0.0 && num < 1.0)
        {
            Pass_num = i;
            break;
        }
    }
}

void Statistics::setBad_numprt(int bad_num)
{
    Bad_num += bad_num;
    Bad_prt = float(Bad_num) / All_num;
}

void Statistics::setBad_numprt(float bad_prt)
{
    Bad_prt = bad_prt;
    float num;
    for (int i = 0; i <= 100; i++)
    {
        num = i - Bad_prt * All_num;
        if (num >= 0.0 && num < 1.0)
        {
            Bad_num = i;
            break;
        }
    }
}

float Statistics::sta_show(int some, bool numprt = true)
{
    if (numprt)
        switch (some)
        {
        case best:
            return Best_num;
            break;
        case good:
            return Good_num;
            break;
        case medium:
            return Medium_num;
            break;
        case pass:
            return Pass_num;
            break;
        case bad:
            return Bad_num;
            break;
        default:
            std::cout << "can not find num!" << std::endl;
        }
    else
        switch (some)
        {
        case best:
            return Best_prt;
            break;
        case good:
            return Good_prt;
            break;
        case medium:
            return Medium_prt;
            break;
        case pass:
            return Pass_prt;
            break;
        case bad:
            return Bad_prt;
            break;
        default:
            std::cout << "can not find prt!" << std::endl;
        }
    return 0;
}

#endif