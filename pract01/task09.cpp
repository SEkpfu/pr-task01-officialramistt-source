#include <iostream>
int summ(int, int, int);                                                                                        // получает на руку
void db(int array_h[][2], int); 
int tax(int, int, int);                                                 




int main(){
    setlocale(LC_ALL,"");
    int array_inp[48][2];
    int array_out[48][2];
    int c_month;
    int bonus = 13;
    std::cout<<"Enter count month"<<std::endl;
    std::cin>>c_month;
    db(array_inp,c_month);
    int i {0};
    for (; i < 4; i++)
    {
        int st = c_month + c_month * i;
        for(int r {i*c_month}; r<st;r++){
            array_out[r][0] = summ(array_inp[r][0],array_inp[r][1], bonus);
            array_out[r][1] = tax(array_inp[r][0],array_inp[r][1], bonus);
        }
    }
    std::cout<<"1. =  "<< array_out[2][0]<<std::endl;
    int summa {};
    for (int m{0};m<c_month;m++){
        summa+=array_out[m][1];
    }
    std::cout<<"2. =  "<<summa<<std::endl;
    int mmax = -100;
    int number;  
    for (int mr{0}; mr<4; mr++){
        if (mmax < array_out[ 2  + mr * c_month ][0]){
            mmax = array_out[ 2  + mr * c_month ][0];
            number = mr + 1;
        }
    }
    std::cout<<"3. =  "<<number<<std::endl;
    int summar = 0;
    i = 0;
    for (; i < 4; i++)
    {
        int st = c_month + c_month * i;
        for(int r {i*c_month}; r<st;r++){
            summar += array_out[r][0];
        }
    }
    std::cout<<"4. =  "<<summar<<std::endl;
}
int summ(int hour, int pay_hourly, int bonus)
{
    int pay = hour * pay_hourly + ((hour * pay_hourly) / 100) * bonus;
    int tax = 13;
    int tax_re = (pay / 100) * tax;
    return pay - tax_re;
}
void db(int array_h[][2], int count)
{
    int i {0};
    
    for (; i < 4; i++)
    {
        int st = count + count * i;
        std::cout<<"worker of "<<i+1<<std::endl;
        int g = 0;
        for(int r {i*count}; r<st;r++){
            g++;
            std::cout << "Enter hour/cash and hour/month "<< g <<" month "<< std::endl;
            std::cin >> array_h[r][0] >> array_h[r][1];    
        }
    }
    
}
int tax(int hour, int pay_hourly, int bonus)
{
    int total = hour * pay_hourly + ((hour * pay_hourly) / 100) * bonus;
    int tax = 13;
    int summ_tax = (total / 100) * tax;
    return summ_tax;
}