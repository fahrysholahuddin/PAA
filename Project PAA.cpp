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

int main(){
	cout << "Program Sortir Buah" << endl;
	cout << "Masukkan nama buah : ";
	cin >> dataBuah[0].nama;
	cout << "Masukan jumlah buah = ";
	cin >> jumlahBuah;
	cout << "=========================";
	for (int i = 0; i < jumlahBuah; i++){
		dataBuah[i].no += 1;
		cout << endl << "Berat buah " << dataBuah[0].nama << " ke-" << i+1 << " = ";
		cin >> dataBuah[i].berat;
		cout << "Kondisi buah " <<dataBuah[0].nama << " ke-" << i+1 << " (0-5) = ";
		cin >> dataBuah[i].kondisi;
	}
	
	for (int i = 0; i < jumlahBuah; i++){
		if (dataBuah[i].kondisi < 1){
			gradeA += 1;
		}else if (dataBuah[i].kondisi >= 1 && dataBuah[i].kondisi <= 2){
			gradeB += 1;
		}
	}
	
	for (int i = 0; i < jumlahBuah; i++){
		totalJumlahKotor += 1;
		totalBeratKotor = totalBeratKotor + dataBuah[i].berat;
	}
	cout << endl << "=========================";
	cout << endl << "Bruto jumlah seluruh buah = "<< totalJumlahKotor;
	cout << endl << "Bruto berat seluruh buah = " << totalBeratKotor;
	cout << endl << "Jumlah Buah Grade A = " << gradeA;
	cout << endl << "Jumlah Buah Grade B = " << gradeB;
}
