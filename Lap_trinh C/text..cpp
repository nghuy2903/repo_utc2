#include<iostream>


using namespace std;

class ArrayList{
	public:
		static const int MAX_SIZE = 100;
		ArrayList();
		bool isEmpty() const;
		bool isFull() const; // kiem tra day chua
		int length() const; // So luong phan tu
		void insert(const int x, int i); // Chen bat ki
		void remove(const int i); // Xoa bat ki
		void removeLast(); // Xoa cuoi
		void sortASC(); // sap xep tang dan
		void append(const int x);
		void print() const;
		void Menu();
	private:
		int element[MAX_SIZE];
		int last;
};

ArrayList::ArrayList(){
	last = -1;
}

bool ArrayList::isEmpty() const{
	if(last == -1)
		return true;
	else
		return false;
}

int ArrayList::length() const{
	return last+1;
}

void ArrayList::append(const int x){   
	if(last == MAX_SIZE-1)
		cout<<"List is full, cannot append!";
	else{
		element[last+1] = x;
		last = last + 1;
	}
}

bool ArrayList::isFull() const{
	if (last == MAX_SIZE - 1) return true;
	 else return false;
}

void ArrayList::insert(const int x, int i){
	if(i > MAX_SIZE -1 || i < 0) cout << "Vi tri khong hop le!" << endl;
	 else if(i > last ) cout << "Vi tri khong hop le!" << endl ;
	  else {
	 	for (int j = last; j >= i ; j--){
	 		element[j+1] = element[j];
		 }
		 element[i] = x;
		 last ++;
	 }
} 

void ArrayList::removeLast(){
	last -- ;
}

void ArrayList::remove(const int i){
	if(i < 0 || i > MAX_SIZE -1) cout << "Vi tri khong hop le!" << endl;
	 else if(i > last ) cout << "Vi tri khong hop le!" << endl ; 
	 else {
	 	for (int j = i-1; j < last; j++){
	 		element[j] = element[j+1];
		 }
		 last --;
	 }
}

void ArrayList::sortASC(){
	for(int i = 0; i < last; i++){
		int min = i;
		for (int j = i+1; j <= last; j++){
			if(element[min] > element[j]) {
			     min = j;
			}
		}
		int temp = element[i];
		    element[i] = element[min];
		    element[min] = temp;

	}
	
}

void ArrayList::print() const{
	for(int i=0 ; i<=last ; i++){
		cout << element[i] << "\t";
	}
	cout << endl;
}

void Menu(){
	ArrayList List;
		cout << "         MENU:        " << endl; 
		cout << "1.Kiem tra day full chua" << endl;
		cout << "2.Tinh so luong phan tu mang" << endl;
		cout << "3.Chen cuoi" << endl << "4.Chen bat ki" << endl;
		cout << "5.Xoa cuoi" << endl << "6.Xoa bat ki" << endl << "7.Sap xep tang dan" << endl << "0. Thoat" <<endl;
	int n;
	do{
		cout << endl <<  "Chon: " ;
		cin >> n;
		switch(n){
			case 1: 
			   if(List.isFull()) cout << "Mang da day" << endl ;
			    else cout << "Mang chua day" << endl;
			   break;
			case 2: 
			   cout << "So luong phan tu mang: " << List.length() << endl;
			   break;
			case 3:
				int x;
				cout << "Nhap gia tri chen: ";
				cin >> x; 
				List.append(x);
				List.print();
				break;
			case 4: 
			    int y,z;
			    cout << "Nhap gia tri can chen: ";
			    cin >> y;
			    do{
			    cout << "Nhap vi tri can chen: ";
			    cin >> z;
		        } while (z<0 || z>99 );  
		        List.insert(y, z);
		        List.print();
		        break;
		    case 5: 
		        List.removeLast();
		        List.print();
		        break;
		    case 6: 
		        int t;
		        do{
		        cout << "Nhap vi tri xoa: ";
		        cin >> t;
		       }  while(t<0 || t>99);
		       List.remove(t);
		       List.print();
		       break;
		    case 7: 
		       List.sortASC();
		       List.print();
		       break;
		}
	} while (n != 0);
}

int main(){
    Menu();

}


