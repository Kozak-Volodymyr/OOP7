#include<fstream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
template<template<class,class>class Container,class Value>
class Vector {
public:
	 Container<Value, std::allocator<Value>>v;
	 void Add() {
		  int n;
		  printf("\n ¬вед≥ть к≥льк≥сть елемент≥в:");
		  cin >> n;
		  getchar();
		  Value *p;
		  p = new Value[n];
		  for (int i = 0; i < n; i++) {
				if (sizeof(p[i]) == 4) {
					 cin >> p[i];
				}
				else {
					 getline(cin, p[i]);
				}
		  }
		  for (int i = 0; i < n; i++) {
				v.push_back(p[i]);
		  }
		  delete[]p;
	 }
	 void Add_file() {
		  string n;
		  printf("\n ¬вед≥ть ≥м'€ файлу:");
		  cin >> n;
		  Value s;
		  ifstream infile(n);
		  while (!infile.eof()) {
				infile >> s;
				v.push_back(s);
		  }
	 }
	 friend ostream& operator<<(ostream&out, Vector&v) {
		  int i = 0;
		  printf("\n ≈лементи вектора:");
		  while (i<v.v.size()) {
				out << v.v[i]<<" ";
				i++;
		  }
		  return out;
	 }
}; 
template<template<class, class>class Container, class Value>
class Operation{
public:
	 Container<Value, std::allocator<Value>>obj;
	 Container<Value, std::allocator<Value>>obj1;
	void Add(Vector<vector, Value>&v1, Vector<vector, Value>&v2) {
		  obj = v1.v;
		  obj1 = v2.v;
	 }
	vector<Value> Change() {
		 vector<Value>obj3;
		 typename std::vector<Value>::iterator i = obj.begin();
		 typename std::vector<Value>::iterator l = obj1.begin();
		 while (i != obj.end() && l != obj1.end()) {
			  if (*i > *l) {
					obj3.push_back(*i);
					i++;
					if (i == obj.end()) {
						 while (l != obj1.end()) {
							  obj3.push_back(*l);
							  l++;
						 }
					}
			  }
			  else {
					obj3.push_back(*l);
					l++;
					if (l == obj1.end()) {
						 while (i != obj.end()) {
							  obj3.push_back(*i);
							  i++;
						 }
					}

			  }
		 }
			  return obj3;
		 }
	vector<Value>Conratena(){
		 vector<Value>obj3;
		 int size;
		 typename std::vector<Value>::iterator i = obj.begin();
		 typename std::vector<Value>::iterator l = obj1.begin();
		 if (obj.size() > obj1.size()) {
			  size = obj.size();
		 }
		 else
			  size = obj1.size();
		 while (obj3.size()<size) {
			  if (i == obj.end()) {
					while (l != obj1.end()) {
						 obj3.push_back(*l);
						 l++;
					}
			  }
			  if (l == obj1.end()) {
					while (i != obj.end()) {
						 obj3.push_back(*i);
						 i++;
					}
			  }
			  if (i != obj.end() && l != obj1.end()) {
					obj3.push_back(*i + *l);
					i++;
					l++;
			  }
		 }
		 return obj3;
	}
	 };
template<class T>
ostream& operator<<(ostream&out, vector<T>&v) {
	 int i = 0;
	 printf("\n ≈лементи масиву:");
	 while (i < v.size()) {
		  out << v[i]<<" ";
		  i++;
	 }
	 return out;
}
template<class T> 
void  operator>>(string name, vector<T>&v1) {
	 int i = 0;
	 ofstream file;
	 file.open(name);
	 while (i < v1.size()) {
		  file << v1[i];
		  i++;
	 }
}
int main() {
	 system("chcp 1251");
	 Vector<std::vector, string> obj,obj1;
	 int i;
	 cout << "\n —пос≥б опрацюванн€ файл≥в(1-введенн€,2-файл):";
	 cin >> i;
	 switch (i) {
	 case 1:
	  obj.Add();
	  obj1.Add();
	  break;
	 case 2:
		  obj.Add_file();
		  obj1.Add_file();
		  break;
	 }
	 cout << obj<<endl;
	 cout << obj1 << endl;
	 vector<string>obj2;
	 Operation<std::vector,string>a; 
	 a.Add(obj1, obj);
	 obj2=a.Conratena();
	 cout << obj2<<endl;
	 /*string f; 
	 printf("\n ¬вед≥ть назву файлу:");
	 getline(cin, f);
	 f >> obj2;*/
	 return 0;
}