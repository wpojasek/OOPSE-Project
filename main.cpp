#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. FILTRY (Parametry wyszukiwania)
// Używamy prostych typów wyliczeniowych (enum) - FEATURE Z GEMINI
// żeby łatwo było wybierać opcje w terminalu.
// ==========================================

enum HungerLevel { LIGHT = 1, MEDIUM, STARVING };
enum CuisineType { POLISH = 1, ITALIAN, FAST_FOOD, ASIAN };
enum PriceRange { CHEAP = 1, MODERATE, EXPENSIVE };

// ==========================================
// 2. KLASA UŻYTKOWNIKA (User)
// Odpowiada za logowanie, rejestrację i ulubione.
// ==========================================

class User {
private:
    string username;
    string password;
    // Na razie przechowujemy nazwy jako stringi. 
    // Docelowo tu będzie wektor wskaźników/identyfikatorów z bazy twojej Krzysiu 
    vector<string> favouriteRestaurants; 

public:
    // Konstruktor bezparametrowy (domyślny)
    User() {}

    // Konstruktor do rejestracji
    User(string uName, string pass) {
        username = uName;
        password = pass;
    }

    string getUsername() {
        return username;
    }

    bool login(string enteredPassword) {
        return password == enteredPassword;
    }

    void addFavourite(string restaurantName) {
        favouriteRestaurants.push_back(restaurantName);
        cout << "[System] Dodano '" << restaurantName << "' do ulubionych!" << endl;
    }

    void showFavourites() {
        cout << "\n--- Ulubione restauracje (" << username << ") ---" << endl;
        if (favouriteRestaurants.empty()) {
            cout << "Brak ulubionych. Musisz cos dodac!" << endl;
        } else {
            for (const string& fav : favouriteRestaurants) {
                cout << "- " << fav << endl;
            }
        }
        cout << "-----------------------------------\n";
    }
};

// ==========================================
// 3. SILNIK WYSZUKIWANIA (SearchEngine)
// Odpowiada za logikę filtrowania
// ==========================================

class SearchEngine {
public:
    // Ta metoda na razie tylko symuluje działanie. 
    // Potem wjebemy tutaj baze danych restauracji od ciebie Krzychu
    void searchRestaurants(int hunger, int cuisine, int price) {
        cout << "\nSzukam restauracji dla podanych filtrow..." << endl;
        
        // Tutaj logika 
        // if (restaurant.cuisine == cuisine && restaurant.price == price) ...
        
        cout << "==========================================" << endl;
        cout << " WYNIKI WYSZUKIWANIA (Symulacja)" << endl;
        cout << "==========================================" << endl;
        if (cuisine == ITALIAN) {
            cout << "1. Pizzeria u Bony (Wysokie dopasowanie!)" << endl;
        } else if (cuisine == POLISH) {
            cout << "1. Schabowy u Babci (Blisko AGH!)" << endl;
        } else {
            cout << "1. Kebab pod Psem" << endl;
        }
        cout << "==========================================\n" << endl;
    }
};

// ==========================================
// 4. GŁÓWNA FUNKCJA (Interfejs Terminalowy)
// ==========================================

int main() {
    cout << "Witaj w Food Finder System!" << endl;
    
    // Prosta symulacja rejestracji (żeby mieć na czym pracować)
    string regUser, regPass;
    cout << "Zarejestruj sie.\nPodaj login: ";
    cin >> regUser;
    cout << "Podaj haslo: ";
    cin >> regPass;
    
    User currentUser(regUser, regPass);
    cout << "\nRejestracja zakonczona sukcesem. Zaloguj sie." << endl;
    
    // Prosta symulacja logowania
    string loginPass;
    bool loggedIn = false;
    
    while (!loggedIn) {
        cout << "Haslo dla " << currentUser.getUsername() << ": ";
        cin >> loginPass;
        if (currentUser.login(loginPass)) {
            loggedIn = true;
            cout << "Zalogowano pomyslnie!" << endl;
        } else {
            cout << "Bledne haslo. Sprobuj ponownie." << endl;
        }
    }

    // Inicjalizacja silnika
    SearchEngine engine;
    int choice = 0;

    // GŁÓWNA PĘTLA PROGRAMU W TERMINALU
    while (choice != 5) {
        cout << "\n--- MENU GLOWNE ---" << endl;
        cout << "1. Wyszukaj restauracje (Filtry)" << endl;
        cout << "2. Dodaj restauracje do ulubionych" << endl;
        cout << "3. Pokaz moje ulubione" << endl;
        cout << "4. (Osoba 2) Dodaj nowa restauracje do bazy [Niedostepne]" << endl;
        cout << "5. Wyjdz" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int h, c, p;
                cout << "\n--- Ustawianie Filtrow ---" << endl;
                cout << "Poziom glodu (1-Lekki, 2-Sredni, 3-Umieram): ";
                cin >> h;
                cout << "Kuchnia (1-Polska, 2-Wloska, 3-FastFood, 4-Azjatycka): ";
                cin >> c;
                cout << "Budzet (1-Tanio, 2-Srednio, 3-Drogo): ";
                cin >> p;
                
                engine.searchRestaurants(h, c, p);
                break;
            }
            case 2: {
                string restName;
                cout << "Podaj nazwe restauracji do dodania: ";
                cin.ignore(); // Czyszczenie bufora przed getline
                getline(cin, restName);
                currentUser.addFavourite(restName);
                break;
            }
            case 3:
                currentUser.showFavourites();
                break;
            case 4:
                cout << "Ta funkcja bedzie zaimplementowana przez osobe od bazy danych!" << endl;
                break;
            case 5:
                cout << "Zamykanie systemu. Smacznego!" << endl;
                break;
            default:
                cout << "Nieznana opcja!" << endl;
        }
    }

    return 0;
}
