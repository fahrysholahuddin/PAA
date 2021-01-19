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
    cout << endl << "=========================\n\n";
    for (int i = 0; i < jumlahBuah; i++)
    {
        dataBuah[i].no = dataBuah[i - 1].no + 1;
        cout << "Berat buah " << dataBuah[0].nama << " No.Pack.ID : " << dataBuah[i].no << " = ";
        cin >> dataBuah[i].berat;
        cout << "Jumlah buah jelek " << " = ";
        cin >> dataBuah[i].kondisi;
    }
    for (int i = 0; i < jumlahBuah; i++)
    {
        int min_idx = i;
        for (int j = i+1; j < jumlahBuah; j++)
            if (dataBuah[j].berat < dataBuah[min_idx].berat)
                min_idx = j;

        string tempNama;
        tempNama = dataBuah[min_idx].nama;
        dataBuah[min_idx].nama = dataBuah[i].nama;
        dataBuah[i].nama = tempNama;

        int tempNo = dataBuah[min_idx].no;
        dataBuah[min_idx].no = dataBuah[i].no;
        dataBuah[i].no = tempNo;

        int tempBerat = dataBuah[min_idx].berat;
        dataBuah[min_idx].berat = dataBuah[i].berat;
        dataBuah[i].berat = tempBerat;

        int tempKondisi = dataBuah[min_idx].kondisi;
        dataBuah[min_idx].kondisi = dataBuah[i].kondisi;
        dataBuah[i].kondisi = tempKondisi;

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
        totalJumlahKotor += 1;
        totalBeratKotor = totalBeratKotor + dataBuah[i].berat;
        totalBeratGradeA = totalBeratGradeA + dataBuahGradeA[i].berat;
        totalBeratGradeB = totalBeratGradeB + dataBuahGradeB[i].berat;
    }

    cout << endl << "=========================\n";
    cout << endl << "Daftar buah keseluruhan \n" << endl;
    for (int i = 0; i < jumlahBuah; i++)
    {
        if (dataBuah[i].kondisi == 0)
        {
           cout << "# no.ID = " << dataBuah[i].no << "A # Kondisi : Bagus " << " # berat : " << dataBuah[i].berat << " Kg" << endl;
        }
        else if (dataBuah[i].kondisi > 0)
        {
            cout << "# no.ID = " << dataBuah[i].no << "B # Kondisi : Jelek " << " # berat : " << dataBuah[i].berat << " Kg" << endl;
        }

    }
    cout << endl << "Jumlah buah keseluruhan = " << totalJumlahKotor << " pack";
    cout << endl << "Jumlah berat buah keseluruhan = " << totalJumlahKotor << " pack";
    cout << endl << "\n=========================\n";
    cout << endl << "Daftar buah " << dataBuahGradeA[0].nama << " layak jual : \n" << endl;

    for (int i = 0; i < gradeA; i++)
    {
        cout << i+1 << "# no.ID = " << dataBuahGradeA[i].no << "A # kodisi : Bagus" << " # Berat : " << dataBuahGradeA[i].berat << " Kg" << endl;

    }

    cout << endl << "Jumlah Buah Grade A (Layak Jual) = " << gradeA << " pack";
    cout << endl << "Total Berat Buah Grade A (Layak Jual) = " << totalBeratGradeA << " Kg";
    cout << endl << "\n=========================\n";
    cout << endl << "Daftar buah " << dataBuahGradeB[0].nama << " tidak layak jual : \n" << endl;

    for (int i = 0; i < gradeB; i++)
    {
        cout << i+1 << "# noID = " << dataBuahGradeB[i].no << "B # Jumlah Buah Jelek : "<< dataBuahGradeB[i].kondisi << " # Berat : " << dataBuahGradeB[i].berat << endl;
    }
    cout << endl << "Jumlah Buah Grade B (Tidak Layak Jual) = " << gradeB << " pack";
    cout << endl << "Total Berat Buah Grade B (Tidak Layak Jual) = " << totalBeratGradeB << " Kg ";
    cout << endl << "\n=========================\n\n";

}

