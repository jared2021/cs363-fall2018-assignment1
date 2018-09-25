#include "Array.h"
#include <iostream>

int main (int argc, char * argv [])
{
  // TODO Add code here to test your Array class.
	Array* a=new Array();
  	(*a).size();
  	(*a).max_size();
  	(*a).set(0,'1');
  	(*a).find(1);
  	(*a).find('1',1);
  	(*a).fill('1');
  	(*a).find('1',1);
	//std::cout<<(*a)[0];
	Array* b=new Array(*a);
	//if((*b)==(*a))
	//{
		//std::cout<< 5;
	//}
	//else
	//{
		//std::cout<< -5;
	//}
	Array* c=new Array(5,'2');
	//if((*c)!=(*b))
	//{
		//std::cout<< -7;
	//}
	//else
	//{
		//std::cout<< 7;
	//}
	Array* d=new Array(5);
	(*d) = (*c);
	//std::cout<<(*d)[0];
	//std::cout<<(*d)[1];
	(*c).get(1);
	Array* e=new Array;
	Array* f=new Array;
	(*e)=(*c).slice(2);
	(*f)=(*d).slice(0,2);
	std::cout<< (*e)[0];
	std::cout<< (*e)[1];
	std::cout<< (*f)[0];
	std::cout<< (*f)[1];

  
  	delete a;
	delete b;
	delete c;
	delete d;
  	return 0;
}
