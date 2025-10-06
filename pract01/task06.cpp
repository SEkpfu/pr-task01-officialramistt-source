#include <iostream>
int summ(int, int, int);                      // получает на руку
int cnt1(int, int, int);                      // без вычета налогов
int cnt2(int);                                // сумма налогов
int db(int &, int &, char *);                 // ввод данных работника
int crr3(int, int, int, int &, int &, int &); // заполнение данных
int contr(int, char *);                       // сравнение заробатка первого и второго
int contr_tax(int, char *);                   // вывод если налог меньше 50 рублей

int main()
{
    setlocale(LC_ALL, "RU");
    char lname_1[20];
    char lname_2[20];
    int bonus = 10;
    int hour1, pay_hourly1;
    int hour2, pay_hourly2;
    int total1, summ_tax1, summ_tax_ded1;
    int total2, summ_tax2, summ_tax_ded2;
    std::cout << "Enter number of lname, hour,pay hourly for 1 worker" << "\n";
    db(hour1, pay_hourly1, lname_1);
    std::cout << "Enter number of lname, hour,pay hourly for 2 worker" << "\n";
    db(hour2, pay_hourly2, lname_2);
    crr3(hour1, pay_hourly1, bonus, total1, summ_tax1, summ_tax_ded1);
    crr3(hour2, pay_hourly2, bonus, total2, summ_tax2, summ_tax_ded2);
    contr(total1, lname_1);
    contr(total2, lname_2);
    contr_tax(summ_tax1, lname_1);
    contr_tax(summ_tax2, lname_2);

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
int db(int &hour, int &pay_hourly, char *lname)
{
    std::cin >> lname;
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