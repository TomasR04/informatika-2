#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

// definuje strukturu Student
struct Student
{
    int id;
    string name; // noddy
    double prumer;
};
// definuje strukturu Node

class Node{
private:
    Student student;
    Node *next;

public:
    Node(){
        student = Student();
        next = nullptr;
    }
    Node(Student newStudent)
    {
        student = newStudent;
        next = nullptr;
    }
    Node* get_next(){
        return next;
    }

    Student get_student(){
        return student;
    }

    void set_next(Node* next){
        this->next = next;
    }

    void vypis_node(){
        cout << student.id << setw(5) << student.name << setw(5) << student.prumer << '\n';
    }

    // Node *operator[](int index)
    // {
    //     Node *current = this;
    //     for (int i = 0; i < index; i++)
    //     {
    //         if (current == nullptr)
    //         {
    //             return nullptr;
    //         }
    //         current = current->next;
    //     }
    //     return current;
    // }
};

class LinkedList{
private:
    Node **pHead;
    std::string filename;

    Student parsujRadek(const string &radek)
    {
        Student s;
        stringstream ss(radek);
        string idStr, nameStr, prumerStr;

        getline(ss, idStr, ',');
        getline(ss, nameStr, ',');
        getline(ss, prumerStr, ',');

        s.id = stoi(idStr);
        s.name = nameStr;
        s.prumer = stod(prumerStr);

        return s;
    }
    
    void ulozStudentyDoSouboru()
    {
        ofstream file(filename);

        if (!file.is_open())
        {
            cerr << "Chyba pri otevirani souboru" << filename << endl;
            return;
        }
        Node *current = *pHead;
        while (current != nullptr)
        {
            file << current->get_student().id << ","
                << current->get_student().name << ","
                << current->get_student().prumer << endl;
            current = current->get_next();
        }
        file.close();
    }

    public:
    
    LinkedList(const string &filename)
    {
        this->filename = filename;
        ifstream soubor(filename);
        string radek;
        pHead = new Node*;
        *pHead = nullptr;

        if (!soubor.is_open())
        {
            cout << "soubor se nepodařilo otevřít" << endl;
        }
        else
        {
            while (getline(soubor, radek))
            {
                if (radek.find("#") != 0 || radek.empty())
                {
                    pridejStudentaNaKonec(parsujRadek(radek));
                }
            }
        }
        soubor.close();
    }
    
    void vypisSeznam()
    {
        Node *current = *pHead;
        while (current != nullptr)
        {
            current->vypis_node();
            current = current->get_next();
        }
    }

    void pridejStudentaNaKonec(Student new_Student)
    {
        Node *newNode = new Node(new_Student);
        if (*pHead == nullptr)
        {
            *pHead = newNode;
        }else{
            Node *last = *pHead;

            while (last->get_next() != nullptr)
            {
                last = last->get_next();
            }

            last->set_next(newNode);
        }


    }

    void setridSeznamPodlePrumeru()
    {
        for (Node *i = *pHead; i != nullptr; i = i->get_next())
        {
            Node *minNode = i;
            for (Node *j = i->get_next(); j != nullptr; j = j->get_next())
            {
                if (j->get_student().prumer < minNode->get_student().prumer)
                {
                    minNode = j;
                }
            }
            if (minNode != i)
            {
                // swap(i->get_student(), minNode->get_student()); TODO
            }
        }
    }
    
    ~LinkedList(){
        ulozStudentyDoSouboru();
        Node *current = *pHead;
        while (current != nullptr)
        {
            Node *next = current->get_next();
            delete current;
            current = next;
        }
        *pHead = nullptr;
    }
};


int main()
{
    string input_file = "studenti.txt";
    string output_file = "studenti_serazeno.txt";

    LinkedList ll(input_file);

    cout << "\n Pred serazenim \n";
    ll.vypisSeznam();

    ll.setridSeznamPodlePrumeru();

    cout << "\n Po serazeni \n";
    ll.vypisSeznam();

    Student st = Student{111,"Karel Hajek", 4.3};

    ll.pridejStudentaNaKonec(st);

    return 0;
}