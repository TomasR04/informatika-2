#include <iostream>

long generator(long previous, int factor){
    return (previous*factor)%2147483647;
}

bool compare_last_bits(long value_a, long value_b){
    return (value_a & 0xFFFF) == (value_b & 0xFFFF);
}

int generation(long a_start, long b_start, int steps){
    long a_result=a_start;
    long b_result=b_start;
    int pocet_shodnych = 0;

    for(int i=0; i<steps;i++){
        a_result = generator(a_result, 16807);
        b_result = generator(b_result, 48271);
        if(compare_last_bits(a_result, b_result)){
            pocet_shodnych++;
        }

        // std::cout<<"Generator A value: "<< a_result <<"Generator B value: " << b_result <<std::endl;
    }
    return pocet_shodnych;
}

int main(){

    long a_start = 65;
    long b_start = 8921;

    std::cout<<generation(a_start, b_start, 40000000)<<std::endl;

}