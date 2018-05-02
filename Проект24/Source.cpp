#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <ctime>
#include <string.h>

#include "Header.h"


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));

	int N = 0;
	printf("Введите номер задания №: ");
	scanf("%d", &N);

	/*for (size_t i = 0; i < 255; i++)
	{
	printf("%d - %c\n", i, i);
	}*/
	if (N == 1)
	{
		int kolvo = 15;
		int flag = 0;
		int srok_dn = 0;
		int srok_man = 0;
		int Sum_pr = 0;
		int DD_curr = 7;
		int MM_curr = 4;
		int srok_curr = 90 + DD_curr;
		Tovar * milk_prod = (Tovar *)malloc(kolvo * sizeof(Tovar));

		if (milk_prod == NULL)
			printf_s("память не выделена");
		else
		{
			for (int i = 0; i < kolvo; i++)
			{
				(milk_prod + i)->entitle = (char*)malloc(12 * sizeof(char));
				sozd_txt((milk_prod + i)->entitle, 12);

				(milk_prod + i)->vendor = (char*)malloc(128 * sizeof(char));
				sozd_txt((milk_prod + i)->vendor, 8);

				(milk_prod + i)->DD_made = Enuma(1, 31);
				(milk_prod + i)->MM_made = 3;

				(milk_prod + i)->DD_save = Enuma(1, 31);
				(milk_prod + i)->MM_save = 4;

				(milk_prod + i)->serial_N = Enuma(106090, 999);
				(milk_prod + i)->quantity = Enuma(100, 150);
				(milk_prod + i)->price = Enuma(25, 570);
			}

			printf_s("Наименование Производитель дата вып  годен до серия № кол-во цена\n");
			for (int i = 0; i < kolvo; i++)
				print_Tovar(milk_prod, i);

			printf_s("1. наименование товара и конечная дата применения (годен до:)\n");
			for (int i = 0; i < kolvo; i++)
				printf_s("%s  %2d.%2d\n",
				(milk_prod + i)->entitle,
					(milk_prod + i)->DD_save,
					(milk_prod + i)->MM_save);
			printf_s("\n");

			printf_s("7. товары, срок годности которых заканчивается в течении 5-ти суток от заданной даты 07.04 :\n");
			for (int i = 0; i < kolvo; i++)
			{
				if ((milk_prod + i)->MM_save == 4)
					srok_dn = 90 + (milk_prod + i)->DD_save;
				if (((milk_prod + i)->MM_save == MM_curr) && (srok_dn - srok_curr < 5))
				{
					print_Tovar(milk_prod, i);
					flag = 1;
				}

			}
			if (flag == 0)
				printf_s("нет товаров срок годности которых заканчивается в течении 5-ти суток");
			printf_s("\n");
			flag = 0;
			printf_s("8. сведения о товарах, срок годности которых менее 20-ти дней. Определить количество просроченных товаров.:\n");
			for (int i = 0; i < kolvo; i++)
			{
				srok_man = 59 + (milk_prod + i)->DD_made;
				if ((milk_prod + i)->MM_save == 3)
					srok_dn = 59 + (milk_prod + i)->DD_save;
				if ((milk_prod + i)->MM_save == 4)
					srok_dn = 90 + (milk_prod + i)->DD_save;
				if (srok_dn - srok_man < 20)
				{
					print_Tovar(milk_prod, i);
					flag = 1;
				}
			}
			if (flag == 0)
				printf_s("нет товаров срок годности которых менее 20 дней");
			printf_s("\n");
			flag = 0;
			for (int i = 0; i < kolvo; i++)
			{
				if (((milk_prod + i)->MM_save == MM_curr) && (srok_dn - srok_curr < 5))
				{
					Sum_pr = Sum_pr + (milk_prod + i)->quantity; flag = 1;
					print_Tovar(milk_prod, i);
				}
			}
			printf_s("\tколичество просроченных товаров %d ед.", Sum_pr);
			printf_s("\n");
			if (flag == 0)
				printf_s("\tнет просроченных товаров");
			printf_s("\n");
		}
		free(milk_prod);
	}
	else if (N == 2)
	{
		char vse_ampl[] = "Gk  SW  RB  LB  CB  RWB LWB CDM RM  CM  LM  RWM LWM CAM Rf  Cf  Lf  RS  LS  ST  ";
		char * ptr_a = &vse_ampl[0];
		char buf[] = "LWB";
		int kolvo = 15;
		int flag = 0;
		Hockey * Hk_st = (Hockey *)malloc(kolvo * sizeof(Hockey));

		if (Hk_st == NULL)
			printf_s("память не выделена");
		else
		{
			for (int i = 0; i < kolvo; i++)
			{
				(Hk_st + i)->FIO = (char*)malloc(25 * sizeof(char));
				sozd_txt((Hk_st + i)->FIO, 25);

				(Hk_st + i)->gde_r = (char*)malloc(12 * sizeof(char));
				sozd_txt((Hk_st + i)->gde_r, 12);
				(Hk_st + i)->god_r = Enuma(1982, 25);
				(Hk_st + i)->amplua = buf;


				//int ind = rand() % 20;
				//char buf[4];
				//strncpy_s(buf, 4, (ptr_a + 4*ind), 4);
				//(Hk_st + i)->amplua = buf;

				(Hk_st + i)->club = (char*)malloc(8 * sizeof(char));
				sozd_txt((Hk_st + i)->club, 8);

				(Hk_st + i)->cnt_games = Enuma(20, 40);
				(Hk_st + i)->cnt_yelcrd = Enuma(1, 3);

			}

			printf_s("Игроки------------------------где и год род. -----------ampl-------club----игры-----жел.к\n");
			for (int i = 0; i < kolvo; i++)
				print_Hockey(Hk_st, i);
			printf_s("\n");
			printf_s("2. сведения о футболистах, старше 20 - ти лет и получающих не более 1 карточки за 10 игр:\n");
			for (int i = 0; i < kolvo; i++)
			{
				if (((2018 - (Hk_st + i)->god_r) > 20) && (((Hk_st + i)->cnt_yelcrd) * 10 < (Hk_st + i)->cnt_games))
					printf_s("FIO-%s  vozr --%d  Yellow c- %d  games -- %d\n", (Hk_st + i)->FIO, (2018 - (Hk_st + i)->god_r), (Hk_st + i)->cnt_yelcrd, (Hk_st + i)->cnt_games);
			}
			printf_s("9. сведения о защитниках, младше 20-ти лет и сыгравших за свой клуб более 40-ка матчей:\n");
			for (int i = 0; i < kolvo; i++)
			{
				if (((Hk_st + i)->amplua == "LWB") && (2018 - (Hk_st + i)->god_r < 20) && ((Hk_st + i)->cnt_games > 40))

					/*if ((((Hk_st + i)->amplua) == "LWB") || (((Hk_st + i)->amplua) == "SW ")||
					(((Hk_st + i)->amplua) == "RB ") || (((Hk_st + i)->amplua) == "LB ")||
					(((Hk_st + i)->amplua) == "CB ") || (((Hk_st + i)->amplua) == "RWB"))*/

					print_Hockey(Hk_st, i);
				flag = 1;
			}
			if (flag == 0)
				printf_s(" таких игроков нет\n");
		}
		free(Hk_st);
	}
	else if (N == 3)
	{
		
		int kolvo = 8;
		char dat51[] = "06.17";
		int vr_total = 0;
		int speed = 0;
		int max = 0;
		int ind = 0;

		reis * Almt = (reis *)malloc(kolvo * sizeof(reis));

		if (Almt == NULL)
			printf_s("память не выделена");
		else
		{
			for (int i = 0; i < kolvo; i++)
			{
				(Almt + i)->N_reis = Enuma(708000, 1000);
				(Almt + i)->marka = (char*)malloc(6 * sizeof(char));
				sozd_txt((Almt + i)->marka, 6);

				(Almt + i)->kuda = (char*)malloc(12 * sizeof(char));
				sozd_txt((Almt + i)->kuda, 12);

				(Almt + i)->dt5 = Enuma(1, 31);
				(Almt + i)->dt51 = &dat51[0];

				(Almt + i)->h_otb = Enuma(8, 6);
				(Almt + i)->m_otb = Enuma(1, 58);

				(Almt + i)->h_prb = Enuma(16, 4);
				(Almt + i)->m_prb = Enuma(1, 58);

				(Almt + i)->Skm = Enuma(2500, 1500);
			}

			printf_s("№ рейса Марка ТС Пункт приб      Дата отб      Вр отб Вр приб Расстояние\n");
			for (int i = 0; i < kolvo; i++)
				print_reis(Almt, i);

			printf_s("6. Вывод данных об авиарейсе с максимальной скоростью \n");
			for (int i = 0; i < kolvo; i++)
			{
				vr_total = 60 * (Almt + i)->h_prb + -60 * (Almt + i)->h_otb + (Almt + i)->m_otb;
				speed = (Almt + i)->Skm / (vr_total / 60);
				if (speed > max)
				{
					max = speed; ind = i;
				}
			}
			printf_s("Расст - %d км, cкорость - %d км/ч\n", (Almt + ind)->Skm, max);
			print_reis(Almt, ind);
			printf_s("\n");

			printf_s("10. Вывод данных об авиарейсе с максимальной длительностью полета.\n");
			max = 0;
			for (int i = 0; i < kolvo; i++)
			{
				vr_total = 60 * (Almt + i)->h_prb + -60 * (Almt + i)->h_otb + (Almt + i)->m_otb;
				if (vr_total > max)
				{
					max = vr_total; ind = i;
				}
			}
			int chs = max / 60;
			int min = max % 60;
			printf_s("км - %d, время в полете - %d ч %d мин\n", (Almt + ind)->Skm, chs, min);
			print_reis(Almt, ind);
			printf_s("\n");
		}
	}
	
	system("pause");
}