

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <locale.h>
#include <Windows.h>
#include <time.h>
#include "Header.h"

int Enuma(int strt, int fl)
{
	int res = 0;
	res = strt + rand() % fl;
	return res;
}
void sozd_txt(char * name, int dlina)
{
	if (dlina == 0)
		dlina = 20 + rand() % 6;
	for (int i = 0; i < dlina; i++)
	{
		if (i == 0)
			*(name + i) = (char)(65 + rand() % 24);
		else
			*(name + i) = (char)(97 + rand() % 24);
	}
	*(name + dlina) = '\0';
}
void print_Tovar(Tovar * milk_prod, int i)
{
	printf("%12s \t%8s   %2d.%2d \t%2d.%2d  %6d   %d     %d \n",
		(milk_prod + i)->entitle,
		(milk_prod + i)->vendor,
		(milk_prod + i)->DD_made,
		(milk_prod + i)->MM_made,
		(milk_prod + i)->DD_save,
		(milk_prod + i)->MM_save,
		(milk_prod + i)->serial_N,
		(milk_prod + i)->quantity,
		(milk_prod + i)->price);
}
void print_Hockey(Hockey * Hk_st, int i)
{
	printf("%25s \t%12s \t%d \t%4s \t%8s \t%d \t%d \n",
		(Hk_st + i)->FIO,
		(Hk_st + i)->gde_r,
		(Hk_st + i)->god_r,
		(Hk_st + i)->amplua,
		(Hk_st + i)->club,
		(Hk_st + i)->cnt_games,
		(Hk_st + i)->cnt_yelcrd);
}
void print_reis(reis * Almt, int i)
{
	printf("%6d \t%6s \t%12s  \t%2d.%s \t%2d:%2d \t%2d:%2d \t%d \n",
		(Almt + i)->N_reis,
		(Almt + i)->marka,
		(Almt + i)->kuda,
		(Almt + i)->dt5,
		(Almt + i)->dt51,
		(Almt + i)->h_otb,
		(Almt + i)->m_otb,
		(Almt + i)->h_prb,
		(Almt + i)->m_prb,
		(Almt + i)->Skm);

}