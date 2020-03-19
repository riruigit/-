#include<iostream>
using namespace std;
typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型

typedef struct LNode {
	ElemType data; //结点的数据域
	struct LNode *next; //结点的指针域
} LNode, *LinkList; //LinkList为指向结构体LNode的指针类型


bool InitList_L(LinkList &L) { //算法2.6 单链表的初始化
	//构造一个空的单链表L
	L = new LNode; //生成新结点作为头结点，用头指针L指向头结点
	L->next = NULL; //头结点的指针域置空
	return true;
}


void CreateList_H(LinkList &L, int n) { //算法2.11 前插法创建单链表
	//逆位序输入n个元素的值，建立到头结点的单链表L
	LinkList p;
	L = new LNode;
	L->next = NULL; //先建立一个带头结点的空链表
	for(int i=0; i<n; i++) {
		p = new LNode; //生成新结点*p
		cin>>p->data;
		p->next = L->next;
		L->next = p; //将新结点*p插入到头结点之后
	}
} //CreateList_F


void CreateList_R(LinkList &L, int n) { //算法2.12 后插法创建单链表
	//正位序输入n个元素的值，建立带表头结点的单链表L
	LinkList p, r;
	L = new LNode;
	L->next = NULL; //先建立一个带头结点的空链表
	r = L; //尾指针r指向头结点
	for(int i=0; i<n; i++) { //将文件中的信息运用后插法插入到链表中
		p = new LNode;//生成新结点
		cin >> p->data;//输入元素值赋给新结点*p的数据域
		p->next = NULL;
		r->next = p;//将新结点*p插入尾结点*r之后
		r = p;//r指向新的尾结点*p
	}
} //CreateList_L


bool GetElem_L(LinkList L, int i,ElemType &e) { //算法2.7 单链表的取值
	//在带头结点的单链表L中查找第i个元素
	//用e返回L中第i个数据元素的值
	int j;
	LinkList p;
	p = L->next;
	j = 1; //初始化，p指向第一个结点，j为计数器
	while (j < i && p) { //顺链域向后扫描，直到p指向第i个元素或p为空
		p = p->next; //p指向下一个结点
		++j; //计数器j相应加1
	}
	if (!p || j > i)
		return false; //i值不合法i＞n或i<=0
	//取第i个结点的数据域
//	return p->data;
	e=p->data;
	return true;
} //GetElem_L


LNode *LocateElem_L(LinkList L, ElemType e,ElemType &k) { //算法2.8 按值查找
	//在带头结点的单链表L中查找值为e的元素
	LinkList p;
	p = L->next;
	while (p && p->data!= e)//顺链域向后扫描，直到p为空或p所指结点的数据域等于e
		p = p->next;
	k++;//p指向下一个结点
	return p; //查找成功返回值为e的结点地址p，查找失败p为NULL
} //LocateElem_L


bool ListInsert_L(LinkList &L, int i, ElemType e) { //算法2.9 单链表的插入
	//在带头结点的单链表L中第i个位置插入值为e的新结点
	int j;
	LinkList p, s;
	p = L;
	j = 0;
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}//查找第i?1个结点，p指向该结点
	if (!p || j > i - 1)
		return false; //i＞n+1或者i＜1
	s = new LNode; //生成新结点*s
	s->data = e; //将结点*s的数据域置为e
	s->next = p->next; //将结点*s的指针域指向结点ai
	p->next = s; //将结点*p的指针域指向结点*s
	return true;
} //ListInsert_L


bool ListDelete_L(LinkList &L, int i) { //算法2.9 单链表的删除
	//在带头结点的单链表L中，删除第i个位置
	LinkList p, q;
	int j;
	p = L;
	j = 0;
	while ((p->next) && (j < i - 1)) { //查找第i?1个结点，p指向该结点
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1))
		return false; //当i>n或i<1时，删除位置不合理
	q = p->next; //临时保存被删结点的地址以备释放
	p->next = q->next; //改变删除结点前驱结点的指针域
	delete q; //释放删除结点的空间
	return true;
} //ListDelete_L


void print(LinkList L) { /* 单链表元素输出函数 */
	LinkList p;
	p=L->next;
	while(p!=NULL) {
		printf("%d   ",p->data);
		p=p->next;
	}
	cout<<endl;
}


int main() {
	LinkList L,P;
	int choose;
	ElemType q,w,e,r,t,y,u;
	cout << "             单链表的基本操作          \n";
	cout << "                1. 初始化              \n";
	cout << "                2. 输入                \n";
	cout << "                3. 查找                \n";
	cout << "                4. 插入                \n";
	cout << "                5. 删除                \n";
	cout << "                6. 输出                \n";
	cout << "                0. 退出                \n\n";
	choose = -1;
	while (choose != 0) {
		cout<< "请选择:"<<endl;
		cin >> choose;
		switch (choose) {
			case 1://创建单链表
				InitList_L(L);
				cout<<"单链表初始化成功"<<endl;
				break;

			case 2: //单链表信息输入
				cout<<"输入1选择前插法，输入2选择后插法"<<endl;
				cin>>u;
				if(u==1) {
					cout<<"输入单链表的长度"<<endl;
					cin>>q;
					cout<<"输入"<<q<<"个整数"<<endl;
					CreateList_H(L,q);
				} else {
					cout<<"输入单链表的长度"<<endl;
					cin>>q;
					cout<<"输入"<<q<<"个整数"<<endl;
					CreateList_R(L,q);
				}
				break;

			case 3://单链表的取值
				cout<<"单链表的取值，输入第i个元素"<<endl;
				cin>>w;
				if(GetElem_L(L,w,e))
					cout<<"第"<<w<<"个元素的值是"<<e<<endl;
				else cout<<"没有这个值"<<endl;
				break;
			case 4: //单链表的插入
				cout<<"单链表的插入，输入第i个位置和元素"<<endl;
				cin>>r>>t;
				if(ListInsert_L(L, r, t))
					cout<<"插入成功"<<endl;
				else  cout<<"插入失败"<<endl;
				break;

			case 5: //单链表的删除
				cout<<"单链表的删除，输入删除元素的位置"<<endl;
				cin>>y;
				if(ListDelete_L(L, y))
					cout<<"删除成功"<<endl;
				else  cout<<"删除失败"<<endl;
				break;

			case 6: //单链表的输出
				print(L);
				break;
		}
	}
	return 0;
}
