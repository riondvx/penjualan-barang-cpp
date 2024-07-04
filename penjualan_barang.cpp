#include <iomanip>
#include <iostream>
#include <string>

struct Barang {
  std::string nama;
  int harga;
  int jumlah;
  int subtotal;
};

int main() {
  Barang daftar_barang[100];
  int ibarang = 0;
  int total_belanja = 0;
  std::string tambah_barang = "y";

  std::cout << "========================\n"
            << "        TOKO ABC        \n"
            << "========================\n";

  while (tambah_barang == "y" || tambah_barang == "Y") {
    std::cout << "-- Barang ke-" << (ibarang + 1) << " --\n";
    std::string nama;
    int harga;
    int jumlah;
    int subtotal;

    std::cout << "Nama   : ";
    getline(std::cin, nama);
    std::cout << "Harga  : ";
    std::cin >> harga;
    std::cin.ignore();
    std::cout << "Jumlah : ";
    std::cin >> jumlah;
    std::cin.ignore();

    subtotal = harga * jumlah;
    total_belanja += subtotal;

    daftar_barang[ibarang].nama = nama;
    daftar_barang[ibarang].harga = harga;
    daftar_barang[ibarang].jumlah = jumlah;
    daftar_barang[ibarang].subtotal = subtotal;

    std::cout << "Tambahkan barang lain ? (y/n) : ";
    getline(std::cin, tambah_barang);

    ibarang++;
  }

  std::cout << "+------------------------------------------------------+\n"
            << "|  No  |  Nama Barang  |  Harga  | Jumlah |  Subtotal  |\n"
            << "+------------------------------------------------------+\n";

  for (int i = 0; i < ibarang; i++) {
    std::cout << "| " << std::setw(4) << std::right << (i + 1) << " | "
              << std::setw(13) << std::left << daftar_barang[i].nama << " | "
              << std::setw(7) << std::right << daftar_barang[i].harga << " | "
              << std::setw(6) << std::right << daftar_barang[i].jumlah << " | "
              << std::setw(10) << std::right << daftar_barang[i].subtotal
              << " |\n";
  }

  std::cout << "+------------------------------------------------------+\n";
  std::cout << "Total Belanja : " << total_belanja << "\n";

  int jumlah_bayar, kembalian;
  std::cout << "Jumlah Bayar  : ";
  std::cin >> jumlah_bayar;
  kembalian = jumlah_bayar - total_belanja;
  std::cout << "Kembalian     : " << kembalian << "\n";

  return 0;
}
