//can run on Windows/Linux
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
void make_date(char * target,int year,int mon,int day,int hour,int min,int sec,int ms){
	target[0]=year-1900;
	target[1]=mon;
	target[2]=day;
	target[3]=hour;
	target[4]=min;
	target[5]=sec;
	target[6]=ms;
}
void fwkg(char* str, int len) {
    for (int i = 0; i < len; i++) {
        str[i] = 0x20;
    }
}
struct w {
    unsigned char len = 0x22;
    unsigned char kzlen = 0;
    char lba_lsb[4] = { 0x14,0,0,0 };
    char lba_msb[4] = { 0,0,0,0x14 };
    char filelen_lsb[4] = { 0,0x08,0,0 };
    char filelen_msb[4] = { 0,0,0x08,0 };
    char date[7]={121,2,24,9,30,8,0};
    
    char wjbz = 2;
    char wy[2] = { 0,0 };
    char vn_lsb[2] = { 1,0 };
    char vn_msb[2] = { 0,1 };
    char fnlen = 1;
};
struct isohead {
    unsigned char lx = 1;
    char cd001_1[5] = { 'C','D','0','0','1' };
    unsigned char ms = 0x01;
    char wy1 = 0;
    char systemname[32] = { "Windows                        " }; 
    
    char vname[32] = { "Hello World!                   " };
    char wy2[8] = { 0,0,0,0,0,0,0,0 };
    char vl1= 0xbf;
    char vl_1 = 0x75;
    char vl_2 = 0;
    char vl_3 = 0;
    char vl_4 = 0;
    char vl_5 = 0;
    char vl_6 = 0x75;
    char vl2 = 0xbf;
    long long wy4 = 0;
    long long wy5 = 0;
    long long wy6 = 0;
    long long wy7 = 0;
    char dn1 = 1;
    char dn2 = 0;
    char dn3 = 0;
    char dn4 = 1;
    char vn1 = 1;
    char vn2 = 0;
    char vn3 = 0;
    char vn4 = 1;
    char k11_1 = 0x00;
    char k11_2 = 0x08;
    char kl2_1 = 0x08;
    char k12_2 = 0x00;
    char ll1[4] = { 0x0A,0,0,0 };
    char ll2[4] = { 0,0,0,0x0A };
    char lsblt[4] = { 0x12,0x00,0x00,0x00 };
    int kxlsb = 0;
    char msblt[4] = { 0x00,0x00,0x00,0x13 };
    int kxmsb = 0;
    //list table
    char ltsize = 0x22;
    char kzsize = 0;
    char fw[8] = { 0x14,0,0,0,0,0,0,0x14};
    char cd[8] = {0,0x08,0,0,0,0,0x08,0};
    char date[7]={121,2,24,9,30,8,0};
    char bz = 2;
    short wy8 = 0;
    char vnumber[4] = { 1,0,0,1 };
    char wy9 = 1;
    char filename = 0x00;
    char k2[623] = { 0 };
    char createdate[17] = { '2','0','2','1','0','2','2','4','0','9','3','0','0','8','0','0',' ' };
    char editdate[17] = { '2','0','2','1','0','2','2','4','0','9','3','0','0','8','0','0',' ' };
    char sxdt[17] = { "0000000000000000" };
    char gsdt[17] = { "0000000000000000" };
    char ver = 1;
    char wy10[1166] = { 0 };
};
struct overisohead {
    char ver = 255;
    char a[6] = { "CD001" };
    char wy[2041] = { 0 };
};
struct dir_list {
    w w1;
    char x = 0;
    char wy1[2015] = {0};
};
struct list_table {
    char len = 1;
    char kzlen = 0;
    char lba[4] = { 0,0,0,0 };
    char pdn = 1;
    char wy[2041] = { 0 };
};
int main()
{
    
    long long f_l = 0x0d;
    char data[2048] = { 0 };
    isohead iso1;
    overisohead o1;
    dir_list fList;
    list_table LSB_lt;
    LSB_lt.len = 1;
    LSB_lt.lba[0] = 0x14;
    list_table MSB_lt;
    MSB_lt.len = 1;
    MSB_lt.lba[3] = 0x14;
    w hw_gdir;
    w hw;
    hw.wjbz = 0;
    iso1.systemname[31] = ' ';
    iso1.vname[31] = ' ';
	hw.filelen_lsb[0] = 0x0d;
    hw.filelen_lsb[1] = 0x00;
    hw.filelen_lsb[2] = 0x00;
    hw.filelen_lsb[3] = 0x00;
    hw.filelen_msb[0] = 0x00;
    hw.filelen_msb[1] = 0x00;
    hw.filelen_msb[2] = 0x00;
    hw.filelen_msb[3] = 0x0d;
    hw.lba_lsb[0] = 0x16;
    hw.lba_msb[3] = 0x16;
    hw.fnlen = 5;
    hw.len = 0x26;
    char fn[5] = { '1','.','t','x','t'};
    ifstream fin("hw.txt", ios::binary | ios::in);
    ofstream fout("output.iso", ios::out | ios::binary);
    char bl_0 = 0;
    for (int i = 0; i < 32768; i++) {
        fout.write(&bl_0, 1);
    }
    fwkg(iso1.k2, 623);
    fout.write((char*)&iso1, 2048);
    fout.write((char*)&o1, 2048);
    //fout.write(data, 2048);
    fout.write((char*)&LSB_lt, 2048);
    fout.write((char*)&MSB_lt, 2048);
    fout.write((char*)&hw_gdir, sizeof(hw_gdir));
    fout.write(data, 1);
    fout.write((char*)&hw, sizeof(hw));
    fout.write(fn, 5);
    fout.write(data, 2048 - sizeof(hw) - sizeof(hw_gdir)-6);
    fout.write(data, 2048);
    char tmpd[10000];
    for (long long i = f_l; i > 0; i -= 9999) {
        fin.read(tmpd, i>9999?9999:i);
        fout.write(tmpd, i > 9999 ? 9999 : i);
    }
    fout.close();
    return 0;
}
