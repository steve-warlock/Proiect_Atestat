//
//  functii.hpp
//  
//
//  Created by Steve Warlock on 21.10.2022.
//

#pragma once

#include "DLL.hpp"


namespace solution{

bool verify(std::string& ,const std::string& );

void tip_citire_tastatura(DLL& , int , std::istream& );

void tip_citire_fisier(DLL& , int , std::ifstream& );

void citire_tastatura(DLL& ,std::istream& );

void citire_fisier(DLL& ,std::fstream& );

void fail_case();

void case_1(DLL& );

void op_1();

void case_2(DLL& , DLL& , std::string& );

void op_2();

void case_3(DLL& );

void op_3();

void case_4(DLL& ,DLL& ,int ,std::string& );

void op_4();

void case_5(DLL& ,DLL& ,int );

void op_5();

void case_6(DLL& ,DLL& ,int );

void op_6();

void case_7(DLL& ,DLL& ,int );

void op_7();

void case_8(DLL& ,DLL& );

void op_8();
}
