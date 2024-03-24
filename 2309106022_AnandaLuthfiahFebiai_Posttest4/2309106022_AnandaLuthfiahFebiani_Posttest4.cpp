#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 100

struct data2 {
    string nama;
    string jenis;
    string jumlah;
};  

data2 dataATK[MAX];
int pos = 0;

void Tampil() {
    if (pos > 0) {
        cout << "Data ATK/S Ditampilkan\n";
        for (int i = 0; i < pos; i++) {
            cout << i + 1 << ". Nama: " << dataATK[i].nama << ", Jenis: " << dataATK[i].jenis << ", Jumlah: " << dataATK[i].jumlah << endl;
        }
    } else {
        cout << "=== Data Masih Kosong ===\n";
    }
}

void Tambah() {
    if (pos >= MAX) {
        cout << "Gudang Data ATK/S Telah Penuh \n";
        return;
    }

        cin.ignore();
        cout << "Tambah Data ATK/S (Nama barang, Jenis barang, dan Jumlah barang) yang di inginkan(dipisahkan dengan koma ','): ";
        string datakan1;
        getline (cin, datakan1);
        size_t nemu = datakan1.find(',');
        if (nemu != string::npos) {
            dataATK[pos].nama = datakan1.substr(0, nemu);
            size_t nemu2 = datakan1.find(',', nemu + 1);
            if (nemu2 != string::npos) {
                dataATK[pos].jenis = datakan1.substr(nemu + 1, nemu2 - nemu - 1);
                dataATK[pos].jumlah = datakan1.substr(nemu2 + 1);
                    pos++;
                } else {
                    cout << "Format Data ATK/S Invalid \n";
                }
            } else {
                cout << "Gudang Data ATK/S Telah Penuh \n";
            } 
            Tampil();
}
        
void Ubah() {
    Tampil();
    cout << "Ubah Data Ke: ";
    int y;
    cin >> y;
    if (y > 0 && y <= pos) {
        cin.ignore();
        cout << "Masukkan Data Nama, Jenis, dan Jumlah ATK/S yang Baru(dipisahkan dengan koma','): ";
        string datakan1;
        getline(cin, datakan1);
        size_t nemu = datakan1.find(',');
        if (nemu != string::npos) {
            dataATK[y - 1].nama = datakan1.substr(0, nemu);
            size_t nemu2 = datakan1.find(',', nemu + 1);
            if (nemu2 != string::npos) {
                dataATK[y - 1].jenis = datakan1.substr(nemu + 1, nemu2 - nemu - 1);
                dataATK[y-1].jumlah = datakan1.substr(nemu2 + 1);
            } else {
                cout << "Format Data ATK/S Invalid \n";
                return;
            }
        } else {
            cout << "Format Data ATK/S Invalid \n";
            return;
        }
    } else {
        cout << "Nomor Pada Data ATK/S Invalid \n";
    }
    Tampil();
}

void Hapus() {
    Tampil();
    cout << "Hapus Data ke: ";
    int x;
    cin >> x;
    if (x > 0 && x <= pos) {
        for (int i = x; i < pos; i++) {
            dataATK[i - 1] = dataATK[i];
        }
        pos--;
    }
    Tampil();
}

void Cari() {
    if (pos > 0) {
        cin.ignore();
        string pencarian;
        cout << "Masukkan Kata Kunci Data ATK/S Pencarian: ";
        getline(cin, pencarian);
        bool ketemu = false;

        cout << "Hasil pencarian untuk \"" << pencarian << "\": \n";
        for (int i = 0; i < pos; i++) {
            if (dataATK[i].nama.find(pencarian) != string::npos || 
                dataATK[i].jenis.find(pencarian) != string::npos ||
                dataATK[i].jumlah.find(pencarian) != string::npos) {
                cout << i + 1 << ". " << dataATK[i].nama << ", " << dataATK[i].jenis << ", " << dataATK[i].jumlah << endl;
                ketemu = true;
            }
        }

        if(!ketemu) {
            cout << "Data ATK/S tidak ditemukan, Silahkan coba lagi \n";
        }
    } else {
        cout << "Data ATK/S masih kosong\n";
    }
}

void Urut() {
    Tampil();
    if (pos > 1) {
    for (int i = 0; i < pos - 1 ; i++) {
        for (int j = 0; j < pos - i - 1; j++) {
            if (dataATK[j].nama > dataATK[j + 1].nama) {
                data2 ngurut = dataATK[j];
                dataATK[j] = dataATK[j + 1];
                dataATK[j + 1] = ngurut;
                }
            }
        } 
        cout << "Data ATK/S Telah Diurutkan Berdasarkan Nama: \n";
        Tampil();
    } else {
        cout << "Data ATK/S yang Diurutkan Tidak Cukup \n";
    }
}

int Hitungjmlkar(int index) {
    if (index < 0) {
        return 0;
    } else {
        return dataATK[index].nama.length() + dataATK[index].jenis.length() + (dataATK[index].jumlah).length() + Hitungjmlkar(index - 1);
    }
}

void JmlKarakData() {
    cout << "Total jumlah karakter dari data ATK/S: " << Hitungjmlkar(pos - 1) << endl;
}

bool Login() {
    string Username, Password;
    cout << "=== Login ===\n";
    cout << "Username: ";
    getline(cin, Username);
    cout << "Password: ";
    getline(cin, Password);
    return Username == "nanda" && Password == "2309106022";
}

int main() {
    int percobaan = 0;
    while (percobaan < 3 && !Login()) {
        cout << "Login gagal. Kesempatan mencoba: " << 2 - percobaan << " kali\n";
        percobaan++;
    }

    if (percobaan == 3) {
        cout << "Percobaan Login telah melebihi batas, percobaan berhenti\n";
        return 0;
    }

    int pilihan;
    do {
        cout << "\n=== GUDANG PENDATAAN ATK/S ===\n"
             << "1. Tambah Data ATK/S\n"
             << "2. Ubah Data ATK/S\n"
             << "3. Hapus Data ATK/S\n"
             << "4. Tampilkan Data ATK/S\n"
             << "5. Cari Data ATK/S\n"
             << "6. Urut Data ATK/S\n"
             << "7. Jumlah Karakter Data ATK/S\n"
             << "8. Keluar\n"
             << "Pilih menu yang tertera diatas (1/2/3/4/5/6/7/8): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: 
                Tambah(); 
                break;
            case 2: 
                Ubah(); 
                break;
            case 3: 
                Hapus(); 
                break;
            case 4: 
                Tampil(); 
                break;
            case 5:
                Cari();
                break;
            case 6:
                Urut();
                break;
            case 7:
                JmlKarakData();
                break;
            case 8: 
                cout << "Terima kasih telah mendata program ATK/S\n"; 
                return 0;
            default: 
                cout << "Pilihan Invalid\n";
        }
    } while (true);

    return 0;
}
