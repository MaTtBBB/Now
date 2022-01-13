#include <iostream>
#include <algorithm>
#include <random>
#include <deque>
#include <fstream>
#include <string>
using namespace std;
int R(int min, int max)
{
    double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


int main(){
    ofstream outfile ("test.txt");
    ofstream outfile1 ("test1.txt");
    ifstream infile;
    infile.open("config.txt");
    srand(static_cast<unsigned int>(time(0)));
    int hard;
    int v1 = hard+1, v1m = round((hard+1)/2), v2 = 2*hard + 2, v2m = hard+1, v3m = round(hard*2 + 2 - (hard*2+1)/2), v3 = round(hard*2 + 2), v1r, v3r, v2r;
    deque<string> b(0);
    deque<string> b1(0);
    deque<bool> bte(0);
    deque<bool> b1te(0);
    deque<int> bd(0);
    deque<string> c(2);
    deque<string> c1(2);
    deque<bool> c1te(2);
    deque<string> c2(3);
    c1[0] = "";
    c1[1] = "не ";
    c1te[0] = true;
    c1te[1] = false;
    c[0] = "и";
    c[1] = "или";
    c2[0] = "";
    c2[1] = "";
    c2[2] = "может ";
    string st = "A/B/C/D/E/F/G/H/J/I/K/L/M/N/O/Q/P/R/S/T/Y/V/X/Z/U/W/A1/B1/C1/D1/E1/F1/G1/H1/J1/I1/K1/L1/M1/N1/O1/Q1/P1/R1/S1/T1/Y1/V1/X1/Z1/U1/W1/A2/B2/C2/D2/E2/F2/G2/H2/J2/I2/K2/L2/M2/N2/O2/Q2/P2/R2/S2/T2/Y2/V2/X2";
    infile >> st;
    int kss = 1;
    for(auto& it : st){
        if(it == '/'){
            kss++;
        }
    }
    cout << "кол-во известных условий (от 0 до " + to_string(kss) + ")"<< endl;
    cin >> v1r;
    cout << "кол-во неизвестных условий (от 0 до " + to_string(kss-v1r) + ")" << endl;
    cin >> v2r;
    cout << "мин кол-во условий для вопросов" << endl;
    cin >> v3m;
    cout << "макс кол-во условий для вопросов" << endl;
    cin >> v3;
    deque<string> a(kss);
    for(int i = 0, k = 0; i<st.size();++i){
        if(st[i] != '/'){
            a[k] += st[i];
        }
        else{
            k++;
        }
    }
    auto rng = default_random_engine {};
    random_shuffle(a.begin(), a.end());
    for(int i = 0; i<v1r; ++i){
        string kj = c1[R(0, 1)];
        b.push_back(a[0]);
        if(kj == ""){
            bte.push_back(true);
            b1te.push_back(true);
        }
        else{
            bte.push_back(false);
            b1te.push_back(false);
        }
        b1.push_back(kj + a[0]);
        a.pop_front();
    }
    for(int i1 = 0; i1<v2r; ++i1){
        v3r = R(v3m, v3);
        if(v3r > b.size()-2){
            v3r = b.size()-2;
        }
        int k1 = R(0, 1);
        int aka = R(1, b.size())-1;
        outfile << "Если " << c1[k1] << b[aka] << " ";
        bool test;
        if(find(bd.begin(), bd.end(), aka) != bd.end()){
            test = (bte[aka]);
        }
        else{
            test = (c1te[k1] == bte[aka]);
        }
        
        deque<pair<string, int>> adr(0);
        for(int i = 0; i<b.size(); ++i){
            if(i != aka){
                adr.push_back(pair<string, int> (b[i], i));
            }
        }
        random_shuffle(adr.begin(), adr.end());
        for(int i = 0; i<v3r; ++i){
            string k2 = c[R(0, 1)];
            int k3 =R(0, 1);
            outfile << k2 << " " << c1[k3] << adr[i].first << " ";
            if (k2 == "и "){
                if(find(bd.begin(), bd.end(), adr[i].second) != bd.end()){
                    test = (test and (bte[adr[i].second]));
                }
                else{
                    test = (test and (c1te[k3] == bte[adr[i].second]));
                }
                
            }
            else{
                if(find(bd.begin(), bd.end(), adr[i].second) != bd.end()){
                    test = (test or (bte[adr[i].second]));
                }
                else{
                    test = (test or (c1te[k3] == bte[adr[i].second]));
                }
            }
        }
        adr.erase(adr.begin(), adr.end());
        int k4 = R(0, 1);
        int k44 = R(0, 2);
        outfile << "то " << c1[k4] << c2[k44] << a[i1] << " ";
        b.push_back(a[i1]);
        if(!test){
            bte.push_back(false);
            bd.push_back(b.size()-1);
        }
        else{
            if(k44 == 2 and c1te[k4]){
                bte.push_back(false);
                bd.push_back(b.size()-1);
            }
            else if(k44 == 2 and !c1te[k4]){
                bte.push_back(false);
            }
            else{
                bte.push_back((c1te[k4] == true));
            }
            
        }
        outfile << endl;
    }
    outfile << "Известно что";
    for(auto& it : b1){
        outfile << ", " << it;
    }
    outfile << endl;
    outfile.close();
    for(int i = 0; i<b.size(); i++){
        if(find(bd.begin(), bd.end(), i) != bd.end()){
            outfile1 << b[i] << " неизвестно" << endl;
        }
        else{
            outfile1 << b[i] << " " << bte[i] << endl;
        }
        
    }
    outfile1.close();
    return 0;
}
