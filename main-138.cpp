#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int R(int min, int max)
{
    double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
class Person{
    public:
        void set(string n,string c,string p,string h,string f,string l,string a,string w,string ci,string ha,string ca){
            name = n;
            color = c;
            pet = p;
            house = h;
            food = f;
            last_name = l;
            action = a;
            work = w;
            city = ci;
            hat_color = ha;
            car = ca;
        }
        deque<string> get(){
            deque<string> propof(11);
            propof = {name, color, pet, house, food, last_name, action,work,city,hat_color,car};
            return propof;
        }
        string name;
        string color;
        string pet;
        string house;
        string food;
        string last_name;
        string action;
        string work;
        string city;
        string hat_color;
        string car;
};
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int hard;
    cin >> hard;
    deque<deque<string>> prop(11, deque<string>(8));
    prop = {{"Антон","Олег","Михаил","Иван","Александр","Денис","Егор","Коли"},{"зеленый","красный","желтый","синий","розовый","фиолетовый","голубой","оранжевый"},{"собака","кот","попугай","рыбка","енот","мышь","тигр","зебра"},{"a","b","c","d","e","f","g","h"},{"a","b","c","d","e","f","g","h"},{"a","b","c","d","e","f","g","h"},{"a","b","c","d","e","f","g","h"},{"a","b","c","d","e","f","g","h"},{"a","b","c","d","e","f","g","h"},{"a","b","c","d","e","f","g","h"},{"a","b","c","d","e","f","g","h"}};
    int perk = R(hard, hard+2);
    deque<Person> allpers(perk);
    for(auto& it : prop){
        random_shuffle(it.begin(), it.end());
    }
    for(int i = 0; i < allpers.size(); i++){
        Person pers;
        pers.set(prop[0][i],prop[1][i],prop[2][i],prop[3][i],prop[4][i],prop[5][i],prop[6][i],prop[7][i],prop[8][i],prop[9][i],prop[10][i]);
        allpers[i] = pers;
        for(auto& it : pers.get()){
            cout << it << " ";
        }
        cout << endl;
    }
    int propk = R(hard, hard+2);
    int ansk = R(hard, hard+2)/2;
    deque<deque<string>> pol(perk, deque<string> (propk));
    for(int i = 0; i<perk; ++i){
        for(int j = 1; j<propk+1; ++j){
            pol[i][j-1] = allpers[i].get()[j];
        }
    }
    cout << "известно что: " << endl;
    for(auto& it : pol){
        random_shuffle(it.begin(), it.end());
    }
    random_shuffle(pol.begin(),pol.end());
    for(int i = 0; i<perk;++i){
        if(i < perk-ansk){
            for(int j = 0; j<propk-ansk; ++j){
                cout << "у " << allpers[i].name << "а " << pol[i][j] << endl; 
            }
        }
        else{
            for(int j = 0; j<propk; ++j){
                if(R(0, 25) != 0){
                    cout << "у кого " << pol[i][j] << endl; 
                }
                else{
                    cout << "что у " << allpers[i].name << " в категории " << endl;
                }
            }
        }
    }
    
    return 0;
}
