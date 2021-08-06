#include <inttypes.h>
#include <iostream>
#include <thread>
#ifndef LIST_H
#define LIST_H

template <typename T>
class Element{
	private:
		Element<T>* next_element;
		Element<T>* prev_element;
		T value;
	public:
		Element(T value);
		T get_value();
		void set_next_elem(Element<T>* next);
		void set_prev_elem(Element<T>* prev);
		Element<T>* get_next_elem();
		Element<T>* get_prev_elem();
};

template <typename T>
class List{
	private:
	    Element<T>* first_element;
	    Element<T>* current_element;
	public:
		List(T value);
		void add_end(T value); //добавление в конец 
		void add_front(T value); //добавление в начало 
		void add_pos(T value, int32_t pos); //добавить на определнную 
		void delete_end(); //удалить последний элемент
		void delete_front(); //Lудалить первый элемент
		void delete_pos(int32_t pos); // удалить с определенной позиции
		void reverse(); //реверс спискаS
		int32_t get_length();
		void print(); //вывести список
		void set_Element(Element<T>*, char[]);
		Element<T>* get_Element(char[]);
		

		//Переопоределение операторов
		friend std::ostream& operator<<(std::ostream&, List<double>&);

};

template class List<double>;
template class List<int>;


#endif