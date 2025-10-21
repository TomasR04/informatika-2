#include <iostream>
void najdi_nejmensi_nejvetsi(int* pole, int velikost_pole, 
    int* nejvetsi, int* nejmensi){
        while(true){
            std::cout<< "adresa: "<<pole
            << ", hodnota: "<< *pole <<std::endl;
            pole++;
        }

}

int main(){
    int pole[10]={9,4,6,27,9,2,3,7,5,8};
    int* nejmensi;
    int* nejvetsi;
    najdi_nejmensi_nejvetsi(pole, 10, nejvetsi, nejmensi);

    std::cout<<*nejmensi << ", " << *nejvetsi <<std::endl;


    return 0;
}