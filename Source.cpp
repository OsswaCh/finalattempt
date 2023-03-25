#include <iostream>
#include <fstream>
#include <queue>
#include "customer.h"
#include "mechanic.h"
#include "queuee.h"
using namespace std;

//make sure to revise the queuee class
//why is the name of the mech not showing

template<typename t>
void showq(queue<t> gq)
{

	queue<t> cq = gq;
	while (!cq.empty()) {
		cout << '\t';
		cout << cq.front().getName() << " at ";
		cq.front().getapp();
		cout << "with";
		customer* p = &cq.front();
		p->getMechName();
		cq.pop();
		cout << '\n';
	}
	cout << '\n';
}

template<typename T>
void sort(queue<T>& q, int size) {
	if (q.size() <= 1) {
		return;
	}
	int n = q.size();
	T x = q.front();
	q.pop();
	sort(q, size);
	int count = 0;
	queue<T> smaller, greater;
	while (!q.empty()) {
		if (q.front() < x) {
			smaller.push(q.front());
		}
		else {
			greater.push(q.front());
		}
		q.pop();
	}
	while (!smaller.empty()) {
		q.push(smaller.front());
		smaller.pop();
	}
	q.push(x);
	while (!greater.empty()) {
		q.push(greater.front());
		greater.pop();
	}
}




int main() {
	
	string aux;
	int sizeM=10; int sizeC;
	//cout << "how many mechanics do you have?" << endl;
	//cin >> sizeM;
	//cout << "how many customers do you expeect to have?" << endl;
	//cin >> sizeC;

	ifstream mechanics("mechanics.txt");
	ifstream customers("customers.txt");
	
	mechanic* Mlist = new mechanic[5];
	customer* Clist = new customer[5];
	queue <customer> orgClient;

	int i = 0; int j = 0;
	while (getline(mechanics, aux)) {
		(Mlist + i)->setName(aux);
		getline(mechanics, aux);
		(Mlist + i)->setAge(stoi(aux));
		getline(mechanics, aux);
		(Mlist + i)->setID(stoi(aux));
		getline(mechanics, aux);
		int numapp = stoi(aux);
		while (numapp) {
			getline(mechanics, aux);
			int h = stoi(aux);
			getline(mechanics, aux);
			int m = stoi(aux);
			(Mlist + i)->addapp(h, m,"");
		}
		i++;
	}
	while (getline(customers, aux)) {
		(Clist + i)->setName(aux);
		getline(customers, aux);
		(Clist + i)->setAge(stoi(aux));
		getline(customers, aux);
		(Clist + i)->setID(stoi(aux));
		getline(customers, aux);
		int numapp = stoi(aux);
		while (numapp) {
			getline(customers, aux);
			int h = stoi(aux);
			getline(customers, aux);
			int m = stoi(aux);
			(Clist + i)->setApp(h, m);
		}
		j++;
	}

	//for (int k = 0; k < 1; k++) {
	//	string name; int id; int age; 
	//	//cout << "enter the mechanic name";
	//	//cin >> name;
	//	///*cout << "enter the mechanic age";
	//	//cin >> age;
	//	//cout << "enter the mechanic id";
	//	//cin >> id;*/
	//	//(Mlist + k)->setName(name);
	//	///*(Mlist + k)->setAge(age);
	//	//(Mlist + k)->setID(id);*/
	//	(Mlist + k)->setName("mohammed"+to_string(k));
	//	i++;
	//}

	//for (int k = 0; k < 1; k++) {
	//	string name; int id; int age; int h; int m;
	//	/*cout << "enter the customer name";
	//	cin >> name;*/
	//	/*cout << "enter the customer age";
	//	cin >> age;
	//	cout << "enter the customer id";
	//	cin >> id;*/
	//	cout << "enter the customer hour";
	//	cin >> h;
	//	cout << "enter the customer min";
	//	cin >> m;

	//	(Clist + k)->setName("yomna" + to_string(k));
	//	/*(Clist + k)->setAge(age);
	//	(Clist + k)->setID(id);*/
	//	(Clist + j)->setApp(h, m);
	//	j++;
	//}

	//for (int k = 0; k < i; k++) {
	//	(Mlist + k)->printinfo();
	//}
	//for (int k = 0; k < j; k++) {
	//	(Clist + k)->printinfo();
	//}

	int n = 0; int m = 0;
	while (n<j) {
		
		if ((Mlist + m)->isAvailable((Clist + n)->getH(), (Clist + n)->getM())) {
			(Mlist + m)->addapp((Clist + n)->getH(), (Clist + n)->getM(), (Clist + n)->getName());
			orgClient.push(*(Clist + n));
			(Clist + n)->setMech((Mlist + m%i)->getName());
			(++n); (++m);
		}
		else
			m=(++m) % i;
	}

	for (int k = 0; k < j; k++) {
		(Clist + k)->getMechName();
		cout << endl;
	}

	cout << "before";


	showq<customer>(orgClient);
	sort(orgClient,j);
	cout << "after";
	showq<customer>(orgClient);
	
	mechanics.close();
	customers.close();
	return 0;
}