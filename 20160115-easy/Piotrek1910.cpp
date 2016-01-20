// INFO: nale¿y zdefiniowaæ _CRT_SECURE_NO_WARNINGS 
// Troche siê nameczy³em bo to mój pierwszy taki projekt z algorytmiki ale dzia³a
// UWAGA: Nie wykrywa b³êdów zapisu rzymskiego wiêc obliczy co popadnie ;d
// UWAGA 2: Czasem crashuje nawet nie wiem dlaczego ;/

#include <stdio.h>
#include <string>

struct znak
{
	char m_znak;
	int m_wartosc;
};

znak znak_rzymski[] = { { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };
znak znak_normalny[10];

enum rodzaj_znaku
{
	ID_ZADEN = 0,
	ID_RZYMSKI,
	ID_ARABSKI
};

class CLiczba
{
private:
	int m_dlugosc;
	rodzaj_znaku m_rodzaj;
	znak* m_znak;

public:
	CLiczba() : m_znak(new znak()), m_rodzaj(ID_ZADEN) {};
	CLiczba(const char *znak);
	~CLiczba();

	void set(const char*znak);
	void operator=(const char*znak);

	void getRoman(char* _return);
	void getArabic(char* _return);

	rodzaj_znaku getType() const { return m_rodzaj; }
	int getSize() const { return m_dlugosc; }

};

CLiczba::CLiczba(const char *_znak)
{
	if (!m_znak)
		m_znak = new znak();

	set(_znak);
}

CLiczba::~CLiczba()
{
	if (m_znak)
		delete[] m_znak;
}

void CLiczba::set(const char*_znak)
{
	if (!_znak)
		return;

	int size = 0;
	for (size = 0; size < 50; size++)
	{
		if (!_znak[size])
			break;
	}
	m_dlugosc = size;


	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (znak __znak : znak_rzymski)
		{
			if (__znak.m_znak == _znak[i])
			{
				m_znak[i] = __znak;
				count++;
			}
		}
	}

	if (count == m_dlugosc)
	{
		m_rodzaj = ID_RZYMSKI;
		return;
	}

	if (count > 0)
		return;


	// je¿eli jednak to nie jest zapis rzymski...

	count = 0;
	for (int i = 0; i < size; i++)
	{
		for (znak __znak : znak_normalny)
		{
			if (__znak.m_znak == _znak[i])
			{
				m_znak[i] = __znak;
				count++;
			}
		}
	}

	// je¿eli wszystkie znaki s¹ arabskie
	if (count == m_dlugosc)
	{
		m_rodzaj = ID_ARABSKI;
		return;
	}


	// a jak nie...
	m_rodzaj = ID_ZADEN;
}

void getRomanChar(int cyfra, int shifter, char** _return)
{
	char buffer[32] = "";

	if (cyfra > 0 && cyfra <= 3)
	{
		for (int i = 0; i < cyfra; i++)
		{
			strcat(buffer, &znak_rzymski[shifter * 2].m_znak);
		}
	}
	else if (cyfra == 4)
	{
		strcpy(buffer, &znak_rzymski[shifter*2].m_znak);
		strcat(buffer, &znak_rzymski[shifter*2 + 1].m_znak);
	}
	else if (cyfra >= 5 && cyfra < 9)
	{
		strcpy(buffer, &znak_rzymski[shifter == 0 ? shifter + 1 : shifter * 2 + 1].m_znak);

		for (int i = 0; i < cyfra - 5; i++)
		{
			strcat(buffer, &znak_rzymski[shifter * 2].m_znak);
		}
	}
	else if (cyfra == 9)
	{
		shifter *= 2;
		strcpy(buffer, &znak_rzymski[0 + shifter].m_znak);
		strcat(buffer, &znak_rzymski[2 + shifter].m_znak);
	}
	else if (cyfra == 0)
	{
		strcpy(buffer, "");
	}

	*_return = buffer;

	return;
}

void CLiczba::getRoman(char* _return)
{
	char buffer[64] = "";
	char buffer2[64] = "";

	if (m_rodzaj != ID_ARABSKI)
	{
		for (int i = 0; i < m_dlugosc; i++)
		{
			strcat(buffer, &m_znak[i].m_znak);
		}

		strcpy(_return, buffer);
		return;
	}


	for (int i = m_dlugosc; i > 0; i--)
	{
		znak cyfra = m_znak[i-1];

		char *buf = "";
		getRomanChar(cyfra.m_wartosc, m_dlugosc - i, &buf);
		strcpy(buffer2, buf);

		strcat(buffer2, buffer);
		strcpy(buffer, buffer2);
	}

	strcpy(_return, buffer);
	return;
}

void CLiczba::getArabic(char* _return)
{
	char buffer[64] = "";
	int result = 0;

	if (m_rodzaj != ID_RZYMSKI)
	{
		for (int i = 0; i < m_dlugosc; i++)
		{
			strcat(buffer, &m_znak[i].m_znak);
		}

		strcpy(_return, buffer);
		return;
	}

	// get char...
	for (int i = 0; i < m_dlugosc; i++)
	{
		buffer[i] = m_znak[i].m_znak;
	}

	// (int)i pominiêcia xD tak¹ sobie wymyœli³em nazwe
	int ip = -1;

	for (int i = 0; i < m_dlugosc; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (buffer[i] == znak_rzymski[j].m_znak && buffer[i + 1] == znak_rzymski[j + 2].m_znak)
			{
				result += znak_rzymski[j + 2].m_wartosc - znak_rzymski[j].m_wartosc;
				ip = i + 1;
			}
			else if (buffer[i] == znak_rzymski[j].m_znak && buffer[i + 1] == znak_rzymski[j + 1].m_znak)
			{
				result += znak_rzymski[j + 1].m_wartosc - znak_rzymski[j].m_wartosc;
				ip = i + 1;
			}
			else if (buffer[i] == znak_rzymski[j].m_znak)
			{
				if (ip == i)
					continue;

				result += znak_rzymski[j].m_wartosc;
			}
		}
	}

	sprintf(buffer, "%d", result);

	strcpy(_return, buffer);

	return;
}

void CLiczba::operator=(const char * znak)
{
	set(znak);
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		znak_normalny[i].m_znak = i + '0';
		znak_normalny[i].m_wartosc = i;
	}

	char sliczba[32] = ""; // string liczba
	char retRoman[64] = "", retArabic[64] = "";

	CLiczba *liczba = new CLiczba();

	printf("--------------------------------------------\n");
	printf("|  Konwerter liczb romanskie<->dziesietne  |\n");
	printf("|              by Piotr Krupa              |\n");
	printf("--------------------------------------------\n");
	printf("Maksymalna liczba to 3999\n");

	while (1)
	{
		strcpy(sliczba, "");
		printf("Podaj liczbe: ");
		scanf("%s", sliczba);

		if (sliczba[0] == '0')
			break;

		if (atoi(sliczba) > 3999)
			continue;

		*liczba = sliczba;

		strcpy(retRoman, "");
		strcpy(retArabic, "");

		liczba->getArabic(retArabic);
		liczba->getRoman(retRoman);
		
		if (liczba->getType() == 0)
			printf("Twoja liczba jest nijaka ;(\n");
		else if (liczba->getType() == ID_RZYMSKI)
			printf("%s => %s\n", retRoman, retArabic);
		else if (liczba->getType() == ID_ARABSKI)
			printf("%s => %s\n", retArabic, retRoman);
	}

	delete liczba;

	return 0;
}