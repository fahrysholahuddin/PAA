#include <iostream>
using namespace std;

int jumlahBuah, totalJumlahKotor, gradeA, gradeB;
float totalBeratKotor;

struct buah
{
	string nama;
	int no;
	float berat;
	int kondisi;
} dataBuah[30];

struct buahGradeA
{
	string nama;
	int no;
	float berat;
	int kondisi;
} dataBuahGradeA[30];

struct buahGradeB
{
	string nama;
	int no;
	float berat;
	int kondisi;
} dataBuahGradeB[30];

int main()
{
	cout << "Program Sortir Buah" << endl;
	cout << "Masukkan nama buah : ";
	cin >> dataBuah[0].nama;
	cout << "Masukan jumlah buah = ";
	cin >> jumlahBuah;
	cout << "=========================";
	for (int i = 0; i < jumlahBuah; i++)
	{
		dataBuah[i].no = dataBuah[i - 1].no + 1;
		cout << endl
			 << "Berat buah " << dataBuah[0].nama << " per pack ke-" << dataBuah[i].no << " = ";
		cin >> dataBuah[i].berat;
		cout << "Jumlah buah jelek " << dataBuah[0].nama << " per pack ke-" << dataBuah[i].no << " (0-1) = ";
		cin >> dataBuah[i].kondisi;
	}

	for (int i = 0; i < jumlahBuah; i++)
	{
		if (dataBuah[i].kondisi == 0)
		{
			gradeA += 1;
			dataBuahGradeA[i].nama = dataBuah[i].nama;
			dataBuahGradeA[i].no = dataBuah[i].no;
			dataBuahGradeA[i].kondisi = dataBuah[i].kondisi;
			dataBuahGradeA[i].berat = dataBuah[i].berat;
		}
		else if (dataBuah[i].kondisi > 0)
		{
			gradeB += 1;
			dataBuahGradeB[i].nama = dataBuah[i].nama;
			dataBuahGradeB[i].no = dataBuah[i].no;
			dataBuahGradeB[i].kondisi = dataBuah[i].kondisi;
			dataBuahGradeB[i].berat = dataBuah[i].berat;
		}
	}

	cout << endl
		 << " debug " << dataBuah[0].nama;

	for (int i = 0; i < jumlahBuah; i++)
	{
		totalJumlahKotor += 1;
		totalBeratKotor = totalBeratKotor + dataBuah[i].berat;
	}

	for (int i = 0; i < jumlahBuah; i++)
	{
	}
	cout << endl
		 << "=========================";
	cout << endl
		 << "Daftar buah keseluruhan " << endl;
	for (int i = 0; i < jumlahBuah; i++)
	{
		cout << "Nama buah : " << dataBuah[0].nama << " no = " << dataBuah[i].no << " kodisi : " << dataBuah[i].kondisi << endl;
	}
	cout << endl
		 << "Jumlah buah keseluruhan = " << totalJumlahKotor << " pack";
	cout << endl
		 << "Jumlah berat buah keseluruhan = " << totalJumlahKotor << " pack";
	cout << endl
		 << "=========================";
	cout << endl
		 << "Daftar buah layak jual : " << endl;
	for (int i = 0; i < jumlahBuah; i++)
	{
		if (dataBuah[i].kondisi == 0)
		{
			cout << "Nama buah : " << dataBuahGradeA[0].nama << " no = " << dataBuahGradeA[i].no << " kodisi : " << dataBuahGradeA[i].kondisi << " Berat : " << dataBuahGradeA[i].berat << endl;
		}
	}
	cout << endl
		 << "Jumlah Buah Grade A (Layak Jual) = " << gradeA;
	cout << endl
		 << "=========================\n";
	for (int i = 0; i < jumlahBuah; i++)
	{
		if (dataBuah[i].kondisi > 0)
		{
			cout << "Nama buah : " << dataBuahGradeB[0].nama << " no = " << dataBuahGradeB[i].no << " kodisi : " << dataBuahGradeB[i].kondisi << " Berat : " << dataBuahGradeB[i].berat << endl;
		}
	}
	cout << endl
		 << "Jumlah Buah Grade B (Non Layak Jual) = " << gradeB;
}
