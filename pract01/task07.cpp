#include <iostream>
int summ(int, int, int);                      // получает на руку
int cnt1(int, int, int);                      // без вычета налогов
int cnt2(int);                                // сумма налогов
int db(int &, int &);                         // ввод данных работника
int crr3(int, int, int, int &, int &, int &); // заполнение данных
int aver(int, int, int, int, int);

int main()
{
    setlocale(LC_ALL, "RU");
    int bonus = 10;
    int hour1, pay_hourly1;
    int hour2, pay_hourly2;
    int hour3, pay_hourly3;
    int hour4, pay_hourly4;
    int hour5, pay_hourly5;
    int total1, summ_tax1, summ_tax_ded1;
    int total2, summ_tax2, summ_tax_ded2;
    int total3, summ_tax3, summ_tax_ded3;
    int total4, summ_tax4, summ_tax_ded4;
    int total5, summ_tax5, summ_tax_ded5;
    std::cout << "Enter number of  hour,pay hourly for 1 worker" << "\n";
    db(hour1, pay_hourly1);
    std::cout << "Enter number of  hour,pay hourly for 2 worker" << "\n";
    db(hour2, pay_hourly2);
    std::cout << "Enter number of  hour,pay hourly for 3 worker" << "\n";
    db(hour3, pay_hourly3);
    std::cout << "Enter number of  hour,pay hourly for 4 worker" << "\n";
    db(hour4, pay_hourly4);
    std::cout << "Enter number of  hour,pay hourly for 5 worker" << "\n";
    db(hour5, pay_hourly5);
    crr3(hour1, pay_hourly1, bonus, total1, summ_tax1, summ_tax_ded1);
    crr3(hour2, pay_hourly2, bonus, total2, summ_tax2, summ_tax_ded2);
    crr3(hour3, pay_hourly3, bonus, total3, summ_tax3, summ_tax_ded3);
    crr3(hour4, pay_hourly4, bonus, total4, summ_tax4, summ_tax_ded4);
    crr3(hour5, pay_hourly5, bonus, total5, summ_tax5, summ_tax_ded5);
    std::cout << "total earnings of 1 worker " << summ_tax_ded1 << "\n";
    std::cout << "total earnings of 2 worker " << summ_tax_ded2 << "\n";
    std::cout << "total earnings of 3 worker " << summ_tax_ded3 << "\n";
    std::cout << "total earnings of 4 worker " << summ_tax_ded4 << "\n";
    std::cout << "total earnings of 5 worker " << summ_tax_ded5 << "\n";
    aver(summ_tax_ded1, summ_tax_ded2, summ_tax_ded3, summ_tax_ded4, summ_tax_ded5);

    return 0;
}
int summ(int hour, int pay_hourly, int bonus)
{
    int pay = cnt1(hour, pay_hourly, bonus);
    int res = cnt2(pay);
    return pay - res;
}
int cnt1(int hour, int pay_hourly, int bonus)
{
    int pay = hour * pay_hourly + ((hour * pay_hourly) / 100) * bonus;
    return pay;
}
int cnt2(int pay)
{
    int tax = 13;
    int res = (pay / 100) * tax;
    return res;
}
int db(int &hour, int &pay_hourly)
{
    std::cin >> hour >> pay_hourly;
    return 0;
}
int crr3(int hour, int pay_hourly, int bonus, int &total, int &summ_tax, int &summ_tax_ded)
{
    total = hour * pay_hourly + ((hour * pay_hourly) / 100) * bonus;
    int tax = 13;
    summ_tax = (total / 100) * tax;
    summ_tax_ded = total - summ_tax;
    return 0;
}
int contr(int total, char *lname)
{
    if (total < 1000)
    {
        std::cout << "total_sum < 1000" << std::endl;
        std::cout << lname << std::endl;
    }
    return 0;
}
int contr_tax(int tax, char *lname)
{
    int n = 0;
    while (lname[n] != '\0')
    {
        n++;
    }
    if (tax > 50)
    {
        std::cout << "tax < 50" << std::endl;
        std::cout << lname[0] << "-" << lname[n - 1] << std::endl;
    }
}
int aver(int t1, int t2, int t3, int t4, int t5)
{
    int summ = (t1 + t2 + t3 + t4 + t5) / 5;
    std::cout << "average salary = " << summ << std::endl;
    return 0;
}