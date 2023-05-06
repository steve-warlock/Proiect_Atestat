//
//  functii.cpp
//  
//
//  Created by Steve Warlock on 21.10.2022.
//

#include "DLL.hpp"
#include "functii.hpp"

std::ifstream fin("fisiere/citire.in");

std::string method, choice, first, second, value;

namespace solution{

DLL p, q;

bool is_music_enable = false;

void toggle_music()
{
    // true - play
    //false - stop
    is_music_enable = !is_music_enable;
    if(is_music_enable)
        system("afplay miracle.mp3 -v 2 -q 1 &>/dev/null &");
    else
        system("killall afplay");
        
}


void fail_case(){
    system("clear");
    std::cout << "Introduceti o optiune valida!\n";
    std::cout << "Apasati tasta Enter pentru a va reintoarce...";
    std::cin.ignore();
    system("clear");
}

bool verify(std::string& type, const std::string& input){
    if(!strcmp(type.c_str(), input.c_str()))
        return true;
    return false;
}

void convertire_citire_tastatura(int i, int& x, bool& iscorrect, std::istream& cin)
{
    iscorrect = true;
    x = 0;
    std::cout << "Introduceti informatia nodului " << i << ": ";
    getline(cin, value);
    std::string::iterator it = value.begin();
    for(; it != value.end(); ++it)
    if(!(*it >= '0' && *it <= '9'))
    {
        iscorrect = false;
        break;
    }
    else
        x = x * 10 + (*it) - '0';

    if(!iscorrect) {
        fail_case();
        convertire_citire_tastatura(i, x, iscorrect, cin);
    }
    
    
}

void convertire_citire_fisier(int i, int& x, bool& iscorrect, std::ifstream& in)
{
    iscorrect = true;
    x = 0;
    std::cout << "Introduceti informatia nodului " << i << ": (fisier)";
    getline(in, value);
    std::string::iterator it = value.begin();
    for(; it != value.end(); ++it)
    if(!(*it >= '0' && *it <= '9'))
    {
        iscorrect = false;
        break;
    }
    else
        x = x * 10 + (*it) - '0';

    if(!iscorrect) {
        fail_case();
        convertire_citire_fisier(i, x, iscorrect, in);
    }
}

void tip_citire_tastatura(DLL& p, int n, std::istream& cin){
    
    std::cout << "Cum doriti sa fie lista memorata?" << '\n';
    std::cout <<"In ordinea introducerii numerelor sau in ordinea inversa?(ordonat/invers): ";
    getline(std::cin, method);
    std::cout << '\n';
    if(verify(method, "ordonat")){
        for(int i = 1; i <= n;)
        {
            int x;
            bool iscorrect;
            convertire_citire_tastatura(i, x, iscorrect, cin);
            if(iscorrect == true)
            {
                i++;
                std::cout << '\n';
                p.AddToTail(p,x);
            }
        }
        std::cout << "Lista a fost introdusa!\n";
        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
        cin.ignore();
        system("clear");
    }
    else if(verify(method, "invers"))
    {
        for(int i = 1; i <= n;)
        {
            int x;
            bool iscorrect;
            convertire_citire_tastatura(i, x, iscorrect, cin);
            if(iscorrect == true)
            {
                i++;
                std::cout << '\n';
                p.AddToHead(p,x);
            }
            
        }
        std::cout << "Lista a fost introdusa!\n";
        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
        cin.ignore();
        system("clear");
    }
    else
    {
        fail_case();
        tip_citire_tastatura(p, n, cin);
    }
}

void tip_citire_fisier(DLL& p, int n, std::ifstream& in){
    
    std::cout << "Cum doriti sa fie lista memorata?" << '\n';
    std::cout <<"In ordinea introducerii numerelor sau in ordinea inversa?(ordonat/invers): ";
    getline(std::cin, method);
    std::cout << '\n';
    if(verify(method, "ordonat"))
    {
        for(int i = 1; i <= n;)
        {
            int x;
            bool iscorrect;
            convertire_citire_fisier(i, x, iscorrect, in);
            if(iscorrect == true)
            {
                i++;
                std::cout << '\n';
                p.AddToTail(p,x);
            }
        }
            
        in.get();
        std::cout << "Lista a fost introdusa!\n";
        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
        std::cin.ignore();
        system("clear");
    }
    else if(verify(method, "invers"))
    {
        for(int i = 1; i <= n;)
        {
            int x;
            bool iscorrect;
            convertire_citire_fisier(i, x, iscorrect, in);
            if(iscorrect == true)
            {
                i++;
                std::cout << '\n';
                p.AddToHead(p,x);
            }
        }
        in.get();
        std::cout << "Lista a fost introdusa!\n";
        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
        std::cin.ignore();
        system("clear");
    }
    else
    {
        fail_case();
        tip_citire_fisier(p, n, in);
    }
}

void citire_tastatura(DLL& p, std::istream& cin){
    int n;
    std::cout << "Introduceti numarul de numere al listei: ";
    cin >> n;
    cin.get();
    std::cout << '\n';
    tip_citire_tastatura(p, n, cin);
}

void citire_fisier(DLL& p, std::ifstream& in){
    if(in.is_open())
    {
        int n;
        std::cout << "Introduceti numarul de numere al listei: (fisier)";
        in >> n;
        std::cout << n;
        in.get();
        std::cout << '\n';
        tip_citire_fisier(p, n, in);
        in.close();
    }
    else
        throw std::runtime_error("Failed to open the file!");
}



void case_1(DLL& p){
    if(p.isEmpty())
    {
        std::cout << "Alegeti tipul de citire: (tastatura/fisier) ";
        std::cin >> choice;
        std::cin.get();
        std::cout << '\n';
        if(verify(choice, "tastatura"))
            citire_tastatura(p, std::cin);
        else
            if(verify(choice, "fisier"))
                citire_fisier(p, fin);
            else
            {
                fail_case();
                case_1(p);
            }
    }
    else
    {
        system("clear");
        std::cout << "Lista nu este vida. Alegeti optiunea 8 pentru a sterge continutul ascesteia.\n";
        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
        std::cin.ignore();
//        std::cout << '\n';
        system("clear");
    }
}

void op_1(){
    system("clear");
    std::cout << "Ce lista doriti sa cititi? (prima/doua) ";
    getline(std::cin,choice);
    std::cout << '\n';
    if(verify(choice, "prima"))
        case_1(p);
    else  if(verify(choice, "doua"))
        case_1(q);
    else {
        fail_case();
        op_1();
    }
}

void case_2(DLL& p, DLL& q, std::string& method){
    
    
    if(verify(method, "prima")){
        if(!p.isEmpty())
        {   std::cout << "\n" << method << " lista este: ";
            std::cout << p << '\n';
            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
            std::cin.ignore();
//            std::cout << '\n';
            system("clear");
        }
        else
        {   std::cout << "Prima lista este vida." << '\n';
            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
            std::cin.ignore();
//            std::cout << '\n';
            system("clear");
        }
    }
    else
        if(verify(method, "doua"))
        {
            if(!q.isEmpty()){
                std::cout << "A " << method << " lista este: ";
                std::cout << q << '\n';
                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                std::cin.ignore();
//                std::cout << '\n';
                system("clear");
            }
            else
            {
                std::cout << "A doua lista este vida." << '\n';
                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                std::cin.ignore();
//                std::cout << '\n';
                system("clear");
            }
        }
        else if(verify(method, "ambele"))
        {
            method[0] = toupper(method[0]);
            std::cout << method << " liste sunt: \n";
            if(!p.isEmpty() || !q.isEmpty()){
                if(!p.isEmpty())
                { std::cout << "Prima" << " lista este: ";
                    std::cout << p << '\n';
                }
                else
                {
                    std::cout << "Prima lista este vida.\n";
                }
                if(!q.isEmpty())
                { std::cout << "A doua" << " lista este: ";
                    std::cout << q << '\n';
                }
                else
                {
                    std::cout << "A doua" << " lista este vida.\n";
                }
            }
            else
                if(p.isEmpty() && q.isEmpty())
                {
                    std::cout << "vide.\n";
                }
            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
            std::cin.ignore();
//            std::cout << '\n';
            system("clear");
        }
        else
        {
            fail_case();
            case_2(p, q, method);
        }
    
    
}

void op_2(){
    system("clear");
    std::cout << "Care lista doriti sa o afisati (prima/doua/ambele)? ";
    getline(std::cin, choice);
    case_2(p, q, choice);
}

void case_3(DLL& p, DLL& q){
    p += q;
    std::cout << "Cele 2 liste au fost concatenate.";
    std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
    std::cin.ignore();
    std::cout << '\n';
    system("clear");
}

void op_3(){
    system("clear");
    if(p.isEmpty())
    {
        std::cout << "Pentru aceasta optiune aveti nevoie de o lista suplimentara.\n";
        std::cin.ignore();
        case_1(p);
    }
    else
        if(q.isEmpty())
        {
            std::cout << "Pentru aceasta optiune aveti nevoie de o lista suplimentara.\n";
            std::cin.ignore();
            case_1(q);
        }
    std::cout << "Cum doriti sa fie concatenarea?" << '\n';
    std::cout << "Prima lista concatenata cu a doua lista sau invers?(prim/doi) ";
    getline(std::cin,choice);
    std::cout << '\n';
    if(verify(choice, "prim"))
        case_3(p, q);
    else
        if(verify(choice, "doi"))
            case_3(q, p);
        else
        {
            fail_case();
            op_3();
        }
    
}

void case_4(DLL& p, DLL& q, int x){
    
    std::cout << "Prima/doua/ambele: (litere mici) ";
    getline(std::cin, method);
    std::cout << '\n';
    if(verify(method, "prima"))
    {
        p.AddToHead(p, x);
        std::cout << "Nodul cu informatia "<< x <<" a fost introdus in " << method << " lista.";
        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
        std::cin.ignore();
//        std::cout << '\n';
        system("clear");
    }
    else
        if(verify(method, "doua"))
        {
            q.AddToHead(q, x);
            std::cout << "Nodul cu informatia "<< x <<" a fost introdus in a " << method << " lista.";
            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
            std::cin.ignore();
//            std::cout << '\n';
            system("clear");
        }
        else
            if(verify(method, "ambele"))
            {
                p.AddToHead(p, x);
                q.AddToHead(q, x);
                std::cout << "Nodul cu informatia " << x << " a fost introdus in " << method << " liste.";
                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                std::cin.ignore();
//                std::cout << '\n';
                system("clear");
            }
            else
            {
                fail_case();
                case_4(p, q, x);
            }
}

void op_4(){
    system("clear");
    std::cout << "De unde va fi citita informatia nodului? (tastatura/fisier) ";
    getline(std::cin, choice);
    if(verify(choice, "tastatura"))
    {
        std::cout << "Lista in care doriti sa introduceti la inceputul acesteia, nodul cu valoarea: ";
        int x;
        std::cin >> x;
        std::cin.get();
        std::cout << '\n';
        case_4(p, q, x);
    }
    else
        if(verify(choice, "fisier"))
        {
            std::cout << "Lista in care doriti sa introduceti la inceputul acesteia, nodul cu valoarea: (fisier)";
            int x;
            fin >> x;
            fin.get();
            std::cout << x;
            std::cin.get();
            std::cout << '\n';
            case_4(p, q, x);
            
        }
        else
        {
            fail_case();
            op_4();
        }
}

void case_5(DLL& p, DLL& q, int x){
    
    std::cout << "Prima/doua/ambele: (litere mici) ";
    getline(std::cin, method);
    std::cout << '\n';
    if(verify(method, "prima"))
    {
        p.AddToTail(p, x);
        std::cout << "Nodul cu informatia "<< x <<" a fost introdus in " << method << " lista.";
        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
        std::cin.ignore();
//        std::cout << '\n';
        system("clear");
    }
    else
        if(verify(method, "doua"))
        {
            q.AddToTail(q, x);
            std::cout << "Nodul cu informatia "<< x <<" a fost introdus in a " << method << " lista.";
            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
            std::cin.ignore();
//            std::cout << '\n';
            system("clear");
        }
        else
            if(verify(method, "ambele"))
            {
                p.AddToTail(p, x);
                q.AddToTail(q, x);
                std::cout << "Nodul cu informatia " << x << " a fost introdus in " << method << " liste.";
                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                std::cin.ignore();
//                std::cout << '\n';
                system("clear");
            }
            else
            {
                fail_case();
                case_5(p, q, x);
            }
    
}

void op_5(){
    system("clear");
    std::cout << "De unde va fi citita informatia nodului? (tastatura/fisier) ";
    getline(std::cin, choice);
    if(verify(choice, "tastatura"))
    {
        std::cout << "Lista in care doriti sa introduceti la sfarsitul acesteia, nodul cu valoarea: ";
        int x;
        std::cin >> x;
        std::cin.get();
        case_5(p, q, x);
    }
    else
        if(verify(method, "fisier"))
        {
            std::cout << "Lista in care doriti sa introduceti la inceputul acesteia, nodul cu valoarea: ";
            int x;
            fin >> x;
            fin.get();
            std::cout << x;
            std::cin.get();
            case_5(p, q, x);
        }
        else
        {
            fail_case();
            op_5();
        }
}

void case_6(DLL& p, DLL& q, int x){
    std::cout << "In ce lista?" << '\n';
    std::cout << "Prima/doua/ambele: (litere mici) ";
    getline(std::cin, method);
    std::cout << '\n';
    if(verify(method, "prima"))
    {
        if(p.search(p,x) == -1)
            std::cout << "Nu exista nodul cu informatia " << x << " in " << method << " lista.\n";
        else
            std::cout << "Pozitia nodului cu informatia " << x << " din " << method <<" lista este " << p.search(p,x) << '.' << '\n';
        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
        std::cin.ignore();
        std::cout << '\n';
        system("clear");
    }
    else
        if(verify(method, "doua"))
        {
            if(q.search(q,x) == -1)
                std::cout << "Nu exista nodul cu informatia " << x << " in a " << method << " lista.\n";
            else
                std::cout << "Pozitia nodului cu informatia " << x << " din a " << method <<" lista este " << q.search(q,x) << '.' << '\n';
            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
            std::cin.ignore();
            std::cout << '\n';
            system("clear");
        }
        else
            if(verify(method, "ambele"))
            {
                if(p.search(p,x) == -1)
                    std::cout << "Nu exista nodul cu informatia " << x << " in " << method << " lista.\n";
                else
                    std::cout << "Pozitia nodului cu informatia " << x << " din " << method <<" lista este " << p.search(p,x) << '.' << '\n';
                if(q.search(q,x) == -1)
                    std::cout << "Nu exista nodul cu informatia " << x << " in a " << method << " lista.\n";
                else
                    std::cout << "Pozitia nodului cu informatia " << x << " din a " << method <<" lista este " << q.search(q,x) << '.' << '\n';
                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                std::cin.ignore();
                std::cout << '\n';
                system("clear");
            }
            else
            {
                fail_case();
                case_6(p, q, x);
            }
}

void op_6(){
    system("clear");
    std::cout << "De unde va fi citita informatia nodului? (tastatura/fisier) ";
    getline(std::cin, choice);
    if(verify(choice, "tastatura"))
    {
        std::cout << "Ce informatie are nodul cautat?: ";
        int x;
        std::cin >> x;
        std::cin.get();
        case_6(p, q, x);
    }
    else
        if(verify(choice, "fisier"))
        {
            std::cout << "Ce informatie are nodul cautat?: (fisier)";
            int x;
            fin >> x;
            fin.get();
            std::cout << x << '\n';
            std::cin.get();
            case_6(p, q, x);
        }
        else
        {
            fail_case();
            op_6();
        }
    
}

void case_7(DLL& p, DLL& q, int x){
    std::cout << "In ce lista?" << '\n';
    std::cout << "Prima/doua/ambele: (litere mici) ";
    getline(std::cin, method);
    std::cout << '\n';
    if(verify(method, "prima"))
    {
        
        p.DeleteNodes(p,x);
        std::cout << "Nodurile cu informatia " << x << " au fost sterse din " << method << " lista.\n";
        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
        std::cin.ignore();
        std::cout << '\n';
        system("clear");
    }
    else
        if(verify(method, "doua"))
        {
            q.DeleteNodes(q,x);
            std::cout << "Nodurile cu informatia " << x << " au fost sterse din a " << method << " lista.\n";
            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
            std::cin.ignore();
            std::cout << '\n';
            system("clear");
        }
        else
            if(verify(method, "ambele"))
            {
                p.DeleteNodes(p,x);
                q.DeleteNodes(q,x);
                std::cout << "Nodurile cu informatia " << x << " au fost sterse din " << method << " liste.\n";
                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                std::cin.ignore();
                std::cout << '\n';
                system("clear");
            }
            else
            {
                fail_case();
                case_7(p, q, x);
            }
}

void op_7(){
    system("clear");
    std::cout << "De unde va fi citita informatia nodului? (tastatura/fisier) ";
    getline(std::cin, choice);
    if(verify(choice, "tastatura"))
    {
        std::cout << "Ce informatie sa aiba nodul/nodurile care va/vor fi sters/sterse?: ";
        int x;
        std::cin >> x;
        std::cin.get();
        case_7(p, q, x);
    }
    else
        if(verify(choice, "fisier"))
        {
            std::cout << "Ce informatie sa aiba nodul/nodurile care va/vor fi sters/sterse?: (fisier)";
            int x;
            fin >> x;
            fin.get();
            std::cout << x;
            std::cin.get();
            std::cout << '\n';
            case_7(p, q, x);
        }
        else
        {
            fail_case();
            op_7();
        }
}

void case_8(DLL& p)
{
    std::cout << "\nIntroduceti o varianta: ";
    getline(std::cin, method);
    if(verify(method, "crescator"))
    {
        p.sortAscending(p);
    }
    else
        if(verify(method, "descrescator"))
        {
            p.sortDescending(p);
        }
        else
        {
            fail_case();
            case_8(p);
        }
}

void op_8()
{
    system("clear");
    std::cout << "Ce lista doriti sa o sortati? (prima/doua/ambele) ";
    getline(std::cin, choice);
    std::cout << '\n';
    if(verify(choice, "prima"))
    {
        if(!p.isEmpty()){
            std::cout << "Cum doriti sa sortati " << choice << " lista? (crescator/descrescator) ";
            case_8(p);
            choice[0] = toupper(choice[0]);
            std::cout << choice << " lista a fost sortata " << method << ".\n";
            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
            std::cin.ignore();
            system("clear");
        }
        else
            if(p.isEmpty())
        {
            choice[0] = toupper(choice[0]);
            std::cout << choice << " lista este vida. Alegeti optiunea 1 pentru a introduce elemente in lista.\n";
            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
            std::cin.ignore();
            system("clear");
        }
    }
    else
        if(verify(choice, "doua"))
        {
            if(!q.isEmpty())
            {
                std::cout << "Cum doriti sa sortati a " << choice << " lista? (crescator/descrescator) ";
                case_8(q);
                std::cout << "A " << choice << " lista a fost sortata " << method << ".\n";
                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                std::cin.ignore();
                system("clear");
            }
            else if(q.isEmpty())
            {
                std::cout << "A " << choice << " lista este vida. Alegeti optiunea 1 pentru a introduce elemente in lista.\n";
                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                std::cin.ignore();
                system("clear");
            }
        }
        else
            if(verify(choice, "ambele"))
            {
                choice[0] = toupper(choice[0]);
                if(!p.isEmpty() && !q.isEmpty()){
                    std::cout << "Cum doriti sa sortati listele?\n";
                    std::cout << "Prima lista: crescator/descrescator? (crescator/descrescator) ";
                    case_8(p);
                    std::cout << "A doua lista: crescator/descrescator? (crescator/descrescator) ";
                    case_8(q);
                    std::cout << choice << " liste sunt sortate.\n";
                    std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                    std::cin.ignore();
                    system("clear");
                }
                else
                {
                    if(p.isEmpty())
                    {
                        std::cout << "Prima lista este vida. Alegeti optiunea 1 pentru a introduce elemente in lista.\n";
                        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                        std::cin.ignore();
                        system("clear");
                    }
                    else
                        if(q.isEmpty())
                        {
                            std::cout << "A doua lista este vida. Alegeti optiunea 1 pentru a introduce elemente in lista.\n";
                            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            system("clear");
                        }
                        else
                            if(p.isEmpty() && q.isEmpty())
                            {
                                
                                std::cout << choice << " liste sunt vide. Alegeti optiunea 1 pentru a introduce elemente in liste.\n";
                                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                                std::cin.ignore();
                                system("clear");
                            }
                }
            }
            else
            {
                fail_case();
                op_8();
            }
    
}

void case_9(DLL& p, DLL& q){
    
    std::cout << "Ce lista doriti sa o stergeti? (prima/doua/ambele) ";
    getline(std::cin, method);
    std::cout << '\n';
    if(verify(method, "prima"))
    {
        p.reset(p);
        method[0] = toupper(method[0]);
        std::cout << method << " lista a fost stearsa.\n";
        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
        std::cin.ignore();
        system("clear");
    }
    else
        if(verify(method, "doua"))
        {
            q.reset(q);
            std::cout << "A " << method << " Lista a fost stearsa.\n";
            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
            std::cin.ignore();
            system("clear");
        }
        else
            if(verify(method, "ambele"))
            {
                p.reset(p);
                q.reset(q);
                method[0] = toupper(method[0]);
                std::cout << method << " liste au fost sterse.\n";
                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniu...";
                std::cin.ignore();
                system("clear");
            }
            else
            {
                fail_case();
                case_9(p, q);
            }
}

void op_9(){
    system("clear");
    case_9(p, q);
}

}
