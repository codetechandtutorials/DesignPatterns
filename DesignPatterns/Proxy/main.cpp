#include "proxy.h"
#include <iostream>
int main() {
	// real store
	ItemRequest our_store_front;
	our_store_front.AddInventory(ItemForSale(123, 10, 1));
	our_store_front.AddInventory(ItemForSale(456, 2, 2));
	our_store_front.AddInventory(ItemForSale(543, 15, 1));
	our_store_front.AddInventory(ItemForSale(233, 6, 1));
	our_store_front.AddInventory(ItemForSale(434, 9, 1));
	our_store_front.AddInventory(ItemForSale(665, 1, 1));

	// proxy it
	CheckBeforeItemRequest proxy_store(&our_store_front);
	proxy_store.AddInventory(ItemForSale(277, 2, 2));


	// client
	PaymentType our_payment = PaymentType::CREDIT;

	auto return_code = proxy_store.RequestItem(234, our_payment);
	std::cout << "return code for purchase 234: " << return_code << '\n';


	auto return_code2 = proxy_store.RequestItem(233, our_payment);
	std::cout << "return code for purchase 233: " << return_code2 << '\n';
}