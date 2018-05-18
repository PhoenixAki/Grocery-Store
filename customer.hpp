#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

class Customer {
	public:
		Customer(int ID, int arrivalTime, int serviceTime);
		int ID;
		int arrivalTime;
		int serviceTime;
		Customer* GetNext();
		void SetNext(Customer* next);
	private:
		Customer *next;
};

#endif

/*
	* ID, arrivalTime, serviceTime left as public for ease of access
	* next left as private to protect information
*/