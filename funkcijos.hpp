
#ifndef UNTITLED5_FUNKCIJOS_HPP
#define UNTITLED5_FUNKCIJOS_HPP
#include "mano_lib.hpp"

class Zmogus {
protected:
    string vardas_;
    string pavarde_;
public:
    Zmogus(string vardas, string pavarde) {
        vardas_ = vardas; pavarde_ = pavarde;
    }
    Zmogus() {
        vardas_ = ""; pavarde_ = "";
    }
    virtual void Vardas(string vardas) = 0;
    virtual void Pavarde(string pavarde) = 0;
    inline string getVardas() const { return vardas_; }
    inline string getPavarde() const { return pavarde_; }
};

class Studentas : public Zmogus {
private:
    vector<int> pazymiai_;
    int egzaminas_;
    double galutinis_;
    double galutinis_m_;

public:
    Studentas() : Zmogus() {
        pazymiai_ = { 0 }, egzaminas_ = 0, galutinis_ = 0, galutinis_m_ = 0;
    }

    Studentas(string v, string p, vector<int> pa, int e);

    //getters
    vector<int> getPazymiai() { return pazymiai_; }
    int getEgzaminas() { return egzaminas_; }
    double getGalutinis() { return galutinis_; }
    double getGalutinis_m() { return galutinis_m_; }
    const string getVardas() const { return vardas_; }
    const string getPavarde() const { return pavarde_; }
    const vector<int> getPazymiai() const { return pazymiai_; }
    const int getEgzaminas() const { return egzaminas_; }
    const double getGalutinis() const { return galutinis_; }
    const double getGalutinis_m_() const { return galutinis_m_; }

    //setters
    void Vardas(string vardas) { vardas_ = vardas; }
    void Pavarde(string pavarde) { pavarde_ = pavarde; }
    void Pazymiai(vector<int> pazymiai) { pazymiai_ = pazymiai; }
    void Egzaminas(int egzaminas) { egzaminas_ = egzaminas; }
    void Galutinis() {
        double vid = std::accumulate(pazymiai_.begin(), pazymiai_.end(), 0.0) / pazymiai_.size();
        galutinis_ = 0.4 * vid + 0.6 * egzaminas_;
    }
    void Galutinis_m() { galutinis_m_ = 0.4 * med() + 0.6 * egzaminas_; }

    //destructor
    ~Studentas() {
        pazymiai_.clear();
    }

    //copy constructor
    Studentas(const Studentas& s) {
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        egzaminas_ = s.egzaminas_;
        pazymiai_ = s.pazymiai_;
        galutinis_ = s.galutinis_;
        galutinis_m_ = s.galutinis_m_;
    }

    //copy assignment operator
    Studentas& operator= (const Studentas& s) {
        if (this == &s) {
            return *this;
        }
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        egzaminas_ = s.egzaminas_;
        pazymiai_ = s.pazymiai_;
        galutinis_ = s.galutinis_;
        galutinis_m_ = s.galutinis_m_;
        return *this;
    }

    string info() {
        char buf[55];
        snprintf(buf, 55, "\n %-15s %-15s %-16.2f", vardas_.c_str(), pavarde_.c_str(), galutinis_);
        string info = buf;
        return info;
    }

    string info_m() {
        char buf[55];
        snprintf(buf, 55, "\n %-15s %-15s %-16.2f", vardas_.c_str(), pavarde_.c_str(), galutinis_m_);
        string info = buf;
        return info;
    }

    double med() {
        sort(pazymiai_.begin(), pazymiai_.end());
        double med;
        if ((pazymiai_.size() - 1) % 2 == 0) {
            med = double(pazymiai_[(pazymiai_.size() - 1) / 2] + pazymiai_[(pazymiai_.size() - 1) / 2 + 1]) / 2;
        }
        else med = pazymiai_[(pazymiai_.size() - 1) / 2];
        return med;
    }
    friend std::ostream& operator<< (std::ostream& out, const Studentas& s) {
        out << s.vardas_ << " " << s.pavarde_ << " ";
        for (int p : s.pazymiai_) {
            out << p << "";
        }
        out << s.egzaminas_ << endl;
        return out;
    }

    friend std::istream& operator>> (std::istream& in, Studentas& s) {
        int paz_sk, paz;
        in >> s.vardas_ >> s.pavarde_;
        for (int i = 0; i < 4; i++) {
            in >> paz;
            s.pazymiai_.push_back(paz);
        }
        in >> s.egzaminas_;
        return in;
    }
};

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{ std::chrono::high_resolution_clock::now() } {}

    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }

    double elapsed() const {
        return std::chrono::duration<double>
            (std::chrono::high_resolution_clock::now() - start).count();
    }
};


Studentas ivedimas(int& n, int x);

vector<Studentas> nuskaitymas_vect(string fname);

list<Studentas> nuskaitymas_list(string fname);

void isvedimasVid(Studentas temp, int n);

void isvedimasMed(Studentas temp, int n);

void gen(int x);

bool palyginimas(const Studentas& a, const Studentas& b);

double nusk_list1(int x);

double nusk_vect1(int x);

double nusk_list2(int x);

double nusk_vect2(int x);

double vect_st_part(int x);

double vect_partition(int x);

string pazGeneravimas();

void failo_nusk(string fname);

void isv(vector<Studentas> v, int x);

void print_sparta(int x);

int print_pradzia();

void testas();

void testas2();

void failo_gen();

void f_nusk();

void duom_ivedimas();

#endif //UNTITLED5_FUNKCIJOS_HPP