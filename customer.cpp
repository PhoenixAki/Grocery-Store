#include "customer.hpp"

Customer::Customer(int ID, int arrivalTime, int serviceTime){
    this->ID = ID;
    this->arrivalTime = arrivalTime;
    this->serviceTime = serviceTime;
    next = nullptr;
}

Customer* Customer::GetNext(){
	return next;
}

void Customer::SetNext(Customer* next){
	this->next = next;
}