#include <iostream>
using namespace std;

int jumlahBuah, totalJumlahKotor, gradeA, gradeB;
float totalBeratKotor, totalBeratGradeA, totalBeratGradeB;

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
    cout << "Masukan jumlah pack buah = ";
    cin >> jumlahBuah;
    cout << "=========================";
    for (int i = 0; i < jumlahBuah; i++)
    {
        dataBuah[i].no = dataBuah[i - 1].no + 1;
        cout << endl << "Berat buah " << dataBuah[0].nama << " per pack ke-" << dataBuah[i].no << " = ";
        cin >> dataBuah[i].berat;
        cout << "Jumlah buah jelek " << dataBuah[0].nama << " per pack ke-" << dataBuah[i].no << " (0-1) = ";
        cin >> dataBuah[i].kondisi;
    }

    for (int i = 0; i < jumlahBuah; i++)
    {
        if (dataBuah[i].kondisi == 0)
        {
            gradeA += 1;
            dataBuahGradeA[gradeA-1].nama = dataBuah[i].nama;
            dataBuahGradeA[gradeA-1].no = dataBuah[i].no;
            dataBuahGradeA[gradeA-1].kondisi = dataBuah[i].kondisi;
            dataBuahGradeA[gradeA-1].berat = dataBuah[i].berat;
        }
        else if (dataBuah[i].kondisi > 0)
        {
            gradeB += 1;
            dataBuahGradeB[gradeB-1].nama = dataBuah[i].nama;
            dataBuahGradeB[gradeB-1].no = dataBuah[i].no;
            dataBuahGradeB[gradeB-1].kondisi = dataBuah[i].kondisi;
            dataBuahGradeB[gradeB-1].berat = dataBuah[i].berat;
        }
    }

    for (int i = 0; i < jumlahBuah; i++)
    {
        totalJumlahKotor += 1;
        totalBeratKotor = totalBeratKotor + dataBuah[i].berat;
        totalBeratGradeA = totalBeratGradeA + dataBuahGradeA[i].berat;
        totalBeratGradeB = totalBeratGradeB + dataBuahGradeB[i].berat;
    }

    cout << endl << "=========================";
    cout << endl << "Daftar buah keseluruhan " << endl;
    for (int i = 0; i < jumlahBuah; i++)
    {
        cout << "Nama buah : " << dataBuah[0].nama << " no = " << dataBuah[i].no << " kodisi : " << dataBuah[i].kondisi << endl;
    }
    cout << endl << "Jumlah buah keseluruhan = " << totalJumlahKotor << " pack";
    cout << endl << "Jumlah berat buah keseluruhan = " << totalJumlahKotor << " pack";
    cout << endl << "=========================";
    cout << endl << "Daftar buah layak jual : " << endl;
    for (int i = 0; i < gradeA; i++)
    {
        cout << "Nama buah : " << dataBuahGradeA[0].nama << " no.ID = " << dataBuahGradeA[i].no << " kodisi : " << dataBuahGradeA[i].kondisi << " Berat : " << dataBuahGradeA[i].berat << endl;
    }
    cout << endl << "Jumlah Buah Grade A (Layak Jual) = " << gradeA << " pack";
    cout << endl << "Total Berat Buah Grade A (Layak Jual) = " << totalBeratGradeA << " Kg";
    cout << endl << "=========================\n";
    cout << endl << "Daftar buah tidak layak jual : " << endl;
    for (int i = 0; i < gradeB; i++)
    {
            cout << "Nama buah : " << dataBuahGradeB[0].nama << " noID = " << dataBuahGradeB[i].no << " kodisi : " << dataBuahGradeB[i].kondisi << " Berat : " << dataBuahGradeB[i].berat << endl;
    }
    cout << endl << "Jumlah Buah Grade B (Tidak Layak Jual) = " << gradeB << " pack";
    cout << endl << "Total Berat Buah Grade B (Tidak Layak Jual) = " << totalBeratGradeB << " Kg ";
}
