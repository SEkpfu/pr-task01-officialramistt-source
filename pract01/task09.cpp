#include <iostream>
int summ(int, int, int);                                                                                        // получает на руку
int cnt1(int, int, int);                                                                                        // без вычета налогов
int cnt2(int);                                                                                                  // сумма налогов
int db(int array_h[], int array_cash[], int);                                                                   // ввод данных работника
int tax(int, int, int);                                                                                         // вычисление налога
int sort(int array_total[], int count);                                                                         // сортировка
int copyr(int array_total[], int sort_array_total[], int count);                                                // копия массива
int find_numb(int array_total[], int sort_array_total[], int array_worke[], int count, int &n_max, int &n_min); // находит номер работника max и min и > 50000
int findMinIndex(int arr[], int size);                                                                 
int findMaxAndIndex(int arr[], int size, int& index);
int countGreaterThan(int arr[], int size, int value);
int sumArray(int arr[], int size);                                                                                                

int main()
{
    setlocale(LC_ALL, "RU");
    int bonus = 10;
    const int MAX_WORKER = 1000;
    int count;
    std::cout << "count of worker" << std::endl;
    std::cin>>count;
    int array_h[MAX_WORKER];
    int array_cash[MAX_WORKER];
    int array_total[MAX_WORKER];
    int array_tax[MAX_WORKER];
    int sort_array_total[MAX_WORKER];
    int array_worke[MAX_WORKER]; 
    int n_max{0};
    int n_min{0};
    db(array_h, array_cash, count);
    for (int i{0}; i < count; i++)
    {
        array_total[i] = summ(array_h[i], array_cash[i], bonus);
        array_tax[i] = tax(array_h[i], array_cash[i], bonus);
    }
    copyr(array_total, sort_array_total, count);
    sort(sort_array_total, count);
    
    int minIndex = findMinIndex(array_total, count);
    std::cout << "Номер минимального элемента: " << minIndex + 1 << std::endl;
    
    int maxValue;
    int maxIndex;
    maxValue = findMaxAndIndex(array_total, count, maxIndex);
    std::cout << "Максимальный элемент: " << maxValue << " (номер: " << maxIndex + 1 << ")" << std::endl;
    
    
    int countGreater = countGreaterThan(array_total, count, 50000);
    std::cout << "Количество элементов > 50000: " << countGreater << std::endl;
    
   
    int totalSum = sumArray(array_total, count);
    std::cout << "Сумма всех элементов: " << totalSum << std::endl;
    





    return 0;
}
int findMinIndex(int arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int findMaxAndIndex(int arr[], int size, int& index) {
    int maxValue = arr[0];
    index = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            index = i;
        }
    }
    return maxValue;
}

int countGreaterThan(int arr[], int size, int value) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > value) {
            count++;
        }
    }
    return count;
}

int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
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
int db(int array_h[], int array_cash[], int count)
{
    for (int i{0}; i < count; i++)
    {
        std::cout << "Enter hour and hour/cash " << i + 1<< std::endl;
        std::cin >> array_h[i] >> array_cash[i];
    }
    return 0;
}
int tax(int hour, int pay_hourly, int bonus)
{
    int total = hour * pay_hourly + ((hour * pay_hourly) / 100) * bonus;
    int tax = 13;
    int summ_tax = (total / 100) * tax;
    return summ_tax;
}
int sort(int array_total[], int count)
{
    for (int i{0}; i < count ; i++)
    {
        for (int j{0}; j < count - i - 1 ; j++)
        {
            if (array_total[j] > array_total[j+1])
            {
                int temp = array_total[j];
                array_total[j] = array_total[j+1];
                array_total[j+1] = temp;
            }
        }
    }
    return 0;
}
int copyr(int array_total[], int sort_array_total[], int count)
{
    for (int i{0}; i < count; i++)
    {
        sort_array_total[i] = array_total[i];
    }
    return  0;
}
int find_numb(int array_total[], int sort_array_total[], int array_worke[], int count, int &n_max, int &n_min)
{
    int maxx = sort_array_total[count - 1];
    int minn = sort_array_total[0];
    int g = 0;
    for (int i{0}; i < count; i++)
    {
        if (maxx == array_total[i])
        {
            n_max = i + 1;
        }
        else if (minn == array_total[i])
        {
            n_min = i + 1;
        }
        if (array_total[i] > 50000)
        {
            array_worke[g] = i + 1;
            g++;
        }
    }
    return g;
}