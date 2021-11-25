#include <iostream>
#include <algorithm>
#include <random>
#include <deque>
#include <fstream>
using namespace std;
int R(int min, int max)
{
    double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


int main()
{
    ofstream outfile ("test.txt");
    srand(static_cast<unsigned int>(time(0)));
    int hard;
    cin >> hard;
    int v1 = hard+1, v1m = round((hard+1)/2), v2 = 2*hard + 2, v2m = hard+1, v3m = round(hard*2 + 2 - (hard*2+1)/2), v3 = round(hard*2 + 2), v1r, v3r, v2r;
    deque<string> a(75);
    deque<string> u(66);
    deque<bool> a1(0);
    deque<string> a2(0);
    deque<string> b(0);
    deque<string> b1(0);
    deque<string> b3(0);
    deque<bool> b2(0);
    deque<string> ts1(0);
    deque<string> c(2);
    deque<string> c1(2);
    c1[0] = "";
    c1[1] = "не ";
    c[0] = "и";
    c[1] = "или";
    string ts = "Ваня/Антон/Саша/Коля/Дима/л/G/H/K/L/M/N/O/Q/P/R/S/T/Y/K/L/M/A/B/C/D/E/F/G/H/K/L/M/N/O/Q/P/R/S/T/Y/K/L/M/A/B/C/D/E/F/G/H/K/L/M/N/O/Q/P/R/S/T/Y/K/L/M";
    string st = "занят/красный/желтый/черный/зол/здесь/там/синий/зеленый/хочет пиццу/хочет пить/хочет спать/знает как решить уравнение/знает что делать/богат/умен/красив/знает что такое агноним/любит яблоки/учит физику/учит алгебру/учит химию/учит биологию/делает проект/думает/программирует/не видит света/не видит других/не навидит других/удивлен/рад/грустит/умер/умирает/жив/ослеп/всех цветов радуги/решает уравнение x^9 - 18x^7 + 108x^5 - 222x^3 + 36x + 6 = 0/решает уравнение (x^3 - 6x)^3 - 6(x^3 - 6x) + 6 = 0/идет на улицу/идет домой/идет в школу/сидит на уроке/покупает очки/покупает акции/продает акции/покупает компьютер/решает уравнение x = 1/ждет автобус/ждет хорошой погоды/ждет плохой погоды/ждет казни/убит/дебил/верит в бога/верит в предсказания/верит в себя/играет в футбол/играет в баскетбол/играет в волейбол/играет в прятки/играет в майнкрафт/пишет условия для проекта/изучает git/изучает sql/изучает потоки/изучает нейросети/изучает python/изучает c++/изучает c#/розовый/коричневый/мертв/думает о других/думает только о себе";
    for(int i = 0, k = 0; i<st.size();++i){
        if(st[i] != '/'){
            a[k] += st[i];
        }
        else{
            k++;
        }
    }
    for(int i = 0, k = 0; i<ts.size();++i){
        if(ts[i] != '/'){
            u[k] += ts[i];
        }
        else{
            k++;
        }
    }
    v1r = R(v1m, v1);
    v2r = R(v2m, v2);
    auto rng = default_random_engine {};
    random_shuffle(a.begin(), a.end());
    for(int i = 0; i<v1r; ++i){
        random_shuffle(u.begin(), u.end());
        b.push_back(u[0] + " " + c1[R(0, 1)] + a[0]);
        string k = c1[R(0, 1)];
        if(k == "не "){
            b2.push_back(false);
        }
        else{
            b2.push_back(true);
        }
        b1.push_back(u[0] + " " + k + a[0]);
        b3.push_back(a[0]);
        a.pop_front();
    }
    for(int i1 = 0; i1<=v2r; ++i1){
        random_shuffle(b.begin(), b.end());
        random_shuffle(u.begin(), u.end());
        v3r = R(v3m, v3);
        if(v3r > b.size()-1){
            v3r = b.size()-1;
        }
        bool test;
        string k1 = c1[R(0, 1)];
        outfile << "Если " << b[0] << " ";
        if(k1 == "не "){
            test = !b2[distance(b3.begin(), find(b3.begin(), b3.end(), b[0]))];
            
        }
        else{
            test = b2[distance(b3.begin(), find(b3.begin(), b3.end(), b[0]))];
        }
        for(int i = 0; i<v3r; ++i){
            string k2 = c[R(0, 1)], k3 = c1[R(0, 1)];
            outfile << k2 << " " << b[i+1] << " ";
            if(k2 == "и"){
                if(k3 == "не "){
                    test = test and !b2[distance(b3.begin(), find(b3.begin(), b3.end(), b[i+1]))];
                }
                else{
                    test = test and b2[distance(b3.begin(), find(b3.begin(), b3.end(), b[i+1]))];
                }
            }
            else{
                if(k3 == "не "){
                    test = test or !b2[distance(b3.begin(), find(b3.begin(), b3.end(), b[i+1]))];
                }
                else{
                    test = test or b2[distance(b3.begin(), find(b3.begin(), b3.end(), b[i+1]))];
                }
            }
        }
        string k4 = c1[R(0, 1)];
        outfile << "то " << u[0] + " " + k4 << a[i1] << " ";
        if(k4 == "не "){
            b.push_back(u[0] + " " + k4 + a[i1]);
            b2.push_back(!test);
            b3.push_back(a[i1]);
            a1.push_back(!test);
        }
        else{
            b.push_back(u[0] + " " + k4 + a[i1]);
            b2.push_back(test);
            b3.push_back(a[i1]);
            a1.push_back(test);
        }
        outfile << endl;
    }
    outfile << "Известно что";
    for(auto& it : b1){
        outfile << ", " << it;
    }
    outfile << endl;
    outfile.close();
    
    return 0;
} 