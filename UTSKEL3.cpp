#include <iostream>
using namespace std;

struct Tiket {
    int id;
    string nama;
    string kategori;
    int harga;
    string status;
};

class SistemTiket {
private:
    Tiket data[100];
    int jumlah = 0;
    int nextId = 1;

public:
    void tambah() {
        if (jumlah >= 100) {
            cout << "Data penuh!\n";
            return;
        }

        Tiket t;
        t.id = nextId++;
        t.status = "Aktif";

        cout << "\n==PEMESANAN TIKET==\nNama: ";
        cin.ignore();
        getline(cin, t.nama);

        int p;
        cout << "Kategori Tiket:\n1. Regular = 250.000\n2. VIP   = 500.000\n3. VVIP  = 750.000\nPilih: ";
        cin >> p;

        if (p == 1) { t.kategori = "Regular"; t.harga = 250000; }
        else if (p == 2) { t.kategori = "VIP"; t.harga = 500000; }
        else if (p == 3) { t.kategori = "VVIP"; t.harga = 750000; }
             else { cout << "Pilihan Tidak Valid\n"; return;}
            
        data[jumlah++] = t;
        cout << "Berhasil tambah tiket.\n";
    }

    void tampil() {
        if (jumlah == 0) {
            cout << "Belum ada data.\n";
            return;
        }

        for (int i = 0; i < jumlah; i++) {
            cout << "\nID       : " << data[i].id << endl;
            cout << "Nama     : " << data[i].nama << endl;
            cout << "Kategori : " << data[i].kategori << endl;
            cout << "Harga    : " << data[i].harga << endl;
            cout << "Status   : " << data[i].status << endl;
        }
    }

    void hapus() {
        int id;
        cout << "\n==HAPUS TIKET==" << endl;
        cout << "ID yang dihapus: ";
        cin >> id;

        for (int i = 0; i < jumlah; i++) {
            if (data[i].id == id) {
                for (int j = i; j < jumlah - 1; j++) {
                    data[j] = data[j + 1];
                }
                jumlah--;
                cout << "Data dihapus.\n";
                return;
            }
        }
        cout << "ID tidak ada.\n";
    }

    void update() {
        int id;
        cout << "\n==UPDATE TIKET==" << endl;
        cout << "ID yang diupdate: ";
        cin >> id;

        for (int i = 0; i < jumlah; i++) {
            if (data[i].id == id) {
                cout << "Nama baru: ";
                cin.ignore();
                getline(cin, data[i].nama);

                int p;
                cout << "\nKategori Tiket:\n1. Regular\n2. VIP\n3. VVIP\nPilih: ";
                cin >> p;

                if (p == 1) { data[i].kategori = "Regular"; data[i].harga = 250000; }
                else if (p == 2) { data[i].kategori = "VIP"; data[i].harga = 500000; }
                else if (p == 3) { data[i].kategori = "VVIP"; data[i].harga = 750000; }
                     else { cout << "Pemilihan Kategori tidak Valid\n"; return;}
                
                cout << "Status (Aktif/Dibatalkan): ";
                cin.ignore();
                getline(cin, data[i].status);

                cout << "Data berhasil diupdate.\n";
                return;
            }
        }
        cout << "ID tidak ditemukan.\n";
    }

    void sorting() {
    int pilih;
    cout << "\n===Sorting Tiket===\n1. Harga (Mahal-Murah)\n2. Nama(A-Z)\nPilih: ";
    cin >> pilih;

    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {

            switch(pilih) {
                case 1:
                    if (data[j].harga < data[j+1].harga)
                        swap(data[j], data[j+1]);
                    break;

                case 2:
                    if (data[j].nama > data[j+1].nama)
                        swap(data[j], data[j+1]);
                    break;
            }
        }
    }

    cout << "\nData setelah sorting:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << data[i].id << " | "
             << data[i].nama << " | "
             << data[i].kategori << " | "
             << data[i].harga << " | "
             << data[i].status << endl;
    }
}

    void statistik() {
        int reg = 0, vip = 0, vvip = 0;
        int aktif = 0, batal = 0;
        int total = 0;

        for (int i = 0; i < jumlah; i++) {
            if (data[i].kategori == "Regular") reg++;
            else if (data[i].kategori == "VIP") vip++;
            else vvip++;

            if (data[i].status == "Aktif") {
                aktif++;
                total += data[i].harga;
            } else {
                batal++;
            }
        }

        cout << "\nJumlah Tiket: " << jumlah << endl;
        cout << "Regular: " << reg << endl;
        cout << "VIP: " << vip << endl;
        cout << "VVIP: " << vvip << endl;
        cout << "Aktif: " << aktif << endl;
        cout << "Dibatalkan: " << batal << endl;
        cout << "Pendapatan: " << total << endl;
    }
};

int main() {
    SistemTiket s;
    int pilih;

    do {
        cout << "\n========SELAMAT DATANG=========\n=SISTEM PEMESANAN TIKET KONSER=\n1. Tambah Tiket\n2. Hapus Tiket\n3. Update Tiket\n4. Tampil Tiket\n5. Sorting Tiket\n6. Statistik\n7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) s.tambah();
        else if (pilih == 2) s.hapus();
        else if (pilih == 3) s.update();
        else if (pilih == 4) s.tampil();
        else if (pilih == 5) s.sorting();
        else if (pilih == 6) s.statistik();

    } while (pilih != 7);

    return 0;
}
