#include "DonationRequest.h"
DonationRequest::DonationRequest() {

}
DonationRequest::DonationRequest(string t, string Q, date r_date, date e_date, string d) {
	type = t;
	Quantity = Q;
	received_date = r_date;
	expiry_date = e_date;
	donor = d;
}