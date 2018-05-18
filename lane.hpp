#ifndef LANE_HPP
#define LANE_HPP

#include "customer.hpp"
#include <iostream>

class Lane{
	public:
		Lane();
		void enqueue(int ID, int arrivalTime, int serviceTime);
		Customer* dequeue();
		Customer* peek();
		int getTotalTime();
		int getSize();
		void updateTimes();
	private:
		Customer *head;
		Customer *tail;
};

#endif