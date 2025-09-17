#include <iostream>
int summ(int, int, int); // получает на руку
int cnt1(int, int, int); // без вычета налогов
int cnt2(int); //сумма налогов
int db(int&,int&); //ввод цифр работника
int crr3(int,int, int, int&, int&, int&); //заполнение данных
int contr(int, int); //сравнение заробатка первого и второго

int main(){
    setlocale(LC_ALL,"RU");
    int bonus = 10;
    int hour1,pay_hourly1;
    int hour2,pay_hourly2;
    int total1, summ_tax1, summ_tax_ded1;
    int total2, summ_tax2, summ_tax_ded2;
    std::cout<<"Enter number of hour,pay hourly for 1 worker"<<"\n";
    db(hour1,pay_hourly1);
    std::cout<<"Enter number of hour,pay hourly for 2 worker"<<"\n";
    db(hour2,pay_hourly2);
    crr3(hour1,pay_hourly1,bonus,total1, summ_tax1, summ_tax_ded1);
    crr3(hour2,pay_hourly2,bonus,total2, summ_tax2, summ_tax_ded2);
    contr(total1,total2);
    std::cout<<summ_tax_ded1 + summ_tax_ded2;
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
int db(int &hour,int &pay_hourly){
    std::cin>>hour>>pay_hourly;
    return 0;
}
int crr3(int hour,int pay_hourly, int bonus, int &total, int &summ_tax, int &summ_tax_ded){
    total = hour * pay_hourly + ((hour * pay_hourly) /100) * bonus;
    int tax = 13;
    summ_tax = (total /100) * tax;
    summ_tax_ded = total - summ_tax;
    return 0;
}
int contr(int total1, int total2){
    if (total1 > total2){
        std::cout<<"max 1 worker"<<std::endl;
    }else if (total1 == total2){
        std::cout<<"1 worker == 2 worker"<<std::endl;
    }else{
        std::cout<<"max 2 worker"<<std::endl;
    }
    return 0;
}















