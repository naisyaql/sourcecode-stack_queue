#include <iostream>
#include <string>

using namespace std;

// Class untuk pesanan
class Pesanan {
public:
    int no_antrian;
    string nama_pelanggan;
    int harga_total;
    string cara_pembayaran;
    Pesanan *berikutnya;
};

// Class untuk linked list queue
class Queue {
private:
    Pesanan *depan, *belakang;

public:
    Queue() {
        depan = NULL;
        belakang = NULL;
    }

    // Fungsi untuk menambahkan pesanan ke antrian
    void enqueue(int no_antrian, string nama_pelanggan, int harga_total, string cara_pembayaran) {
        Pesanan *temp = new Pesanan;
        temp->no_antrian = no_antrian;
        temp->nama_pelanggan = nama_pelanggan;
        temp->harga_total = harga_total;
        temp->cara_pembayaran = cara_pembayaran;
        temp->berikutnya = NULL;
        if (depan == NULL) {
            depan = temp;
            belakang = temp;
        } else {
            belakang->berikutnya = temp;
            belakang = temp;
        }
        cout << " " << endl;
        cout << "Pesanan berhasil ditambahkan" << endl;
    }

    // Fungsi untuk menghapus pesanan dari antrian
    void dequeue() {
        if (depan == NULL) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Pesanan *temp = depan;
        depan = depan->berikutnya;
        cout << "Panggilan untuk no antrian " << temp->no_antrian << " dengan nama " << temp->nama_pelanggan << ", silahkan ambil pesanan. Selamat Anda mendapat takjil gratis sebuah Dimsum Nanas" << endl;
        cout << "Nama Pelanggan : " << temp->nama_pelanggan << endl;
        cout << "Jumlah Harga : " << temp->harga_total << endl;
        cout << "Cara Pembayaran : " << temp->cara_pembayaran << endl;
        cout << endl;
        delete temp;
    }

    // Fungsi untuk menampilkan daftar antrian
    void display() {
        if (depan == NULL) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Pesanan *temp = depan;
        cout << "Daftar Antrian:" << endl;
        while (temp != NULL) {
            cout << "No Antrian : " << temp->no_antrian << ", Nama Pelanggan : " << temp->nama_pelanggan << ", Harga Total : " << temp->harga_total << ", Cara Pembayaran : " << temp->cara_pembayaran << endl;
            temp = temp->berikutnya;
        }
    }
};

// Class untuk linked list stack
class Stack {
    private:
        struct Takjil {
            string nama_takjil;
            Takjil *next;
        };
        Takjil *top;

    public:
        Stack() {
            top = NULL;
        }

        // Fungsi untuk menambahkan takjil ke stack
        void push(string nama_takjil) {
            Takjil *temp = new Takjil;
            temp->nama_takjil = nama_takjil;
            temp->next = top;
            top = temp;
            cout << "Takjil berhasil ditambahkan" << endl;
        }

        // Fungsi untuk menghapus takjil dari stack
        void pop() {
            if (top == NULL) {
                cout << "Mohon maaf takjil sedang kosong" << endl;
                return;
            }

            else {
                if (top->next == NULL){
                    top = NULL;
                }
            }
            Takjil *temp = top;
            top = top->next;
            cout << "Selamat Anda mendapat takjil gratis sebuah "
                 << temp->nama_takjil << endl;
            delete temp;

            return;
        }

        // Fungsi untuk mengecek apakah stack kosong atau tidak
        bool is_empty() {
            return top == NULL;
        }
};

// Deklarasi objek antrian dan stack
int main() {
    Queue pesanan_queue;
    Stack takjil_stack;
    int pilihan;

    while (true) {
        cout << " " << endl;
        cout << "Menu : " << endl;
        cout << "1. Tambahkan Antrian" << endl;
        cout << "2. Tambahkan Takjil" << endl; 
        cout << "3. Selesaikan Pesanan" << endl; 
        cout << "4. Tampilkan daftar antrian" << endl; 
        cout << "5. Keluar" <<endl;
        cout << " " << endl;
        cout << "Masukkan pilihan : "; 
        cin >> pilihan;

    switch (pilihan) {
        case 1: {
            int no_antrian, harga_total;
            string nama_pelanggan, cara_pembayaran;

            cout << "Masukkan no antrian: ";
            cin >> no_antrian;
            cout << "Masukkan nama pelanggan: ";
            cin >> nama_pelanggan;
            cout << "Masukkan harga total: ";
            cin >> harga_total;
            cout << "Masukkan cara pembayaran: ";
            cin >> cara_pembayaran;

            pesanan_queue.enqueue(no_antrian, nama_pelanggan, harga_total, cara_pembayaran);
            break;
        }
        case 2: {
            string nama_takjil;
            int jumlah_takjil;

            cout << "Masukkan nama takjil : ";
            cin >> nama_takjil;
            cout << "Masukkan jumlah takjil : ";
            cin >> jumlah_takjil;

            for (int i = 0; i < jumlah_takjil; i++) {
                takjil_stack.push(nama_takjil);
            }

            cout << jumlah_takjil << " takjil berhasil ditambahkan" << endl;
            break;
        }
        case 3: {
            pesanan_queue.dequeue();
            break;
        }
        case 4: {
            pesanan_queue.display();
            break;
        }
        case 5: {
            return 0;
        }
        default: {
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    }
}

return 0;
};