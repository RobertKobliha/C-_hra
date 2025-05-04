#include <iostream>
#include <string>

using namespace std;

int zlato = 100;
int meè = 1;
int magie = 1;
int štít = 1;

void Intro() {
    cout << "==============================" << endl;
    cout << "        GOBLIN GANG          " << endl;
    cout << "==============================" << endl;
    cout << "Zdravím cestovateli, vítej v Concer Worldu.\n";
    cout << "Musím uznat, že dnes máš mizerný den.\n";
    cout << "Nejde se odsud dostat, ledaže bys zabil JE.\n";
    cout << "Žijí zde pouze goblini, kteøí se ženou za zlatem,\n";
    cout << "takže pokud prohraješ, ztratíš všechno.\n";
    cout << "Pro zaèátek ti dám 100 zlatých.Hodnì štìstí.\n\n";
}


void HlavníMenu() {
    cout << "\n==============================" << endl;
    cout << "Zlato: " << zlato << endl;
    cout << "Co chceš dìlat?" << endl;
    cout << "1 - Jít do obchodu" << endl;
    cout << "2 - Bojovat s gobliny" << endl;
    cout << "3 - Bojovat s final bossem" << endl;
    cout << "4 - Ukonèit hru" << endl;
    cout << "Volba: ";
}


void Obchod() {
    int výbìr;
    do {
        cout << "\n===== OBCHOD =====" << endl;
        cout << "Zaplat nebo vypadni chudáky to nikdo nechce" << endl;
        cout << "Zlato: " << zlato << endl;
        cout << "1 - Vylepšit meè aktuální úroveò: " << meè << " - cena: " << meè * 30 << endl;
        cout << "2 - Vylepšit kouzla aktuální úroveò: " << magie << " - cena: " << magie * 30 << endl;
        cout << "3 - Vylepšit štít aktuální úroveò: " << štít << " - cena: " << štít * 30 << endl;
        cout << "4 - Návrat do hlavního menu" << endl;
        cout << "Volba: ";
        cin >> výbìr;

        int cena;
        switch (výbìr) {
            case 1:
                cena = meè * 30;
                if (zlato >= cena) {
                    meè++;
                    zlato -= cena;
                    cout << "Meè byl vylepšen na úroveò " << meè << endl;
                } else {
                    cout << "Ha jseš chudej." << endl;
                }
                break;
            case 2:
                cena = magie * 30;
                if (zlato >= cena) {
                    magie++;
                    zlato -= cena;
                    cout << "Kouzla byla vylepšena na úroveò " << magie << "!" << endl;
                } else {
                    cout << "Ha jseš chudej." << endl;
                }
                break;
            case 3:
                cena = štít * 30;
                if (zlato >= cena) {
                    štít++;
                    zlato -= cena;
                    cout << "Štít byl vylepšen na úroveò " << štít << "!" << endl;
                } else {
                    cout << "Ha jseš chudej." << endl;
                }
                break;
            case 4:
                cout << "Odešel jsi z obchodu, chudší nebo bez nièeho, každopádnì ostuda." << endl;
                break;
            default:
                cout << "Neplatná volba." << endl;
        }
    } while (výbìr != 4);
}

void goblini() {
    cout << "\n(Goblini nevypadají jako zdatní bojovníci ale dokážou pøekvapit obvzlášt když máš zlato. Èím více ho máš tím jsou silnìjší.)\n";
}

void Boss() {
    cout << "\n(Oni, postrach všech goblinù a lidí. Nepatøí sem, ale parazitování na jiných je až moc baví)\n";
}

int main() {
    int výbìr;
    Intro();

    do {
        HlavníMenu();
        cin >> výbìr;

        switch (výbìr) {
            case 1:
                openShop();
                break;
            case 2:
                fightGoblins();
                break;
            case 3:
                fightBoss();
                break;
            case 4:
                cout << "Konec hry. Díky za hraní!" << endl;
                break;
            default:
                cout << "Neplatná volba." << endl;
        }
    } while (výbìr != 4);

    return 0;
}
