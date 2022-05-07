#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <stdio.h>
#include <stdlib.h>

#include <sstream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::to_string;
using std::left;


const int C = 50;
const string duom = "1000000rez.txt";
const string rez = "vargsai1000000.txt";
const string rez1 = "kieti1000000.txt";

struct data {
    string vardas, pavarde;
    int egz = 0;
    vector<int> nd;
    double rez = 0, mediana = 0;

};



//class data {
//
//public:
//  string vardas;
//  string pavarde;
//  double egz;
//  vector<double> nd;
//  double rez = 0;
//  double mediana = 0;
//  data() : egz(0) { };
////  Data(istream& is);
//};






void ivestis(data& temp);
void isved(const data& temp);
void isvedmediana(const data& temp);
void ivestis1(data& temp, int kiek);
bool isNumber(const string& s);
void nuskaitymas();
void ivestisfailas(const data& temp);
void isvedfailas(const data& temp);
void fileGenerator(int studentuKiekis, string failoPav);


void eil_po_eil(std::string read_vardas, std::string write_vardas, vector<data>& sarasas);
bool compare_pavarde(const string& a, const string& b);
void trycatch(string& a);
