#include <iostream>
#include <algorithm>
#include <random>
#include <deque>
using namespace std;
int R(int min, int max)
{
    double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int hard;
    cin >> hard;
    int v1 = hard+1, v1m = round((hard+1)/2), v2 = 2*hard + 2, v2m = hard+1, v3m = round(hard*2 + 2 - (hard*2+1)/2), v3 = round(hard*2 + 2), v1r, v3r, v2r, rounds = 1; // ! вроде выполнено но надо тестить ! сделать условие если колво условий больше условий
    cin >> rounds;
    for(int u11 = 0; u11<rounds; ++u11){
        deque<string> a(75);
        deque<bool> a1(0);
        deque<string> a2(0);
        deque<string> b(0);
        deque<string> b1(0);
        deque<string> b3(0);
        deque<bool> b2(0);
        deque<string> c(2);
        deque<string> c1(2);
        c1[0] = "";
        c1[1] = "не ";
        c[0] = "и";
        c[1] = "или";
        string st = "A/B/C/D/E/F/G/H/J/I/K/L/M/N/O/Q/P/R/S/T/Y/V/X/Z/U/W/A1/B1/C1/D1/E1/F1/G1/H1/J1/I1/K1/L1/M1/N1/O1/Q1/P1/R1/S1/T1/Y1/V1/X1/Z1/U1/W1/A2/B2/C2/D2/E2/F2/G2/H2/J2/I2/K2/L2/M2/N2/O2/Q2/P2/R2/S2/T2/Y2/V2/X2";
        for(int i = 0, k = 0; i<st.size();++i){
            if(st[i] != '/'){
                a[k] += st[i];
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
            b.push_back(a[0]);
            b1.push_back(a[0]);
            b3.push_back(a[0]);
            a.pop_front();
        }
        for(auto& it : b1){
            string k = c1[R(0, 1)];
            it = k + it;
            if(k == "не "){
                b2.push_back(false);
            }
            else{
                b2.push_back(true);
            }
        }
        for(int i1 = 0; i1<=v2r; ++i1){
            random_shuffle(b.begin(), b.end());
            v3r = R(v3m, v3);
            if(v3r > b.size()-1){
                v3r = b.size()-1;
            }
            bool test;
            string k1 = c1[R(0, 1)];
            cout << "Если " << k1 << b[0] << " ";
            if(k1 == "не "){
                test = !b2[distance(b3.begin(), find(b3.begin(), b3.end(), b[0]))];
                
            }
            else{
                test = b2[distance(b3.begin(), find(b3.begin(), b3.end(), b[0]))];
            }
            for(int i = 0; i<v3r; ++i){
                string k2 = c[R(0, 1)], k3 = c1[R(0, 1)];
                cout << k2 << " " << k3 << b[i+1] << " ";
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
            cout << "то " << k4 << a[i1] << " ";
            if(k4 == "не "){
                b.push_back(a[i1]);
                b2.push_back(!test);
                b3.push_back(a[i1]);
                a1.push_back(!test);
            }
            else{
                b.push_back(a[i1]);
                b2.push_back(test);
                b3.push_back(a[i1]);
                a1.push_back(test);
            }
            cout << endl;
        }
        cout << "Известно что";
        for(auto& it : b1){
            cout << ", " << it;
        }
        cout << endl;
        string ans;
        for(int i = 0; i<=v2r; ++i){
            int ke = R(0, v2r-i);
            cout << a[ke] << ": ";
            cin >> ans;
            if(ans == "yes"){
                if(a1[ke]){
                    cout << "верно" << endl;
                }
                else{
                    cout << "неверно" << endl;
                }
            }
            else if(ans == "no"){
                if(!a1[ke]){
                    cout << "верно" << endl;
                }
                else{
                    cout << "неверно" << endl;
                }
            }
            else{
                cout << "неверно, правильный ответ: " << a1[ke] << endl;
            }
            a.erase(a.begin()+ke);
            a1.erase(a1.begin()+ke);
        }
    }
    
    return 0;
} //добавить раунды, настройку сложности, колво ошибок для вылета, время, таблицу результатов, перенести все в графику


