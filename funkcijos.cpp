#include "funkcijos.hpp"

Studentas::Studentas(string v, string p, vector<int> pa, int e) : Zmogus(v, p) {
    Pazymiai(pa);
    Egzaminas(e);
}

string pazGeneravimas() {
    vector<string> paz;
    for (int i = 0; i < 5; i++) {
        paz.push_back(std::to_string(rand() % 10 + 1) + " ");
    }
    string p = std::accumulate(paz.begin(), paz.end(), std::string(""));
    paz.clear();
    return p;
};

bool palyginimas(const Studentas& a, const Studentas& b) {
    return a.getGalutinis() < b.getGalutinis();
}

void gen(int x) {
    string name = "stud" + std::to_string(x) + ".txt";
    ofstream failas(name);
    failas << "\tVardas" << "\tPavarde" << "\t Pazymiai";
    for (int i = 1; i < x + 1; i++) {
        string info = "\n\tVardas" + std::to_string(i) + "\tPavarde" + std::to_string(i) + " " + pazGeneravimas();
        failas << info;
    }
    failas.close();
};

vector<Studentas> nuskaitymas_vect(string fname) {
    std::ifstream failas(fname);
    vector<Studentas> studentai;
    if (failas.is_open()) {
        string eil;
        vector<int> paz;
        int p;
        int n = 4;
        std::stringstream s(eil);
        while (getline(failas, eil)) {
            Studentas stud;
            failas >> stud;
            stud.Galutinis();
            stud.Galutinis_m();
            studentai.push_back(stud);
            paz.clear();
        }
        failas.close();
    }
    else {
        cout << "Klaida atidarant faila";
        exit(0);
    }
    return studentai;
}

list<Studentas> nuskaitymas_list(string fname) {
    std::ifstream failas(fname);
    list<Studentas> studentai;
    if (failas.is_open()) {
        string eil;
        vector<int> paz;
        int p;
        int n = 4;
        std::stringstream s(eil);
        while (getline(failas, eil)) {
            Studentas stud;
            failas >> stud;
            stud.Galutinis();
            stud.Galutinis_m();
            studentai.push_back(stud);
            paz.clear();
        }
        failas.close();
    }
    else {
        cout << "Klaida atidarant faila";
        exit(0);
    }
    return studentai;
}

double nusk_list1(int x) {
    Timer t;
    string fname = "stud" + std::to_string(x) + ".txt";
    list<Studentas> studentai = nuskaitymas_list(fname);
    studentai.sort(palyginimas);
    list<Studentas> n;
    auto z = (std::find_if(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.getGalutinis() == 5.0;
        }));
    std::move(studentai.begin(), z, std::back_inserter(n));
    studentai.erase(studentai.begin(), z);
    auto l = t.elapsed();
    ofstream f1("moksliukai_l" + std::to_string(x));
    ofstream f2("nevykeliai_l" + std::to_string(x));
    for (Studentas a : studentai) {
        f1 << a.info();
    }
    for (Studentas a : n) {
        f2 << a.info();
    };
    n.clear();
    f1.close();
    f2.close();
    studentai.clear();
    return l;
};

double nusk_list2(int x) {
    Timer t;
    string fname = "stud" + std::to_string(x) + ".txt";
    list<Studentas> studentai = nuskaitymas_list(fname);
    studentai.sort(palyginimas);
    list<Studentas> n;
    list<Studentas> m;
    auto z = (std::find_if(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.getGalutinis() == 5.0;
        }));
    std::move(studentai.begin(), z, std::back_inserter(n));
    std::move(z, studentai.end(), std::back_inserter(m));
    auto l = t.elapsed();
    ofstream f1("moksliukai_l2" + std::to_string(x));
    ofstream f2("nevykeliai_l2" + std::to_string(x));
    for (Studentas a : m) {
        f1 << a.info();
    }
    for (Studentas a : n) {
        f2 << a.info();
    }
    n.clear();
    m.clear();
    f1.close();
    f2.close();
    studentai.clear();
    return l;
};

double nusk_vect1(int x) {
    Timer t;
    string fname = "stud" + std::to_string(x) + ".txt";
    vector<Studentas> studentai = nuskaitymas_vect(fname);
    sort(studentai.begin(), studentai.end(), palyginimas);
    vector<Studentas> n;
    auto z = (std::find_if(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.getGalutinis() == 5.0;
        }));
    std::move(studentai.begin(), z, std::back_inserter(n));
    studentai.erase(studentai.begin(), z);
    auto l = t.elapsed();
    ofstream f1("moksliukai_v" + std::to_string(x));
    ofstream f2("nevykeliai_v" + std::to_string(x));
    for (Studentas a : studentai) {
        f1 << a.info();
    }
    for (Studentas a : n) {
        f2 << a.info();
    }
    n.clear();
    f1.close();
    f2.close();
    studentai.clear();
    return l;
};

double nusk_vect2(int x) {
    Timer t;
    string fname = "stud" + std::to_string(x) + ".txt";
    vector<Studentas> studentai = nuskaitymas_vect(fname);
    sort(studentai.begin(), studentai.end(), palyginimas);
    vector<Studentas> n;
    vector<Studentas> m;
    auto z = (std::find_if(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.getGalutinis() == 5.0;
        }));
    std::move(studentai.begin(), z, std::back_inserter(n));
    std::move(z, studentai.end(), std::back_inserter(m));
    auto l = t.elapsed();
    ofstream f1("moksliukai_v2" + std::to_string(x));
    ofstream f2("nevykeliai_v2" + std::to_string(x));
    for (Studentas a : m) {
        f1 << a.info();
    }
    for (Studentas a : n) {
        f2 << a.info();
    }
    n.clear();
    m.clear();
    f1.close();
    f2.close();
    studentai.clear();
    return l;
};

double vect_st_part(int x) {
    Timer t;
    string fname = "stud" + std::to_string(x) + ".txt";
    vector<Studentas> studentai = nuskaitymas_vect(fname);
    vector<Studentas> n;
    auto it = std::stable_partition(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.getGalutinis() < 5.0;
        });
    std::copy(studentai.begin(), it, std::back_inserter(n));
    studentai.erase(studentai.begin(), it);
    auto l = t.elapsed();
    ofstream f1("moksliukai_rem" + std::to_string(x));
    ofstream f2("nevykeliai_rem" + std::to_string(x));
    for (Studentas a : studentai) {
        f1 << a.info();
    }
    for (Studentas a : n) {
        f2 << a.info();
    }
    n.clear();
    f1.close();
    f2.close();
    studentai.clear();
    return l;
};

double vect_partition(int x) {
    Timer t;
    string fname = "stud" + std::to_string(x) + ".txt";
    vector<Studentas> studentai = nuskaitymas_vect(fname);
    vector<Studentas> n;
    vector<Studentas> m;
    std::partition_copy(studentai.begin(), studentai.end(), std::back_inserter(n),
        std::back_inserter(m), [](const Studentas& s) {
            return s.getGalutinis() < 5.0;
        });
    auto l = t.elapsed();
    ofstream f1("moksliukai_part" + std::to_string(x));
    ofstream f2("nevykeliai_part" + std::to_string(x));
    for (Studentas a : m) {
        f1 << a.info();
    }
    for (Studentas a : n) {
        f2 << a.info();
    }
    n.clear();
    m.clear();
    f1.close();
    f2.close();
    studentai.clear();
    return l;
};

void isv(vector<Studentas> v, int x) {
    Studentas stud;
    Timer t;
    vector<Studentas> m;
    vector<Studentas> n;
    for (int i = 0; i < v.size() - 1; i++) {
        stud = v[i];
        if (stud.getGalutinis() >= 5.0) {
            m.push_back(stud);
        }
        else n.push_back(stud);
    }
    cout << "Studentu isskirstymas i 2 grupes uztruko:" << t.elapsed() << endl;
    t.reset();
    ofstream f1("moksliukai" + std::to_string(x));
    ofstream f2("nevykeliai" + std::to_string(x));
    for (int i = 0; i < m.size(); i++) {
        stud = m[i];
        f1 << stud.info();
    }
    for (int i = 0; i < n.size(); i++) {
        stud = n[i];
        f2 << stud.info();
    }
    cout << "Studentu isskirstymas i 2 failus uztruko:" << t.elapsed() << endl;
    m.clear();
    n.clear();
    f1.close();
    f2.close();
};

Studentas ivedimas(int& n, int x) {
    string vardas, pavarde;
    int egz, paz_sk, p;
    vector<int> paz;
    int sum = 0;
    cout << "Iveskite varda:";
    cin >> vardas;
    cout << "Iveskite pavarde:";
    cin >> pavarde;
    cout << "Iveskite egzamino pazymi:";
    cin >> egz;
    cout << "Iveskite pazymiu skaiciu:";
    cin >> paz_sk;
    if (x == 0) {
        for (int i = 0; i < paz_sk; i++) {
            cout << "Iveskite  pazymi:";
            cin >> p;
            paz.push_back(p);
        }
    }
    else {
        for (int i = 0; i < paz_sk; i++) {
            paz.push_back(rand() % 10 + 1);
            cout << "Sugeneruotas pazymys:" << paz.back() << endl;
        }
    }
    Studentas stud = Studentas(vardas, pavarde, paz, egz);
    stud.Galutinis();
    stud.Galutinis_m();
    paz.clear();
    return stud;
}


void failo_nusk(string fname) {
    vector<Studentas> studentai = nuskaitymas_vect(fname);
    sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        return a.getVardas() < b.getVardas();
        });
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 10);
    cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(20) <<
        "Galutinis(vid.)" << left << setw(20) << "Galutinis(med.)" << endl;
    SetConsoleTextAttribute(h, 15);
    for (Studentas i : studentai) {
        cout << i.info() << std::right << setw(10) << setprecision(3) << i.getGalutinis_m() << endl;
    }
    studentai.clear();
}


void isvedimasVid(Studentas temp, int n) {
    cout << temp.info() << endl;
}

void isvedimasMed(Studentas temp, int n) {
    cout << temp.info_m() << endl;
}

void print_sparta(int x) {
    cout << left << setw(25) << x
        << left << setw(15) << nusk_list1(x) << left << setw(15) << nusk_vect1(x)
        << left << setw(15) << nusk_list2(x) << left << setw(15) << nusk_vect2(x) << endl;
}

int print_pradzia() {
    int p;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 9);
    cout << "Pasirinkite programos funkcija (irasykite funkcijos numeri):\n";
    SetConsoleTextAttribute(h, 15);
    cout << "(1) Programos spartos testas (list ir vector)\n" <<
        "(2) Programos spartos testas (tik vector)\n" << "(3) Failo su atsitiktiniais duomenimis generavimas\n" <<
        "(4) Duomenu nuskaitymas is failo\n" << "(5) Duomenu ivedimas\n" << "(0) Baigti programos veikima\n";
    cin >> p;
    return p;
}

void testas() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 10);
    cout << left << setw(25) << "Irasu skaicius faile" << left << setw(30) << "Vienas naujas konteineris"
        << left << setw(30) << "Du nauji konteineriai" << "\n"
        << left << setw(25) << "" << left << setw(15) << "List" << left << setw(15) << "Vector"
        << left << setw(15) << "List" << left << setw(15) << "Vector" << endl;
    SetConsoleTextAttribute(h, 15);
    print_sparta(1000);
    print_sparta(10000);
    print_sparta(100000);
    print_sparta(1000000);
    print_sparta(10000000);
    cout << endl;
}

void testas2() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 10);
    cout << "\n" << left << setw(25) << "Irasu skaicius faile" << left << setw(20) << "find_if + move"
        << left << setw(20) << "stable_partition" << left << setw(20) << "find_if + 2x move"
        << left << setw(20) << "partition_copy" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << left << setw(25) << "1000"
        << left << setw(20) << nusk_vect1(1000) << left << setw(20) << vect_st_part(1000)
        << left << setw(20) << nusk_vect2(1000) << left << setw(20) << vect_partition(1000) << endl;
    cout << left << setw(25) << "1000000"
        << left << setw(20) << nusk_vect1(1000000) << left << setw(20) << vect_st_part(1000000)
        << left << setw(20) << nusk_vect2(1000000) << left << setw(20) << vect_partition(1000000) << endl;
}

void failo_gen() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 9);
    int x, n;
    cout << "Kiek failu generuoti?";
    cin >> n;
    for (int a = 1; a <= n; a++) {
        cout << "Kiek eiluciu duomenu generuoti?";
        cin >> x;
        cout << endl;
        gen(x);
    }
}

void f_nusk() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 9);
    string f;
    cout << "Iveskite failo pavadinima:";
    cin >> f;
    cout << endl;
    failo_nusk(f);
}

void duom_ivedimas() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 9);
    vector<Studentas> studentai;
    int n, m;
    string com, com2;
    cout << "Iveskite studentu skaiciu:";
    cin >> n;
    cout << endl;
    cout << "Pazymius generuoti atsitiktinai? (T/N):";
    cin >> com;
    cout << endl;
    while (com != "T" && com != "t" && com != "N" && com != "n") {
        cout << "Negaliojantis pasirinkimas, bandykite dar karta:";
        cin >> com;
    }
    if (com == "N" || com == "n") {
        for (int i = 0; i < n; i++) { studentai.push_back(ivedimas(m, 0)); }
    }
    else {
        for (int i = 0; i < n; i++) { studentai.push_back(ivedimas(m, 1)); }
    }
    cout << "Galutini bala skaiciuoti pagal vidurki ar mediana? (V/M):";
    cin >> com2;
    cout << endl;
    while (com2 != "V" && com2 != "v" && com2 != "M" && com2 != "m") {
        cout << "Negaliojantis pasirinkimas, bandykite dar karta:";
        cin >> com2;
    }
    if (com2 == "V" || com2 == "v") {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 10);
        cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(20) <<
            "Galutinis(vid.)" << endl;
        SetConsoleTextAttribute(h, 15);
        for (Studentas a : studentai) {
            isvedimasVid(a, m);
        }
    }
    else {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 10);
        cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(20) <<
            "Galutinis(med.)" << endl;
        SetConsoleTextAttribute(h, 5);
        for (Studentas a : studentai) {
            isvedimasMed(a, m);
        }
    }
    studentai.clear();

}