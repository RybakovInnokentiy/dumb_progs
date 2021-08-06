#include <inttypes.h>
#include <iostream>
#include "List.h"
#include <conio.h>
#include <stdlib.h>
using namespace std;

//Class Element
template <typename T>
Element<T>::Element(T value){
	this->value = value;
	this->next_element = NULL;
	this->prev_element = NULL;
}

template <typename T>
T Element<T>::get_value(){
	return this->value;
}

template <typename T>
void Element<T>::set_next_elem(Element<T>* next){
	this->next_element = next;
}

template <typename T>
void Element<T>::set_prev_elem(Element<T>* prev){
	this->prev_element = prev;
}

template <typename T>
Element<T>* Element<T>::get_next_elem(){
	return this->next_element;
}

template <typename T>
Element<T>* Element<T>::get_prev_elem(){
	return this->prev_element;
}

//Class List
template <typename T>
List<T>::List(T value){
	Element<T>* init_element = new Element<T>(value);
	this->first_element = init_element;
	this->current_element = init_element;	
}

template <typename T>
void List<T>::set_Element(Element<T>* element, char which_elem[]){
	if(which_elem == "first_element") this->first_element = element;
	else if(which_elem == "current_element") this->current_element = element;
}

template <typename T>
Element<T>* List<T>::get_Element(char which_elem[]){
	Element<T>* ret_element = NULL;
	if(which_elem == "first_element") ret_element = first_element;
	else if(which_elem == "current_element") ret_element = current_element;
	return ret_element;
}

template <typename T>
void List<T>::add_end(T value){
	Element<T>* new_element = new Element<T>(value);
	this->current_element->set_next_elem(new_element);
	new_element->set_prev_elem(this->current_element);
	this->current_element = new_element;
}

template <typename T>
void List<T>::add_front(T value){
	Element<T>* new_element = new Element<T>(value);
	new_element->set_next_elem(this->first_element);
	this->first_element->set_prev_elem(new_element);
	this->first_element = new_element;
}

template <typename T>
void List<T>::add_pos(T value, int32_t pos){
	Element<T>* new_element = new Element<T>(value);
	Element<T>* current_elem = this->first_element;
	for (int32_t i = 0; i < pos - 1; i++){
		current_elem = current_elem->get_next_elem();
	}
	new_element->set_prev_elem(current_elem);
	new_element->set_next_elem(current_elem->get_next_elem());
	current_elem->get_next_elem()->set_prev_elem(new_element);
	current_elem->set_next_elem(new_element);
}

template <typename T>
void List<T>::delete_end(){
	this->current_element = this->current_element->get_prev_elem();
	delete this->current_element->get_next_elem();
	this->current_element->set_next_elem(NULL);
}

template <typename T>
void List<T>::delete_front(){
	this->first_element = this->first_element->get_next_elem();
	delete this->first_element->get_prev_elem();
	this->first_element->set_prev_elem(NULL);
}

template <typename T>
void List<T>::delete_pos(int32_t pos){
	Element<T>* current_elem = this->first_element;
	Element<T>* deleted_elem = NULL;
	for (int32_t i = 0; i < pos; i++)
		current_elem = current_elem->get_next_elem();
	deleted_elem = current_elem;
	current_elem = current_elem->get_next_elem();
	current_elem->set_prev_elem(deleted_elem->get_prev_elem());
	deleted_elem->get_prev_elem()->set_next_elem(current_elem);
	delete deleted_elem;
}

template <typename T>
int32_t List<T>::get_length(){
	int32_t length = 0;
	Element<T>* current_elem = this->first_element;
	while(current_elem){
		length++;
		current_elem = current_elem->get_next_elem();
	}
	return length;
}
//Реверс списка
template <typename T>
void List<T>::reverse(){
	List<T>* reversed_list = new List(0);
	Element<T>* current_elem = this->current_element;
	Element<T>* prev_elem = current_elem->get_prev_elem();
	int32_t length = this->get_length();
	for(int32_t i = 0; i < length; i++){
		if(i==0){
			current_elem->set_prev_elem(NULL);
			this->first_element = current_elem; 	
		} 
		else{
			current_elem->set_prev_elem(current_elem->get_next_elem());	
		} 

		if(i==length-1){
			current_elem->set_next_elem(NULL);
			this->current_element = current_elem;
		}
		else{
			current_elem->set_next_elem(prev_elem);
			current_elem = prev_elem;
			prev_elem = current_elem->get_prev_elem();
		}
	}
}

//Вывод списка
template <typename T>
void List<T>::print(){
	Element<T>* current_elem = this->first_element;
	while(current_elem){
		cout << current_elem->get_value() << "\t";
		current_elem = current_elem->get_next_elem();
	}
	cout << endl;
}

//переопределение операторов


ostream& operator<<(ostream& out, List<double>& list){
	Element<double>* current_elem = list.first_element;
	while(current_elem){
		out << current_elem->get_value() << "\t";
		current_elem = current_elem->get_next_elem();
	}
	out << endl;
	return out;
}


