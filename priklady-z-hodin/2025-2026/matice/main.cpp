#include <iostream>
#include <ctime>

void tiskni_pole(int** pole, int radky, int sloupce){
    for (int i = 0; i < radky; ++i){
        for (int j = 0; j < sloupce; ++j){
            std::cout<<pole[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }
}

int main(){
    int radky, sloupce;
    std::cin>>radky;
    std::cin>>sloupce;

    int** matice_1 = nullptr;

    matice_1 = new int*[radky]; 

    std::srand(std::time(0));

    for (int i = 0; i < radky; ++i) {
        // pPole2D[i] je typu 'ukazatel na int'
        matice_1[i] = new int[sloupce];
        for (int j = 0; j < sloupce; ++j){
            matice_1[i][j] = std::rand()%10;
        }
    }
    tiskni_pole(matice_1, radky, sloupce);

    return 0;
}