using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorytm_artmetyczny
{
    class Konwersja
    {  
        bool czy = false;
        int rozmiar;
        public void Rzym_Ar(string Liczba)
        {
            int lewa = Convert.ToInt32(Liczba);
            string NowaLiczba = "";
            while (lewa > 0)
            {
                if (lewa - 1000 >= 0)
                {
                    lewa -= 1000;
                    NowaLiczba += "M";
                }
                else if (lewa - 900 >= 0)
                {
                    lewa -= 900;
                    NowaLiczba += "CM";
                }
                else if (lewa - 500 >= 0)
                {
                    lewa -= 500;
                    NowaLiczba += "D";
                }
                else if (lewa - 400 >= 0)
                {
                    lewa -= 400;
                    NowaLiczba += "CD";
                }
                else if (lewa - 100 >= 0)
                {
                    lewa -= 100;
                    NowaLiczba += "C";
                }
                else if (lewa - 90 >= 0)
                {
                    lewa -= 90;
                    NowaLiczba += "XC";
                }
                else if (lewa - 50 >= 0)
                {
                    lewa -= 50;
                    NowaLiczba += "L";
                }
                else if (lewa - 40 >= 0)
                {
                    lewa -= 40;
                    NowaLiczba += "XL";
                }
                else if (lewa - 10 >= 0)
                {
                    lewa -= 10;
                    NowaLiczba += "X";
                }
                else if (lewa - 9 >= 0)
                {
                    lewa -= 9;
                    NowaLiczba += "IX";
                }
                else if (lewa - 5 >= 0)
                {
                    lewa -= 5;
                    NowaLiczba += "V";
                }
                else if (lewa - 4 >= 0)
                {
                    lewa -= 4;
                    NowaLiczba += "IV";
                }
                else
                {
                    lewa -= 1;
                    NowaLiczba += "I";
                }
            }
            Console.WriteLine(NowaLiczba);
        }
        public void Ar_Rzym(string Liczba)
        {            
            rozmiar = Liczba.Length;
            int wynik = 0;
            for (int i = 0; i < rozmiar ; i++)
            {
                czy = true;
                if (i + 1 < rozmiar )
                {
                    if (Liczba[i] == 'I' && Liczba[i + 1] == 'V')
                    {
                        wynik += 4;
                        i++;
                        czy = false;
                    }
                    else if (Liczba[i] == 'I' && Liczba[i + 1] == 'X')
                    {
                        wynik += 9;
                        i++;
                        czy = false;
                    }
                    else if (Liczba[i] == 'X' && Liczba[i + 1] == 'L')
                    {
                        wynik += 40;
                        i++;
                        czy = false;
                    }
                    else if (Liczba[i] == 'X' && Liczba[i + 1] == 'C')
                    {
                        wynik += 90;
                        i++;
                        czy = false;
                    }
                    else if (Liczba[i] == 'C' && Liczba[i + 1] == 'D')
                    {
                        wynik += 400;
                        i++;
                        czy = false;
                    }
                    else if (Liczba[i] == 'C' && Liczba[i + 1] == 'M')
                    {
                        wynik += 900;
                        i++;
                        czy = false;
                    }
                }
                if (Liczba[i] == 'I' &&  czy == true)
                {
                    wynik += 1;
                }
                else if (Liczba[i] == 'V' && czy == true)
                {
                    wynik += 5;
                }
                else if (Liczba[i] == 'X' && czy == true)
                {
                    wynik += 10;
                }
                else if (Liczba[i] == 'L' && czy == true)
                {
                    wynik += 50;
                }
                else if (Liczba[i] == 'C' && czy == true )
                {
                    wynik += 100;
                }
                else if (Liczba[i] == 'D' && czy == true)
                {
                    wynik += 500;
                }
                else if (Liczba[i] == 'M' && czy == true)
                {
                    wynik += 1000;
                }    
            }
            Console.WriteLine(wynik);      
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                    string liczba = Console.ReadLine();
                    int numer;
                    bool wynik = Int32.TryParse(liczba, out numer);
                    Konwersja Kon = new Konwersja();

                    if (wynik == true)
                    {
                        Kon.Rzym_Ar(liczba);
                    }
                    else
                    {
                        Kon.Ar_Rzym(liczba);
                    }
            }
        }
    }
}
