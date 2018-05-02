#pragma once

struct Tovar                 
{
	char *entitle;
	char *vendor;
	int DD_made;
	int MM_made;
	int DD_save;
	int MM_save;
	int serial_N;
	int	quantity;
	int price;
};
struct Hockey                
{
	char *FIO;
	char *gde_r;
	int god_r;
	char *amplua;
	char *club;
	int cnt_games;
	int cnt_yelcrd;
};
struct reis                   
{
	int N_reis;
	char * marka;
	char * kuda;
	int dt5;
	char * dt51;
	int h_otb;
	int m_otb;
	int h_prb;
	int m_prb;
	int Skm;
};
int Enuma(int strt, int fl);
void sozd_txt(char * name, int dlina);
void print_Hockey(Hockey * Hk_st, int i);
void print_Tovar(Tovar * milk_prod, int i);
void print_reis(reis * Almt, int i);