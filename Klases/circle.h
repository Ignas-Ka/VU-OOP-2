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
const string duom = "100000rez.txt";
const string rez = "vargsai100000.txt";
const string rez1 = "kieti100000.txt";

//struct data {
//    string vardas, pavarde;
//    int egz = 0;
//    vector<int> nd;
//    double rez = 0, mediana = 0;
//
//};



class data {
    private:
	    string vardas, pavarde;
	    int egz;
	    vector<int> nd;
	    double rez, mediana;
    public:
        data() : vardas(""), pavarde(""), egz(0), nd(0), rez(0.0), mediana (0.0)  { }  // default konstruktorius

        string getVardas() const { return vardas; }
        string getPavarde() const { return pavarde; }
        int getEgzaminas() const { return egz; }
        const vector<int>& getNd() const { return nd; }
        vector<int>& getNd() { return nd; }
        double getRez() const { return rez; }
        double getMediana() const { return mediana; }

        void setVardas(string vardas) { this->vardas = vardas; }
        void setPavarde(string pavarde) { this->pavarde = pavarde; }
        void setEgzaminas(int egz) { this->egz = egz; }
        void setNd(vector<int> nd) { this->nd = nd; }
        void setRez(double rez) { this->rez = rez; }
        void setMediana(double mediana) { this->mediana = mediana; }

        data(const data& that)
        {
            this->vardas = that.vardas;
            this->pavarde = that.pavarde;
            this->egz = that.egz;
            this->nd = that.nd;
            this->rez = that.rez;
            this->mediana = that.mediana;
        }

        data& operator=(const data& that)
        {
            if (this != &that)
            {
                this->vardas = that.vardas;
                this->pavarde = that.pavarde;
                this->egz = that.egz;
                this->nd = that.nd;
                this->rez = that.rez;
                this->mediana = that.mediana;
            }
            return *this;
        }

        ~data()
        {
            nd.clear();
        }

        // rezultatø sudëtis
        data operator + (const data& b) {
            data rezult;
            rezult.rez = rez + b.rez;
            rezult.mediana = mediana + b.mediana;
            return rezult;
        }

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
