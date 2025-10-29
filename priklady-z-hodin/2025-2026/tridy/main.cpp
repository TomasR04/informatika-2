#include <iostream>

class Obdelnik{
    private: 
        int a = 10;
        int b = 12;
    public:
        void tisk(){
            std::cout<<"Strana a: "<<a<<", strana b: "<<b<<std::endl;
        }
        void zmen_a(int a){
            this->a=a;
        }
};


int main(){

    Obdelnik obdelnik1;
    Obdelnik* pobdelnik1 = &obdelnik1;

    obdelnik1.tisk();
    obdelnik1.zmen_a(5);
    pobdelnik1->tisk();

    return 0;
}