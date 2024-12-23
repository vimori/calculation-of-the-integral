#include <iostream>
#include <cmath>


using namespace std;

double f(double x){
    return log(x)/x;
}

double Left_Rect(double a, double b, double n){
    double length = (b - a) / n; //длина прямоугольника
    double sum = 0.0;
    for(int i = 0; i <= n-1; i++){
        sum+=length*f(a+i*length);
    }
    cout << endl;
    return sum;
}

double Right_Rect(double a, double b, double n){
    double length = (b - a) / n; //длина прямоугольника
    double sum = 0.0;
    for(int i = 1; i <= n; i++){
        sum+=length*f(a+i*length);
    }
    return sum;
}

double Middle_Rect(double a, double b, int n){
    double length = (b - a) / n; //длина прямоугольника
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        double x0 = a + i * length; //координата начала прямоугольника
        double x2 = a + (i + 1) * length; //координата начала прямоугольника
        double x1 = (x0 + x2) / 2; //координата середины прямоугольника
        sum+=length*f(x1);
    }
    cout << endl;
    return sum;

}

double trapeze(double a, double b, int n){
    double length = (b - a) / n; // высота трапеции
    double sum = 0.0;
    for(int i = 0; i <= n-1; i++){
        sum+=(f(a+i*length)+f(a+(i+1)*length));
    }
    sum*=length/2; 
    return sum;  
}

int main(){
    setlocale(LC_ALL,"ru");
    int a,b,n;
    int N[] = { 10, 20, 50, 100, 1000, 10000 };
    wcout << L"Выберете метод численного интегрирования: " << endl;
    wcout << L"1-метод левых прямоугольников" << endl;
    wcout << L"2-метод средних прямоугольников" << endl;
    wcout << L"3-метод правых прямоугольников" << endl;
    wcout << L"4-метод трапеций" << endl;
    cout << endl;
    wcout << L"Введите цифру, соотвествующую выбранному вами методу" << endl;
    cin >> n; 
    wcout << L"Введите значение левой границы интегрирования: " << endl;
    cin >> a;
    wcout << L"Введите значение правой границы интегрирования: " << endl;
    cin >> b;

    switch(n){
        case 1: 
            wcout << L"Вычисление значения интеграла методом Левых прямоугольников" << endl;
            for(int i=0;i<sizeof(N) / sizeof(N[0]);i++){
            cout << "n = " << N[i] << "\t" <<Left_Rect(a,b,N[i]) << endl;
            }
            break;
        case 2:
            wcout << L"Вычисление значения интеграла методом Средних прямоугольников" <<endl;
            for(int i=0;i<sizeof(N) / sizeof(N[0]);i++){
            cout << "n = " << N[i] << "\t" << Middle_Rect(a,b,N[i]) << endl;
            }
            break;
        case 3:
            wcout << L"Вычисление значения интеграла методом Правых прямоугольников" <<endl;
            for(int i=0;i<sizeof(N) / sizeof(N[0]);i++){
            cout << "n = " << N[i] << "\t" << Right_Rect(a,b,N[i]) << endl;
            }
            break;
        case 4:
            wcout << L"Вычисление значения интеграла методом Трапеций" <<endl;
            for(int i=0;i<sizeof(N) / sizeof(N[0]);i++){
            cout << "n = " << N[i] << "\t" <<trapeze(a,b,N[i]) << endl;
            }
            break;             
        default:
            wcout << L"Пожалуйста введите цифру от 1 до 4";
            break;
    }
    return 0;
}