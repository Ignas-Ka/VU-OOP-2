#include "Circle.h"



int main()
{
//    std::ios::sync_with_stdio(false);
//
//
//    auto start = std::chrono::high_resolution_clock::now();
//    auto st=start;
//
//
//    fileGenerator(1000000, "1000000rez");
//
//
//    auto end = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
//    std::cout << "1000000 eiluciu failo generavimas uztruko: "<< diff.count() << " s\n";
//    return 0;


    setlocale(LC_ALL, "Lithuanian");
    int mok = 0;
    vector<data> sarasas;
    data laik;
    string abc;
    string dar;

    cout << "---------------------------------------------------------------- " << endl;

    cout << "Jei norite, kad duomenis skaitytu is failo � 1, jei paciam ivesti � 0" << endl;
    trycatch(abc);

    if (abc == "1") {
        nuskaitymas();
    }

    else {

        do {
            mok++;
            sarasas.reserve(mok);
            cout << "Ar norite kad " << mok << " -am(ai) mokiniui(-ei) pazymiai butu generuojami atsitiktinai? (bet koks simbolis) - taip, 0 - ne" << endl;
            cin >> abc;
            if (abc == "0") {
                ivestis(laik);
                sarasas.push_back(laik);
            }
            else {
                cout << "Kiek nd pazymiu turi mokinys? (max - " << C << " )" << endl;
                cin >> abc;
                while (!(isNumber(abc)) || (std::stoi(abc) > 10 || std::stoi(abc) < 0)) {
                    cout << "Ivedete blogai, veskite dar karta " << endl;
                    cin >> abc;
                }
                ivestis1(laik, std::stoi(abc));
                sarasas.push_back(laik);
            }
            cout << "Ar norite prideti dar viena mokini? (bet koks simbolis) - taip, 0 - ne" << endl;
            cin >> dar;
        } while (dar != "0");


        cout << "---------------------------------------------------------------- " << endl;
        cout << "Jei norite Vidurkio: rasykite � 1, jei norite Medianos rasykite � 0 " << endl;

        cin >> abc;

        while ((abc != "1") && (abc != "0")) {
            cout << "Ivedete blogai, veskite dar karta " << endl;
            cin >> abc;
        }


        if (abc == "1") {
            cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavarde " << std::setw(10) << "Galutinis (Vid.) " << endl;
            cout << "---------------------------------------------------------------- " << endl;
            for (const auto& el : sarasas) {
                isved(el);
            }
        }

        else if (abc == "0") {
            cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavarde " << std::setw(10) << "Galutinis (Med.) " << endl;
            cout << "---------------------------------------------------------------- " << endl;
            for (const auto& el : sarasas) {
                isvedmediana(el);
            }
        }
    }
    sarasas.clear();
    system("pause");
    return 0;
}
