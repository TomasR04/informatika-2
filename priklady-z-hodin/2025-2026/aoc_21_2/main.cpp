#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

class submarine {
    //position[0] = hloubka
    //position[1] = vzdálenost
    int position[2];
    int horizontal;
    int depth;
    int aim;
    
    
    public:
    submarine() {
        position[0] = 0;
        position[1] = 0;
        horizontal = 0;
        depth = 0;
        aim = 0;
    }
    
    void forward(int x) {
        position[1] += x;
        position[0] += aim * x;
    }
    void down(int x) {
        
        aim += x;
    }
    void up(int x) {
        
        aim -= x;
    }
    
    void move(string command, int x) {
        if (command == "forward") {
            forward(x);
        } else if (command == "down") {
            down(x);
        } else if (command == "up") {
            up(x);
        } else {
            cout << "Neznamy prikaz: " << command << endl;
        }
        cout << "Horizontal: " << horizontal << ", Depth: " << depth << ", Position[0]: " << position[0] << ", Position[1]: " << position[1] << endl;
    }

    int get_position_product() {
        return position[0] * position[1];
    }

    
};

int main() {
    ifstream soubor("data.txt");
    
    if (!soubor.is_open()){
        cout << "Soubor nelze otevrit!!!" << endl;
        
        return 1;
    }

    submarine new_submarine;

    string line;

    while (getline(soubor, line)) {
        int space_pos = line.find(" ");
        
        string command = line.substr(0, space_pos);
        string number_part = line.substr(space_pos + 1);
    

        new_submarine.move(command, stoi(number_part));

        // cout << "command name: " << command << ", number:" << number_part << endl;
    }


    cout << "Finalni pozice: " << new_submarine.get_position_product() << endl;

    return 0;
}