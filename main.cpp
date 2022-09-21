
//
//  main.cpp
//  Double_Linked_List
//
//  Created by Steve Warlock on 02.04.2022.
//

#include "DLL.hpp"

std::ifstream fin("fisiere/citire.in");

void meniu()
{
    system("clear");
    std::cout << "\n\n\t\tListe Liniare Dublu Inlantuite\n\n";
    std::cout << "\n\t1. Citeste lista (tastatura/fisier)\n";
    std::cout << "\n\t2. Afisarea listei/listelor (tastatura)\n";
    std::cout << "\n\t3. Concatenarea a 2 liste\n";
    std::cout << "\n\t4. Adaugarea unui nod nou la inceputul listei\n";
    std::cout << "\n\t5. Adaugarea unui nod nou la sfarsitul listei\n";
    std::cout << "\n\t6. Cautarea pozitiei unui nod de cheie data\n";
    std::cout << "\n\t7. Stergerea nodurilor cu informatia x\n";
    std::cout << "\n\t8. Resetarea listei/listelor\n";
    std::cout << "\n\t0. Iesire\n\n";
}

solution::DLL p,q;
char val[101];
int m,op;
std::string type,method;
bool ok = false;
int main() {
    system("afplay miracle.mp3 -v 1 -q 1 &>/dev/null &");
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
                system("clear");
                if(p.isEmpty())
                {
                    std::cout << "Alegeti tipul de citire: (tastatura/fisier) ";
                    std::cin >> type;
                    std::cin.get();
                    std::cout << '\n';
                    if(!strcmp(type.c_str(), "tastatura"))
                    {
                        int n;
                        std::cout << "Introduceti numarul de numere al listei: ";
                        std::cin >> n;
                        std::cin.get();
                        std::cout << '\n';
                        std::cout << "Cum doriti sa fie lista memorata?" << '\n';
                        std::cout <<"In ordinea introducerii numerelor sau in ordinea inversa?(ordonat/invers): ";
                        std::cin >> method;
                        std::cin.get();
                        std::cout << '\n';
                        if(!strcmp(method.c_str(),"ordonat")){
                            for(int i = 1; i <= n; ++i)
                            {
                                int x;
                                std::cout << "Introduceti informatia nodului " << i << ": ";
                                std::cin >> x;
                                std::cout << '\n';
                                p.AddToTail(p,x);
                            }
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                        }
                        else if(!strcmp(method.c_str(), "invers"))
                        {
                            for(int i = 1; i <= n; ++i)
                            {
                                int x;
                                std::cout << "Introduceti informatia nodului " << i << ": ";
                                std::cin >> x;
                                std::cout << '\n';
                                p.AddToHead(p,x);
                                
                            }
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                        }
                    }
                    else if(!strcmp(type.c_str(), "fisier"))
                    {
                        int n;
                        std::cout << "Introduceti numarul de numere al listei: (fisier)";
                        fin >> n;
                        fin.get();
                        std::cout << '\n';
                        std::cout << "Cum doriti sa fie lista memorata?" << '\n';
                        std::cout <<"In ordinea introducerii numerelor sau in ordinea inversa?(ordonat/invers): ";
                        std::cin >> method;
                        std::cout << '\n';
                        if(!strcmp(method.c_str(),"ordonat"))
                        {
                            for(int i = 1; i <= n; ++i)
                            {
                                int x;
                                std::cout << "Introduceti informatia nodului " << i << ": (fisier)";
                                fin >> x;
                                std::cout << '\n';
                                p.AddToTail(p,x);
                            }
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                            fin.get();
                        }
                        else if(!strcmp(method.c_str(), "invers"))
                        {
                            for(int i = 1; i <= n; ++i)
                            {
                                int x;
                                std::cout << "Introduceti informatia nodului " << i << ": (fisier)";
                                fin >> x;
                                std::cout << '\n';
                                p.AddToHead(p,x);
                            }
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                            fin.get();
                        }
                    }
                    system("clear");
                }
                else
                {
                    system("clear");
                    std::cout << "Lista nu este vida. Alegeti optiunea 8 pentru a sterge continutul ascesteia.\n";
                    std::cin.ignore();
                    std::cin.get();
                    std::cout << '\n';
                    system("clear");
                }
                break;
                
            case 2:
                system("clear");
                std::cout << "Care lista doriti sa o afisati (prima/doua/ambele)? ";
                std::cin >> method;
                std::cin.get();
                std::cout << '\n';
                if(!strcmp(method.c_str(), "prima"))
                {
                    if(!p.isEmpty())
                    {
                        std::cout << "\n" << method << " lista este: ";
                        std::cout << p << '\n';
                        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniul principal...";
                        std::cin.ignore();
                        std::cout << '\n';
                        system("clear");
                    }
                    else
                    {
                        std::cout << "Lista este vida." << '\n';
                        std::cout << "Apasati tasta Enter pentru a va reintoarce la meniul principal...";
                        std::cin.ignore();
                        std::cout << '\n';
                        system("clear");
                    }
                }
                else
                    if(!strcmp(method.c_str(), "doua"))
                    {
                        if(!q.isEmpty())
                        {
                            std::cout << "\n" << method << " lista este: ";
                            std::cout << q << '\n';
                            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniul principal...";
                            std::cin.ignore();
                            std::cout << '\n';
                            system("clear");
                        }
                        else
                        {
                            std::cout << "Lista este vida." << '\n';
                            std::cout << "Apasati tasta Enter pentru a va reintoarce la meniul principal...";
                            std::cin.ignore();
                            std::cout << '\n';
                            system("clear");
                        }
                        
                    }
                    else
                        if(!strcmp(method.c_str(), "ambele"))
                        {
                            if(!p.isEmpty() && !q.isEmpty())
                            {
                                std::cout << "\n" << method << " liste sunt: ";
                                std::cout << p << "si " << q << '\n';
                                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniul principal...";
                                std::cin.ignore();
                                std::cout << '\n';
                                system("clear");
                            }
                            else if(p.isEmpty() && !q.isEmpty())
                            {
                                std::cout << "Prima lista este vida." << '\n';
                                std::cout << "A doua lista este " << q << '\n';
                                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniul principal...";
                                std::cin.ignore();
                                std::cout << '\n';
                                system("clear");
                            }
                            else if(!p.isEmpty() && q.isEmpty())
                            {
                                std::cout << "Prima lista este " << p << '\n';
                                std::cout << "A doua lista este vida." << '\n';
                                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniul principal...";
                                std::cin.ignore();
                                std::cout << '\n';
                                system("clear");
                            }
                            else
                            {
                                std::cout << "Ambele liste sunt vide." << '\n';
                                std::cout << "Apasati tasta Enter pentru a va reintoarce la meniul principal...";
                                std::cin.ignore();
                                std::cout << '\n';
                                system("clear");
                            }
                        }
                break;
                
            case 3:
                system("clear");
                if(q.isEmpty())
                {   std::cout << "Pentru aceasta optiune aveti nevoie de o lista suplimentara.\n";
                    std::cout << "Alegeti tipul de citire: (tastatura/fisier) ";
                    std::cin >> type;
                    std::cin.get();
                    std::cout << '\n';
                    if(!strcmp(type.c_str(), "tastatura"))
                    {
                        int n;
                        std::cout << "Introduceti numarul de numere al listei: ";
                        std::cin >> n;
                        std::cin.get();
                        std::cout << '\n';
                        std::cout << "Cum doriti sa fie lista memorata?" << '\n';
                        std::cout <<"In ordinea introducerii numerelor sau in ordinea inversa?(ordonat/invers): ";
                        std::cin >> method;
                        std::cin.get();
                        std::cout << '\n';
                        if(!strcmp(method.c_str(),"ordonat")){
                            for(int i = 1; i <= n; ++i)
                            {
                                int x;
                                std::cout << "Introduceti informatia nodului " << i << ": ";
                                std::cin >> x;
                                std::cout << '\n';
                                q.AddToTail(q,x);
                            }
                            std::cout << "\nApasati tasta ENTER pentru a continua...";
                            std::cin.ignore();
                            std::cin.get();
                        }
                        else if(!strcmp(method.c_str(), "invers"))
                        {
                            for(int i = 1; i <= n; ++i)
                            {
                                int x;
                                std::cout << "Introduceti informatia nodului " << i << ": ";
                                std::cin >> x;
                                std::cout << '\n';
                                q.AddToHead(q,x);
                            }
                            std::cout << "\nApasati tasta ENTER pentru a continua...";
                        }
                    }
                    else if(!strcmp(type.c_str(), "fisier"))
                    {
                        int n;
                        std::cout << "Introduceti numarul de numere al listei: (fisier).";
                        fin >> n;
                        fin.get();
                        std::cout << '\n';
                        std::cout << "Cum doriti sa fie lista memorata?" << '\n';
                        std::cout <<"In ordinea introducerii numerelor sau in ordinea inversa? (ordonat/invers): ";
                        std::cin >> method;
                        std::cout << '\n';
                        if(!strcmp(method.c_str(),"ordonat")){
                            for(int i = 1; i <= n; ++i)
                            {
                                int x;
                                std::cout << "Introduceti informatia nodului " << i << ": (fisier).";
                                fin >> x;
                                std::cout << '\n';
                                q.AddToTail(q,x);
                            }
                            std::cout << "\nApasati tasta ENTER pentru a continua...";
                            std::cin.ignore();
                            std::cin.get();
                            fin.get();
                        }
                        else if(!strcmp(method.c_str(), "invers"))
                        {
                            for(int i = 1; i <= n; ++i)
                            {
                                int x;
                                std::cout << "Introduceti informatia nodului " << i << ": (fisier).";
                                fin >> x;
                                std::cout << '\n';
                                q.AddToHead(q,x);
                            }
                            std::cout << "\nApasati tasta ENTER pentru a continua...";
                            std::cin.ignore();
                            std::cin.get();
                            fin.get();
                        }
                    }
                    system("clear");
                }
                else
                {
                    std::cout << "Lista nu este vida. Alegeti optiunea 8 pentru a sterge continutul ascesteia.\n";
                    std::cin.ignore();
                    std::cin.get();
                    std::cout << '\n';
                    system("clear");
                }
                std::cout << "Cum doriti sa fie concatenarea?" << '\n';
                std::cout << "Prima lista concatenata cu a doua lista sau invers?(prim/doi) ";
                std::cin >> method;
                std::cout << '\n';
                if(!strcmp(method.c_str(), "prim"))
                {   p += q;
                    std::cout << "Cele 2 liste au fost concatenate.";
                    std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                    std::cin.ignore();
                    std::cin.get();
                    std::cout << '\n';
                }
                else
                    if(!strcmp(method.c_str(), "doi"))
                    { q += p;
                        std::cout << "Cele 2 liste au fost concatenate.";
                        std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                        std::cin.ignore();
                        std::cin.get();
                        std::cout << '\n';
                    }
                system("clear");
                break;
            case 4:
                system("clear");
                std::cout << "De unde va fi citita informatia nodului? (tastatura/fisier) ";
                std::cin >> type;
                if(!strcmp(type.c_str(), "tastatura"))
                {
                    std::cout << "Lista in care doriti sa introduceti la inceputul acesteia, nodul cu valoarea: ";
                    int x;
                    std::cin >> x;
                    std::cin.get();
                    std::cout << '\n';
                    std::cout << "Prima/doua/ambele: ";
                    std::cin >> method;
                    std::cin.get();
                    std::cout << '\n';
                    if(!strcmp(method.c_str(), "prima"))
                    {
                        p.AddToHead(p,x);
                        std::cout << "Nodul cu informatia " << x << " a fost introdus in " << method << " lista.";
                        std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                        std::cin.ignore();
                        std::cin.get();
                        std::cout << '\n';
                        system("clear");
                    }
                    else
                        if(!strcmp(method.c_str(), "doua"))
                        {
                            q.AddToHead(q,x);
                            std::cout << "Nodul cu informatia " << x << " a fost introdus in a " << method << " lista.";
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                            std::cout << '\n';
                            system("clear");
                        }
                        else
                            if(!strcmp(method.c_str(), "ambele"))
                            {
                                p.AddToHead(p,x);
                                q.AddToHead(q,x);
                                std::cout << "Nodul cu informatia " << x << " a fost introdus in " << method << " liste.";
                                std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                                std::cin.ignore();
                                std::cin.get();
                                std::cout << '\n';
                                system("clear");
                            }
                }
                else
                    if(!strcmp(type.c_str(), "fisier"))
                    {
                        std::cout << "Lista in care doriti sa introduceti la inceputul acesteia, nodul cu valoarea: (fisier)";
                        int x;
                        fin >> x;
                        fin.get();
                        std::cin.get();
                        std::cout << '\n';
                        std::cout << "prima/doua/ambele: ";
                        std::cin >> method;
                        std::cin.get();
                        std::cout << '\n';
                        if(!strcmp(method.c_str(), "prima"))
                        {
                            p.AddToHead(p,x);
                            std::cout << "Nodul cu informatia " << x << " a fost introdus in " << method << " lista.";
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                            std::cout << '\n';
                            system("clear");
                        }
                        else
                            if(!strcmp(method.c_str(), "doua"))
                            {
                                q.AddToHead(q,x);
                                std::cout << "Nodul cu informatia " << x << " a fost introdus in a " << method << " lista.";
                                std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                                std::cin.ignore();
                                std::cin.get();
                                std::cout << '\n';
                                system("clear");
                            }
                            else
                                if(!strcmp(method.c_str(), "ambele"))
                                {
                                    p.AddToHead(p,x);
                                    q.AddToHead(q,x);
                                    std::cout << "Nodul cu informatia " << x << " a fost introdus in " << method << " liste.";
                                    std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                                    std::cin.ignore();
                                    std::cin.get();
                                    std::cout << '\n';
                                    system("clear");
                                }
                    }
                break;
            case 5:
                system("clear");
                std::cout << "De unde va fi citita informatia nodului? (tastatura/fisier) ";
                std::cin >> type;
                if(!strcmp(type.c_str(), "tastatura"))
                {
                    std::cout << "Lista in care doriti sa introduceti la sfarsitul acesteia, nodul cu valoarea: ";
                    int x;
                    std::cin >> x;
                    std::cin.get();
                    std::cout << '\n';
                    std::cout << "Prima/doua/ambele: ";
                    std::cin >> method;
                    std::cin.get();
                    std::cout << '\n';
                    if(!strcmp(method.c_str(), "prima"))
                    {
                        p.AddToTail(p,x);
                        std::cout << "Nodul cu informatia " << x << " a fost introdus in " << method << " lista.";
                        std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                        std::cin.ignore();
                        std::cin.get();
                        std::cout << '\n';
                        system("clear");
                    }
                    else
                        if(!strcmp(method.c_str(), "doua"))
                        {
                            q.AddToTail(q,x);
                            std::cout << "Nodul cu informatia " << x << " a fost introdus in a " << method << " lista.";
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                            std::cout << '\n';
                            system("clear");
                        }
                        else
                            if(!strcmp(method.c_str(), "ambele"))
                            {
                                p.AddToTail(p,x);
                                q.AddToTail(q,x);
                                std::cout << "Nodul cu informatia " << x << " a fost introdus in " << method << " liste.";
                                std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                                std::cin.ignore();
                                std::cin.get();
                                std::cout << '\n';
                                system("clear");
                            }
                }
                else
                    if(!strcmp(type.c_str(), "fisier"))
                    {
                        std::cout << "Lista in care doriti sa introduceti la inceputul acesteia, nodul cu valoarea: ";
                        int x;
                        fin >> x;
                        fin.get();
                        std::cin.get();
                        std::cout << '\n';
                        std::cout << "Prima/doua/ambele: ";
                        std::cin >> method;
                        std::cin.get();
                        std::cout << '\n';
                        if(!strcmp(method.c_str(), "prima"))
                        {
                            p.AddToTail(p,x);
                            std::cout << "Nodul cu informatia " << x << " a fost introdus in " << method << " lista.";
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                            std::cout << '\n';
                            system("clear");
                        }
                        else
                            if(!strcmp(method.c_str(), "doua"))
                            {
                                q.AddToTail(q,x);
                                std::cout << "Nodul cu informatia " << x << " a fost introdus in a " << method << " lista.";
                                std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                                std::cin.ignore();
                                std::cin.get();
                                std::cout << '\n';
                                system("clear");
                            }
                            else
                                if(!strcmp(method.c_str(), "ambele"))
                                {
                                    p.AddToTail(p,x);
                                    q.AddToTail(q,x);
                                    std::cout << "Nodul cu informatia " << x << " a fost introdus in " << method << " liste.";
                                    std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                                    std::cin.ignore();
                                    std::cin.get();
                                    std::cout << '\n';
                                    system("clear");
                                }
                    }
                break;
            case 6:
                system("clear");
                std::cout << "De unde va fi citita informatia nodului? (tastatura/fisier) ";
                std::cin >> type;
                if(!strcmp(type.c_str(), "tastatura"))
                {
                    std::cout << "Ce informatie are nodul cautat?: ";
                    int x;
                    std::cin >> x;
                    std::cin.get();
                    std::cout << '\n';
                    std::cout << "In ce lista?" << '\n';
                    std::cout << "Prima/doua/ambele: ";
                    std::cin >> method;
                    if(!strcmp(method.c_str(), "prima"))
                    {
                        if(p.search(p,x) == -1)
                            std::cout << "Nu exista nodul cu informatia " << x << " in " << method << " lista.\n";
                        else
                            std::cout << "Pozitia nodului cu informatia " << x << " din " << method <<" lista este " << p.search(p,x) << '.' << '\n';
                        std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                        std::cin.ignore();
                        std::cin.get();
                        std::cout << '\n';
                        system("clear");
                    }
                    else
                        if(!strcmp(method.c_str(), "doua"))
                        {
                            if(q.search(q,x) == -1)
                                std::cout << "Nu exista nodul cu informatia " << x << " in " << method << " lista.\n";
                            else
                                std::cout << "Pozitia nodului cu informatia " << x << " din a " << method <<" lista este " << q.search(q,x) << '.' << '\n';
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                            std::cout << '\n';
                            system("clear");
                        }
                        else
                            if(!strcmp(method.c_str(), "ambele"))
                            {
                                if(p.search(p,x) == -1)
                                    std::cout << "Nu exista nodul cu informatia " << x << " in " << method << " lista.\n";
                                else
                                    std::cout << "Pozitia nodului cu informatia " << x << " din " << method <<" lista este " << p.search(p,x) << '.' << '\n';
                                if(q.search(q,x) == -1)
                                    std::cout << "Nu exista nodul cu informatia " << x << " in a " << method << " lista.\n";
                                else
                                    std::cout << "Pozitia nodului cu informatia " << x << " din a " << method <<" lista este " << q.search(q,x) << '.' << '\n';
                                std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                                std::cin.ignore();
                                std::cin.get();
                                std::cout << '\n';
                                system("clear");
                            }
                }
                else
                    if(!strcmp(type.c_str(), "fisier"))
                    {
                        std::cout << "Ce informatie are nodul cautat?: (fisier)";
                        int x;
                        fin >> x;
                        fin.get();
                        std::cin.get();
                        std::cout << '\n';
                        std::cout << "In ce lista?" << '\n';
                        std::cout << "Prima/doua/ambele: ";
                        std::cin >> method;
                        if(!strcmp(method.c_str(), "prima"))
                        {
                            if(p.search(p,x) == -1)
                                std::cout << "Nu exista nodul cu informatia " << x << " in " << method << " lista.\n";
                            else
                                std::cout << "Pozitia nodului cu informatia " << x << " din " << method <<" lista este " << p.search(p,x) << '.' << '\n';
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                            std::cout << '\n';
                            system("clear");
                        }
                        else
                            if(!strcmp(method.c_str(), "doua"))
                            {
                                if(q.search(q,x) == -1)
                                    std::cout << "Nu exista nodul cu informatia " << x << " in " << method << " lista.\n";
                                else
                                    std::cout << "Pozitia nodului cu informatia " << x << " din a " << method <<" lista este " << q.search(q,x) << '.' << '\n';
                                std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                                std::cin.ignore();
                                std::cin.get();
                                std::cout << '\n';
                                system("clear");
                            }
                            else
                                if(!strcmp(method.c_str(), "ambele"))
                                {
                                    if(p.search(p,x) == -1)
                                        std::cout << "Nu exista nodul cu informatia " << x << " in " << method << " lista.\n";
                                    else
                                        std::cout << "Pozitia nodului cu informatia " << x << " din " << method <<" lista este " << p.search(p,x) << '.' << '\n';
                                    if(q.search(q,x) == -1)
                                        std::cout << "Nu exista nodul cu informatia " << x << " in a " << method << " lista.\n";
                                    else
                                        std::cout << "Pozitia nodului cu informatia " << x << " din a " << method <<" lista este " << q.search(q,x) << '.' << '\n';
                                    std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                                    std::cin.ignore();
                                    std::cin.get();
                                    std::cout << '\n';
                                    system("clear");
                                }
                    }
                break;
            case 7:
                system("clear");
                std::cout << "De unde va fi citita informatia nodului? (tastatura/fisier) ";
                std::cin >> type;
                if(!strcmp(type.c_str(), "tastatura"))
                {
                    std::cout << "Ce informatie sa aiba nodul/nodurile care va/vor fi sters/sterse?: ";
                    int x;
                    std::cin >> x;
                    std::cin.get();
                    std::cout << '\n';
                    std::cout << "In ce lista?" << '\n';
                    std::cout << "Prima/doua/ambele: ";
                    std::cin >> method;
                    if(!strcmp(method.c_str(), "prima"))
                    {
                        
                        p.DeleteNodes(p,x);
                        std::cout << "Nodurile cu informatia " << x << " au fost sterse din " << method << " lista.\n";
                        std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                        std::cin.ignore();
                        std::cin.get();
                        std::cout << '\n';
                        system("clear");
                    }
                    else
                        if(!strcmp(method.c_str(), "doua"))
                        {
                            q.DeleteNodes(q,x);
                            std::cout << "Nodurile cu informatia " << x << " au fost sterse din a " << method << " lista.\n";
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                            std::cout << '\n';
                            system("clear");
                        }
                        else
                            if(!strcmp(method.c_str(), "ambele"))
                            {
                                p.DeleteNodes(p,x);
                                q.DeleteNodes(q,x);
                                std::cout << "Nodurile cu informatia " << x << " au fost sterse din " << method << " liste.\n";
                                std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                                std::cin.ignore();
                                std::cin.get();
                                std::cout << '\n';
                                system("clear");
                            }
                }
                else
                    if(!strcmp(type.c_str(), "fisier"))
                    {
                        std::cout << "Ce informatie sa aiba nodul/nodurile care va/vor fi sters/sterse?: (fisier)";
                        int x;
                        fin >> x;
                        fin.get();
                        std::cin.get();
                        std::cout << '\n';
                        std::cout << "In ce lista?" << '\n';
                        std::cout << "Prima/doua/ambele: ";
                        std::cin >> method;
                        if(!strcmp(method.c_str(), "prima"))
                        {
                            p.DeleteNodes(p,x);
                            std::cout << "Nodurile cu informatia " << x << " au fost sterse din " << method << " lista.\n";
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                            std::cout << '\n';
                            system("clear");
                        }
                        else
                            if(!strcmp(method.c_str(), "doua"))
                            {
                                q.DeleteNodes(q,x);
                                std::cout << "Nodurile cu informatia " << x << " au fost sterse din a " << method << " lista.\n";
                                std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                                std::cin.ignore();
                                std::cin.get();
                                std::cout << '\n';
                                system("clear");
                            }
                            else
                                if(!strcmp(method.c_str(), "ambele"))
                                {
                                    p.DeleteNodes(p,x);
                                    q.DeleteNodes(q,x);
                                    std::cout << "Nodurile cu informatia " << x << " au fost sterse din " << method << " liste.\n";
                                    std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                                    std::cin.ignore();
                                    std::cin.get();
                                    std::cout << '\n';
                                    system("clear");
                                }
                    }
                break;
            case 8:
                system("clear");
                std::cout << "Ce lista doriti sa o stergeti? (prima/doua/ambele) ";
                std::cin >> method;
                if(!strcmp(method.c_str(), "prima"))
                {
                    p.reset(p);
                    std::cout << method << " Lista a fost stearsa.\n";
                    std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                    std::cin.ignore();
                    std::cin.get();
                    std::cout << '\n';
                }
                else
                    if(!strcmp(method.c_str(), "doua"))
                    {
                        q.reset(q);
                        std::cout << "A " << method << " Lista a fost stearsa.\n";
                        std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                        std::cin.ignore();
                        std::cin.get();
                        std::cout << '\n';
                    }
                    else
                        if(!strcmp(method.c_str(), "ambele"))
                        {
                            p.reset(p);
                            q.reset(q);
                            std::cout << method << "Ambele liste au fost sterse.\n";
                            std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                            std::cin.ignore();
                            std::cin.get();
                            std::cout << '\n';
                        }
                system("clear");
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
                std::cout << "\nApasati tasta ENTER pentru a va reintoarce la meniu...";
                std::cin.ignore();
                system("clear");
        }
    }while(true);
    system("killall afplay");
    return 0;
}
