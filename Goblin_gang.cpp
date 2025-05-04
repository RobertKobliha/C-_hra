#include <iostream>
#include <string>

using namespace std;

int zlato = 100;
int me� = 1;
int magie = 1;
int �t�t = 1;

void Intro() {
    cout << "==============================" << endl;
    cout << "        GOBLIN GANG          " << endl;
    cout << "==============================" << endl;
    cout << "Zdrav�m cestovateli, v�tej v Concer Worldu.\n";
    cout << "Mus�m uznat, �e dnes m� mizern� den.\n";
    cout << "Nejde se odsud dostat, leda�e bys zabil JE.\n";
    cout << "�ij� zde pouze goblini, kte�� se �enou za zlatem,\n";
    cout << "tak�e pokud prohraje�, ztrat� v�echno.\n";
    cout << "Pro za��tek ti d�m 100 zlat�ch.Hodn� �t�st�.\n\n";
}


void Hlavn�Menu() {
    cout << "\n==============================" << endl;
    cout << "Zlato: " << zlato << endl;
    cout << "Co chce� d�lat?" << endl;
    cout << "1 - J�t do obchodu" << endl;
    cout << "2 - Bojovat s gobliny" << endl;
    cout << "3 - Bojovat s final bossem" << endl;
    cout << "4 - Ukon�it hru" << endl;
    cout << "Volba: ";
}


void Obchod() {
    int v�b�r;
    do {
        cout << "\n===== OBCHOD =====" << endl;
        cout << "Zaplat nebo vypadni chud�ky to nikdo nechce" << endl;
        cout << "Zlato: " << zlato << endl;
        cout << "1 - Vylep�it me� aktu�ln� �rove�: " << me� << " - cena: " << me� * 30 << endl;
        cout << "2 - Vylep�it kouzla aktu�ln� �rove�: " << magie << " - cena: " << magie * 30 << endl;
        cout << "3 - Vylep�it �t�t aktu�ln� �rove�: " << �t�t << " - cena: " << �t�t * 30 << endl;
        cout << "4 - N�vrat do hlavn�ho menu" << endl;
        cout << "Volba: ";
        cin >> v�b�r;

        int cena;
        switch (v�b�r) {
            case 1:
                cena = me� * 30;
                if (zlato >= cena) {
                    me�++;
                    zlato -= cena;
                    cout << "Me� byl vylep�en na �rove� " << me� << endl;
                } else {
                    cout << "Ha jse� chudej." << endl;
                }
                break;
            case 2:
                cena = magie * 30;
                if (zlato >= cena) {
                    magie++;
                    zlato -= cena;
                    cout << "Kouzla byla vylep�ena na �rove� " << magie << "!" << endl;
                } else {
                    cout << "Ha jse� chudej." << endl;
                }
                break;
            case 3:
                cena = �t�t * 30;
                if (zlato >= cena) {
                    �t�t++;
                    zlato -= cena;
                    cout << "�t�t byl vylep�en na �rove� " << �t�t << "!" << endl;
                } else {
                    cout << "Ha jse� chudej." << endl;
                }
                break;
            case 4:
                cout << "Ode�el jsi z obchodu, chud�� nebo bez ni�eho, ka�dop�dn� ostuda." << endl;
                break;
            default:
                cout << "Neplatn� volba." << endl;
        }
    } while (v�b�r != 4);
}

void goblini() {
    cout << "\n(Goblini nevypadaj� jako zdatn� bojovn�ci ale dok�ou p�ekvapit obvzl�t kdy� m� zlato. ��m v�ce ho m� t�m jsou siln�j��.)\n";
}

void Boss() {
    cout << "\n(Oni, postrach v�ech goblin� a lid�. Nepat�� sem, ale parazitov�n� na jin�ch je a� moc bav�)\n";
}

int main() {
    int v�b�r;
    Intro();

    do {
        Hlavn�Menu();
        cin >> v�b�r;

        switch (v�b�r) {
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
                cout << "Konec hry. D�ky za hran�!" << endl;
                break;
            default:
                cout << "Neplatn� volba." << endl;
        }
    } while (v�b�r != 4);

    return 0;
}
