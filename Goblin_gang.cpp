#include <iostream>
#include <string>

using namespace std;

int zlato = 100;
int meč = 1;
int magie = 1;
int štít = 1;

void Intro() {
    cout << "==============================" << endl;
    cout << "        GOBLIN GANG          " << endl;
    cout << "==============================" << endl;
    cout << "Zdravim cestovateli, vitej v Concer Worldu." << endl;
    cout << "Musim uznat, ze dnes mas mizerny den." << endl;
    cout << "Nejde se odsud dostat, ledaze bys zabil JE." << endl;
    cout << "Ziji zde pouze goblini, ktery se zenou za zlatem," << endl;
    cout << "takze pokud prohrajes, ztratis vsechno." << endl;
    cout << "A neboj vsichni mluvi bez hacku a carek" << endl;
    cout << "Pro zacatek ti dám 100 zlatych.Hodne stesti." << endl;
}


void HlavníMenu() {
    cout << "==============================" << endl;
    cout << "Zlato: " << zlato << endl;
    cout << "Co chces delat?" << endl;
    cout << "1 - Jit do obchodu" << endl;
    cout << "2 - Bojovat s gobliny" << endl;
    cout << "3 - Bojovat s final bossem" << endl;
    cout << "4 - Ukoncit hru" << endl;
    cout << "Volba: ";
}


void Obchod() {
    int výběr;
    do {
        cout << "\n===== OBCHOD =====" << endl;
        cout << "Zaplat nebo vypadni chudaky tu nikdo nechce" << endl;
        cout << "Zlato: " << zlato << endl;
        cout << "1 - Vylepsit mec aktuálni úroven: " << meč << " - cena: " << meč * 30 << endl;
        cout << "2 - Vylepsit kouzla aktualni uroven: " << magie << " - cena: " << magie * 30 << endl;
        cout << "3 - Vylepsit stit aktualni uroven: " << štít << " - cena: " << štít * 30 << endl;
        cout << "4 - Navrat do hlavniho menu" << endl;
        cout << "Volba: ";
        cin >> výběr;

        int cena;
        switch (výběr) {
            case 1:
                cena = meč * 30;
                if (zlato >= cena) {
                    meč++;
                    zlato -= cena;
                    cout << "Mec byl vylepsen na uroven " << meč << endl;
                } else {
                    cout << "Ha jses chudej." << endl;
                }
                break;
            case 2:
                cena = magie * 30;
                if (zlato >= cena) {
                    magie++;
                    zlato -= cena;
                    cout << "Kouzla byla vylepsena na uroven " << magie << "!" << endl;
                } else {
                    cout << "Ha jses chudej." << endl;
                }
                break;
            case 3:
                cena = štít * 30;
                if (zlato >= cena) {
                    štít++;
                    zlato -= cena;
                    cout << "Stit byl vylepsen na uroven " << štít << "!" << endl;
                } else {
                    cout << "Ha jses chudej." << endl;
                }
                break;
            case 4:
                cout << "Odesel jsi z obchodu, chudsí nebo bez niceho, kazdopadne ostuda." << endl;
                break;
            default:
                cout << "Neplatna volba." << endl;
        }
    } while (výběr != 4);
}

void goblini() {
    cout << "Goblini nevypadají jako zdatní bojovníci ale dokázou prekvapit obvzlást kdyz más zlato. Cím více ho más tím jsou silnejsi.";
    //cout <<
}

void Boss() {
    cout << "Oni, postrach vsech goblinu a lidi. Nepatrí sem, ale parazitování na jinych je az moc bavi";
}

int main() {
    int výběr;
    Intro();

    do {
        HlavníMenu();
        cin >> výběr;

        switch (výběr) {
            case 1:
                Obchod();
                break;
            case 2:
                goblini();
                break;
            case 3:
                Boss();
                break;
            case 4:
                cout << "Konec hry. Diky za hrani!" << endl;
                break;
            default:
                cout << "Neplatna volba." << endl;
        }
    } while (výběr != 4);

    return 0;
}
