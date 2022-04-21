#include "ALL_CLASS.H"
#include <iostream>

const int Record = 5;
const int Search = 6;
const int Delete = 7;
const int Goback = 8;
const int Exit = 9;

Student student[100], teacher;
Statistics calc;
void refer_sta();
int interface_welcome();
int inetrface_record();
int interface_search();
int interface_delete();

int main()
{
start:
    int cyb = interface_welcome();
    if (cyb == Record)
    {
        if (inetrface_record() == Goback)
            goto start;
    }
    else if (cyb == Search)
    {
        if (interface_search() == Goback)
            goto start;
    }
    else if (cyb == Delete)
    {
        if (interface_delete())
            goto start;
    }
    else if (cyb = Exit)
    {
        for (int i = 0; i < calc.show_allnum(); ++i)
            student[i].~Student();
        calc.~Statistics();
    }
    return 0;
}

int interface_welcome()
{
    system("color 5E");
    system("mode con cols=100 lines=50");
    for (int i = 0; i < 100; ++i)
        std::cout << "*";
    for (int i = 0; i < 100; ++i)
        std::cout << "-";
    std::cout << "                         welcome to management of student scores system"
              << std::endl;
    for (int i = 0; i < 100; ++i)
        std::cout << "-";
    std::cout << std::endl
              << "if you want to Record Information:Input 5"
              << std::endl
              << std::endl
              << "if you want to Search Information:Input 6"
              << std::endl
              << std::endl
              << "if you want to Delete Information:Input 7"
              << std::endl
              << std::endl
              << "if you want to Exit the System:   Input 9"
              << std::endl
              << std::endl;
    int j;
again:
    std::cout << "Please Input: "
              << std::endl;
    std::cin >> j;
    if (j != 1 && j != 2 && j != 3 && j != 5)
        goto again;
    return j;
}
void refer_sta()
{
    calc.clear();
    float all_scores = 0;
    for (int i = 0; i < calc.show_allnum(); ++i)
    {
        if (student[i].showScore() >= 90)
        {
            calc.setBest_numprt(1);
            student[i].setPlace(best);
        }
        else if (student[i].showScore() >= 80)
        {
            calc.setGood_numprt(1);
            student[i].setPlace(good);
        }
        else if (student[i].showScore() >= 70)
        {
            calc.setMedium_numprt(1);
            student[i].setPlace(medium);
        }
        else if (student[i].showScore() >= 60)
        {
            calc.setPass_numprt(1);
            student[i].setPlace(pass);
        }
        else
        {
            calc.setBad_numprt(1);
            student[i].setPlace(bad);
        }
        all_scores += student[i].showScore();
        for (int j = i; j < calc.show_allnum(); ++j)
        {
            if (student[i].showScore() < student[j].showScore())
            {
                teacher = student[i];
                student[i] = student[j];
                student[j] = teacher;
            }
            else if (student[i].showScore() == student[j].showScore())
                if (student[i].showName().compare(student[j].showName()) > 0)
                {
                    teacher = student[i];
                    student[i] = student[j];
                    student[j] = teacher;
                }
        }
    }
    for (int k = 0; k <= calc.show_allnum(); ++k)
        student[k].setRank(k + 1);
    calc.setAve_scores(all_scores / calc.show_allnum());
}
int inetrface_record()
{
    system("color 6C");
    system("mode con cols=100 lines=50");
    for (int i = 0; i < 100; ++i)
        std::cout << "*";
    for (int i = 0; i < 100; ++i)
        std::cout << "-";
    std::cout << "                                     Record Information"
              << std::endl;
    for (int i = 0; i < 100; ++i)
        std::cout << "-";
    std::cout << "you can input \"end\" to end recording."
              << std::endl;
    std::string user_name;
    std::string user_number;
    float user_score;
    for (int i = calc.show_allnum(); i < 100; ++i)
    {
        std::cout << "name: ";
        std::cin >> user_name;
        if (user_name == "end")
            break;
        std::cout << "number: ";
        std::cin >> user_number;
        calc.setAll_num(1);
        std::cout << "score: ";
        std::cin >> user_score;
        student[i].setNumber(user_number);
        student[i].setName(user_name);
        student[i].setScore(user_score);
    }
    refer_sta();
    return Goback;
}
int interface_search()
{
search_again:
    system("cls");
    system("color 8B");
    system("mode con cols=100 lines=50");
    for (int i = 0; i < 100; ++i)
        std::cout << "*";
    for (int i = 0; i < 100; ++i)
        std::cout << "-";
    std::cout << "                                     Search Information"
              << std::endl;
    for (int i = 0; i < 100; ++i)
        std::cout << "-";
    for (int i = 0; i < 100; ++i)
        std::cout << " ";
    std::string user_name = "";
    std::string user_score = "";
    std::string result;
    std::cout << "you can input \"sta\" to display statistics information"
              << std::endl
              << "you can input \"(name)\", \"(score)\" or \"(number)\" to search information"
              << std::endl;
    std::cin >> result;
    if (result == "sta")
    {
        std::cout << "[all num]:   " << calc.show_allnum() << std::endl
                  << "[best num]:  " << calc.sta_show(best) << "  "
                  << "[best prt]:  " << calc.sta_show(best, false) * 100 << "%" << std::endl
                  << "[good num]:  " << calc.sta_show(good) << "  "
                  << "[good prt]:  " << calc.sta_show(good, false) * 100 << "%" << std::endl
                  << "[medium num]:" << calc.sta_show(medium) << "  "
                  << "[medium prt]:" << calc.sta_show(medium, false) * 100 << "%" << std::endl
                  << "[pass num]:  " << calc.sta_show(pass) << "  "
                  << "[pass prt]:  " << calc.sta_show(pass, false) * 100 << "%" << std::endl
                  << "[bad num]:   " << calc.sta_show(bad) << "  "
                  << "[bad prt]:   " << calc.sta_show(bad, false) * 100 << "%" << std::endl
                  << "[ave score]: " << calc.showAve_scores() << std::endl;
    }
    else
    {
        for (int i = 0; i < result.length(); ++i)
        {
            if (isalpha(result[i]) && result[i] != '.')
                user_name += result[i];
            if (isdigit(result[i]) || result[i] == '.')
                user_score += result[i];
        }
        unsigned int dot = user_score.length(), sum = 0;
        for (int i = 0; i < user_score.length(); ++i)
        {
            if (user_score[i] != '.')
                sum = 10 * sum + user_score[i] - 48;
            else
                dot = i + 1;
        }
        float score = float(sum);
        for (int i = 0; i < user_score.length() - dot; ++i)
            score = float(sum) / 10;
        std::cout << "[Name]        [Score]     [Rank]       [Place]      [Number]" << std::endl;
        for (int i = 0; i < calc.show_allnum(); ++i)
        {
            if (user_name == "")
            {
                if (score >= 1000)
                {
                    if (student[i].showNumber() == std::to_string(int(score)))
                    {
                        std::cout << student[i].showName()
                                  << "         "
                                  << student[i].showScore()
                                  << "         "
                                  << student[i].showRank();
                        if (student[i].showPlace() == best)
                            std::cout << "          best         ";
                        else if (student[i].showPlace() == good)
                            std::cout << "          good         ";
                        else if (student[i].showPlace() == medium)
                            std::cout << "          medium       ";
                        else if (student[i].showPlace() == pass)
                            std::cout << "          pass         ";
                        else
                            std::cout << "          bad          ";
                        std::cout << student[i].showNumber()
                                  << std::endl;
                    }
                }
                else
                {
                    if (student[i].showScore() == score)
                    {
                        std::cout << student[i].showName()
                                  << "         "
                                  << student[i].showScore()
                                  << "         "
                                  << student[i].showRank();
                        if (student[i].showPlace() == best)
                            std::cout << "          best         ";
                        else if (student[i].showPlace() == good)
                            std::cout << "          good         ";
                        else if (student[i].showPlace() == medium)
                            std::cout << "          medium       ";
                        else if (student[i].showPlace() == pass)
                            std::cout << "          pass         ";
                        else
                            std::cout << "          bad          ";
                        std::cout << student[i].showNumber()
                                  << std::endl;
                    }
                }
            }
            else if (user_score == "")
            {
                if (student[i].showName() == user_name)
                {
                    std::cout << student[i].showName()
                              << "         "
                              << student[i].showScore()
                              << "         "
                              << student[i].showRank();
                    if (student[i].showPlace() == best)
                        std::cout << "          best         ";
                    else if (student[i].showPlace() == good)
                        std::cout << "          good         ";
                    else if (student[i].showPlace() == medium)
                        std::cout << "          medium       ";
                    else if (student[i].showPlace() == pass)
                        std::cout << "          pass         ";
                    else
                        std::cout << "          bad          ";
                    std::cout << student[i].showNumber()
                              << std::endl;
                }
            }
            else if (student[i].showName() == user_name && student[i].showScore() == score)
            {
                std::cout << student[i].showName()
                          << "         "
                          << student[i].showScore()
                          << "         "
                          << student[i].showRank();
                if (student[i].showPlace() == best)
                    std::cout << "          best         ";
                else if (student[i].showPlace() == good)
                    std::cout << "          good         ";
                else if (student[i].showPlace() == medium)
                    std::cout << "          medium       ";
                else if (student[i].showPlace() == pass)
                    std::cout << "          pass         ";
                else
                    std::cout << "          bad          ";
                std::cout << student[i].showNumber()
                          << std::endl;
            }
        }
    }
    std::cout << "Do you want Search again?(Yes/No)"
              << std::endl;
    std::string input;
    std::cin >> input;
    if (input == "YES" || input == "yes" || input == "Yes" || input == "Y" || input == "y" || input == "YeS" || input == "yEs")
        goto search_again;
    return Goback;
}
int interface_delete()
{
delete_again:
    system("cls");
    system("color 8B");
    system("mode con cols=100 lines=50");
    for (int i = 0; i < 100; ++i)
        std::cout << "*";
    for (int i = 0; i < 100; ++i)
        std::cout << "-";
    std::cout << "                                     Delete Information"
              << std::endl;
    for (int i = 0; i < 100; ++i)
        std::cout << "-";
    std::cout << "Input name or score!"
              << std::endl;
    std::string result, user_name, user_score;
    std::cin >> result;
    for (int i = 0; i < result.length(); ++i)
    {
        if (isalpha(result[i]) && result[i] != '.')
            user_name += result[i];
        if (isdigit(result[i]) || result[i] == '.')
            user_score += result[i];
    }

    unsigned int dot = user_score.length(), sum = 0;
    for (int i = 0; i < user_score.length(); ++i)
    {
        if (user_score[i] != '.')
            sum = 10 * sum + user_score[i] - 48;
        else
            dot = i + 1;
    }
    float score = float(sum);
    for (int i = 0; i < user_score.length() - dot; ++i)
        score = float(sum) / 10;
    int num;
    for (int i = 0; i < calc.show_allnum(); ++i)
    {
        if (user_name == "")
        {
            if (student[i].showScore() == score)
            {
                num = i;
                break;
            }
        }
        else if (user_score == "")
        {
            if (student[i].showName() == user_name)
            {
                num = i;
                break;
            }
        }
        else if (student[i].showName() == user_name && student[i].showScore() == score)
        {
            num = i;
            break;
        }
    }
    for (int i = num; i < calc.show_allnum() - 1; ++i)
        student[num] = student[num + 1];
    calc.setAll_num(-1);
    std::cout << "have delete "
              << student[num].showName()
              << " information"
              << std::endl;
    refer_sta();
    std::cout << "Do you want Delete again?(Yes/No)"
              << std::endl;
    std::string input;
    std::cin >> input;
    if (input == "YES" || input == "yes" || input == "Yes" || input == "Y" || input == "y" || input == "YeS" || input == "yEs")
        goto delete_again;
    return Goback;
}
