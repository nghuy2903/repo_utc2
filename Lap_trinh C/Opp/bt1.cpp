#include <iostream>

using namespace std;

int main() {
    int month, year;

    cin >> month;
    cin >> year;
    if(month < 1 || month > 12) {
        if(year <= 1975 || year >= 2019){
        cout << "Thang khong hop le.Nam khong hop le.";
        return 0;}
        }
    if (month < 1 || month > 12) {
            cout << "Thang khong hop le.";
        }
    
    else if (year <= 1975 || year >= 2019) {
        cout << "Nam khong hop le." << endl;
        return 0;
        } 
        // Kiểm tra tháng không hợp lệ
         else {
            // Kiểm tra số ngày trong tháng
            int days_in_month;
            if (month == 2) {
                // Xét tháng 2 và kiểm tra năm nhuận
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    days_in_month = 29;
                } else {
                    days_in_month = 28;
                }
            } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                days_in_month = 30;
            } else {
                days_in_month = 31;
            }

            cout  << days_in_month;
        }

    return 0;
}
