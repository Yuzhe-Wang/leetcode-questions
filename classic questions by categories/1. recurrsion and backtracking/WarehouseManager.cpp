#include <iostream>
#include <list>
#include <unordered_map>
#include <priority_queue>

using namespace std;

class WarehouseManager {

	/**
	* Add a new product to the warehouse.
	* 
	* @param productId The product’s ID. Unique to a product but there can be multiple copies of the same product in the warehouse
	* @returns The number of those products currently in the warehouse
	*/
	public:
    int addProduct(int productId) {
		// todo
        int result = 0;
        if(record.find(productId) == record.end()) {
            result = 1;
            record[productId] = result;
        } else {
            result = ++ record[productId];
        }
        return result;
	}

	/**
	* Ships the given order. This requires removing the products from the warehouse.
	*
	* @param products A list of product IDs
	* @returns Whether or not we were able to ship the order. In order to ship an order, we must have all of the products in stock.
	*/
	bool shipOrder(list<int> products) { // item exists, enough number
		// todo
        // construct a check map
        unordered_map<int,int> order;
        for(int curr: products) {
            if(order.find(curr) == order.end()) {
                order[curr] = 1;
            } else {
                order[curr] ++;
            }
        }

        // check if the order can be fullfilled
        for(const auto& i: order) {
            if(record.find(i.first) == record.end() || i.second > record[i.first]) {
                return false;
            }
        }

        // complete the order since it's valid up to here
        for(const auto& j: order) {
            record[j.first] -= j.second;
        }
        return true;
	}

    /* 3. Return_order:
    Given a list of ids, find out if all the products can be returned to the warehouse or not.
    input: ar‍‌‌‍‍‌‌‍‍‍‌‌‍‌‍‌‌‍‍‌ray of id numbers
    output: true/false */

    bool returnOrder(list<int> products) {
        for(int i: products) {
            if(record.find(i) == record.end()) {
                return false;
            }
        }

        for(const int& i: products) {
            record[i] ++;
        }
        return true;
    }

    // 4. FIFO queue implementation of add_product
    int addProduct(int productId, float timeStamp) {
        int result = 0;
        if(record.find(productId) == record.end()) {
            priority_queue<int> temp;
            temp.push(timeStamp);
            record[productId] = temp;
            result = 1;
        } else {
            record[productId].push(timeStamp);
            result = record[productId].size();
        }
        return result;
    }

    // 5. FIFO queue implementation of ship_order
    bool shipOrder(list<int> products) {

        // construct a check map
        unordered_map<int,int> order;
        for(int curr: products) {
            if(order.find(curr) == order.end()) {
                order[curr] = 1;
            } else {
                order[curr] ++;
            }
        }

        for(const auto& i: order) {
            if(record.find(i.first) == record.end() || i.second > record[i.first].size()) {
                return false;
            }
        }

        for(const auto& j: order) {
            record[j.first].pop();
        }
        return true;
    }

    private:
    unordered_map<int,int> record;
    unordered_map<int,priority_queue<int>> record;
};