#include "Circle.h"


void nuskaitymas()
{
    ifstream df(duom);
    ofstream rf(rez);
    ofstream rf1(rez1);

    rf << std::left << std::setw(15) << "Vardas " << std::setw(15) << "Pavarde " << std::setw(15) << "Galutinis (Vid.) " << std::setw(15) << "Galutinis (Med.) " << endl;
    rf << "---------------------------------------------------------------- " << endl;
    rf1 << std::left << std::setw(15) << "Vardas " << std::setw(15) << "Pavarde " << std::setw(15) << "Galutinis (Vid.) " << std::setw(15) << "Galutinis (Med.) " << endl;
    rf1 << "---------------------------------------------------------------- " << endl;
    df.ignore(LONG_MAX, '\n');
    int p_elem = 0;
    int paz;
    double vidurkis = 0;
    vector<data> sarasas;
    int ind = 0;



    auto start = std::chrono::high_resolution_clock::now();
    auto st=start;

    string pagalba;
    double egzas;
    double rez;

    while (!df.eof())
    {
        data temp;
        df >> pagalba;
        temp.setVardas(pagalba);
        df >> pagalba;
        temp.setPavarde(pagalba);
        for (int i = 0; i < 5; i++)
        {
            df >> paz;
            temp.getNd().push_back(paz);
            vidurkis += paz;
        }
        df >> egzas;
        temp.setEgzaminas(egzas);


        if (temp.getNd().size() != 0) vidurkis = vidurkis / temp.getNd().size();

        else vidurkis = 0;

        temp.setRez(vidurkis * 0.4 + temp.getEgzaminas() * 0.6);


        sort(temp.getNd().begin(), temp.getNd().begin() + temp.getNd().size());
        if (temp.getNd().size() % 2 == 1)
        {
            temp.setMediana(temp.getNd()[temp.getNd().size() / 2] * 0.4 + temp.getEgzaminas() * 0.6);
        }
        else
        {
            temp.setMediana(((temp.getNd()[temp.getNd().size() / 2] + temp.getNd()[(temp.getNd().size() / 2) - 1]) / 2.0) * 0.4 + temp.getEgzaminas() * 0.6);
        }




        sarasas.push_back(temp);
        vidurkis = 0;
//        cout << ind << endl;
//        ind++;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    std::cout << "100000 eiluciu failo nuskaitymas uztruko: "<< diff.count() << " s\n";

    std::sort(sarasas.begin(), sarasas.end(), [](data a, data b)
    {
        if (a.getRez() == b.getRez()) return a.getPavarde() < b.getPavarde();
        return a.getRez() < b.getRez();
    });


    start = std::chrono::high_resolution_clock::now();


    vector<data> vargsiukai;
    vector<data> kietiakai;

    for (const auto& el : sarasas) {
        if(el.getRez() >= 5)
        {
            vargsiukai.push_back(el);
            rf1 << std::left << std::setw(15) << el.getVardas() << " " << std::setw(15) << el.getPavarde();
            rf1 << std::setw(15) << std::fixed << std::setprecision(2) << el.getRez() << std::setw(15) << std::fixed << std::setprecision(2) << el.getMediana() << " " << endl;
        }
        else
        {
            kietiakai.push_back(el);
            rf << std::left << std::setw(15) << el.getVardas() << " " << std::setw(15) << el.getPavarde();
            rf << std::setw(15) << std::fixed << std::setprecision(2) << el.getRez() << std::setw(15) << std::fixed << std::setprecision(2) << el.getMediana() << " " << endl;
        }
    }

//    vector<data> vargsiukai;
//
//    for (const auto& el : sarasas)
//    {
//        int iteratorius = 0;
//        if(el.rez >= 5)
//        {
//            rf1 << std::left << std::setw(15) << el.vardas << " " << std::setw(15) << el.pavarde;
//            rf1 << std::setw(15) << std::fixed << std::setprecision(2) << el.rez << std::setw(15) << std::fixed << std::setprecision(2) << el.mediana << " " << endl;
//        }
//        else
//        {
//            vargsiukai.push_back(el);
//            sarasas.erase(sarasas.begin()+iteratorius);
//            rf << std::left << std::setw(15) << el.vardas << " " << std::setw(15) << el.pavarde;
//            rf << std::setw(15) << std::fixed << std::setprecision(2) << el.rez << std::setw(15) << std::fixed << std::setprecision(2) << el.mediana << " " << endl;
//        }
//        iteratorius++;
//    }


    end = std::chrono::high_resolution_clock::now();
    diff = end-start; // Skirtumas (s)
    std::cout << "100000 eiluciu failo rusiavimas ir isvedimas i 2 naujus failus uztruko: "<< diff.count() << " s\n";


    diff = std::chrono::high_resolution_clock::now()-st; // Skirtumas (s)
    std::cout << "Visas sugaistas laikas: "<< diff.count() << " s\n\n";


    df.close();
    rf.close();
    sarasas.clear();

}


bool isNumber(const string& s)
{

    for (char const& ch : s)
    {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

void fileGenerator(int studentuKiekis, string failoPav)
{
    string vardas, pavarde;
    srand(time(0));
    ofstream fout(failoPav + ".txt");
    fout << "Vardas" << setw(31) << "Pavarde";
    for(int i = 1; i <= 5; i++)
    {
        fout << setw(24) << "ND" << i << setw(26);
    }
    fout << "Egz." << setw(25) << '\n';
    for(int i = 1; i <= studentuKiekis; i++)
    {
        vardas = "Vardas"+to_string(i);
        pavarde = "Pavarde"+to_string(i);
        fout << left << setw(30) << vardas << setw(29) << pavarde;
        for(int j = 0; j < 6; j++)
        {
            fout << setw(25) << (rand() % 10) + 1;
        }
        fout << '\n';
    }
    fout.close();
}

void ivestis(data& temp)
{
    string pagalba;

    int n = 0;
    int k = 1;
    double vidurkis = 0;
    string s1;
    temp.getNd().clear();
    cout << "Iveskite varda: ";
    cin >> pagalba;
    temp.setVardas(pagalba);
    cout << "Iveskite pavarde: ";
    cin >> pagalba;
    temp.setPavarde(pagalba);
    cout << "Rasykite 0, jei pazymiai baigiasi (max nd pazymiu yra " << C << " )" << endl;

//    temp.nd.reserve(1);
    while (k && (n < C))      //
    {

        cout << "Iveskite " << n + 1 << " - a pazymi: ";
        cin >> s1;
        if (isNumber(s1) && !(std::stoi(s1) > 10 || std::stoi(s1) < 0))
        {
            if (std::stoi(s1) == 0)
            {
                k = 0;
            }
            else
            {
                temp.getNd().push_back(std::stoi(s1));
                vidurkis += temp.getNd().back();
            }
        }
        else
        {
            temp.getNd().push_back(10);
            vidurkis += temp.getNd().back();
            cout << "galimai ivedete ne numeri arba netinkama pazymi todel " << n + 1 << " mokiniui(-ei) jis buvo pakeistas i 10" << endl;
        }


        if (k != 0)
        {
            n++;
            temp.getNd().reserve(n + 1);
        }
    }


    if (temp.getNd().size() != 0)
    {
        vidurkis = vidurkis / n;
    }
    else vidurkis = 0;



    cout << "Iveskite egzamino ivertinima: ";
    cin >> s1;
    if (isNumber(s1) && !(std::stoi(s1) > 10 || std::stoi(s1) < 0))
    {
        temp.setEgzaminas(std::stoi(s1));
    }
    else
    {
        temp.setEgzaminas(10);
        cout << "galimai ivedete ne numeri arba netinkama egzamino pazymi todel " << n + 1 << " mokiniui(-ei) jis buvo pakeistas i 10" << endl;
    }
    temp.setRez(vidurkis * 0.4 + temp.getEgzaminas() * 0.6);

    if (temp.getNd().size() == 0)
    {
        temp.setMediana(temp.getEgzaminas() * 0.6);
    }
    else
    {
        sort(temp.getNd().begin(), temp.getNd().begin() + n);
        if (temp.getNd().size() % 2 == 1)
        {
            temp.setMediana(temp.getNd()[temp.getNd().size() / 2] * 0.4 + temp.getEgzaminas() * 0.6);
        }
        else
        {
            temp.setMediana(((temp.getNd()[temp.getNd().size() / 2] + temp.getNd()[(temp.getNd().size() / 2) - 1]) / 2.0) * 0.4 + temp.getEgzaminas() * 0.6);
        }
    }

    //return temp;
}

void ivestis1(data& temp, int kiek)
{
    string pagalba;

    double vidurkis = 0;
    srand((unsigned)time(0));
    if (kiek > 0)
    {
        temp.getNd().reserve(kiek);
    }

    cout << "Iveskite varda: ";
    cin >> pagalba;
    temp.setVardas(pagalba);
    cout << "Iveskite pavarde: ";
    cin >> pagalba;
    temp.setPavarde(pagalba);
    cout << "pazymiai: " << endl;
    for (int i = 0; i < kiek; i++)
    {
        temp.getNd()[i] = (rand() % 10) + 1;
        cout << temp.getNd()[i] << " ";
        vidurkis += temp.getNd()[i];
        // n++;

    }

    if (kiek != 0)
    {
        vidurkis = vidurkis / kiek;
    }
    else vidurkis = 0;

    temp.setEgzaminas((rand() % 10) + 1);
    cout << endl;
    cout << "Egzaminas: " << temp.getEgzaminas() << endl;

    temp.setRez(vidurkis * 0.4 + temp.getEgzaminas() * 0.6);

    if (kiek > 0)
    {
        sort(temp.getNd().begin(), temp.getNd().begin() + kiek);
        if (kiek % 2 == 1)
        {
            temp.setMediana(temp.getNd()[kiek / 2] * 0.4 + temp.getEgzaminas() * 0.6);
        }
        else
        {
            temp.setMediana(((temp.getNd()[kiek / 2] + temp.getNd()[(kiek / 2) - 1]) / 2.0) * 0.4 + temp.getEgzaminas() * 0.6);
        }
    }
    else temp.setMediana(temp.getEgzaminas() * 0.6);
}

void ivestisfailas(data& temp)
{
    cout << "labas" << endl;
}

void isved(const data& temp)
{
    cout << std::left << std::setw(10) << temp.getVardas() << " " << std::setw(10) << temp.getPavarde();
    cout << std::setw(10) << std::fixed << std::setprecision(2) << temp.getRez() << " " << endl;
}

void isvedmediana(const data& temp)
{
    cout << std::left << std::setw(10) << temp.getVardas() << " " << std::setw(10) << temp.getPavarde();
    cout << std::setw(10) << std::fixed << std::setprecision(2) << temp.getMediana() << " " << endl;
}

void isvedfailas(const data& temp)
{
    cout << std::left << std::setw(10) << temp.getVardas() << " " << std::setw(10) << temp.getPavarde();
    cout << std::setw(10) << std::fixed << std::setprecision(2) << temp.getRez() << std::setw(10) << std::fixed << std::setprecision(2) << temp.getMediana() << " " << endl;
}

void trycatch(string& a)
{
    cin >> a;
    do
    {
        try
        {
            if (cin.fail())
            {
                throw std::runtime_error("Irasete netinkamai\n");
            }
        }
        catch (const std::runtime_error& e)
        {
            std::wcout << e.what();
            std::wcin.clear();
            std::wcin.ignore(256, '\n');
            cout << "Iveskite is naujo: " << endl;
            cin >> a;
        }
    }
    while (std::cin.fail() == true);
}

void eil_po_eil(std::string read_vardas, std::string write_vardas, vector<data>& sarasas)
{
    string pagalba;

    data laikinas;
    std::vector<std::string> splited;
    std::string eil;
    std::string abcas;
    std::stringstream my_buffer;
    string paz;
    double vidurkis = 0;
    int n = 1;
    int nd;
    std::ifstream open_f(read_vardas);
    std::ofstream out_f(write_vardas);

    out_f << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavarde " << std::setw(10) << "Galutinis (Vid.) " << std::setw(10) << "Galutinis (Med.) " << endl;
    out_f << "---------------------------------------------------------------- " << endl;
    while (open_f)
    {
        if (!open_f.eof())
        {
            std::getline(open_f, eil);
            splited.push_back(eil);
            my_buffer.str(eil);
            my_buffer >> pagalba;
            laikinas.setVardas(pagalba);
            my_buffer >> pagalba;
            laikinas.setPavarde(pagalba);
            cout << laikinas.getVardas() << " " << laikinas.getPavarde() << " ";
            for (int i = 0; i < 15; i++)
            {
                my_buffer >> paz;
                cout << paz << " ";
            }


            cout << endl;



        }
        else break;
    }

    open_f.close();
    out_f.close();

    splited.resize(0);
}
























/*

while (open_f) {
    n = 1;
    //  laikinas.nd.clear();
    //  laikinas.nd.reserve(n);

    if (!open_f.eof()) {
        std::getline(open_f, eil);
        my_buffer.str(eil);
        // cout << eil;
         // nuskaitymas


        my_buffer >> laikinas.vardas >> laikinas.pavarde;
        cout << laikinas.vardas << " " << laikinas.pavarde << " ";
        for (int i = 0; i < 15; i++) { my_buffer >> paz; cout << paz; }


        /*
        while ((my_buffer >> paz)&&(isNumber(paz))) {
       // if ((isNumber(paz)) {
            n++;
                vidurkis += std::stoi(paz);
            //    cout << paz << " ";
                laikinas.nd.reserve(n);
                laikinas.nd.push_back(std::stoi(paz));
      //  }
        }


        // my_buffer.str("");
        // cout << endl;
        // laikinas.egz = paz;
         //cout << laikinas.egz << endl;
        // laikinas.nd.pop_back();

         vidurkis = vidurkis / laikinas.nd.size();
         laikinas.rez = vidurkis * 0.4 + laikinas.egz * 0.6;


         //mediana
         sort(laikinas.nd.begin(), laikinas.nd.begin() + laikinas.nd.size());
         if (laikinas.nd.size() % 2 == 1) {
             laikinas.mediana = laikinas.nd[laikinas.nd.size() / 2] * 0.4 + laikinas.egz * 0.6;
         }
         else {
             laikinas.mediana = ((laikinas.nd[laikinas.nd.size() / 2] + laikinas.nd[(laikinas.nd.size() / 2) - 1]) / 2.0) * 0.4 + laikinas.egz * 0.6;
         }

        // cout << abcas << endl;
        // splited.push_back(eil);



        // sarasas.push_back(laikinas);


        // isvedfailas(laikinas);

         //sarasas.clear();
    }
    else break;
}

*/
