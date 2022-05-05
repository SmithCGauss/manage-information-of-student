#include <AllClass.h>


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

