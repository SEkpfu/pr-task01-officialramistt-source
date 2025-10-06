#include <iostream>
int main(){
    setlocale(LC_ALL,"RU");
    int hour,pay_hourly,bonus;
    std::cout<<"Enter number of hour,pay hourly,%bonus"<<"\n";
    std::cin>>hour>>pay_hourly>>bonus;
    int pay = hour * pay_hourly + ((hour * pay_hourly) /100) * bonus;
    std::cout<<pay;
    return 0;
}
