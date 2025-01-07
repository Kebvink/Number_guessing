#include <iostream>
#include <random>


int Maximalwert = 100;                                                          //Standartwert für den maximalen Wert
const int Minimalwert = 1;                                                      //Fester Minimalwert für den Zufallsgenerator                                

char Menu();                    
void Game(int min, int max);
int RandomNumber(int min, int max);

int main() {

char auswahl;

    while (true)                                                                //Endlosschleife, für das Menü
    {
        auswahl=Menu();
        if (auswahl=='S'||auswahl=='s')                                         //Auswahl Starten des Spiels mit Eingabeüberprüfung
        {
            std::cout << "Spiel wird gestartet" << std::endl;
            Game(Minimalwert, Maximalwert);
        }
        else if (auswahl=='O'||auswahl=='o')                                    //Auswahl der Optionen mit Eingabeüberprüfung
        {
            std::cout << "Bitte geben sie den maximalwert ein, Standart sind 100." << std::endl;
            std::cin >> Maximalwert;
        }
        else if (auswahl=='B'||auswahl=='b')                                    //Auswahl Beenden des Spiels mit Eingabeüberprüfung
        {
            std::cout << "Spiel wird beendet" << std::endl;
            break;
        }
        else                                                                    //Falsche Eingabe                   
        {
            std::cout << "Falsche Eingabe" << std::endl;
        }
    }
    return 0;
}

char Menu(){                                                                //Menüfunktion mit Rückgabe des gewählten Menüpunktes
    char auswahl;

    std::cout << "Mit S starten Sie das Spiel" << std::endl;
    std::cout << "Mit O gehen Sie in die Optionen" << std::endl;
    std::cout << "Mit B beenden Sie das Spiel" << std::endl;
    std::cin >> auswahl;
    return auswahl;
}

void Game (int min, int max)                                                //Spiel Funktion mit Eingabeüberprüfung
{
int Random_Number=RandomNumber(min, max);
int Eingabe;
std::cout << "Bitte geben sie eine Zahl zwischen " << min << " und " << max << " ein." << std::endl;
std::cin >> Eingabe;
while (Eingabe!=Random_Number)
{
    if (Eingabe>Random_Number)
    {
        std::cout << "Die gesuchte Zahl ist kleiner" << std::endl;
    }
    else
    {
        std::cout << "Die gesuchte Zahl ist groeßer" << std::endl;
    }
    std::cin >> Eingabe;
}
std::cout << "Herzlichen Glueckwunsch, sie haben die Zahl erraten" << std::endl;
return;
}

int RandomNumber(int min, int max)                                          //Zufallszahlengenerator mit der Random Library
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}