#include <iostream>
int summ(int hour,int pay_hourly, int bonus); // получает на руку
int cnt1(int hour,int pay_hourly, int bonus); // без вычета налогов
int cnt2(int pay); //сумма налогов

int main(){
    setlocale(LC_ALL,"RU");
    int hour,pay_hourly,bonus;
    std::cout<<"Enter number of hour,pay hourly,%bonus"<<"\n";
    std::cin>>hour>>pay_hourly>>bonus;
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
