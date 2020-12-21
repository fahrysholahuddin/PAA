#include<iostream>
using namespace std;

int jumlahBuah,totalJumlahKotor,gradeA,gradeB;
float totalBeratKotor;

struct buah{
	string nama;
	int no;
	float berat;
	int kondisi;
}dataBuah[30];

struct buahGradeA{
	string nama;
	int no;
	float berat;
	int kondisi;
}dataBuahGradeA[30];

int main(){
	cout << "Program Sortir Buah" << endl;
	cout << "Masukkan nama buah : ";
	cin >> dataBuah[0].nama;
	cout << "Masukan jumlah buah = ";
	cin >> jumlahBuah;
	cout << "=========================";
	for (int i = 0; i < jumlahBuah; i++){
		dataBuah[i].no += 1;
		cout << endl << "Berat buah " << dataBuah[0].nama << " per pack ke-" << dataBuah[i].no << " = ";
		cin >> dataBuah[i].berat;
		cout << "Kondisi buah " <<dataBuah[0].nama << " per pack ke-" << dataBuah[i].no << " (0-5) = ";
		cin >> dataBuah[i].kondisi;
	}

	for (int i = 0; i < jumlahBuah; i++){
		if (dataBuah[i].kondisi < 1){
			gradeA += 1;
			dataBuah[0].nama = dataBuahGradeA[i].nama;
			dataBuah[i].no = dataBuahGradeA[i].no;
			dataBuah[i].kondisi = dataBuahGradeA[i].kondisi;
			dataBuah[i].berat = dataBuahGradeA[i].berat;
		}else if (dataBuah[i].kondisi >= 1 && dataBuah[i].kondisi <= 2){
			gradeB += 1;
		}
	}

	for (int i = 0; i < jumlahBuah; i++){
		totalJumlahKotor += 1;
		totalBeratKotor = totalBeratKotor + dataBuah[i].berat;
	}

	for(int i = 0; i < jumlahBuah; i++){

	}
	cout << endl << "=========================";
	cout << endl << "Bruto jumlah seluruh buah = "<< totalJumlahKotor;
	cout << endl << "Bruto berat seluruh buah = " << totalBeratKotor;
	cout << endl << "Jumlah Buah Grade A (Layak Jual) = " << gradeA << endl ;
	cout << endl << "Daftar buah layak jual : ";
	for (int i = 0; i < gradeA ; i++){
            cout << dataBuahGradeA[i].nama;
			dataBuahGradeA[i].no;
			dataBuahGradeA[i].kondisi;
			dataBuahGradeA[i].berat;
	}


	cout << endl << "Jumlah Buah Grade B = " << gradeB;
}
