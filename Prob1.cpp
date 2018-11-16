#include <iostream>
#include <map> //Biblioteca do map

using namespace std;

int main() {
	map <string,double> items;
	int cases,number,list;
	double price,total = 0;
	string product;
	cin >> cases;
	while(cases--) {
		cin >> list;
		while(list--) {
			cin >> product >> price;
			items.insert(make_pair(product,price));
		}
		cin >> list;
		while(list--) {
			cin >> product >> number;
			if(items.find(product) != items.end()) {
				total += items[product] * number;
			}
		}
		items.clear();
		printf("R$ %.2f\n",total);
		total = 0;
	}
	return 0;
}