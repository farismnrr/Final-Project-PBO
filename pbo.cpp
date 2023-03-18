#include <iostream>
#include <string>
#define PIN_CODE 12345
using namespace std;

class Account {
private:
    int saldo = 500000;

public:
    int getSaldo() {
        return saldo;
    }

    void tarikTunai(int jumlah) {
        if (jumlah > saldo) {
            cout << "Maaf, saldo Anda tidak mencukupi." << endl << endl;
        } else {
            saldo -= jumlah;
            cout << "Silakan ambil uang Anda." << endl;
            cout << "Sisa saldo Anda: Rp " << saldo << endl << endl;
        }
    }

    void setorTunai(int jumlah) {
        saldo += jumlah;
        cout << "Uang berhasil disetor." << endl;
        cout << "Saldo Anda saat ini: Rp " << saldo << endl << endl;
    }
};

class ATM {
private:
    int menu, pin, pinCheck = 0;
    bool logged = false;
    Account account;

public:
    void login() {
        cout << "KELOMPOK 1: \n";
        cout << "Faris Munir Mahdi   | 21081010064\n";
        cout << "Farrel Tiuraka V    | 21081010222\n";
        cout << "Daffa Tungga Wisesa | 21081010243\n";
        cout << "Raditya Lungguk S P | 21081010259\n";
        cout << "Achmad Robby        | \n\n";
        
        while (!logged) {
            cout << "=== ATM ===" << endl;
            cout << "Masukkan PIN Anda: ";
            cin >> pin;

            if (pin == PIN_CODE) {
                logged = true;
                cout << "Anda berhasil login." << endl << endl;
            } else {
                cout << "PIN salah!" << endl << endl;
                pinCheck++;

                if (pinCheck == 3) {
                    cout << "Anda sudah 3x salah PIN. Program akan berakhir." << endl;
                    exit(0);
                }
            }
        }
    }

    void run() {
        do {
            cout << "=== ATM ===" << endl;
            cout << "Pilih salah satu menu:" << endl;
            cout << "1. Cek Saldo" << endl;
            cout << "2. Tarik Tunai" << endl;
            cout << "3. Setor Tunai" << endl;
            cout << "4. Keluar" << endl;
            cout << "Masukkan pilihan: ";
            cin >> menu;

            switch (menu) {
                case 1:
                    cout << "Saldo Anda saat ini: Rp " << account.getSaldo() << endl << endl;
                    break;
                case 2:
                    int tarikTunai;
                    cout << "Masukkan jumlah uang yang akan ditarik: Rp ";
                    cin >> tarikTunai;
                    account.tarikTunai(tarikTunai);
                    break;
                case 3:
                    int setorTunai;
                    cout << "Masukkan jumlah uang yang akan disetor: Rp ";
                    cin >> setorTunai;
                    account.setorTunai(setorTunai);
                    break;
                case 4:
                    cout << "Terima kasih telah menggunakan ATM ini." << endl;
                    break;
                default:
                    cout << "Pilihan tidak tersedia." << endl << endl;
                    break;
            }
        } while (menu != 4);
    }
};

int main() {
    ATM atm;
    atm.login();
    atm.run();

    return 0;
}
