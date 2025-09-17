#include <iostream>
int summ(int, int, int); // получает на руку
int cnt1(int, int, int); // без вычета налогов
int cnt2(int); //сумма налогов
int db(int&,int&,int&); //ввод цифр работника
int crr3(int,int, int, int&, int&, int&); //заполнение данных

int main(){
    setlocale(LC_ALL,"RU");
    int hour,pay_hourly,bonus;
    int total, summ_tax, summ_tax_ded;
    db(hour,pay_hourly,bonus);
    crr3(hour,pay_hourly,bonus,total, summ_tax, summ_tax_ded);
    int result = summ(hour,pay_hourly,bonus);
    std::cout<<result;
    return 0;
}
int summ(int hour,int pay_hourly, int bonus){
    int pay = cnt1(hour,pay_hourly,bonus);
    int res = cnt2(pay);
    return pay - res;

}
int cnt1(int hour,int pay_hourly, int bonus){
    int pay = hour * pay_hourly + ((hour * pay_hourly) /100) * bonus;
    return pay;
}
int cnt2(int pay){
    int tax = 13;
    int res = (pay /100) * tax;
    return res;
}
int db(int &hour,int &pay_hourly,int &bonus){
    std::cout<<"Enter number of hour,pay hourly,%bonus"<<"\n";
    std::cin>>hour>>pay_hourly>>bonus;
    return 0;
}
int crr3(int hour,int pay_hourly, int bonus, int &total, int &summ_tax, int &summ_tax_ded){
    total = hour * pay_hourly + ((hour * pay_hourly) /100) * bonus;
    int tax = 13;
    summ_tax = (total /100) * tax;
    summ_tax_ded = total - summ_tax;
    return 0;
}

