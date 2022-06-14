#include <iostream>
#include <string>
 
using namespace std;

#define swapCountries(A, B) \
    {                      \
        Country aux = A;       \
        A = B;             \
        B = aux;           \
    }

class Country {
    public:
        Country() {
            this->name = "";
            this->goldMedals = -1;
            this->silverMedals = -1;
            this->bronzeMedals = -1;
        }

        Country(std::string countryName,
                int goldMedals,
                int silverMedals,
                int bronzeMedals) {
            
            this->name = countryName;
            this->goldMedals = goldMedals;
            this->silverMedals = silverMedals;
            this->bronzeMedals = bronzeMedals;
        }

        bool operator < (Country const country) {
            if (this->goldMedals < country.goldMedals) return true;
            else if (this->goldMedals > country.goldMedals) return false;

            if (this->silverMedals < country.silverMedals) return true;
            else if (this->silverMedals > country.silverMedals) return false;

            if (this->bronzeMedals < country.bronzeMedals) return true;
            else if (this->bronzeMedals > country.bronzeMedals) return false;

            return false;
        }

        bool operator > (Country const country) {
            if (this->goldMedals > country.goldMedals) return true;
            else if (this->goldMedals < country.goldMedals) return false;

            if (this->silverMedals > country.silverMedals) return true;
            else if (this->silverMedals < country.silverMedals) return false;

            if (this->bronzeMedals > country.bronzeMedals) return true;
            else if (this->bronzeMedals < country.bronzeMedals) return false;

            return false;
        }

        bool operator == (Country const country) {
            if (this->goldMedals != country.goldMedals) return false;
            if (this->silverMedals != country.silverMedals) return false;
            if (this->bronzeMedals != country.bronzeMedals) return false;
            
            return true;
        }

        std::string getName() {
            return this->name;
        }

    private:
        std::string name;
        int goldMedals;
        int silverMedals;
        int bronzeMedals;

    friend class OlimpicCountries;
};

class OlimpicCountries {
    public:
        OlimpicCountries() {
            this->countriesAmount = -1;
            countries = nullptr;
        }

        OlimpicCountries(int countriesAmount) {
            this->countriesAmount = countriesAmount;
            countries = new Country[countriesAmount];
        }

        ~OlimpicCountries() {
            delete []this->countries;
            this->countries = nullptr;
        }

        void sortCountriesByName() {
            for (int i = 0; i < this->countriesAmount; i++) {
                int minCountry = i;
                for (int j = i; j < this->countriesAmount; j++) {
                    if (this->countries[j].getName() < this->countries[minCountry].getName()) {
                        minCountry = j;
                    }
                }
                swapCountries(this->countries[i], this->countries[minCountry]);
            }
        }

        void sortCountriesByMedals() {
            for (int i = 0; i < this->countriesAmount; i++) {
                int minCountry = i;
                for (int j = i; j < this->countriesAmount; j++) {
                    if (this->countries[j] < this->countries[minCountry]) {
                        minCountry = j;
                    }
                }
                swapCountries(this->countries[i], this->countries[minCountry]);
            }
        }

    private:
        int countriesAmount;
        Country *countries;
};

int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
 
    return 0;
}