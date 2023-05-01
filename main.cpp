
//
//  main.cpp
//  Double_Linked_List
//
//  Created by Steve Warlock on 02.04.2022.
//

#include "DLL.hpp"
#include "functii.hpp"


void meniu(){
    system("clear");
    std::cout << "\n\n\n\t\tListe Liniare Dublu Inlantuite\n\n";
    std::cout << "\n\t1. Citeste o lista (tastatura/fisier)\n";
    std::cout << "\n\t2. Afisarea listei/listelor (tastatura)\n";
    std::cout << "\n\t3. Concatenarea a 2 liste\n";
    std::cout << "\n\t4. Adaugarea unui nod nou la inceputul listei\n";
    std::cout << "\n\t5. Adaugarea unui nod nou la sfarsitul listei\n";
    std::cout << "\n\t6. Cautarea pozitiei unui nod de cheie data\n";
    std::cout << "\n\t7. Stergerea nodurilor cu informatia x\n";
    std::cout << "\n\t8. Sortarea listelor (crescator/descrescator)\n";
    std::cout << "\n\t9. Resetarea listei/listelor\n";
    std::cout << "\n\t0. Iesire\n\n";
}


char val[101];
int m, op;
bool ok = false;

int main() {
    system("afplay miracle.mp3 -v 3 -q 1 &>/dev/null &");
    do{
        meniu();
        std::cout << "Introduceti optiunea: ";
        std::cin >> val;
        std::cin.get();
        if(strlen(val) == 1)
            if(val[0] >= '0' && val[0] <= '8')
            { m = val[0] - '0'; ok = true;}
            else
            {m = 101; ok = false;}
            else
                if(strlen(val) > 1)
                { ok = false;
                    for(int i = 0; i < strlen(val); ++i)
                        m = m * 10 + val[i] - '0';
                }
        if(ok)
            op = m;
        else op = 101;
        std::cout << '\n';
        switch (op) {
            case 1:
                solution::op_1();
                break;
                
            case 2:
                solution::op_2();
                break;
                
            case 3:
                solution::op_3();
                break;
                
            case 4:
                solution::op_4();
                break;
                
            case 5:
                solution::op_5();
                break;
                
            case 6:
                solution::op_6();
                break;
                
            case 7:
                solution::op_7();
                break;
                
            case 8:
                solution::op_8();
                break;
                
            case 9:
                solution::op_9();
                break;
                
            case 0:
                system("clear");
                std::cout << "\n\n\n\n\n\n\n\n\n\t\t\x1b[32mMultumesc pentru acordarea timpului dumneavoastra! 😊\x1b[0m";
                std::cin.ignore();
                std::cout << '\n';
                system("killall afplay");
                system("clear");
                exit(0);
                break;
                
            default:
                system("clear");
                std::cout << "\n\n\nIntroduceti o optiune valida!";
                std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...\n";
                std::cin.ignore();
                system("clear");
                
        }
    }while(true);
    
    return 0;
}
