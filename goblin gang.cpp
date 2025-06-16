#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int zlato = 100;
int mec = 1;
int magie = 1;
int stit = 1;
bool magiePouzita = false;
int schopnostStitu = 3;
int zivoty;

void Intro() {
    cout << "==============================" << endl;
    cout << "        GOBLIN GANG" << endl;
    cout << "==============================" << endl;
    cout << "Zdravim cestovateli, vitej v Concer Worldu.\n";
    cout << "Musim uznat, ze dnes mas mizerny den.\n";
    cout << "Nejde se odsud dostat, ledaze bys zabil JE.\n";
    cout << "Ziji zde pouze goblini, kteri se zenou za zlatem.\n";
    cout << "Pokud prohrajes, ztratis vsechno krom magie.\n";
    cout << "Pro zacatek ti dam 100 zlatych. Hodne stesti.\n";
    zivoty = stit;
}

void HlavniMenu() {
    cout << "\n==============================" << endl;
    cout << "Zlato: " << zlato << endl;
    cout << "Co chces delat?" << endl;
    cout << "1 - Jit do obchodu" << endl;
    cout << "2 - Bojovat" << endl;
    cout << "3 - Bojovat s final bossem" << endl;
    cout << "4 - Inventar" << endl;
    cout << "5 - Nevestinec" << endl;
    cout << "6 - Ukoncit hru" << endl;
    cout << "Volba: ";
}

void Obchod() {
    int vyber;
    do {
        cout << "\n===== OBCHOD =====" << endl;
        cout << "Zaplat nebo vypadni chudaky to nikdo nechce" << endl;
        cout << "Zlato: " << zlato << endl;
        cout << "1 - Vylepsit mec (" << mec << "->" << mec+1 << ") - cena: " << mec * 30 << endl;
        cout << "2 - Vylepsit magii (" << magie << "->" << magie+1 << ") - cena: " << magie * 30 << endl;
        cout << "3 - Vylepsit stit (+1 zivot) - cena: " << stit * 30 << endl;
        cout << "4 - Navrat do hlavniho menu" << endl;
        cin >> vyber;

        int cena;
        switch (vyber) {
            case 1:
                cena = mec * 30;
                if (zlato >= cena) {
                    mec++;
                    zlato -= cena;
                    cout << "Mec vylepsen na uroven " << mec << "!" << endl;
                } else {
                    cout << "Nedostatek zlatych!" << endl;
                }
                break;
            case 2:
                cena = magie * 30;
                if (zlato >= cena) {
                    magie++;
                    zlato -= cena;
                    cout << "Magie vylepsena na uroven " << magie << "!" << endl;
                } else {
                    cout << "Nedostatek zlatych!" << endl;
                }
                break;
            case 3:
                cena = stit * 30;
                if (zlato >= cena) {
                    stit++;
                    zlato -= cena;
                    cout << "Stit vylepsen! Nyni mas " << stit << " zivotu!" << endl;
                } else {
                    cout << "Nedostatek zlatych!" << endl;
                }
                break;
            case 4:
                cout << "Opoustis obchod...chudší nebo bez nièeho každopádnì ostuda" << endl;
                break;
            default:
                cout << "Neplatna volba!" << endl;
        }
    } while (vyber != 4);
}

void Inventar() {
    cout << "\n====== INVENTAR ======" << endl;
    cout << "Zlato: " << zlato << endl;
    cout << "Zivoty: " << zivoty << "/" << stit << endl;
    cout << "Sila mece: " << mec << endl;
    cout << "Sila magie: " << magie << endl;
    cout << "Obrana: " << schopnostStitu << "/3" << endl;
    cout << "======================" << endl;
}

void Nevestinec() {
    cout << "No vitej. A uzij si sve tezce vydelane penize. Nejsou tu hezke zeny ale lepsi vyhodit prachy zde nez je dat zkrblikum.\n";
    zlato = 0;
}

int VyberAkce(bool bossBoj = false) {
    cout << "\nVyber jak je chces zmrzacit:" << endl;
    cout << "1 - Utok mecem (" << mec << " sila)" << endl;
    cout << "2 - Magie (" << magie << " sila)" << endl;
    cout << "3 - Stit (" << schopnostStitu << "/3 pouziti)" << endl;
    if (bossBoj) {
        cout << "4 - Uhyb (50% uspesnost)" << endl;
    }
    cout << "Tvoje volba: ";

    int volba;
    cin >> volba;
    return volba;
}

void BojSNepritelem(int enemyHP, string jmenoNepritele, int odmenaMin, int odmenaMax) {
    zivoty = stit;
    magiePouzita = false;
    schopnostStitu = 3;

    cout << "\nBojujes s " << jmenoNepritele << " (" << enemyHP << " zivoty)!" << endl;

    while (enemyHP > 0 && zivoty > 0) {
        cout << "\n" << jmenoNepritele << ": " << enemyHP << "/" << enemyHP << " zivoty" << endl;
        cout << "Tvuj zivot: " << zivoty << "/" << stit << endl;

        int akce = VyberAkce();
        int poskozeni = 0;
        bool branim = false;

        switch (akce) {
            case 1:
                poskozeni = mec;
                cout << "Utocis mecem za " << poskozeni << " poskozeni!" << endl;
                break;
            case 2:
                if (!magiePouzita) {
                    poskozeni = magie;
                    magiePouzita = true;
                    cout << "Pouzivas magii za " << poskozeni << " poskozeni!" << endl;
                } else {
                    cout << "Magie jiz byla pouzita!" << endl;
                }
                break;
            case 3:
                if (schopnostStitu > 0) {
                    schopnostStitu--;
                    branim = true;
                    cout << "Chranis se stitem!" << endl;
                } else {
                    cout << "Stit je vycerpan!" << endl;
                }
                break;
            default:
                cout << "Neplatna volba!" << endl;
        }

        if (poskozeni > 0) {
            enemyHP -= poskozeni;
            cout << "Zasahl jsi nepritele za " << poskozeni << " poskozeni!" << endl;
        }

        if (enemyHP > 0 && !branim) {
            int utokNepritele = 1 + rand() % (stit / 2 + 1);
            zivoty -= utokNepritele;
            cout << jmenoNepritele << " te zasahl za " << utokNepritele << " poskozeni!" << endl;
        } else if (branim) {
            cout << "Uspesne jsi se ubránil!" << endl;
        }
    }

    if (zivoty > 0) {
        int odmena = odmenaMin + rand() % (odmenaMax - odmenaMin + 1);
        zlato += odmena;
        cout << "\nPorazil jsi " << jmenoNepritele << " a ziskal " << odmena << " zlatych!" << endl;
    } else {
        cout << "\nByl jsi porazen!" << endl;
        mec = 1;
        stit = 1;
        zlato = zlato / 2;
    }
}

void NahodnyBoj() {
    int volba = rand() % 3;
    switch (volba) {
        case 0:
            BojSNepritelem(10 + stit * 2, "Zkrblici", 1000, 5000);
            break;
        case 1:
            BojSNepritelem(5 + stit, "Goblin Gang", 500, 1500);
            break;
        case 2:
            BojSNepritelem(20 + stit * 3, "Goblin Machine", 1500, 3500);
            break;
    }
}

void BojSBossem() {
    cout << "\n=== BOJ S BOSSEM ===" << endl;
    cout << "Magnetron a Polarisurge! Dva tlustosi, už jen sedí a hází kameny" << endl;

    int magnetronHP = 750;
    int polarisurgeHP = 800;
    const int magnetronMaxHP = 750;
    const int polarisurgeMaxHP = 800;

    zivoty = stit;
    magiePouzita = false;
    schopnostStitu = 3;

    while ((magnetronHP > 0 || polarisurgeHP > 0) && zivoty > 0) {
        cout << "\nTvuj zivot: " << zivoty << "/" << stit << endl;
        cout << "Magnetron: " << magnetronHP << "/750" << endl;
        cout << "Polarisurge: " << polarisurgeHP << "/800" << endl;

        int akce = VyberAkce(true);
        int poskozeni = 0;
        bool uhyb = false;
        bool branim = false;

        switch (akce) {
            case 1:
                poskozeni = mec;
                cout << "Utocis mecem za " << poskozeni << " poskozeni!" << endl;
                break;
            case 2:
                if (!magiePouzita) {
                    poskozeni = magie;
                    magiePouzita = true;
                    cout << "Pouzivas magii za " << poskozeni << " poskozeni!" << endl;
                } else {
                    cout << "Magie jiz byla pouzita!" << endl;
                }
                break;
            case 3:
                if (schopnostStitu > 0) {
                    schopnostStitu--;
                    branim = true;
                    cout << "Chranis se stitem!" << endl;
                } else {
                    cout << "Stit je vycerpan!" << endl;
                }
                break;
            case 4:
                uhyb = true;
                if (rand() % 2 == 0) {
                    cout << "Uspesne jsi uhnul kamenùm!" << endl;
                    magnetronHP -= 100;
                    polarisurgeHP -= 100;
                    cout << "Bossové se v zlosti poranili o skálu(-100 zivotu kazdy)!" << endl;
                } else {
                    cout << "Nedokazal jsi uhnout!" << endl;
                }
                break;
            default:
                cout << "Neplatna volba!" << endl;
        }

        if (!uhyb && poskozeni > 0) {
            if (magnetronHP > 0) {
                magnetronHP -= poskozeni;
                cout << "Zasahl jsi Magnetrona (-" << poskozeni << " HP)!" << endl;
            } else if (polarisurgeHP > 0) {
                polarisurgeHP -= poskozeni;
                cout << "Zasahl jsi Polarisurge (-" << poskozeni << " HP)!" << endl;
            }
        }

        if (magnetronHP < 0) magnetronHP = 0;
        if (polarisurgeHP < 0) polarisurgeHP = 0;


        if (magnetronHP > 0 && polarisurgeHP > 0) {

            if (magnetronHP < magnetronMaxHP/2 && polarisurgeHP > polarisurgeMaxHP*0.8) {
                magnetronHP = magnetronMaxHP;
                cout << "Magnetron se obnovil na plne zdravi diky Polarisurge!" << endl;
            }


            if (polarisurgeHP < polarisurgeMaxHP*0.2 && magnetronHP >= magnetronMaxHP/2) {
                polarisurgeHP = polarisurgeMaxHP;
                cout << "Polarisurge se obnovila na plne zdravi diky Magnetronovi!" << endl;
            }


            if (!branim && !uhyb) {
                int magnetronUtok = (polarisurgeMaxHP - polarisurgeHP) / 2;
                int polarisurgeUtok = (magnetronMaxHP - magnetronHP) * 2;

                zivoty -= magnetronUtok;
                cout << "Magnetron utoci se silou " << magnetronUtok << "!" << endl;

                zivoty -= polarisurgeUtok;
                cout << "Polarisurge utoci se silou " << polarisurgeUtok << "!" << endl;
            }
        }
        else if ((magnetronHP > 0 || polarisurgeHP > 0) && !branim && !uhyb) {
            int kamen = 100 + rand() % 51;
            zivoty -= kamen;
            cout << "Boss na tebe hazí kamen (-" << kamen << " HP)!" << endl;
        }

        if (zivoty < 0) zivoty = 0;
    }

    if (zivoty > 0) {
        cout << "\nGratulace! Porazil jsi oba bosse!" << endl;
        zlato += 5000;
        cout << "Ziskavas 5000 zlatych!" << endl;
    } else {
        cout << "\nBohuzel, prohral jsi..." << endl;
        mec = 1;
        stit = 1;
        zlato = zlato / 2;
    }
}

void Menu() {
    int volba;
    do {
        HlavniMenu();
        cin >> volba;

        switch (volba) {
            case 1:
                Obchod();
                break;
            case 2:
                NahodnyBoj();
                break;
            case 3:
                BojSBossem();
                break;
            case 4:
                Inventar();
                break;
            case 5:
                Nevestinec();
                break;
            case 6:
                cout << "Ukoncil jsi hru.Dik za hraní." << endl;
                break;
            default:
                cout << "Neplatna volba!" << endl;
        }
    } while (volba != 6 && zivoty > 0);
}

int main() {
    srand(time(0));
    Intro();
    Menu();
    return 0;
}
