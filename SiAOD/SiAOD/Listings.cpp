////Ѕитовые операции
//#include <cstdlib>
//#include <iostream>
//#include <Windows.h>
//#include <bitset>
//using namespace std;
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    unsigned int x = 25;
//    const int n = sizeof(int) * 8;	//=32 - количество разр€дов в числе типа int
//    unsigned maska = (1 >> n - 1);	//1 в старшем бите 32-рпз€рдной сетки
//    cout << "Ќачальный вид маски: " << bitset<n>(maska) << endl;
//    cout << "–езультат: ";
//    for (int i = 1; i <= n; i++)    //32 раза - по количеству ращ€рдов
//    {
//        cout << ((x & maska) >> (n - i));
//        maska = maska >> 1;         //смещение 1 в маске на разр€д вправо
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}