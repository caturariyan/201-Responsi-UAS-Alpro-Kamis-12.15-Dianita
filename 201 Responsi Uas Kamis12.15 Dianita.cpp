#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class analisisPenjualan {
private:
	string kode[100], nama[100];
	int jumlah[100], harga[100];
	int n = 0;
	
public:
	void bukaFile(string namaFile) {
		ifstream file (namaFile.c_str());
		if (!file.is_open()) {
			cout << "Gagal membuka file" << endl;
			return;
		}
		
		while (n < 100 && getline(file, kode[n], ',')) {
			getline(file, nama[n], ',');
			file >> jumlah[n];
			file.ignore();
			file >> harga[n];
			file.ignore();
			n++;
		}
		file.close();
	}
	
	void tampilData() {
		
		cout << left << setw(10) << "Kode" << setw(20) << "Nama" << setw(10) << "Jumlah" << setw(10) << "Harga" << "Total" << endl;
		for (int i = 0; i < n; i++) {
			cout << left << setw(10) << kode[i] << setw(20) << nama[i] << setw(10) << jumlah[i] << setw(10) << harga[i] << jumlah[i] * harga[i] << endl;
		}
		cout << "---------------------------------------------------------\n";
	}
	
	void cariKode(string kd) {
		for (int i = 0; i < n; i++) {
			if (kode[i] == kd) {
				cout << "\n[!] Data Barang Ditemukan \n";
				cout << "Kode Barang   : " << kode[i] << endl;
				cout << "Nama Barang   : " << nama[i] << endl;
				cout << "Jumlah Barang : " << jumlah[i] << endl;
				cout << "Harga Barang  : " << harga[i] << endl;
				cout << "Total Penjualan : " << jumlah[i] * harga[i] << endl;
				return;
			}
		}
		cout << "\n[!] Data Barang Tidak Ditemukan \n";
	}
	
	void cariTermurah() {
		int murah = 0;
		for (int i = 0; i < n; i++) {
			if (harga[i] < harga[murah]) {
				murah = i;
			}
		}
		
		cout << "\n[!] Data Barang Termurah Ditemukan \n";
		cout << "Kode Barang   : " << kode[murah] << endl;
		cout << "Nama Barang   : " << nama[murah] << endl;
		cout << "Jumlah Barang : " << jumlah[murah] << endl;
		cout << "Harga Barang  : " << harga[murah] << endl;
		cout << "Total Penjualan : " << jumlah[murah] * harga[murah] << endl;
	}
	
	urutTermahal() {
		cout << "\n---------------------------------------------------------\n";
		cout << "                Data Diurutkan dari Termahal\n";
		cout << "---------------------------------------------------------\n";
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < n-i-1; j++) {
				if (harga[j] < harga[j+1]) {
					swap(kode[j], kode[j+1]);
					swap(nama[j], nama[j+1]);
					swap(jumlah[j], jumlah[j+1]);
					swap(harga[j], harga[j+1]);
				}
			}
		}
		tampilData();
	}
	
	urutTermurah() {
		cout << "\n---------------------------------------------------------\n";
		cout << "                Data Diurutkan dari Termurah\n";
		cout << "---------------------------------------------------------\n";
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < n-i-1; j++) {
				if (harga[j] > harga[j+1]) {
					swap(kode[j], kode[j+1]);
					swap(nama[j], nama[j+1]);
					swap(jumlah[j], jumlah[j+1]);
					swap(harga[j], harga[j+1]);
				}
			}
		}
		tampilData();
	}
	
	void simpanUrut(string namaFile) {
		ofstream file (namaFile.c_str());
		if (!file.is_open()) {
			cout << "Gagal membuka file" << endl;
			return;
		}
		
		file << "\n---------------------------------------------------------\n";
		file << "                   Hasil Sorting Data\n";
		file << "---------------------------------------------------------\n";
		file << left << setw(10) << "Kode" << setw(20) << "Nama" << setw(10) << "Jumlah" << setw(10) << "Harga" << endl;
		for (int i = 0; i < n; i++) {
			file << left << setw(10) << kode[i] << setw(20) << nama[i] << setw(10) << jumlah[i] << setw(10) << harga[i] << endl;
		}
		file << "---------------------------------------------------------\n";
		file.close();
		
		cout << "\n[!] Hasil Sorting Berhasil Disimpan ke " << namaFile << endl;
	}
	
	void totalPendapatan() {
		cout << "\n---------------------------------------------------------\n";
		cout << "                  Data Penjualan\n";
		cout << "---------------------------------------------------------\n";
		tampilData();
		
		int total = 0;
		for (int i = 0; i < n; i++) {
			total += jumlah[i] * harga[i];
		}
		
		cout << "[!]Total Pendapatan dari Semua Transaksi : Rp " << total << endl;
	}
	
	void simpanAnalisis(string namaFile) {
		ofstream file (namaFile.c_str());
		if (!file.is_open()) {
			cout << "Gagal membuka file" << endl;
			return;
		}
		
		file << "\n---------------------------------------------------------\n";
		file << "                 Hasil Analisis Penjualan\n";
		file << "---------------------------------------------------------\n";
		file << left << setw(10) << "Kode" << setw(20) << "Nama" << setw(10) << "Jumlah" << setw(10) << "Harga" << "Total" << endl;
		for (int i = 0; i < n; i++) {
			file << left << setw(10) << kode[i] << setw(20) << nama[i] << setw(10) << jumlah[i] << setw(10) << harga[i] << jumlah[i] * harga[i] << endl;
		}
		file << "---------------------------------------------------------\n";
		
		int total = 0;
		for (int i = 0; i < n; i++) {
			total += jumlah[i] * harga[i];
		}
		
		file << "[!]Total Pendapatan dari Semua Transaksi : Rp " << total << endl;
		file.close();
		
		cout << "\n[!] Hasil Analisis Penjualan Berhasil Disimpan ke " << namaFile << endl;
	}
};

int main() {
	analisisPenjualan ap;
	ap.bukaFile("penjualan.txt");
	
	int pilih;
	string kode;
	
	do {
		cout << "\n========================================================\n";
		cout << "         MENU ANALISIS PENJUALAN TOKO 201\n";
		cout << "========================================================\n";
		cout << "1. Lihat data penjualan\n";
		cout << "2. Cari barang berdasarkan kode\n";
		cout << "3. Cari barang berdasarkan harga termurah\n";
		cout << "4. Urutkan produk dari termahal ke termurah\n";
		cout << "5. Urutkan produk dari termurah ke termahal\n";
		cout << "6. Simpan hasil sorting ke file txt\n";
		cout << "7. Lihat total seluruh pendapatan\n";
		cout << "8. Simpan hasil analisis penjualan ke file txt\n";
		cout << "0. Keluar\n";
		cout << "---------------------------------------------------------\n";
		cout << "Pilih Menu : ";
		cin >> pilih;
		cout << "========================================================\n";
		
		switch(pilih) {
			case 1:
				cout << "\n---------------------------------------------------------\n";
				cout << "                  Data Penjualan\n";
				cout << "---------------------------------------------------------\n";
				ap.tampilData();
				break;
			case 2:
				cout << "\nMasukkan kode barang yg ingin dicari : ";
				cin >> kode;
				ap.cariKode(kode);
				break;
			case 3:
				ap.cariTermurah();
				break;
			case 4:
				ap.urutTermahal();
				break;
			case 5:
				ap.urutTermurah();
				break;
			case 6:
				ap.simpanUrut("hasil_sort_penjualan.txt");
				break;
			case 7:
				ap.totalPendapatan();
				break;
			case 8:
				ap.simpanAnalisis("hasil_analisis_penjualan.txt");
				break;
			case 0:
				cout << "Terima Kasih :)" << endl;
				break;
			default:
				cout << "Pilihan Anda Tidak Ada\n";
				break;
		} 
	} while (pilih != 0);
	
	return 0;
}

