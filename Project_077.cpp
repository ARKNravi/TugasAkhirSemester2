#include <iostream>
#include <fstream>
#include <iomanip>      
using namespace std;

char kembali;
string file;
int banyakdata;

typedef struct
{
	string nomorktp;
	string nama;
    string status;
	string golongandarah;
}datapenting;

void haldepan();
void menuatas();
void menubawah();
void menuutama();
void input(fstream &dataorang, int banyak_data);
void tampilkan(fstream &dataorang, int banyak_data);
void searching(fstream &dataorang, int banyak_data);
void sorting(fstream &dataorang, int banyak_data);
void transaksi(fstream &dataorang, int banyak_data);
void searchingtahap(fstream &dataorang, int banyak_data);
void swap(string *a, string *b);
int main()
{
    int banyak_data, pilih;
    fstream dataorang, jumlah;

    haldepan();

	do {
	system("CLS");
    menuatas();
	menuutama();
	cout << "\nMasukkan Pilihan  : ";
	cin >> pilih;
	if (pilih == 1){
		system("CLS");
		input(dataorang , banyak_data);
	}
	else if (pilih == 2) {
        system("CLS");
        tampilkan(dataorang, banyak_data);
    }
	else if (pilih == 3) {
		system("CLS");
		searching(dataorang, banyak_data);
	}
    else if (pilih == 4) {
        system("CLS");
        sorting(dataorang, banyak_data);
    }
    else if (pilih == 5) {
        system("CLS");
        transaksi(dataorang, banyak_data);
    }
	else if (pilih == 6) {
		exit(0);
	}
    menubawah();
	} while (kembali == 'y' || kembali == 'Y');   
}

void haldepan()
{
    cout << " =============================================================" << endl;
    cout << "|                                                             |" << endl;
    cout << "|                PROGRAM PENDATAAN MAHASISWA                  |" << endl;
    cout << "|                                                             |" << endl;
    cout << "| ----------------------------------------------------------- |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|     Universitas Pembangunan Nasional Veteran Yogyakarta     |" << endl;
    cout << "|                                                             |" << endl;
    cout << " =============================================================" << endl;
    cout << endl;
	system("PAUSE");
	system("CLS");
}
    
void menuatas()
{
    cout << " _____________________________________________________________" << endl;
    cout << "    Universitas Pembangunan Nasional Veteran Yogyakarta" << endl;
    cout << " =============================================================" << endl;
}

void menubawah()
{
    cout << endl;
    cout << "=============================================================" << endl;
    cout << " Kembali ke Menu Utama? (y/n) : "; cin >> kembali;
	system("CLS");
}

void menuutama()
{
	cout << "              MENU UTAMA PROGRAM PENDATAAN";
    cout << "\n ------------------------------------------------------------- \n";
	cout << "\n1. Input Data";
	cout << "\n2. Tampilkan Data";
	cout << "\n3. Searching Data";
    cout << "\n4. Sorting Data";
    cout << "\n5. Transaksi";
	cout << "\n6. EXIT";
}

void input(fstream &dataorang, int banyak_data)
{
    system("CLS");

	datapenting input[99];

	menuatas();
	cout <<"Masukkan Nama File   =";
    cin >>file;
    cout <<" Banyaknya Data      =";
    cin >> banyakdata;
        for (int i = 0; i < banyakdata; i++)
    {
       cin.ignore();
	cout << "        Nomer KTP       = ";
	getline(cin, input[i].nomorktp );
	cout << "        Nama            = ";
	getline(cin, input[i].nama);
    cout << "        Status          = ";
    getline(cin, input[i].status);
	cout << "        Golongan Darah   = ";
    getline(cin, input[i].golongandarah);
    banyak_data++;
    }
    
	
	
	dataorang.open(file, ios::out | ios::trunc);
	for (int i = 0; i < banyak_data; i++)
	{
		dataorang << input[i].nomorktp  << endl;
		dataorang << input[i].nama << endl;
        dataorang << input[i].status << endl;
		dataorang << input[i].golongandarah << endl;
	}
	dataorang.close();
	cout << "\nBerhasil ditambahkan.\n";
    
    
}

void searching(fstream &dataorang, int banyak_data)
{
int mid=0, low=0, high=0;
	system("CLS");

	datapenting searching[99];
    banyak_data=0;
	int pilihs,pilihse;
	bool found = false;
    int ubah;
	string cari;

    menuatas();
	cout <<"Masukkan Nama File   = ";
    cin >>file;
    system("CLS");
	dataorang.open(file);
    if (dataorang.is_open())
    {
        int k = banyak_data;
        while (!dataorang.fail())
        {
		getline(dataorang, searching[k].nomorktp );
		getline(dataorang, searching[k].nama);
		getline(dataorang, searching[k].status);
		getline(dataorang, searching[k].golongandarah);
        k++;
        }
        banyak_data = k - 1;
        dataorang.close();
        system("CLS");
    menuatas();
	cout <<"1. Sequential";
    cout <<"\n2. Binary";
    cout <<"\nMasukkan Pilihan	: ";
    cin >>pilihs;
    if (pilihs == 1)
    {
       menuatas();
	cout << "             MENCARI DATA DENGAN SEQUENTIAL" << endl;
	cout << " =============================================================" << endl;
	cout << endl;
    cout <<"1. NIK";
    cout <<"\n2.Nama";
    cout <<"\n3.Status";
    cout <<"\n4.Golongan Darah";
    cout <<"\nMasukkan Pilihan	: ";
    cin >>pilihse;
	cin.ignore();
    if (pilihse == 1){
    cout << "Cari NIK = ";
	getline(cin, cari);
    for (int i = 0; i < banyak_data; i++)
    {
        if(searching[i].nomorktp  == cari){
            ubah = i;
            found = true;
        }
    }

	if(!found){
        cout << "\nData tidak ditemukan!";
		cout << endl;
    } 
	else {
		cout << "\n INFORMASI DATA MAHASISWA" << endl;
		cout << " -------------------------------------------------------------" << endl;
				cout << "NIK             = " << searching[ubah].nomorktp  << endl;
            	cout << "Nama            = " << searching[ubah].nama << endl;
				cout << "Status          = " << searching[ubah].status << endl;
				cout << "Golongan Darah  = " << searching[ubah].golongandarah << endl;	
    }
	cout << endl;
    }
    else if (pilihse == 2) {
    cout << "Cari Nama	= ";
	getline(cin, cari);
    for (int i = 0; i < banyak_data; i++)
    {
        if(searching[i].nama  == cari){
            ubah = i;
            found = true;
        }
    }

	if(!found){
        cout << "\nData tidak ditemukan!";
		cout << endl;
    } 
	else {
        cout << "\n INFORMASI DATA MAHASISWA" << endl;
		cout << " -------------------------------------------------------------" << endl;
			    cout << "NIK             = " << searching[ubah].nomorktp  << endl;
                cout << "Nama            = " << searching[ubah].nama << endl;
			    cout << "Status          = " << searching[ubah].status << endl;
			    cout << "Golongan Darah  = " << searching[ubah].golongandarah << endl;		
    }
	cout << endl;
    }
    else if (pilihse == 3){
        cout << "Cari Status = ";
	getline(cin, cari);
    for (int i = 0; i < banyak_data; i++)
    {
        if(searching[i].status  == cari){
            ubah = i;
            found = true;
        }
    }

	if(!found){
        cout << "\nData tidak ditemukan!";
		cout << endl;
    } 
	else {
        cout << "\n INFORMASI DATA MAHASISWA" << endl;
		cout << " -------------------------------------------------------------" << endl;
			    cout << "NIK             = " << searching[ubah].nomorktp  << endl;
                cout << "Nama            = " << searching[ubah].nama << endl;
			    cout << "Status          = " << searching[ubah].status << endl;
			    cout << "Golongan Darah  = " << searching[ubah].golongandarah << endl;		
    }
	cout << endl;
    }
    if (pilihse == 4) {
        cout << "Cari Golongan Darah = ";
	getline(cin, cari);
    for (int i = 0; i < banyak_data; i++)
    {
        if(searching[i].golongandarah  == cari){
            ubah = i;
            found = true;
        }
    }

	if(!found){
        cout << "\nData tidak ditemukan!";
		cout << endl;
    } 
	else {
        cout << "\n INFORMASI DATA MAHASISWA" << endl;
		cout << " -------------------------------------------------------------" << endl;
			    cout << "NIK             = " << searching[ubah].nomorktp  << endl;
                cout << "Nama            = " << searching[ubah].nama << endl;
			    cout << "Status          = " << searching[ubah].status << endl;
			    cout << "Golongan Darah  = " << searching[ubah].golongandarah << endl;		
    }
	cout << endl;
    }
	
    }
    else if (pilihs == 2){
        menuatas();
	cout << "             MENCARI DATA DENGAN BINARY" << endl;
	cout << " =============================================================" << endl;
	cout << endl;
    cout <<"1. NIK";
    cout <<"\n2.Nama";
    cout <<"\n3.Status";
    cout <<"\n4.Golongan Darah";
    cout <<"\nMasukkan Pilihan	: ";
    cin >>pilihse;
	cin.ignore();
    if (pilihse == 1){
        for (int i = 0; i < banyak_data; i++)
        {
            for (int j = 0; j < banyak_data - i; j++)
            {
                if (searching[j].nomorktp > searching[j+1].nomorktp)
                {
                    string temp1 = searching[j].nomorktp;
                    searching[j].nomorktp = searching[j+1].nomorktp;
                    searching[j+1].nomorktp = temp1;
                    string temp2 = searching[j].status;
                    searching[j].status = searching[j+1].status;
                    searching[j+1].status = temp2;
                    string temp3 = searching[j].golongandarah;
                    searching[j].golongandarah = searching[j+1].golongandarah;
                    searching[j+1].golongandarah = temp3;
                    string bil = searching[j].nama;
                    searching[j].nama = searching[j+1].nama;
                    searching[j+1].nama = bil;
                }
            }
        }
        
        cout << "Masukan Nomor KTP \t= ";
        cin>> cari;
        do
        {
            mid = (low + high) / 2;
            if (cari ==searching[mid].nomorktp )
            {
                found = true;
                low += banyak_data;
            }
            else if (searching[mid].nomorktp < cari)
            {
                low = mid + 1;
            }
            else if (searching[mid].nomorktp > cari)
            {
                high = mid - 1;
            }
        } while (found == false && low <= high);

        if (found == true)
        {
            cout << "\n\tNomor KTP \t= " << searching[mid].nomorktp << endl;
            cout << "\tNama \t\t= " << searching[mid].nama << endl;
            cout << "\tstatus \t\t= " << searching[mid].status << endl;
            cout << "\tGolongan Darah  = " << searching[mid].golongandarah << endl;
        }
        else
        {

            cout << "\nData tidak ditemukan" << endl;
        }
    }
    else if (pilihse == 2) {
        for (int i = 0; i < banyak_data - 1; i++)
        {
            for (int j = 0; j < banyak_data - 1 - i; j++)
            {
                if (searching[j].nama > searching[j+1].nama)
                {
                    string temp1 = searching[j].nomorktp;
                    searching[j].nomorktp = searching[j+1].nomorktp;
                    searching[j+1].nomorktp = temp1;
                    string temp2 = searching[j].status;
                    searching[j].status = searching[j+1].status;
                    searching[j+1].status = temp2;
                    string temp3 = searching[j].golongandarah;
                    searching[j].golongandarah = searching[j+1].golongandarah;
                    searching[j+1].golongandarah = temp3;
                    string bil = searching[j].nama;
                    searching[j].nama = searching[j+1].nama;
                    searching[j+1].nama = bil;
                }
            }
        }
        cout << "Masukan Nama \t= ";
        cin >> cari;
        do
        {
            mid = (low + high) / 2;
            if (searching[mid].nama == cari)
            {
                found = true;
                low += banyak_data;
            }
            else if (searching[mid].nama < cari)
            {
                low = mid + 1;
            }
            else if (searching[mid].nama > cari)
            {
                high = mid - 1;
            }
        } while (low <= high && found == false);

        if (found == true)
        {
            cout << "\n\tNomor KTP \t= " << searching[mid].nomorktp << endl;
            cout << "\tNama \t\t= " << searching[mid].nama << endl;
            cout << "\tstatus \t\t= " << searching[mid].status << endl;
            cout << "\tGolongan Darah  = " << searching[mid].golongandarah << endl;
        }
        else
        {
            cout << "\nData tidak ditemukan" << endl;
        }
    }
    else if (pilihse == 3){
            for (int i = 0; i < banyak_data - 1; i++)
        {
            for (int j = 0; j < banyak_data - 1 - i; j++)
            {
                if (searching[j].status > searching[j+1].status)
                {
                    // sorting nama
                    string temp1 = searching[j].nomorktp;
                    searching[j].nomorktp = searching[j+1].nomorktp;
                    searching[j+1].nomorktp = temp1;
                    string temp2 = searching[j].status;
                    searching[j].status = searching[j+1].status;
                    searching[j+1].status = temp2;
                    string temp3 = searching[j].golongandarah;
                    searching[j].golongandarah = searching[j+1].golongandarah;
                    searching[j+1].golongandarah = temp3;
                    string bil = searching[j].nama;
                    searching[j].nama = searching[j+1].nama;
                    searching[j+1].nama = bil;
                }
            }
        }
        cout << "Masukan Status \t= ";
        cin >> cari;
        do
        {
            mid = (low + high) / 2;
            if (searching[mid].status == cari)
            {
                found = true;
                low += banyak_data;
            }
            else if (searching[mid].status < cari)
            {
                low = mid + 1;
            }
            else if (searching[mid].status > cari)
            {
                high = mid - 1;
            }
        } while (low <= high && found == false);

        if (found == true)
        {
            cout << "\n\tNomor KTP \t= " << searching[mid].nomorktp << endl;
            cout << "\tNama \t\t= " << searching[mid].nama << endl;
            cout << "\tstatus \t\t= " << searching[mid].status << endl;
            cout << "\tGolongan Darah  = " << searching[mid].golongandarah << endl;
        }
        else
        {
            cout << "\nData tidak ditemukan" << endl;
        }
    }
    if (pilihse == 4) {
            for (int i = 0; i < banyak_data - 1; i++)
        {
            for (int j = 0; j < banyak_data - 1 - i; j++)
            {
                if (searching[j].golongandarah > searching[j+1].golongandarah)
                {
                    // sorting nama
                    string temp1 = searching[j].nomorktp;
                    searching[j].nomorktp = searching[j+1].nomorktp;
                    searching[j+1].nomorktp = temp1;
                    string temp2 = searching[j].status;
                    searching[j].status = searching[j+1].status;
                    searching[j+1].status = temp2;
                    string temp3 = searching[j].golongandarah;
                    searching[j].golongandarah = searching[j+1].golongandarah;
                    searching[j+1].golongandarah = temp3;
                    string bil = searching[j].nama;
                    searching[j].nama = searching[j+1].nama;
                    searching[j+1].nama = bil;
                }
            }
        }
        cout << "Masukan Nomor KTP \t= ";
        cin >> cari;
        do
        {
            mid = (low + high) / 2;
            if (searching[mid].golongandarah == cari)
            {
                found = true;
                low += banyak_data;
            }
            else if (searching[mid].golongandarah < cari)
            {
                low = mid + 1;
            }
            else if (searching[mid].golongandarah > cari)
            {
                high = mid - 1;
            }
        } while (low <= high && found == false);

        if (found == true)
        {
            cout << "\n\tNomor KTP \t= " << searching[mid].nomorktp << endl;
            cout << "\tNama \t\t= " << searching[mid].nama << endl;
            cout << "\tstatus \t\t= " << searching[mid].status << endl;
            cout << "\tGolongan Darah  = " << searching[mid].golongandarah << endl;
        }
        else
        {
            cout << "\nData tidak ditemukan" << endl;
        }
    }
	
    }
        } 
        
    
    
      else
    {
        cout<<"file eror : file tidak berhasil dibaca, eror salah nama!"<<endl;
        system("PAUSE");
    }
    
}

void tampilkan(fstream &dataorang, int banyak_data)
{
	datapenting tampilkan[99];
    banyak_data=0;
    menuatas();
	cout <<"Masukkan Nama File   = ";
    cin >>file;

	dataorang.open(file);
    if (dataorang.is_open())
    {
        int i = banyak_data;
        while (!dataorang.fail())
        {
		getline(dataorang, tampilkan[i].nomorktp );
		getline(dataorang, tampilkan[i].nama);
		getline(dataorang, tampilkan[i].status);
		getline(dataorang, tampilkan[i].golongandarah);
        i++;
        }
        banyak_data = i - 1;
        cout << setfill('=') << setw(76) << '=' << endl;
        cout << setfill(' ') << setw(16) << left << " Nomer KTP" << setw(30) << left << "Nama" << setw(12) << left << "Gol. Darah" << setw(18) << left << "Status" << endl;
        cout << setfill('=') << setw(76) << '=' << endl;
        for (int i = 0; i < banyak_data; i++)
        {
            cout << setfill(' ') << ' ' << setw(15) << left << tampilkan[i].nomorktp << setw(30) << left << tampilkan[i].nama << setw(12) << left << tampilkan[i].golongandarah << setw(18) << left << tampilkan[i].status << endl;
        }
        cout << setfill('=') << setw(76) << '=' << endl;
        } 
    else
    {
        cout<<"file eror : file tidak berhasil dibaca, eror salah nama!"<<endl;
        system("PAUSE");
    }

}
	

    void sorting(fstream &dataorang, int banyak_data)
    {
    datapenting sorting[99], tempat;
	int pilih2, pilih1;
    banyak_data = 0;
    menuatas();
	cout <<"Masukkan Nama File   = ";
    cin >>file;
    dataorang.open(file);
	if (dataorang.is_open())
    {
        int k = banyak_data;
        while (!dataorang.fail())
        {
		getline(dataorang, sorting[k].nomorktp );
		getline(dataorang, sorting[k].nama);
		getline(dataorang, sorting[k].status);
		getline(dataorang, sorting[k].golongandarah);
        k++;
        }
        banyak_data = k - 1;
        for(int j=0; j< banyak_data;j++){
    cout << "\n ------------------------------------------------------------- \n";
    cout << "\n Data Sebagai Berikut";
    cout << " Nomor KTP      = " << sorting[j].nomorktp  << endl;
    cout << " Nama           = " << sorting[j].nama << endl;
    cout << " Status         = " << sorting[j].status << endl;
    cout << " Golongan Darah = " << sorting[j].golongandarah << endl;
    
        }
        system("PAUSE");
        system("CLS");
    cout << "            PENGURUTAN DATA";
	cout << "\n ------------------------------------------------------------- \n";
	cout << endl;
    cout << "1. Bubble Sort\n";
    cout << "2. Shell Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Selection Sort\n";
	cout << " Masukkan Pilihan : "; cin >> pilih1; 
	if (pilih1 == 1)
    {
        cout << "            PENGURUTAN DATA";
	cout << "\n ------------------------------------------------------------- \n";
	cout << endl;
    cout << "1. NIK\n";
    cout << "2. Nama\n";
    cout << "3. Status\n";
    cout << "4. Golongan Darah\n";
	cout << " Masukkan Pilihan : "; cin >> pilih2;
    if (pilih2 == 1) {
		for (int i = 0; i < banyak_data; i++) {
        for (int j = i+1; j < banyak_data; j++) {
            if (sorting[i].nomorktp > sorting[j].nomorktp) {
                tempat = sorting[i];
                sorting[i] = sorting[j];
                sorting[j] = tempat; } } } } 
                
    else if (pilih2 == 2) {
		for (int i = 0; i < banyak_data; i++) {
			for (int j = i+1; j < banyak_data; j++) {
				if (sorting[i].nama > sorting[j].nama) {
					tempat = sorting[i];
					sorting[i] = sorting[j];
					sorting[j] = tempat; } } } }
    else if (pilih2 == 3) {
		for (int i = 0; i < banyak_data; i++) {
			for (int j = i+1; j < banyak_data; j++) {
				if (sorting[i].status > sorting[j].status) {
					tempat = sorting[i];
					sorting[i] = sorting[j];
					sorting[j] = tempat; } } } }
    else if (pilih2 == 4) {
		for (int i = 0; i < banyak_data; i++) {
			for (int j = i+1; j < banyak_data; j++) {
				if (sorting[i].golongandarah > sorting[j].golongandarah) {
					tempat = sorting[i];
					sorting[i] = sorting[j];
					sorting[j] = tempat; } } } }                 
    }
    else if (pilih1 == 2)
    {
        cout << "            PENGURUTAN DATA ";
	cout << "\n ------------------------------------------------------------- \n";
	cout << endl;
    cout << "1. NIK\n";
    cout << "2. Nama\n";
    cout << "3. Status\n";
    cout << "4. Golongan Darah\n";
	cout << " Masukkan Pilihan : "; cin >> pilih2;
    if (pilih2 == 1) {
		for (int interval = banyak_data / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < banyak_data; i += 1) {
      string temp = sorting[i].nomorktp;
      int j;
      for (j = i; j >= interval && sorting[j - interval].nomorktp > temp; j -= interval) {
        sorting[j].nomorktp = sorting[j - interval].nomorktp;}
      sorting[j].nomorktp = temp;} } } 
                
    else if (pilih2 == 2) {
		for (int interval = banyak_data / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < banyak_data; i += 1) {
      string temp = sorting[i].nama;
      int j;
      for (j = i; j >= interval && sorting[j - interval].nama > temp; j -= interval) {
        sorting[j].nama = sorting[j - interval].nama;}
      sorting[j].nama = temp;} } }

    else if (pilih2 == 3) {
		for (int interval = banyak_data / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < banyak_data; i += 1) {
      string temp = sorting[i].status;
      int j;
      for (j = i; j >= interval && sorting[j - interval].status > temp; j -= interval) {
        sorting[j].status = sorting[j - interval].status;}
      sorting[j].status = temp;} } }

    else if (pilih2 == 4) {
		for (int interval = banyak_data / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < banyak_data; i += 1) {
      string temp = sorting[i].golongandarah;
      int j;
      for (j = i; j >= interval && sorting[j - interval].golongandarah > temp; j -= interval) {
        sorting[j].golongandarah = sorting[j - interval].golongandarah;}
      sorting[j].golongandarah = temp;} } }                 
    }

    else if (pilih1 == 3)
    {
        cout << "            PENGURUTAN DATA ";
	cout << "\n ------------------------------------------------------------- \n";
	cout << endl;
    cout << "1. NIK\n";
    cout << "2. Nama\n";
    cout << "3. Status\n";
    cout << "4. Golongan Darah\n";
	cout << " Masukkan Pilihan : "; cin >> pilih2;
    if (pilih2 == 1) {
    for (int i = 1; i < banyak_data; i++)
    {
        string key = sorting[i].nomorktp;
        int j = i - 1;
        while (j >= 0 && sorting[j].nomorktp > key)
        {
            sorting[j + 1].nomorktp = sorting[j].nomorktp;
            j = j - 1;
        }
        sorting[j + 1].nomorktp = key;
    } } 
                
    else if (pilih2 == 2) {
		for (int i = 1; i < banyak_data; i++)
    {
        string key = sorting[i].nama;
        int j = i - 1;
        while (j >= 0 && sorting[j].nama > key)
        {
            sorting[j + 1].nama = sorting[j].nama;
            j = j - 1;
        }
        sorting[j + 1].nama = key;
    } }

    else if (pilih2 == 3) {
		for (int i = 1; i < banyak_data; i++)
    {
        string key = sorting[i].status;
        int j = i - 1;
        while (j >= 0 && sorting[j].status > key)
        {
            sorting[j + 1].status = sorting[j].status;
            j = j - 1;
        }
        sorting[j + 1].status = key;
    } }

    else if (pilih2 == 4) {
		for (int i = 1; i < banyak_data; i++)
    {
        string key = sorting[i].golongandarah;
        int j = i - 1;
        while (j >= 0 && sorting[j].golongandarah > key)
        {
            sorting[j + 1].status = sorting[j].golongandarah;
            j = j - 1;
        }
        sorting[j + 1].golongandarah = key;
    } }                 
    }
    else if (pilih1 == 4)
    {
        cout << "            PENGURUTAN DATA";
	cout << "\n ------------------------------------------------------------- \n";
	cout << endl;
    cout << "1. NIK\n";
    cout << "2. Nama\n";
    cout << "3. Status\n";
    cout << "4. Golongan Darah\n";
	cout << " Masukkan Pilihan : "; cin >> pilih2;
    if (pilih2 == 1) {
    for (int step = 0; step < banyak_data - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < banyak_data; i++) {

      if (sorting[i].nomorktp < sorting[min_idx].nomorktp)
        min_idx = i;
    }
   swap(&sorting[min_idx].nomorktp, &sorting[step].nomorktp);
  } } 
                
    else if (pilih2 == 2) {
		for (int step = 0; step < banyak_data - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < banyak_data; i++) {

      if (sorting[i].nama < sorting[min_idx].nama)
        min_idx = i;
    }
   swap(&sorting[min_idx].nama, &sorting[step].nama);
  } }

    else if (pilih2 == 3) {
		for (int step = 0; step < banyak_data - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < banyak_data; i++) {

      if (sorting[i].status < sorting[min_idx].status)
        min_idx = i;
    }
   swap(&sorting[min_idx].status, &sorting[step].status);
  } }

    else if (pilih2 == 4) {
		for (int step = 0; step < banyak_data - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < banyak_data; i++) {

      if (sorting[i].golongandarah < sorting[min_idx].golongandarah)
        min_idx = i;
    }
   swap(&sorting[min_idx].golongandarah, &sorting[step].golongandarah);
  }}                 
    }
	

	dataorang.open(file, ios::app);
	for (int i = 0; i < banyak_data; i++)
	{
		dataorang << sorting[i].nomorktp  << endl;
		dataorang << sorting[i].nama << endl;
        dataorang << sorting[i].status << endl;
		dataorang << sorting[i].golongandarah << endl;
	}
	dataorang.close();
	
	for (int i = 0; i < banyak_data; i++)
    {
	cout << "\n ------------------------------------------------------------- \n";
    cout << " Nomor Pendaftaran = " << sorting[i].nomorktp  << endl;
	cout << " Nama Peserta      = " << sorting[i].nama << endl;
	cout << " Umur              = " << sorting[i].status << endl;
    cout << " Jenis Kelamin     = " << sorting[i].golongandarah << endl;
    }
        } 
        
      else
    {
        cout<<"file eror : file tidak berhasil dibaca, eror salah nama!"<<endl;
        system("PAUSE");
    }
    
    }

    void transaksi(fstream &dataorang, int banyak_data)
    {   
        datapenting transaksi[99];
        string namaFile1, namaFile2;
        bool found = false;
        banyak_data=0;
        string cari;
        int ubah;
        int ubahtahap;
        int pilih;
    menuatas();
    cout<<"Menu Transaksi";
    cout<<"\n1. Splitting";
    cout<<"\n2. Updating";
    cout<<"\nMasukkan Pilihan	:";
    cin>>pilih;
    if (pilih == 1){
		system("CLS");
        cout << "Nama File \t= ";
    cin >> file;
dataorang.open(file);
    if (dataorang.is_open())
    {
        int i = banyak_data;
        while (!dataorang.fail())
        {
		getline(dataorang, transaksi[i].nomorktp );
		getline(dataorang, transaksi[i].nama);
		getline(dataorang, transaksi[i].status);
		getline(dataorang, transaksi[i].golongandarah);
        i++;
        }
        banyak_data = i - 1;
        for (int i = 0; i < banyak_data; i++)
    {
    getline(dataorang, transaksi[i].nomorktp);
	getline(dataorang, transaksi[i].nama);
	getline(dataorang, transaksi[i].status);
    getline(dataorang, transaksi[i].golongandarah);
    }
        dataorang.close();
        cout << endl;
        cout << setfill('=') << setw(76) << '=' << endl;
        cout << setfill(' ') << setw(16) << left << " Nomer KTP" << setw(30) << left << "Nama" << setw(12) << left << "Gol. Darah" << setw(18) << left << "Status" << endl;
        cout << setfill('=') << setw(76) << '=' << endl;
        for (int i = 0; i < banyak_data; i++)
        {
            cout << setfill(' ') << ' ' << setw(15) << left << transaksi[i].nomorktp << setw(30) << left << transaksi[i].nama << setw(12) << left << transaksi[i].golongandarah << setw(18) << left << transaksi[i].status << endl;
        }
        cout << setfill('=') << setw(76) << '=' << endl;
        cin.ignore();
        cout << "\nMembagi file menjadi 2 : " << endl;
        cout << "Masukan nama file ke-1 hasil spliting = ";
        getline(cin, namaFile1);
        cout << "Masukan nama file ke-2 hasil spliting = ";
        getline(cin, namaFile2);
        cout << "\nSpliting Berhasil!" << endl;
        cout << "[Tekan sembarang tombol untuk melihat hasil]" << endl;
        system("pause");
        system("cls");
        cout << "\nData File 1" << endl;
        cout << setfill('=') << setw(76) << '=' << endl;
        cout << setfill(' ') << setw(16) << left << " Nomer KTP" << setw(30) << left << "Nama" << setw(12) << left << "Gol. Darah" << setw(18) << left << "Status" << endl;
        cout << setfill('=') << setw(76) << '=' << endl;
        for (int i = 0; i < banyak_data / 2; i++)
        {
            cout << setfill(' ') << ' ' << setw(15) << left << transaksi[i].nomorktp << setw(30) << left << transaksi[i].nama << setw(12) << left << transaksi[i].golongandarah << setw(18) << left << transaksi[i].status << endl;
        }
        cout << setfill('=') << setw(76) << '=' << endl;
        cout << "\nData File 2" << endl;
        cout << setfill('=') << setw(76) << '=' << endl;
        cout << setfill(' ') << setw(16) << left << " Nomer KTP" << setw(30) << left << "Nama" << setw(12) << left << "Gol. Darah" << setw(18) << left << "Status" << endl;
        cout << setfill('=') << setw(76) << '=' << endl;
        for (int i = (banyak_data / 2); i < banyak_data; i++)
        {
            cout << setfill(' ') << ' ' << setw(15) << left << transaksi[i].nomorktp << setw(30) << left << transaksi[i].nama << setw(12) << left << transaksi[i].golongandarah << setw(18) << left << transaksi[i].status << endl;
        }
        cout << setfill('=') << setw(76) << '=' << endl;
        dataorang.open(namaFile1);
        if (dataorang.is_open())
        {
            for (int i = 0; i < banyak_data / 2; i++)
            {
                dataorang << transaksi[i].nomorktp << " " << transaksi[i].nama << " " << transaksi[i].status << " " << transaksi[i].golongandarah << endl;
            }
            dataorang.close();
        }
        dataorang.open(namaFile2);
        if (dataorang.is_open())
        {
            for (int i = (banyak_data / 2); i < banyak_data; i++)
            {
                dataorang << transaksi[i].nomorktp << " " << transaksi[i].nama << " " << transaksi[i].status << " " << transaksi[i].golongandarah << endl;
            }
            dataorang.close();
        }
        }
        else{
        cout<<"file eror : file tidak berhasil dibaca, eror salah nama!"<<endl;
        system("PAUSE"); 
        }
        
    
    }
    else if (pilih == 2){
        system("CLS");
        cout << "Nama File \t= ";
    cin >> file;
       dataorang.open(file);
    if (dataorang.is_open())
    {
        int i = banyak_data;
        while (!dataorang.fail())
        {
		getline(dataorang, transaksi[i].nomorktp );
		getline(dataorang, transaksi[i].nama);
		getline(dataorang, transaksi[i].status);
		getline(dataorang, transaksi[i].golongandarah);
        i++;
        }
        banyak_data = i - 1;
        	menuatas();
	cout << "             MENCARI DATA " << endl;
	cout << " =============================================================" << endl;
	cout << endl;

	cin.ignore();
	cout << "Cari Nomor Pendaftaran  Peserta = ";
	getline(cin, cari);

    // updatetahap
    for (int i = 0; i < banyak_data; i++)
    {
        if(transaksi[i].nomorktp  == cari){
            ubah = i;
            found = true;
        }
    }

	if(!found){
        cout << "\nData tidak ditemukan!";
		cout << endl;
    } 
	else {
		cout << "\n INFORMASI DATA " << endl;
		cout << " -------------------------------------------------------------" << endl;
				cout << "Nomor Pendaftaran = " << transaksi[ubah].nomorktp  << endl;
            	cout << "Nama Peserta      = " << transaksi[ubah].nama << endl;
				cout << "Umur              = " << transaksi[ubah].status << endl;
				cout << "Jenis Kelamin     = " << transaksi[ubah].golongandarah << endl;

				
		cout << "\n Data Apa Yang ingin diubah ? : \n";
		cout<<" 1. Nama\n";
		cout<<" 2. Status\n";
		cout<<" 3. Golongan Darah\n";
        cout<<"Masukkan Pilihan     :";
		cin >> ubahtahap;

		if (ubahtahap == 1){
			cin.ignore();
			cout<< "Nama diubah menjadi : ";
			getline(cin, transaksi[ubah].nama);
			}
		else if (ubahtahap == 2){
			cin.ignore();
			cout<< "Status diubah menjadi : ";
			getline(cin, transaksi[ubah].status);
			}
		else if (ubahtahap == 3){
			cin.ignore();
			cout<< "Golongan Darah diubah menjadi : ";
			getline(cin, transaksi[ubah].golongandarah);
			}
        cout << "Masukan nama file hasil Updating = ";
        getline(cin, namaFile1);
        cout << "\nSpliting Berhasil!" << endl;
        cout << "[Tekan sembarang tombol untuk melihat hasil]" << endl;
        system("pause");
        system("cls");
        cout << "\nData File" << endl;
        cout << setfill('=') << setw(76) << '=' << endl;
        cout << setfill(' ') << setw(16) << left << " Nomer KTP" << setw(30) << left << "Nama" << setw(12) << left << "Gol. Darah" << setw(18) << left << "Status" << endl;
        cout << setfill('=') << setw(76) << '=' << endl;
        cout << setfill(' ') << ' ' << setw(15) << left << transaksi[ubah].nomorktp << setw(30) << left << transaksi[ubah].nama << setw(12) << left << transaksi[ubah].golongandarah << setw(18) << left << transaksi[ubah].status << endl;
        dataorang.open(namaFile1);
        if (dataorang.is_open())
        {
                dataorang << transaksi[ubah].nomorktp << " " << transaksi[ubah].nama << " " << transaksi[ubah].status << " " << transaksi[ubah].golongandarah << endl;
            dataorang.close();
        }
    }
        } 
        else{
        cout<<"file eror : file tidak berhasil dibaca, eror salah nama!"<<endl;
        system("PAUSE");
        }
    }
        
    }
    void swap(string *a, string *b) {
  string temp = *a;
  *a = *b;
  *b = temp;
}

