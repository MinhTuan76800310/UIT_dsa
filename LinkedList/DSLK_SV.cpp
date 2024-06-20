
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY {
    int Ngay, Thang, Nam;
};
struct SINHVIEN {
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE{
    SINHVIEN key;
    NODE* pNext;
};
struct LIST{
    NODE*pHead, *pTail;
};

void NhapNgay(NGAY &a);
void XuatNgay(NGAY a);
void NhapSinhVien(SINHVIEN &a);
void XuatSinhVien(SINHVIEN a);
NODE* CreateNode(SINHVIEN x);
void CreateEmptyList(LIST &L);
void AddTail(LIST& l, NODE* p);
void add_Y_afterQ(LIST &, NODE*, NODE *);
void XuatDS(LIST L);
void NhapDS(LIST &L, int n);
void ChenGiam(LIST &, SINHVIEN);

int main() {
    LIST L;
    int n;
    SINHVIEN sv;

    NhapSinhVien(sv);

    cin >> n ;
    NhapDS(L, n);

    ChenGiam(L, sv);

    XuatDS(L);

    return 0;
}
void NhapNgay(NGAY &a){
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a){
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a){
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a){
    cout << a.MASV;         cout << "\t";
    cout << a.HoTen;        cout << "\t";
    XuatNgay(a.NgaySinh);   cout << "\t";
    cout << a.GioiTinh;     cout << "\t";
    cout << a.DiemToan;     cout << "\t";
    cout << a.DiemLy;       cout << "\t";
    cout << a.DiemHoa;      cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}
NODE* CreateNode(SINHVIEN x) {
	NODE* p = new NODE;
	p->key = x;
	p->pNext = NULL;
	return p;
}
void CreateEmptyList(LIST &L){
    L.pHead=L.pTail=NULL;
}
void AddTail(LIST& l, NODE* p){
	if (l.pHead == NULL)	{
		l.pHead = l.pTail = p;
		return;
	}
	l.pTail->pNext = p;
	l.pTail = p;
}
void NhapDS(LIST &L, int n) {
    SINHVIEN sv;
    CreateEmptyList(L);
    for(int i=0; i<n; i++) {
        NhapSinhVien(sv);
        AddTail(L, CreateNode(sv));
    }
}
void XuatDS(LIST L) {
    if(L.pHead==NULL) {cout << "Empty List."; return;}
	NODE* p = L.pHead;
    while (p) {
        XuatSinhVien(p->key);
        cout << endl;
        p = p->pNext;
    }
}
void add_Y_afterQ(LIST &L, NODE* Y, NODE *Q) {
	Y->pNext=Q->pNext;
	Q->pNext=Y;
	if(L.pTail==Q)
		L.pTail=Y;
}
void ChenGiam(LIST &L, SINHVIEN sv){
NODE* newNode = CreateNode(sv);

    if (L.pHead == NULL || sv.MASV >= L.pHead->key.MASV) {
        newNode->pNext = L.pHead;
        L.pHead = newNode;
        if (L.pTail == NULL)
            L.pTail = newNode;
        return;
    }

    NODE* iteratorNode = L.pHead;
    while (iteratorNode->pNext != NULL && sv.MASV < iteratorNode->pNext->key.MASV) {
        iteratorNode = iteratorNode->pNext;
    }

    newNode->pNext = iteratorNode->pNext;
    iteratorNode->pNext = newNode;

    if (newNode->pNext == NULL)
        L.pTail = newNode;
}
